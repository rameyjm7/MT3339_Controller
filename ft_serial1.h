#ifndef FT_SERIAL1_H
#define FT_SERIAL1_H

extern "C"
{
#include "libftdi1/ftdi.h"
}
#include "QDebug"
#include "unistd.h"
#define PIN_SD0 0x01
#define PIN_SD1 0x02
#define PIN_SD2 0x04
#define PIN_SD3 0x08
#define PIN_SCK PIN_SD0
#define PIN_MISO PIN_SD1
#define PIN_MOSI PIN_SD2
#define PIN_SEN PIN_SD3
class ft_serial1
{
public:

    typedef unsigned char            BYTE;
    typedef unsigned int            DWORD;
    BYTE lastCMD;
    //declare for MPSSE command
    const BYTE MSB_RISING_EDGE_CLOCK_BYTE_OUT = '\x10';
    const BYTE MSB_FALLING_EDGE_CLOCK_BYTE_OUT = '\x11';
    const BYTE MSB_RISING_EDGE_CLOCK_BIT_OUT = '\x12';
    const BYTE MSB_FALLING_EDGE_CLOCK_BIT_OUT = '\x13';
    const BYTE MSB_RISING_EDGE_CLOCK_BYTE_IN = '\x20';
    const BYTE MSB_RISING_EDGE_CLOCK_BIT_IN = '\x22';
    const BYTE MSB_FALLING_EDGE_CLOCK_BYTE_IN = '\x24';
    const BYTE MSB_FALLING_EDGE_CLOCK_BIT_IN = '\x26';
    BYTE OutputBuffer[32]; //Buffer to hold MPSSE commands and data to be sent to FT2232
    DWORD dwNumBytesToSend=0;
    BYTE InputBuffer[32];
    bool bDEBUGMODE = true;
    bool isOpen = false;
    int interface;

    // ===========================================================================
    //  Settings
    // ===========================================================================
    static const int vendor = 0x0403;                  // FTDI
    static const int default_device_code = 0x6011;     // FT4232H

    static const uint32_t i2c_clock_speed      = 400000;   // Hz: do not exceed 400000 (fast mode)
    static const uint8_t  latency_millisec     = 2;        //
    static const uint32_t chunk_size           = 65535;    // bytes

    static const uint32_t jtag_clock_speed     = 1000000;  // Hz
    static const uint32_t read_retries         = 10;       // times to retry reading data from the ft4232 before giving up

    static const uint32_t spi_clock_speed      = 1000000;  // Hz  do not exceed 6 MHz (FTDI limit)



    // ----- Constructors -----
    ft_serial1 ();
    ~ft_serial1();
    void Close();
    void Setup(uint8_t instance, uint8_t port, uint16_t device_code = 0x6011);
    void WriteRead(int numread);
    void addByte(BYTE b1);
    void setGPIOState(BYTE dir, BYTE val);

    void digitalWrite(BYTE pin, int value);
    void sendByteBB(BYTE byte);
    void digitalWriteNow(unsigned char pin, int value);
    void I2CStart();
    void I2CStop();
    void I2CByte(BYTE addr, BYTE data);
    void CLK_ACK();
    void SPIStart();
    void SPIStop();






    //! For asynchronous serial, RS232
    bool IsPresent (void) { return is_present; }
    bool IsReady (void) { return is_ready; }

    int SetBaudRate (uint32_t baudRate);
    int Flush (void);

    int GetChars (char* str, uint32_t maxChars, uint32_t& numReceived);
    int PutChars (unsigned char *str, uint32_t numChars);

    int ReadLine (char* str, uint32_t timeoutMsec = 100, int num_chars =65536);
    int WriteLine (const char* str);


    int read_decode_eeprom(ftdi_context *ftdi);
    void readEEPROM();
    int findDevices();
private:
    bool is_present, is_ready;
    char buffer[65536];
    uint32_t count, head, tail;

    // ----- FTDI Info -----
    struct ftdi_context* ftdi;
    unsigned int chip_id;


};

#endif // FT_SERIAL1_H
