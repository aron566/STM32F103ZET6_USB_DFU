/**
 *  @file User_Main.c
 *
 *  @date 2021-01-11
 *
 *  @author aron566
 *
 *  @copyright Copyright (c) 2021 aron566 <aron566@163.com>.
 *
 *  @brief 主线任务
 *
 *  @details 1、
 *
 *  @version V1.0
 */
#ifdef __cplusplus ///<use C compiler
extern "C" {
#endif
/** Includes -----------------------------------------------------------------*/
/* Private includes ----------------------------------------------------------*/
#include "User_Main.h"
#include "main.h"
/** Private typedef ----------------------------------------------------------*/
/** Private macros -----------------------------------------------------------*/                                                          
/** Private constants --------------------------------------------------------*/
/** Public variables ---------------------------------------------------------*/
/** Private variables --------------------------------------------------------*/

/** Private function prototypes ----------------------------------------------*/

/** Private user code --------------------------------------------------------*/

/** Private application code -------------------------------------------------*/
/*******************************************************************************
*
*       Static code
*
********************************************************************************
*/

/** Public application code --------------------------------------------------*/
/*******************************************************************************
*
*       Public code
*
********************************************************************************
*/

/**
  ******************************************************************
  * @brief   任务处理循环
  * @param   [in]None
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-02-25
  ******************************************************************
  */
void User_Main_Task_Process_Loop(void)
{
  for(;;)
  {  
    /*定时器模块启动*/
    Timer_Port_Start();
  }
  /*never return*/
}

/**
  ******************************************************************
  * @brief   初始化各模块功能
  * @param   [in]None
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-02-25
  ******************************************************************
  */
void User_Main_Task_Init(void)
{
  printf("*******\r\nDFU_APP:V2.0.\r\n*******\r\n");
  /*串口操作初始化*/
  Uart_Port_Init();

  /*Flash接口初始化*/
  Flash_Port_Init();

  /*定时器初始化*/
  Timer_Port_Init();
  
  /*other initialization task code*/
}

/**
  ******************************************************************
  * @brief   中断向量表迁移
  * @param   [in]None
  * @return  None.
  * @author  aron566
  * @version V1.0
  * @date    2021-02-25
  ******************************************************************
  */
void User_InterruptVectorTable_Move(void)
{
  SCB->VTOR = (0x08000000+(128*1024));
}

#ifdef __cplusplus ///<end extern c
}
#endif
/******************************** End of file *********************************/