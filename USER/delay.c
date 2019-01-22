#include "delay.h"
#include "data_typedef.h"

static u32 fac_us = 80;

#if 0
/**************************************************************
函数名称 : delay_init
函数功能 : 初始化延迟函数
输入参数 : SYSCLK：系统时钟频率
返回值  	 : 无
备注		 : SYSTICK的时钟固定为AHB时钟
**************************************************************/
void delay_init(u8 SYSCLK)
{
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);	/* SysTick频率为HCLK */
    fac_us = SYSCLK;
}
#endif

/**************************************************************
函数名称 : delay_us
函数功能 : 延时微秒(us)函数
输入参数 : nus：需要延时多少微秒
返回值  	 : 无
备注		 : 无
**************************************************************/
void delay_us(u32 nus)
{
    u32 ticks;
    u32 told, tnow, tcnt = 0;
    u32 reload = SysTick->LOAD;				/* LOAD的值 */
    ticks = nus * fac_us; 					/* 需要的节拍数 */
    told = SysTick->VAL;        			/* 刚进入时的计数器值 */

    while(1)
    {
        tnow = SysTick->VAL;

        if(tnow != told)
        {
            if(tnow < told)tcnt += told - tnow;	/* 这里注意一下SYSTICK是一个递减的计数器就可以了 */
            else tcnt += reload - tnow + told;
			
            told = tnow;
            if(tcnt >= ticks)break;				/* 时间超过/等于要延迟的时间,则退出 */
        }
    }
}

/**************************************************************
函数名称 : delay_ms
函数功能 : 延时毫秒(ms)函数
输入参数 : nms：需要延时多少毫秒
返回值  	 : 无
备注		 : 无
**************************************************************/
void delay_ms(u16 nms)
{
    u32 i;

    for(i = 0; i < nms; i++)
	{	
		delay_us(1000);
    }
}


