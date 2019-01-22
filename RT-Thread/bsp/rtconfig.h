#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

/* RT-Thread内核部分 */
#define RT_NAME_MAX 8					//内核对象名称最大长度，大于该长度的名称多余部分会被自动裁掉
#define RT_ALIGN_SIZE 4					//字节对齐时设定对齐的字节个数。常使用ALIGN(RT_ALIGN_SIZE)进行字节对齐
#define RT_THREAD_PRIORITY_MAX 32		//定义系统线程优先级数；通常用RT_THREAD_PRIORITY_MAX-1定义空闲线程的优先级
#define RT_TICK_PER_SECOND 1000			//定义时钟节拍，为1000时表示1000个tick每 秒，一个tick为1ms
#define RT_USING_OVERFLOW_CHECK			//检查栈是否溢出，未定义则关闭
#define RT_DEBUG						//定义该宏开启debug模式，未定义则关闭
#define RT_DEBUG_INIT 0					//开启debug模式时：该宏定义为0时表示关闭打印组件初始化信息，定义为1时表示启用
#define RT_DEBUG_THREAD 0				//开启debug模式时：该宏定义为0时表示关闭打印线程切换信息，定义为1时表示启用
#define RT_USING_HOOK					//定义该宏表示开启钩子函数的使用，未定义则关闭
#define IDLE_THREAD_STACK_SIZE 256		//定义了空闲线程的栈大小

/* 
线程间同步与通信部分，
该部分会使用到的对象有信号量、
互斥量、事件、邮箱、消息队列、信号等 
*/
#define RT_USING_SEMAPHORE				//定义该宏可开启信号量的使用，未定义则关闭
#define RT_USING_MUTEX					//定义该宏可开启互斥量的使用，未定义则关闭
#define RT_USING_EVENT					//定义该宏可开启事件集的使用，未定义则关闭
#define RT_USING_MAILBOX				//定义该宏可开启邮箱的使用，未定义则关闭
#define RT_USING_MESSAGEQUEUE			//定义该宏可开启消息队列的使用，未定义则关闭
#define RT_USING_SIGNALS				//定义该宏可开启信号的使用，未定义则关 闭

/* 内存管理部分 */
#define RT_USING_MEMPOOL				//定义该宏可开启静态内存池的使用，未定义则关闭
#define RT_USING_MEMHEAP				//定义该宏可开启两个或以上内存堆拼接的使用，未定义则关闭
#define RT_USING_SMALL_MEM				//定义该宏可开启开启小内存管理算法，未定义则关闭
//#define RT_USING_SLAB					//定义该宏可开启SLAB内存管理算法，未定义则关闭
#define RT_USING_HEAP					//定义该宏可开启堆的使用，未定义则关闭

/* 内核设备对象 */
#define RT_USING_DEVICE					//表示开启了系统设备的使用，使用设备驱动
#define RT_USING_CONSOLE				//定义该宏可开启系统控制台设备的使用，未定义则关闭
#define RT_CONSOLEBUF_SIZE 128			//定义控制台设备的缓冲区大小
#define RT_CONSOLE_DEVICE_NAME "uart1"	//控制台设备的名称

/* 自动初始化方式 */
#define RT_USING_COMPONENTS_INIT		//定义该宏开启自动初始化机制，未定义则关闭
#define RT_USING_USER_MAIN				//定义该宏  启设置应用入口为main函数
#define RT_MAIN_THREAD_STACK_SIZE 2048	//定义main线程的栈大小

/* FinSH */
#define RT_USING_FINSH					//定义该宏可开启系统FinSH调试工具的使用，未定义则关闭
#ifdef RT_USING_FINSH
#define FINSH_THREAD_NAME "tshell"		//开启系统FinSH时：将该线程名称定义为tshell
#define FINSH_USING_HISTORY				//开启系统FinSH时：使用历史命令
#define FINSH_HISTORY_LINES 5			//开启系统FinSH时：对历史命令行数的定义
#define FINSH_USING_SYMTAB				//开启系统FinSH时：定义该宏开启使用Tab键，未定义则关闭
#define FINSH_THREAD_PRIORITY 20		//开启系统FinSH时：定义该线程的优先级
#define FINSH_THREAD_STACK_SIZE 4096	//开启系统FinSH时：定义该线程的栈大小
#define FINSH_CMD_SIZE 80				//开启系统FinSH时：定义命令字符长度
#define FINSH_USING_MSH					//开启系统FinSH时：定义该宏开启MSH功能
#define FINSH_USING_MSH_DEFAULT			//开启系统FinSH时：开启MSH功能时，定义该宏默认使用MSH功能
#define FINSH_USING_MSH_ONLY			//开启系统FinSH时：定义该宏，仅使用MSH功能
#endif

/* 关于 MCU */
#define STM32L475VE						//定义该工程使用的MCU为STM32L475VE
#define RT_HSE_VALUE 8000000			//定义时钟源频率
#define RT_USING_LED					//定义该宏开启LED的使用
#define RT_USING_SERIAL					//定义该宏开启串口的使用
#define BSP_USING_UART1					//定义该宏开启UART1的使用


#endif/* __RTTHREAD_CFG_H__ */
