//#include "Uart_Variable_Length.h"

//uint8_t rx_buff[RX_BUFF_SIZE] = {0};

///**
//  * @brief   启动串口DMA接收与使能IDLE中断函数
//  * @note    由用户在main函数调用
//  * @param   *huart：串口句柄
//  * @param   无
//  * @param   无
//  * @retval  无 
//  */
//void Enable_IDLE_Receive_DMA(UART_HandleTypeDef *huart)
//{
//	HAL_UART_Receive_DMA(huart, (uint8_t *)rx_buff, sizeof(rx_buff));  //开启串口DMA接收
//	__HAL_UART_ENABLE_IT(huart, UART_IT_IDLE);  //使能指定的串口中断(IDLE中断)
//}

///**
//  * @brief   处理空闲中断
//  * @note    由用户在stm32f1xx_it.c文件的串口中断函数调用
//  * @param   *huart：串口句柄
//  * @param   无
//  * @param   无
//  * @retval  无 
//  */
//void Idle_Interrupt_Process(UART_HandleTypeDef *huart)
//{
//	if(__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) != RESET){  //也就是触发了空闲中断
//		uint32_t num = 0;
//		
//		num = huart1.Instance->SR;
//		num = huart1.Instance->DR;
//		num = num;  /*<这三句代码是清除空闲中断标志位的>*/		
//		//__HAL_UART_CLEAR_IDLEFLAG(&huart1);  这个代码与上面三句代码功能相同
//		
//		HAL_UART_DMAStop(huart);  /*<停止DMA>*/				
//		HAL_UART_RxCpltCallback(huart);  /*<处理接收到的数据的回调函数，该函数也可以是用户自定义函数>*/		
//	}
//}

///**
//  * @brief   处理接收到的数据的回调函数，该函数也可以使用用户自定义函数
//  * @note    该函数不需要调用
//  * @param   *huart：串口句柄
//  * @param   无
//  * @param   无
//  * @retval  无 
//  */
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//  UNUSED(huart); /*<避免gcc/g++警告>*/
//	
//  uint16_t len = 0;
//	
//  if(huart->Instance == USART1){
//    len = huart->RxXferSize - huart->hdmarx->Instance->CNDTR;    /*<len = 串口DMA接收长度 - DMA剩余的待传输字节数目>*/
//    //len = sizeof(rx_buff) -  __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);  这句代码与上局代码功能一致  			
//    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)rx_buff, len);	   /*<用户串口数据处理地方>*/			
//    HAL_UART_Receive_DMA(&huart1, (uint8_t *)rx_buff, sizeof(rx_buff));  /*<重新启动串口DMA接收>*/
//  }
//}