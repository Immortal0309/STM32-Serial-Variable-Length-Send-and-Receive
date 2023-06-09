//#include "Uart_Variable_Length.h"

//uint8_t rx_buff[RX_BUFF_SIZE] = {0};

///**
//  * @brief   ��������DMA������ʹ��IDLE�жϺ���
//  * @note    ���û���main��������
//  * @param   *huart�����ھ��
//  * @param   ��
//  * @param   ��
//  * @retval  �� 
//  */
//void Enable_IDLE_Receive_DMA(UART_HandleTypeDef *huart)
//{
//	HAL_UART_Receive_DMA(huart, (uint8_t *)rx_buff, sizeof(rx_buff));  //��������DMA����
//	__HAL_UART_ENABLE_IT(huart, UART_IT_IDLE);  //ʹ��ָ���Ĵ����ж�(IDLE�ж�)
//}

///**
//  * @brief   ��������ж�
//  * @note    ���û���stm32f1xx_it.c�ļ��Ĵ����жϺ�������
//  * @param   *huart�����ھ��
//  * @param   ��
//  * @param   ��
//  * @retval  �� 
//  */
//void Idle_Interrupt_Process(UART_HandleTypeDef *huart)
//{
//	if(__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) != RESET){  //Ҳ���Ǵ����˿����ж�
//		uint32_t num = 0;
//		
//		num = huart1.Instance->SR;
//		num = huart1.Instance->DR;
//		num = num;  /*<�������������������жϱ�־λ��>*/		
//		//__HAL_UART_CLEAR_IDLEFLAG(&huart1);  �������������������빦����ͬ
//		
//		HAL_UART_DMAStop(huart);  /*<ֹͣDMA>*/				
//		HAL_UART_RxCpltCallback(huart);  /*<������յ������ݵĻص��������ú���Ҳ�������û��Զ��庯��>*/		
//	}
//}

///**
//  * @brief   ������յ������ݵĻص��������ú���Ҳ����ʹ���û��Զ��庯��
//  * @note    �ú�������Ҫ����
//  * @param   *huart�����ھ��
//  * @param   ��
//  * @param   ��
//  * @retval  �� 
//  */
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//  UNUSED(huart); /*<����gcc/g++����>*/
//	
//  uint16_t len = 0;
//	
//  if(huart->Instance == USART1){
//    len = huart->RxXferSize - huart->hdmarx->Instance->CNDTR;    /*<len = ����DMA���ճ��� - DMAʣ��Ĵ������ֽ���Ŀ>*/
//    //len = sizeof(rx_buff) -  __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);  ���������Ͼִ��빦��һ��  			
//    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)rx_buff, len);	   /*<�û��������ݴ���ط�>*/			
//    HAL_UART_Receive_DMA(&huart1, (uint8_t *)rx_buff, sizeof(rx_buff));  /*<������������DMA����>*/
//  }
//}