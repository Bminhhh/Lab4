/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define RED1_Pin GPIO_PIN_1
#define RED1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_2
#define RED2_GPIO_Port GPIOA
#define PURPLE1_Pin GPIO_PIN_5
#define PURPLE1_GPIO_Port GPIOA
#define PURPLE2_Pin GPIO_PIN_6
#define PURPLE2_GPIO_Port GPIOA
#define PB4_Pin GPIO_PIN_10
#define PB4_GPIO_Port GPIOB
#define PB5_Pin GPIO_PIN_11
#define PB5_GPIO_Port GPIOB
#define PB6_Pin GPIO_PIN_12
#define PB6_GPIO_Port GPIOB
#define SELECT_Pin GPIO_PIN_13
#define SELECT_GPIO_Port GPIOB
#define MODIFY_Pin GPIO_PIN_14
#define MODIFY_GPIO_Port GPIOB
#define SET_Pin GPIO_PIN_15
#define SET_GPIO_Port GPIOB
#define GREEN1_Pin GPIO_PIN_9
#define GREEN1_GPIO_Port GPIOA
#define GREEN2_Pin GPIO_PIN_10
#define GREEN2_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_12
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_13
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_14
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_15
#define EN3_GPIO_Port GPIOA
#define PB0_Pin GPIO_PIN_6
#define PB0_GPIO_Port GPIOB
#define PB1_Pin GPIO_PIN_7
#define PB1_GPIO_Port GPIOB
#define PB2_Pin GPIO_PIN_8
#define PB2_GPIO_Port GPIOB
#define PB3_Pin GPIO_PIN_9
#define PB3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
