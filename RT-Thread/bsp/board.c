/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-07-24     Tanek        the first version
 * 2018-11-12     Ernest Chen  modify copyright
 */
#include <rthw.h>
#include <rtthread.h>
#include "board.h"
#ifdef RT_USING_LED
#include "led.h"
#endif
#ifdef RT_USING_SERIAL
#include "drv_usart.h"
#endif

// Holds the system core clock, which is the system clock 
// frequency supplied to the SysTick timer and the processor 
// core clock.
extern uint32_t SystemCoreClock;


void _Error_Handler(char *file, int line)
{
	/* USER CODE BEGIN Error_Handler_Debug */
  	/* User can add his own implementation to report the HAL error return state */
  	while(1)
  	{
  	}
  	/* USER CODE END Error_Handler_Debug */
}

/*
  * @brief System Clock Configuration
  * @retval None
*/
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct;
  	RCC_ClkInitTypeDef RCC_ClkInitStruct;

	__HAL_RCC_PWR_CLK_ENABLE();
	
    /* Initializes the CPU, AHB and APB busses clocks */
  	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 1;
  	RCC_OscInitStruct.PLL.PLLN = 20;
  	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  	RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  	RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  	{
    	_Error_Handler(__FILE__, __LINE__);
  	}

    /* Initializes the CPU, AHB and APB busses clocks */
  	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1| RCC_CLOCKTYPE_PCLK2;
  	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  	{
    	_Error_Handler(__FILE__, __LINE__);
  	}

    /* Configure the main internal regulator output voltage */
  	if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  	{
    	_Error_Handler(__FILE__, __LINE__);
  	}
}

/**
 *  HAL adaptation
 */
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
    /* Return function status */
    return HAL_OK;
}

uint32_t HAL_GetTick(void)
{
    return rt_tick_get() * 1000 / RT_TICK_PER_SECOND;
}

void HAL_SuspendTick(void)
{
    return ;
}

void HAL_ResumeTick(void)
{
    return ;
}

void HAL_Delay(__IO uint32_t Delay)
{
    return ;
}

void SysTick_Handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
#define RT_HEAP_SIZE 4*1024
static uint32_t rt_heap[RT_HEAP_SIZE];	// heap default size: 16K(1024 * 4 * 4)
RT_WEAK void *rt_heap_begin_get(void)
{
    return rt_heap;
}

RT_WEAK void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif

/**
 * This function will initial your board.
 */
void rt_hw_board_init()
{	
	/* 使用HAL库，初始化HAL */
	HAL_Init();

	/* 初始化系统时钟和SysTick */
    SystemClock_Config();
	SysTick_Config(SystemCoreClock / RT_TICK_PER_SECOND);

	/* 硬件 BSP 初始化统统放在这里，比如 LED，串口，LCD 等 */
#ifdef RT_USING_LED
	led_init();
#endif

#ifdef RT_USING_SERIAL
    stm32_hw_usart_init();
#endif
	
	
    /* Call components board initial (use INIT_BOARD_EXPORT()) */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
    
#if defined(RT_USING_CONSOLE) && defined(RT_USING_DEVICE)
	rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif
    
#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif
}

