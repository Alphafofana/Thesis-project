/**
******************************************************************************
* @brief This file contains functions for handling the communication Through
*  UART/USART.
* @file UART_Transmit.c
* @author(s)
* @version 1.3
* @date 27-May-2019
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "UART_Transmit.h"

/* Private variables ---------------------------------------------------------*/
/* UART handler */ 
UART_HandleTypeDef huart3;
/* Transmission flag status for transmission through interrupt*/ 
ITStatus UartReady = RESET;
/* Size of Transmission buffer */ 
 char Buffer[Transmission_Buffer_Size];

 /**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART3_UART_Init()
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 9600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}
/**
* @brief Function to transmit to bluetooth.
* @param DataBitstream_TypeDef
* @return void
*/
void UART_Transmit(float Data)
{
  HAL_UART_Transmit(&huart3, (uint8_t*)Buffer, sprintf(Buffer, "%f,\n\r", Data), 5000);
}

/**
* @brief Function to transmit to bluetooth.
* @param DataBitstream_TypeDef
* @return void
*/
void UART_UART_TransmitIT(float Data)
{
  /* Start the transmission process */
  if(HAL_UART_Transmit_IT(&huart3, (uint8_t *)Buffer, sprintf(Buffer, "%f,\n\r", Data))!= HAL_OK)
  {
    Error_Handler();
  }
  /* Wait for the end of the transfer */
  while (UartReady != SET)
  {
  }
  /* Reset transmission flag */ 
  UartReady = RESET;
}
/* USER CODE BEGIN 4 */
/**
* @brief Tx Transfer completed callback
* @param UartHandle: UART handle.
* @note This example shows a simple way to report end of IT Tx transfer, and
* you can add your own implementation.
* @retval None
*/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  /* Set transmission flag: transfer complete*/ 
  UartReady = SET;
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @param DataBitstream_TypeDef
  * @return void
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
