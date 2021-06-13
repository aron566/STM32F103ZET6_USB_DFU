/**                                                                             
 *  @file fal_cfg.h                                                    
 *                                                                              
 *  @date 2021年06月11日 00:05:25 星期五
 *                                                                              
 *  @author Copyright (c) 2021 aron566 <aron566@163.com>.                       
 *                                                                              
 *  @brief None.                                                                
 *                                                                              
 *  @version V1.0                                                               
 */                                                                             
#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_                                                         
/** Includes -----------------------------------------------------------------*/
#include <stdint.h> /**< need definition of uint8_t */                          
#include <stddef.h> /**< need definition of NULL    */                          
#include <stdbool.h>/**< need definition of BOOL    */                        
#include <stdio.h>  /**< if need printf             */                          
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <limits.h> /**< need variable max value    */                          
/** Private includes ---------------------------------------------------------*/
                                                                                
/** Use C compiler -----------------------------------------------------------*/
#ifdef __cplusplus ///< use C compiler                                          
extern "C" {                                                                  
#endif                                                                          
/** Private defines ----------------------------------------------------------*/
                                                                      
/** Exported typedefines -----------------------------------------------------*/
                                                                       
/** Exported constants -------------------------------------------------------*/
                                                                                
/** Exported macros-----------------------------------------------------------*/
#define FAL_PART_HAS_TABLE_CFG

#define NOR_FLASH_DEV_NAME             "nor_flash0"
#define FAL_PART_TABLE_FLASH_DEV_NAME  NOR_FLASH_DEV_NAME
#define FAL_USING_NOR_FLASH_DEV_NAME   "nor_flash0"
#define FAL_PART_TABLE_END_OFFSET      (16*1024*1024L)
/* ===================== Flash device Configuration ========================= */
extern const struct fal_flash_dev stm32f1_onchip_flash;
extern struct fal_flash_dev nor_flash0;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &stm32f1_onchip_flash,                                           \
    &nor_flash0,                                                     \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG
/* partition table */
#define FAL_PART_TABLE                                                               \
{                                                                                    \
    {FAL_PART_MAGIC_WORD,   "bl",         "stm32_onchip",          0,  128*1024, 0}, \
    {FAL_PART_MAGIC_WORD,   "app",        "stm32_onchip",   128*1024,  128*1024, 0}, \
    {FAL_PART_MAGIC_WORD,   "download",   "stm32_onchip",   128*1024*2,  128*1024, 0}, \
    {FAL_PART_MAGIC_WORD,   "factory",    "stm32_onchip",   128*1024*3,  128*1024, 0}, \
    {FAL_PART_MAGIC_WORD,   "flag",       NOR_FLASH_DEV_NAME,       0, 1024*1024, 0}, \
    {FAL_PART_MAGIC_WORD,   "kv",         NOR_FLASH_DEV_NAME, 1024*1024, 15*1024*1024, 0}, \
}
#endif /* FAL_PART_HAS_TABLE_CFG */

/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/
                                                                                
#ifdef __cplusplus ///<end extern c                                             
}                                                                               
#endif                                                                          
#endif                                                                          
/******************************** End of file *********************************/
