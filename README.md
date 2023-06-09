# STM32-Serial-Variable-Length-Send-and-Receive
该仓库仅上传串口不定长收发模块

# 使用教程
1. main.c
#include "Debug.h"
#include "Uart_Variable_Length.h"

int main(void)
{
  Enable_IDLE_Receive_DMA(&huart1);
  while (1)
  {		
    HAL_Delay(1);  
  }
}
2. stm32f1xx_it.c
#include "Uart_Variable_Length.h"

void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart1);	
  /*<处理空闲中断>*/
  Idle_Interrupt_Process(&huart1);
}
