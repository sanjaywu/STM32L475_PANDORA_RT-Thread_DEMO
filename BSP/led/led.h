#ifndef __LED_H__
#define __LED_H__

#include "data_typedef.h"


/* RGB灯接口定义 */
#define LED_R(n)	(n ? HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET))
#define LED_G(n)	(n ? HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET))
#define LED_B(n)	(n ? HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET))
#define LED_OFF		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9, GPIO_PIN_SET)

void led_init(void);





#endif




