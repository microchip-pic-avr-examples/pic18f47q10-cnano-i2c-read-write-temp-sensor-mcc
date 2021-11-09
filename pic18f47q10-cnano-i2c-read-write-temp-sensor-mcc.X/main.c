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
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/i2c_host/i2c_host_types.h"
#include "mcc_generated_files/i2c_host/mssp1.h"


#define I2C_CLIENT_ADDR                 0x49            /* 7-bit address */
#define MCP9800_REG_ADDR_CONFIG         0x01
#define MCP9800_REG_ADDR_TEMPERATURE    0x00
#define CONFIG_DATA_12BIT_RESOLUTION    0x60
#define RESOLUTION                      12
#define REGISTER_SIZE                   16
#define RIGHT_SHIFT_VALUE (REGISTER_SIZE - RESOLUTION)
#define DATALENGTH                      2

const i2c_host_interface_t *I2C = &i2c1_host_interface;

void main(void)
{
    /* Initialize the device */
    SYSTEM_Initialize();
    
    /* Declare variables */
    uint8_t     dataWrite[2];
    uint8_t     dataRead[2];
    uint16_t    rawTempValue;
    float       tempCelsius;
    
    /* Set the resolution to 12-bits */
    dataWrite[0] = MCP9800_REG_ADDR_CONFIG;
    dataWrite[1] = CONFIG_DATA_12BIT_RESOLUTION;
    
    if (I2C->Write(I2C_CLIENT_ADDR, dataWrite, DATALENGTH))
    {
        while(I2C->IsBusy())
        {
            I2C->Tasks();
        }
        if (I2C->ErrorGet() != I2C_ERROR_NONE)
        {
            /* Write operation is successful */
        }
        else
        {
            /* Error handling */
        }
    }
    
    
    dataWrite[0] = MCP9800_REG_ADDR_TEMPERATURE;
    while (1)
    {
        /* Read out the 12-bit raw temperature value */
        if (I2C->WriteRead(I2C_CLIENT_ADDR, dataWrite, DATALENGTH, dataRead, DATALENGTH))
        {
            while(I2C->IsBusy())
            {
                I2C->Tasks();
            }
            if (I2C->ErrorGet() != I2C_ERROR_NONE)
            {
                /* Write operation is successful */
            }
            else
            {
                /* Error handling */
            }
        }
        
        /* Combine the two 8-bit values into on 16-bit value */
        rawTempValue = (dataRead[0] << 8 | dataRead[1]);
        rawTempValue = rawTempValue >> RIGHT_SHIFT_VALUE;     
        
        /* Convert the raw temperature data to degrees Celsius according to the MCP9800 data sheet */
        tempCelsius = (float) (rawTempValue / 16.0);
        __delay_ms(500);
    }
}