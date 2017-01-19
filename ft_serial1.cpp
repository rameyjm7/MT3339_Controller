#include "ft_serial1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <libftdi1/ftdi.h>
ft_serial1::~ft_serial1()
{
    is_present = false;
    ftdi_set_bitmode (ftdi, 0, BITMODE_RESET);
    ftdi_usb_close (ftdi);
    ftdi_free (ftdi);
}

void ft_serial1::Close()
{

    if(isOpen)
    {
        ftdi_set_bitmode(ftdi, 0, BITMODE_RESET);
        ftdi_usb_close(ftdi);
        ftdi_deinit(ftdi);
        isOpen = false;
        qDebug() << "FTDI Interface " << interface << "closed.";
    }
    else    qDebug() << "FTDI Interface " << interface << "is not open.";

}
void ft_serial1::sendByteBB(BYTE byte)
{
    for (int i = 7; i >= 0; i--) { // most significant bit first
        if (byte & (1 << i))
            digitalWrite(PIN_MOSI, 1);
        else
            digitalWrite(PIN_MOSI, 0);

        // do a clock
        digitalWrite(PIN_SCK, 1);
        digitalWrite(PIN_SCK, 0);
    }

}
void ft_serial1::digitalWrite(BYTE pin, int value)
{
    // store current value
    static BYTE r = 0;
    if (value)
        r |= pin;
    else
        r &= ~pin;

    ftdi_write_data(ftdi,&r,sizeof(r));
}
void ft_serial1::SPIStart()
{
    digitalWriteNow(0x08,0);
    digitalWriteNow(0x01|0x04|0x08,0);
}
void ft_serial1::SPIStop()
{    digitalWriteNow(0x01|0x04,1);
     digitalWriteNow(0x08,1);

}
void ft_serial1::I2CStart()
{
    digitalWriteNow(0x04,0);
    digitalWriteNow(0x01,0);
}
void ft_serial1::I2CStop()
{
    digitalWriteNow(0x01,1); // clk high
    digitalWriteNow(0x01|0x04,1); // sda high
}
void ft_serial1::I2CByte(BYTE addr, BYTE data)
{
    I2CStart();
    sendByteBB(addr);
    CLK_ACK();
    sendByteBB(data);
    CLK_ACK();
    I2CStop();
}
void ft_serial1::CLK_ACK()
{
    // do a clock
    digitalWrite(PIN_SCK, 1);
    digitalWrite(PIN_SCK, 0);
}
void ft_serial1::Setup(uint8_t instance, uint8_t port, uint16_t device_code)
{

    // ----- Initialize -----
//    ftdi = ftdi_new ();
    ftdi_interface por;
    if(port == 0) por = INTERFACE_A;
    else if(port == 1) por = INTERFACE_B;
    else if(port == 2) por = INTERFACE_C;
    else if(port == 3) por = INTERFACE_D;
    ftdi_set_interface (ftdi, por);
    is_ready = false;

    // ----- Open the device -----
    // qDebug ("# FT4232HSerial: Opening the device...\n");
    int r = ftdi_usb_open_desc_index (ftdi, vendor, device_code, NULL, NULL, instance);
    is_present = (r == 0);
    if (!is_present) return;







    // ----- Setup the device -----
     qDebug ("# FT4232HSerial: Setting up the FTDI interface %d...",port);
    int status = ftdi_read_chipid (ftdi, &chip_id);
    //    status |= ftdi_read_eeprom (ftdi);
    //    status |= ftdi_eeprom_decode (ftdi, 0);

    status |= ftdi_usb_reset (ftdi);
    status |= ftdi_usb_purge_buffers (ftdi);

    status |= ftdi_set_latency_timer (ftdi, latency_millisec);
    status |= ftdi_write_data_set_chunksize (ftdi, chunk_size);
    status |= ftdi_read_data_set_chunksize (ftdi, chunk_size);
    status |= ftdi_set_bitmode (ftdi, 0, BITMODE_RESET);
    if (status) {
        qDebug ("# FT4232HSerial: Error setting up the device.\n");
        return;
    }

    // ----- Serial Port Setup -----
     qDebug ("# FT4232HSerial: Setting up the serial port...\n");
    status = ftdi_set_baudrate (ftdi, 115200);
    status |= ftdi_set_line_property (ftdi, BITS_8, STOP_BIT_1, NONE);
    status |= ftdi_setflowctrl (ftdi, SIO_DISABLE_FLOW_CTRL);
    if (status) {
//        qDebug ("# FT4232HSerial: Error setting up serial port settings.\n");
        return;
    }

    // ----- ReadLine buffer -----
    count = head = tail = 0;

    // ----- Ready -----
     qDebug ("# FT4232HSerial: Purging the buffers...\n");
    status = ftdi_usb_purge_buffers (ftdi);
    is_ready = true;
    isOpen = true;
}



void ft_serial1::digitalWriteNow(unsigned char pin, int value)
{
    // store current value
    static unsigned char r = lastCMD;

    if (value)
    {
        r &= ~pin;
        r |= pin;
    }

    else
        r &= ~pin;
    ftdi_write_data(ftdi, &r, sizeof(r));
}

void ft_serial1::WriteRead(int numread)
{
    ftdi_usb_purge_buffers(ftdi);
    ftdi_write_data(ftdi,OutputBuffer,sizeof(dwNumBytesToSend));
    ftdi_read_data(ftdi,InputBuffer,numread);
    qDebug() << InputBuffer;
}
void ft_serial1::addByte( BYTE b1)
{

    OutputBuffer[dwNumBytesToSend++] = b1;
}

void ft_serial1::setGPIOState(BYTE dir, BYTE val)
{
    OutputBuffer[dwNumBytesToSend++] = 0x80; // Sets GPIOL pins
    OutputBuffer[dwNumBytesToSend++] = val; // 0000 0000 value
    OutputBuffer[dwNumBytesToSend++] = dir; // 0000 1011 direction
}





ft_serial1::ft_serial1 ()
{
    ftdi = ftdi_new ();
}



int ft_serial1::SetBaudRate (uint32_t baudRate)
// ---------------------------------------------------------------------------
//  Sets the baud rate of the serial port.
// ---------------------------------------------------------------------------
{
     qDebug ("# FT4232HSerial::SetBaudRate: Setting baud rate to %d...\n", baudRate);
    int status = ftdi_set_baudrate (ftdi, baudRate);
    if (status) return status;
    return ftdi_usb_purge_buffers (ftdi);
}


int ft_serial1::Flush (void)
// ---------------------------------------------------------------------------
//  Flushes the serial port and internal buffer.
// ---------------------------------------------------------------------------
{
    count = head = tail = 0;
    return ftdi_usb_purge_buffers (ftdi);
}


int ft_serial1::GetChars (char* str, uint32_t maxChars, uint32_t& numReceived)
// ---------------------------------------------------------------------------
//  Gets up to maxChars from the serial port.
//  Returns 1 if none are available.
// ---------------------------------------------------------------------------
{
//    qDebug ("# FT4232HSerial::GetChars: Getting %d chars...\n", maxChars);
    int r = ftdi_read_data (ftdi, (unsigned char*) str, maxChars);
//    qDebug ("# FT4232HSerial::GetChars: Return code %d.\n", r);
    numReceived = 0;
    if (r < 0) return r;
    if (r == 0) return 1;
    numReceived = r;
    return 0;
}


int ft_serial1::PutChars (unsigned char* str, uint32_t numChars)
// ---------------------------------------------------------------------------
//  Sends chars to the serial port (do not send more than 4096).
// ---------------------------------------------------------------------------
{
    while (numChars > 0) {
        int n = (numChars > 4096) ? 4096 : numChars;
        int r = ftdi_write_data (ftdi, str, n);
        if (r < 0) return r;
        numChars -= r;
        str += r;
    }
    return 0;
}


int ft_serial1::ReadLine (char* str, uint32_t timeoutMsec, int num_chars)
// ---------------------------------------------------------------------------
//  Reads a line.
//  Maintains an internal buffer so successive lines are not lost.
// ---------------------------------------------------------------------------
{
    const uint32_t pollMsec = 10;

    while (true) {

        // ----- Copy until <CR> or <LF> -----
        char ch = 0;
        while (count > 0) {
            ch = buffer[tail];
            // qDebug ("%c", ch);  fflush (stdout);
            if (ch == '\r' || ch == '\n') break;
            *str++ = ch;
            count--;
            tail = (tail + 1) % num_chars;
        }

        // ----- Found <CR> or <LF> -----
        if (ch == '\r' || ch == '\n') {
            *str++ = '\0';
            count--;
            tail = (tail + 1) % num_chars;
            if (count > 0 && buffer[tail] == '\n') {
                count--;
                tail = (tail + 1) % num_chars;
            }
            return 0;
        }

        // ----- Get more characters -----
        uint32_t maxChars = num_chars - count;
        if (num_chars - head < maxChars) maxChars = num_chars - head;

        uint32_t numReceived;
        uint32_t t;
        for (t=0; t < timeoutMsec; t += pollMsec) {
            int r = GetChars (buffer+head, maxChars, numReceived);
            // if (!r) qDebug ("Received %d\n", numReceived);
            if (r == 0 && numReceived) break;
            usleep (pollMsec * 1000);
        }

        // ----- If timeout -----
        if (t >= timeoutMsec) {
            *str = '\0';
            return 1;
        }

        // ----- Update buffer -----
        head += numReceived;
        count += numReceived;
    }
    return 0;
}


int ft_serial1::WriteLine (const char* str)
// ---------------------------------------------------------------------------
//  Writes a line.
// ---------------------------------------------------------------------------
{
    char out[1024];
    sprintf (out, "%s\r\n", str);
    return PutChars ((unsigned char *)out, strlen(out));
}

void ft_serial1::readEEPROM()
{
    struct ftdi_context *ftdi;
    int f, i;
    int vid = 0;
    int pid = 0;
    char const *desc    = 0;
    char const *serial  = 0;
    int erase = 0;
    int use_defaults = 0;
    int large_chip = 0;
    int do_write = 0;
    int retval = 0;
    int value;

    if ((ftdi = ftdi_new()) == 0)
    {
        qDebug( "Failed to allocate ftdi structure :%s \n",
                ftdi_get_error_string(ftdi));
//        return EXIT_FAILURE;
    }

    // Select first interface
    ftdi_set_interface(ftdi, INTERFACE_ANY);

    if (!vid && !pid && desc == NULL && serial == NULL)
    {
        struct ftdi_device_list *devlist, *curdev;
        int res;
        if ((res = ftdi_usb_find_all(ftdi, &devlist, 0, 0)) < 0)
        {
            qDebug( "No FTDI with default VID/PID found\n");
            retval =  EXIT_FAILURE;
            goto do_deinit;
        }
        if (res > 1)
        {
            int i = 1;
            qDebug( "%d FTDI devices found: Only Readout on EEPROM done. ",res);
            qDebug( "Use VID/PID/desc/serial to select device\n");
            for (curdev = devlist; curdev != NULL; curdev= curdev->next, i++)
            {
                f = ftdi_usb_open_dev(ftdi,  curdev->dev);
                if (f<0)
                {
                    qDebug( "Unable to open device %d: (%s)",
                            i, ftdi_get_error_string(ftdi));
                    continue;
                }
                qDebug( "Decoded values of device %d:\n", i);
                read_decode_eeprom(ftdi);
                ftdi_usb_close(ftdi);
            }
            ftdi_list_free(&devlist);
            retval = EXIT_SUCCESS;
            goto do_deinit;
        }
        else if (res == 1)
        {
            f = ftdi_usb_open_dev(ftdi,  devlist[0].dev);
            if (f<0)
            {
                qDebug( "Unable to open device %d: (%s)",
                        i, ftdi_get_error_string(ftdi));
            }
        }
        else
        {
            qDebug( "No devices found\n");
            f = 0;
        }
        ftdi_list_free(&devlist);
    }
    else
    {
        // Open device
        f = ftdi_usb_open_desc(ftdi, vid, pid, desc, serial);
        if (f < 0)
        {
            qDebug( "Device VID 0x%04x PID 0x%04x", vid, pid);
            if (desc)
                qDebug( " Desc %s", desc);
            if (serial)
                qDebug( " Serial %s", serial);
            qDebug( "\n");
            qDebug( "unable to open ftdi device: %d (%s)\n",
                    f, ftdi_get_error_string(ftdi));

            retval = -1;
            goto done;
        }
    }
    if (erase)
    {
        f = ftdi_erase_eeprom(ftdi); /* needed to determine EEPROM chip type */
        if (f < 0)
        {
            qDebug( "Erase failed: %s",
                    ftdi_get_error_string(ftdi));
            retval =  -2;
            goto done;
        }
        if (ftdi_get_eeprom_value(ftdi, CHIP_TYPE, & value) <0)
        {
            qDebug( "ftdi_get_eeprom_value: %d (%s)\n",
                    f, ftdi_get_error_string(ftdi));
        }
        if (value == -1)
            qDebug( "No EEPROM\n");
        else if (value == 0)
            qDebug( "Internal EEPROM\n");
        else
            qDebug( "Found 93x%02x\n", value);
        retval = 0;
        goto done;
    }

    if (use_defaults)
    {
        ftdi_eeprom_initdefaults(ftdi, NULL, NULL, NULL);
        if (ftdi_set_eeprom_value(ftdi, MAX_POWER, 500) <0)
        {
            qDebug( "ftdi_set_eeprom_value: %d (%s)\n",
                    f, ftdi_get_error_string(ftdi));
        }
        if (large_chip)
            if (ftdi_set_eeprom_value(ftdi, CHIP_TYPE, 0x66) <0)
            {
                qDebug( "ftdi_set_eeprom_value: %d (%s)\n",
                        f, ftdi_get_error_string(ftdi));
            }
        f=(ftdi_eeprom_build(ftdi));
        if (f < 0)
        {
            qDebug( "ftdi_eeprom_build: %d (%s)\n",
                    f, ftdi_get_error_string(ftdi));
            retval = -1;
            goto done;
        }
    }
    else if (do_write)
    {
        ftdi_eeprom_initdefaults(ftdi, NULL, NULL, NULL);
        f = ftdi_erase_eeprom(ftdi);
        if (ftdi_set_eeprom_value(ftdi, MAX_POWER, 500) <0)
        {
            qDebug( "ftdi_set_eeprom_value: %d (%s)\n",
                    f, ftdi_get_error_string(ftdi));
        }
        f = ftdi_erase_eeprom(ftdi);/* needed to determine EEPROM chip type */
        if (ftdi_get_eeprom_value(ftdi, CHIP_TYPE, & value) <0)
        {
            qDebug( "ftdi_get_eeprom_value: %d (%s)\n",
                    f, ftdi_get_error_string(ftdi));
        }
        if (value == -1)
            qDebug( "No EEPROM\n");
        else if (value == 0)
            qDebug( "Internal EEPROM\n");
        else
            qDebug( "Found 93x%02x\n", value);
        f=(ftdi_eeprom_build(ftdi));
        if (f < 0)
        {
            qDebug( "Erase failed: %s",
                    ftdi_get_error_string(ftdi));
            retval = -2;
            goto done;
        }
        f = ftdi_write_eeprom(ftdi);
        {
            qDebug( "ftdi_eeprom_decode: %d (%s)\n",
                    f, ftdi_get_error_string(ftdi));
            retval = 1;
            goto done;
        }
    }
    retval = read_decode_eeprom(ftdi);
done:
    ftdi_usb_close(ftdi);
do_deinit:
    ftdi_free(ftdi);

}

int ft_serial1::findDevices()
{
    int ret, i;
    struct ftdi_context *ftdi;
    struct ftdi_device_list *devlist, *curdev;
    char manufacturer[128], description[128];
    int retval = EXIT_SUCCESS;

    if ((ftdi = ftdi_new()) == 0)
    {
        qDebug( "ftdi_new failed\n");
        return EXIT_FAILURE;
    }

    if ((ret = ftdi_usb_find_all(ftdi, &devlist, 0, 0)) < 0)
    {
        qDebug( "ftdi_usb_find_all failed: %d (%s)\n", ret, ftdi_get_error_string(ftdi));
        retval =  EXIT_FAILURE;
        goto do_deinit;
    }

    qDebug("Number of FTDI devices found: %d\n", ret);

    i = 0;
    for (curdev = devlist; curdev != NULL; i++)
    {
        qDebug("Checking device: %d\n", i);
        if ((ret = ftdi_usb_get_strings(ftdi, curdev->dev, manufacturer, 128, description, 128, NULL, 0)) < 0)
        {
            qDebug( "ftdi_usb_get_strings failed: %d (%s)\n", ret, ftdi_get_error_string(ftdi));
            retval = EXIT_FAILURE;
            goto done;
        }
        qDebug("Manufacturer: %s, Description: %s\n\n", manufacturer, description);
        curdev = curdev->next;
    }
done:
    ftdi_list_free(&devlist);
do_deinit:
    ftdi_free(ftdi);

}

int ft_serial1::read_decode_eeprom(struct ftdi_context *ftdi)
{
    int i, j, f;
    int value;
    int size;
    unsigned char buf[256];

    f = ftdi_read_eeprom(ftdi);
    if (f < 0)
    {
        qDebug( "ftdi_read_eeprom: %d (%s)\n",
                f, ftdi_get_error_string(ftdi));
        return -1;
    }


    ftdi_get_eeprom_value(ftdi, CHIP_SIZE, & value);
    if (value <0)
    {
        qDebug( "No EEPROM found or EEPROM empty\n");
        qDebug( "On empty EEPROM, use -w option to write default values\n");
        return -1;
    }
    qDebug( "Chip type %d ftdi_eeprom_size: %d\n", ftdi->type, value);
    if (ftdi->type == TYPE_R)
        size = 0xa0;
    else
        size = value;
    ftdi_get_eeprom_buf(ftdi, buf, size);
    for (i=0; i < size; i += 16)
    {
        fprintf(stdout,"0x%03x:", i);

        for (j = 0; j< 8; j++)
            fprintf(stdout," %02x", buf[i+j]);
        fprintf(stdout," ");
        for (; j< 16; j++)
            fprintf(stdout," %02x", buf[i+j]);
        fprintf(stdout," ");
        for (j = 0; j< 8; j++)
            fprintf(stdout,"%c", isprint(buf[i+j])?buf[i+j]:'.');
        fprintf(stdout," ");
        for (; j< 16; j++)
            fprintf(stdout,"%c", isprint(buf[i+j])?buf[i+j]:'.');
        fprintf(stdout,"\n");
    }

    f = ftdi_eeprom_decode(ftdi, 1);
    if (f < 0)
    {
        qDebug( "ftdi_eeprom_decode: %d (%s)\n",
                f, ftdi_get_error_string(ftdi));
        return -1;
    }
    return 0;
}
