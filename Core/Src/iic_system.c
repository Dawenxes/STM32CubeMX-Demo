//
// Created by 阳庆瑶 on 2023/10/11.
//

#include "iic_system.h"
#include "myiic.h"

static void I2C_GPIO_Config(void) {
    GPIO_InitTypeDef gpio_init_struct;

    IIC_SCL_GPIO_CLK_ENABLE();  /* SCL引脚时钟使能 */
    IIC_SDA_GPIO_CLK_ENABLE();  /* SDA引脚时钟使能 */

    gpio_init_struct.Pin = IIC_SCL_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;        /* 推挽输出 */
    gpio_init_struct.Pull = GPIO_PULLUP;                /* 上拉 */
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;      /* 高速 */
    HAL_GPIO_Init(IIC_SCL_GPIO_PORT, &gpio_init_struct);/* SCL */

    gpio_init_struct.Pin = IIC_SDA_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_OD;        /* 开漏输出 */
    HAL_GPIO_Init(IIC_SDA_GPIO_PORT, &gpio_init_struct);/* SDA */
    /* SDA引脚模式设置,开漏输出,上拉, 这样就不用再设置IO方向了, 开漏输出的时候(=1), 也可以读取外部信号的高低电平 */

    iic_stop();
}

/**
* @brief I2C 工作模式配置
 * @param 无
 * @retval 无
 */
 static void I2C_Mode_Configu(void) {
    I2C_InitTypeDef I2C_InitStructure;

    /* I2C 配置 */
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;

    /* 高电平数据稳定，低电平数据变化 SCL 时钟线的占空比 */
    I2C_InitStructure.DutyCycle = I2C_DUTYCYCLE_16_9;

    I2C_InitStructure.OwnAddress1 = I2Cx_OWN_ADDRESS7;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.NoStretchMode
    /* I2C 的寻址模式 */
    I2C_InitStructure.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

    /* 通信速率 */
    I2C_InitStructure.ClockSpeed = I2C_Speed;

    /* I2C 初始化 */
    I2C_Init(EEPROM_I2Cx, &I2C_InitStructure);

    /* 使能 I2C */
    I2C_Cmd(EEPROM_I2Cx, ENABLE);
}