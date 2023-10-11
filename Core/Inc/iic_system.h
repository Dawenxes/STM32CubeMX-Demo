//
// Created by 阳庆瑶 on 2023/10/11.
//

#ifndef STM32CUBEMX_DEMO_IIC_SYSTEM_H
#define STM32CUBEMX_DEMO_IIC_SYSTEM_H

#include "main.h"

#define EEPROM_I2Cx I2C1
#define EEPROM_I2C_APBxClock_FUN RCC_APB1PeriphClockCmd
#define EEPROM_I2C_CLK RCC_APB1Periph_I2C1
#define EEPROM_I2C_GPIO_APBxClock_FUN RCC_APB2PeriphClockCmd
#define EEPROM_I2C_GPIO_CLK RCC_APB2Periph_GPIOB
#define EEPROM_I2C_SCL_PORT GPIOB
#define EEPROM_I2C_SCL_PIN GPIO_Pin_6
#define EEPROM_I2C_SDA_PORT GPIOB
#define EEPROM_I2C_SDA_PIN GPIO_Pin_7

#define I2C_Speed 400000 //*

/* 这个地址只要与 STM32 外挂的 I2C 器件地址不一样即可 */
#define I2Cx_OWN_ADDRESS7 0X0A
/* AT24C01/02 每页有 8 个字节 */
#define I2C_PageSize 8

static void I2C_GPIO_Config(void);

#endif //STM32CUBEMX_DEMO_IIC_SYSTEM_H
