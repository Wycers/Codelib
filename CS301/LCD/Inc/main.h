/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY0_Pin GPIO_PIN_5
#define KEY0_GPIO_Port GPIOC
#define KEY0_EXTI_IRQn EXTI9_5_IRQn
#define KEY1_Pin GPIO_PIN_15
#define KEY1_GPIO_Port GPIOA

#define LCD_LED_Pin GPIO_PIN_10
#define LCD_LED_GPIO_Port GPIOC

#define LCD_CS_Pin GPIO_PIN_9
#define LCD_CS_GPIO_Port GPIOC

#define RS_Pin GPIO_PIN_8
#define RS_GPIO_Port GPIOC

#define WR_Pin GPIO_PIN_7
#define WR_GPIO_Port GPIOC

#define RD_Pin GPIO_PIN_6
#define RD_GPIO_Port GPIOC

#define D1_Pin GPIO_PIN_0
#define D1_GPIO_Port GPIOB
#define D2_Pin GPIO_PIN_1
#define D2_GPIO_Port GPIOB
#define D3_Pin GPIO_PIN_2
#define D3_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_3
#define D4_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_4
#define D5_GPIO_Port GPIOB
#define D6_Pin GPIO_PIN_5
#define D6_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_6
#define D7_GPIO_Port GPIOB
#define D8_Pin GPIO_PIN_7
#define D8_GPIO_Port GPIOB
#define D9_Pin GPIO_PIN_8
#define D9_GPIO_Port GPIOB
#define D10_Pin GPIO_PIN_9
#define D10GPIO_Port GPIOB
#define D11_Pin GPIO_PIN_10
#define D11GPIO_Port GPIOB
#define D12_Pin GPIO_PIN_11
#define D12GPIO_Port GPIOB
#define D13_Pin GPIO_PIN_12
#define D13GPIO_Port GPIOB
#define D14_Pin GPIO_PIN_13
#define D14GPIO_Port GPIOB
#define D15_Pin GPIO_PIN_14
#define D15GPIO_Port GPIOB
#define D16_Pin GPIO_PIN_15
#define D16GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
