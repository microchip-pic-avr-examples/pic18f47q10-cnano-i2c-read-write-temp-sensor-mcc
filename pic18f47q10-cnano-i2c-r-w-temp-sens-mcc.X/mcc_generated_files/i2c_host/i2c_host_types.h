/**
  I2C Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c_host_types.h

  @Summary
    This is the generated driver types header file for the I2C driver.

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

#ifndef I2C_HOST_TYPES_H
#define	I2C_HOST_TYPES_H

/**
  I2C_ERROR Enumeration
 
  @Description
    I2C ERROR code
     
*/
enum I2C_ERROR
{
    I2C_ERROR_NONE,             /* No Error */
    I2C_ERROR_NACK,             /* Client returned NACK */
    I2C_ERROR_BUS_COLLISION,    /* Bus Collision Error */
};

/**
  I2C_TRANSFER_SETUP structure
 
  @Description
    I2C Clock Speed (100KHZ to 1MHZ)
     
*/
struct I2C_TRANSFER_SETUP
{
  uint32_t clkSpeed;            // I2C Clock Speed
};

#endif // end of I2C_HOST_TYPES_H