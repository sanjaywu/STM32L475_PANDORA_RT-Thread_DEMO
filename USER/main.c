#include "main.h"
#include "board.h"
#include "rtthread.h"
#include "data_typedef.h"
#include "delay.h"
#include "led.h"

void led_start(void);

int main(void)
{	
	u32 count = 1;
	
	while(count > 0)
	{
		LED_R(0);
		//rt_kprintf("led on, count: %d\r\n", count);
		rt_thread_mdelay(500);
		LED_R(1);
		rt_thread_mdelay(500);
		//rt_kprintf("led off\r\n");
		count++;
	}

	return 0;
}


void led_thread_entry(void *parameter)
{
	u32 count = 1;
	
	while(count > 0)
	{
		LED_R(0);
		//rt_kprintf("led on, count: %d\r\n", count);
		rt_thread_mdelay(500);
		LED_R(1);
		rt_thread_mdelay(500);
		//rt_kprintf("led off\r\n");
		count++;
	}
}

void led_start(void)
{
	rt_thread_t led_thread = RT_NULL;;

    /* 创建LED线程 */
    led_thread = rt_thread_create("led",
                                    led_thread_entry,
                                    RT_NULL,
                                    1024, 
                                    RT_THREAD_PRIORITY_MAX / 2 - 4, 
                                    50);
	/* 创建LED线程成功，则启动线程 */
    if(led_thread != RT_NULL)
    {
        rt_thread_startup(led_thread);
    }
}





















