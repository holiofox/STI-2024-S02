/**
  ******************************************************************************
  * @file    bsp_general_tim.c
  * @author  STMicroelectronics
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   通用定时器PWM输出范例
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火  STM32 F429 开发板  
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./tim/bsp_general_tim.h"

/**
  * @brief  配置TIM复用输出PWM时用到的I/O
  * @param  无
  * @retval 无
  */
void TIMx_GPIO_Config(void) 
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*开启相关的GPIO外设时钟*/
	RCC_AHB1PeriphClockCmd (GENERAL_OCPWM_GPIO_CLK, ENABLE); 
  /* 定时器通道引脚复用 */
	GPIO_PinAFConfig(GENERAL_OCPWM_GPIO_PORT,GENERAL_OCPWM_PINSOURCE,GENERAL_OCPWM_AF); 
  
	/* 定时器通道引脚配置 */															   
	GPIO_InitStructure.GPIO_Pin = GENERAL_OCPWM_PIN;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;    
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 
	GPIO_Init(GENERAL_OCPWM_GPIO_PORT, &GPIO_InitStructure);
}
void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/*
 * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
 * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
 * 另外三个成员是通用定时器和高级定时器才有.
 *-----------------------------------------------------------------------------
 * TIM_Prescaler         都有
 * TIM_CounterMode			 TIMx,x[6,7]没有，其他都有（基本定时器）
 * TIM_Period            都有
 * TIM_ClockDivision     TIMx,x[6,7]没有，其他都有(基本定时器)
 * TIM_RepetitionCounter TIMx,x[1,8]才有(高级定时器)
 *-----------------------------------------------------------------------------
 */
void TIM_PWMOUTPUT_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 开启TIMx_CLK,x[2,3,4,5,12,13,14] 
  RCC_APB1PeriphClockCmd(GENERAL_TIM_CLK, ENABLE); 

  /* 累计 TIM_Period个后产生一个更新或者中断*/		
  //当定时器从0计数到8999，即为9000次，为一个定时周期
  TIM_TimeBaseStructure.TIM_Period = 900-1;       
	
	// 通用控制定时器时钟源TIMxCLK = HCLK/2=90MHz 
	// 设定定时器频率为=TIMxCLK/(TIM_Prescaler+1)=100KHz
  TIM_TimeBaseStructure.TIM_Prescaler = 900-1;	
  // 采样时钟分频
  TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
  // 计数方式
  TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	
	// 初始化定时器TIMx, x[2,3,4,5,12,13,14] 
	TIM_TimeBaseInit(GENERAL_TIM, &TIM_TimeBaseStructure);
	
	/*PWM模式配置*/
	/* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_Pulse = 450-1;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  	  //当定时器计数值小于CCR1_Val时为高电平
  TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);	 //使能通道1
  // 使能定时器的更新中断
  TIM_ITConfig(GENERAL_TIM, TIM_IT_Update, ENABLE);

  // 配置中断优先级，假设你已经定义了NVIC配置的函数
  NVIC_Configuration(); // 这是一个假设的函数名，需要你根据实际情况实现
	/*使能通道1重载*/
	TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	
	// 使能定时器
	TIM_Cmd(GENERAL_TIM, ENABLE);	
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(GENERAL_TIM, TIM_IT_Update) != RESET) // 检查指定的TIM中断发生与否:更新中断
    {
        TIM_ClearITPendingBit(GENERAL_TIM, TIM_IT_Update);  // 清除TIM的中断待处理位:更新中断
        TIM_Cmd(GENERAL_TIM, DISABLE); // 停止定时器
        //只输出一个脉冲
        TIM_SetCounter(GENERAL_TIM, 0);
		    
    }
}

/*********************************************END OF FILE**********************/
