#ifndef __I2C_TOUCH_H
#define	__I2C_TOUCH_H

#include "stm32f4xx.h"


/* 如果用的是4.3寸RGB屏，其触摸芯片可能是GT1151QM，它的I2C地址不同，需要定义这个宏 */
//#define LCD_4_3_TOUCH_GT1151QM

#ifndef LCD_4_3_TOUCH_GT1151QM
#define GTP_ADDRESS                      0x28
#else
#define GTP_ADDRESS                      0xBA 
#endif


#define I2CT_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define I2CT_LONG_TIMEOUT         ((uint32_t)(10 * I2CT_FLAG_TIMEOUT))


#define GTP_I2C                          I2C2
#define GTP_I2C_CLK                      RCC_APB1Periph_I2C2

#define GTP_I2C_SCL_PIN                  GPIO_Pin_4                  
#define GTP_I2C_SCL_GPIO_PORT            GPIOH                       
#define GTP_I2C_SCL_GPIO_CLK             RCC_AHB1Periph_GPIOH
#define GTP_I2C_SCL_SOURCE               GPIO_PinSource4
#define GTP_I2C_SCL_AF                   GPIO_AF_I2C2

#define GTP_I2C_SDA_PIN                  GPIO_Pin_5                  
#define GTP_I2C_SDA_GPIO_PORT            GPIOH                    
#define GTP_I2C_SDA_GPIO_CLK             RCC_AHB1Periph_GPIOH
#define GTP_I2C_SDA_SOURCE               GPIO_PinSource5
#define GTP_I2C_SDA_AF                   GPIO_AF_I2C2

#define GTP_RST_GPIO_PORT                GPIOD
#define GTP_RST_GPIO_CLK                 RCC_AHB1Periph_GPIOD
#define GTP_RST_GPIO_PIN                 GPIO_Pin_11

#define GTP_INT_GPIO_PORT                GPIOD
#define GTP_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOD
#define GTP_INT_GPIO_PIN                 GPIO_Pin_13
#define GTP_INT_READ()                   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_13)

//#define GTP_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOD
//#define GTP_INT_EXTI_PINSOURCE           EXTI_PinSource12


static uint32_t I2C_TIMEOUT_UserCallback(void);


uint32_t I2C_WriteBytes(uint8_t ClientAddr,uint8_t* pBuffer,  uint8_t NumByteToWrite);
uint32_t I2C_ReadBytes(uint8_t ClientAddr,uint8_t* pBuffer, uint16_t NumByteToRead);

void I2C_Touch_Init(void);
void I2C_ResetChip(void);


#endif /* __I2C_TOUCH_H */
