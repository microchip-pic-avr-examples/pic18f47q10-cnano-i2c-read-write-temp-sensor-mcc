/**
 * I2C Generated Driver Interface Header File
 *
 * @file i2c_host_interface.h
 *
 * @defgroup i2c_host_interface I2C_HOST_INTERFACE
 *
 * @brief This file contains other data types for I2C module.
 *
 * @version I2C Driver Version 2.0.0
 */

/*
© [2021] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef I2C_HOST_INTERFACE_H
#define I2C_HOST_INTERFACE_H

/**
  Section: Included Files
 */
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>
#include "i2c_host_types.h"

/**
 * @ingroup i2c_host_interface
 * @strcut i2c_host_interface_t
 * @brief Structure containing the function pointers of I2C drivers.
 */
typedef struct
{
    void (*Initialize)(void);
    void (*Deinitialize)(void);
    bool (*Write)(uint16_t address, uint8_t *data, size_t dataLength);
    bool (*Read)(uint16_t address, uint8_t *data, size_t dataLength);
    bool (*WriteRead)(uint16_t address, uint8_t *writeData, size_t writeLength, uint8_t *readData, size_t readLength);
    bool (*TransferSetup)(i2c_host_transfer_setup_t* setup, uint32_t srcClkFreq);
    i2c_host_error_t (*ErrorGet)(void);
    bool (*IsBusy)(void);
    void (*CallbackRegister)(void (*callback)(void));
    void (*Tasks)(void);
} i2c_host_interface_t;

/**
 * @ingroup i2c1_host
 * @example i2c1_host_interface_example_code
 * @brief In this I2C Host example, a byte of data is written in to EEPROM and read it back.
 *        Case 1: Data 0xAA is written in to EEPROM at location 0x0010 and read the same back, using I2C1_Write() and I2C1_WriteRead() functions.
 *        Case 2: Data 0x55 is written in to EEPROM at location 0x0020 and read the same back using I2C1_Write() and I2C1_Read() functions.
 * @code
 * 
 * void main(void)
 * {
 *    uint8_t transmitData[10];
 *    uint8_t writeLength;
 *    uint8_t readLength;
 *    uint8_t writeData;
 *    uint8_t readData;
 *    uint8_t eepromAddr = 0x50; // 7-bit EEPROM address
 *    uint8_t waitCounter;
 *
 *    // Initializes Clock, Pins, Interrupts and I2C host
 *    SYSTEM_Initialize();
 *    // Case 1:
 *    transmitData[0] = 0x00;  // load MSB of EEPROM location
 *    transmitData[1] = 0x10;  // load LSB of EEPROM location
 *    transmitData[2] = 0xAA;  // load data
 *    writeLength = 3; // 2 bytes of location address + 1 byte data
 *
 *    if ( i2c1_host_interface.Write(eepromAddr, transmitData, writeLength))
 *    {
 *        waitCounter = 100; // This value depends on the system clock, I2C clock and data length.
 *        while ( i2c1_host_interface.IsBusy() && waitCounter)
 *        {
 *            i2c1_host_interface.Tasks();
 *            waitCounter--;
 *        }
 *
 *        if (  i2c1_host_interface.ErrorGet() == I2C_ERROR_NONE)
 *        {
 *            // Write operation is successful
 *        }
 *        else
 *        {
 *            // Error handling
 *        }
 *    }
 *
 *    writeLength = 2; // 2 bytes of location address
 *    readLength = 1; // 1 byte read
 *    if (i2c1_host_interface.WriteRead(eepromAddr, transmitData, writeLength, readData , readLength))
 *    {
 *        waitCounter = 100; // This value depends on the system clock, I2C clock and data length.
 *        while ( i2c1_host_interface.IsBusy() && waitCounter)
 *        {
 *            i2c1_host_interface.Tasks();
 *            waitCounter--;
 *        }
 *
 *        if (  i2c1_host_interface.ErrorGet() == I2C_ERROR_NONE)
 *        {
 *            // WriteRead operation is successful
 *        }
 *        else
 *        {
 *            // Error handling
 *        }
 *    }
 *
 *    // Case 2:
 *    transmitData[0] = 0x00;  // load MSB of EEPROM location
 *    transmitData[1] = 0x20;  // load LSB of EEPROM location
 *    transmitData[2] = 0x55;  // load data
 *    writeLength = 3; // 2 bytes of location address + 1 byte data
 *    if (i2c1_host_interface.Write(eepromAddr, transmitData, writeLength))
 *    {
 *        waitCounter = 100; // This value depends on the system clock, I2C clock and data length.
 *        while ( i2c1_host_interface.IsBusy() && waitCounter)
 *        {
 *            i2c1_host_interface.Tasks();
 *            waitCounter--;
 *        }
 *
 *        if ( i2c1_host_interface.ErrorGet() == I2C_ERROR_NONE)
 *        {
 *            // Write operation is successful
 *        }
 *        else
 *        {
 *            // Error handling
 *        }
 *    }
 *
 *    writeLength = 2; // 2 bytes of location address
 *    if (i2c1_host_interface.Write(eepromAddr, transmitData, writeLength))
 *    {
 *        waitCounter = 100; // This value depends on the system clock, I2C clock and data length.
 *        while ( i2c1_host_interface.IsBusy() && waitCounter)
 *        {
 *            i2c1_host_interface.Tasks();
 *            waitCounter--;
 *        }
 *
 *        if ( i2c1_host_interface.ErrorGet() == I2C_ERROR_NONE)
 *        {
 *            // Write operation is successful
 *        }
 *        else
 *        {
 *            // Error handling
 *        }
 *    }
 *
 *    readLength = 1; // 1 byte read
 *    if (i2c1_host_interface.Read(eepromAddr, readData, readLength))
 *    {
 *        waitCounter = 100; // This value depends on the system clock, I2C clock and data length.
 *        while ( i2c1_host_interface.IsBusy() && waitCounter)
 *        {
 *            i2c1_host_interface.Tasks();
 *            waitCounter--;
 *        }
 *
 *        if ( i2c1_host_interface.ErrorGet() == I2C_ERROR_NONE)
 *        {
 *            // Read operation is successful
 *        }
 *        else
 *        {
 *            // Error handling
 *        }
 *    }
 *
 *     while (1)
 *     {
 *     }
 * }
 * @endcode
*/
#endif // end of I2C_HOST_INTERFACE_H

