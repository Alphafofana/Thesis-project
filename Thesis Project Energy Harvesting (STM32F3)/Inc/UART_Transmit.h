/**
******************************************************************************
* @brief Headerfile for UART_Transmit.c. This file contains all includes,
* defines and function prototypes for UART_Transmit.
* @file UART_Transmit.h
* @author(s)
* @version 1.3
* @date 27-May-2019
******************************************************************************
*/

/* Defines to prevent recursive inclusion -------------------------------------*/
#ifndef __UART_TRANSMITT_H
#define __UART_TRANSMITT_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Defines ------------------------------------------------------------------*/

#define Transmission_Buffer_Size 22

//* Function prototypes -----------------------------------------------*/
void MX_USART3_UART_Init();
void UART_Transmit(float Data);
void UART_TransmitIT(float Data);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle);
void Error_Handler(void);



#endif /* __UART_TRANSMITT_H */
