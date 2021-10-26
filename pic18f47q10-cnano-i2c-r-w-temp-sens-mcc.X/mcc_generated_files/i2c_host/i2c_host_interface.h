/**
  I2C interface Header File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c_host_interface.h

  @Summary
    This is the generated driver interface header file for the I2C driver.

  @Description
    This file provides common enumerations for I2C driver.
    Generation Information :
        Product Revision  :   - 
        Device            :  
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.30 and above
        MPLAB             :  MPLABX v5.45 and above
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

#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H
/**
  Section: Included Files
*/
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>
#include "i2c_host_types.h"
    
/**
  I2C_HOST_INTERFACE

  @Description
    Structure containing the function pointers of I2C driver.
 */
struct I2C_HOST_INTERFACE
{   
    void (*Initialize)(void);
    bool (*Write)(uint16_t address, uint8_t *data, size_t dataLength);
    bool (*Read)(uint16_t address, uint8_t *data, size_t dataLength);
    bool (*WriteRead)(uint16_t address, uint8_t *writeData, size_t writeLength, uint8_t *readData, size_t readLength);
    bool (*TransferSetup)(struct I2C_TRANSFER_SETUP* setup, uint32_t srcClkFreq);
    enum I2C_ERROR (*ErrorGet)(void);
    bool (*IsBusy)(void);
    void (*CallbackRegister)(void (*handler)(void));
};

#endif // end of I2C_INTERFACE_H

