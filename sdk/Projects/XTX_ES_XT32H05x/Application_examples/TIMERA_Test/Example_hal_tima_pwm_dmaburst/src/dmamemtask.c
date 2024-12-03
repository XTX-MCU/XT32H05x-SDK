/**
  ******************************************************************************
  * @file    dmamemtask.c
  * @author  Software Team
  * @brief   
  *          
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dmamemtask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup DMA_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @addtogroup DMA_Task_Private_Variables 
  * @{
  */
DMA_HandleTypeDef hTimaDmarx;
DMA_HandleTypeDef hTimaDmatx;
/**
  * @}
  */

/** @addtogroup DMA_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void XT_DMAMEM1_Init(void );
static void XT_DMAMEM2_Init(void );

/* Private user code ---------------------------------------------------------*/
/**
 * @brief  DMAPeriphTx Initialization Function
 */
static void XT_DMAPeriphTIMA_Init(void)
{
    hTimaDmatx.Instance       = DMA1_Channel2;
    hTimaDmatx.ChannelIndex   = 2;
    hTimaDmatx.Init.Direction = DMA_MEMORY_TO_PERIPH_FC_DMAC;
    hTimaDmatx.Init.SrcInc    = DMA_SINC_INCREMENT;
    hTimaDmatx.Init.DstInc    = DMA_DINC_NOCHANGE;
    hTimaDmatx.Init.SrcDataSize  = DMA_SDATAALIGN_WORD;
    hTimaDmatx.Init.DstDataSize  = DMA_DDATAALIGN_WORD;
    hTimaDmatx.Init.SrcBurstSize = DMA_SRC_MSIZE_4;
    hTimaDmatx.Init.DstBurstSize = DMA_DST_MSIZE_4;
    hTimaDmatx.Init.Mode = DMA_SGLBLK;
    hTimaDmatx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hTimaDmatx) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handler();
    }
	  
	  hTimaDmarx.Instance       = DMA1_Channel3;
    hTimaDmarx.ChannelIndex   = 3;
    hTimaDmarx.Init.Direction = DMA_PERIPH_TO_MEMORY_FC_DMAC;
    hTimaDmarx.Init.SrcInc    = DMA_SINC_NOCHANGE;
    hTimaDmarx.Init.DstInc    = DMA_DINC_INCREMENT;
	  
    hTimaDmarx.Init.SrcDataSize  = DMA_SDATAALIGN_WORD;
    hTimaDmarx.Init.DstDataSize  = DMA_DDATAALIGN_WORD;
    hTimaDmarx.Init.SrcBurstSize = DMA_SRC_MSIZE_4;
    hTimaDmarx.Init.DstBurstSize = DMA_DST_MSIZE_4;
    hTimaDmarx.Init.Mode = DMA_SGLBLK;
    hTimaDmarx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hTimaDmarx) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handler();
    }
}


/**
  * @}
  */

/** @addtogroup DMA_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_Dmamem_Init(void)
{
    XT_DMAPeriphTIMA_Init();
}

/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_Dmamem_Task(void)
{
  /* USER CODE */
}

void XT_TIMx_DMA_readcfg(TIM_HandleTypeDef *htim, uint16_t timchid)
{
	/* DMA request*/			
	/* HW handshaking */
	uint32_t hwifch, hwifcfg;
	switch(timchid)
	{
		case TIM_DMA_ID_CC1:
			if(htim->Instance ==TIM1)	
			{
				hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC1;		            
			  hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC1;			
			}
			else if(htim->Instance ==TIM2)				
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC1;		    hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC1;	}
			else if(htim->Instance ==TIMG1)				
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC1;		    hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC1;			}                                                       
			else if(htim->Instance ==TIMG2)				            
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC1;		    hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC1;			}                                                       
			else if(htim->Instance ==TIMG3)				            
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC1;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC1;	}                                                       
			else if(htim->Instance ==TIMG4)				            
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC1;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC1;	}
		
			break;
			
		case 	TIM_DMA_ID_CC2:	
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC2;	}
			else if(htim->Instance ==TIM2)				
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC2;	}
			else if(htim->Instance ==TIMG1)				
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC2;			}                                                       
			else if(htim->Instance ==TIMG2)				            
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC2;			}                                                       
			else if(htim->Instance ==TIMG3)				            
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC2;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC2;		}                                                       
			else if(htim->Instance ==TIMG4)				            
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC2;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC2;		}	
			break;
			
		case TIM_DMA_ID_CC3:			
			/* DMA request*/			
			/* HW handshaking */
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC3;		     hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC3;		}
			else if(htim->Instance ==TIM2)				                                                              
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC2;		     hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC3;		}
			else if(htim->Instance ==TIMG1)				                                                              
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC2;		     hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC3;		}                                                       
			else if(htim->Instance ==TIMG2)				                                                              
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC2;		     hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC3;		}                                                       
			else if(htim->Instance ==TIMG3)				                                                              
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC2;		   hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC3;		}                                                       
			else if(htim->Instance ==TIMG4)				                          
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC2;		   hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC3;		}
			break;
			
		case TIM_DMA_ID_CC4:	  
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC4;		    hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC4;			}
			else if(htim->Instance ==TIM2)				
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC4;		    hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC4;			}
			else if(htim->Instance ==TIMG1)				
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC4;			}                                                       
			else if(htim->Instance ==TIMG2)				                                                          
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC4;			}                                                       
			else if(htim->Instance ==TIMG3)				                                                          
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC2;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC4;		}                                                       
			else if(htim->Instance ==TIMG4)				                         
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC2;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC4;		}					
			break;	
			
		case TIM_DMA_ID_UPDATE:
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_UDT;		    hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_UDT;			}
			else if(htim->Instance ==TIM2)				
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_UDT;		    hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_UDT;			}
			else if(htim->Instance ==TIMG1)				                                                      
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_UDT;		    hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_UDT;			}                                                       
			else if(htim->Instance ==TIMG2)				                                                        
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_UDT;		    hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_UDT;			}                                                       
			else if(htim->Instance ==TIMG3)				                                                          
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_UDT;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_UDT;		}                                                       
			else if(htim->Instance ==TIMG4)				                                                      
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_UDT;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_UDT;		}
			 
			break;
			
		case TIM_DMA_ID_COMMUTATION:
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_TRG;	      hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_TRG;		}
			else if(htim->Instance ==TIM2)			                  
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_TRG;	      hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_TRG;		}
			else if(htim->Instance ==TIMG1)			                                                      
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_TRG;			  hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_TRG;		}                                                       
			else if(htim->Instance ==TIMG2)			                                                    
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_TRG;			  hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_TRG;		}                                                       
			else if(htim->Instance ==TIMG3)			                                                              
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_TRG;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_TRG;	}                                                       
			else if(htim->Instance ==TIMG4)			                                                        
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_TRG;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_TRG;	}		 
			break;
			
		default:
			break;
	}
 
		LL_DMA_SetHWHSIFSelectByIndex(hwifch,		(hwifcfg & 0x3));
#if defined(XT32H0xxB)    
		SYSCFG->DMA_CFG_2 &= ~(3UL << (hwifch<<1));   
		SYSCFG->DMA_CFG_2 |= (((hwifcfg & 0xC) >>2) << (hwifch<<1));
#endif /* XT32H0xxB */
		__HAL_LINKDMA(htim,hdma[timchid], hTimaDmarx);
			/* HW handshaking */
		__HAL_DMA_CONFIG_SRCHS(htim->hdma[timchid], DMA_SRCHS_POL_HIGH|DMA_SRCHS_HW, (hwifch << DMA_CH_CHCFG_SRCPER_Pos)); 

	return;
}


void XT_TIMx_DMA_writecfg(TIM_HandleTypeDef *htim, uint16_t timchid)
{
	/* DMA request*/			
	/* HW handshaking */
	uint32_t hwifch, hwifcfg;
	switch(timchid)
	{
		case TIM_DMA_ID_CC1:
			if(htim->Instance ==TIM1)	
			{
				hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC1;		            
			  hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC1;			
			}
			else if(htim->Instance ==TIM2)				
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC1;		    hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC1;	}
			else if(htim->Instance ==TIMG1)				
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC1;		    hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC1;			}                                                       
			else if(htim->Instance ==TIMG2)				            
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC1;		    hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC1;			}                                                       
			else if(htim->Instance ==TIMG3)				            
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC1;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC1;	}                                                       
			else if(htim->Instance ==TIMG4)				            
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC1;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC1;	}
		
			break;
			
		case 	TIM_DMA_ID_CC2:	
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC2;	}
			else if(htim->Instance ==TIM2)				
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC2;	}
			else if(htim->Instance ==TIMG1)				
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC2;			}                                                       
			else if(htim->Instance ==TIMG2)				            
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC2;			}                                                       
			else if(htim->Instance ==TIMG3)				            
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC2;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC2;		}                                                       
			else if(htim->Instance ==TIMG4)				            
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC2;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC2;		}	
			break;
			
		case TIM_DMA_ID_CC3:			
			/* DMA request*/			
			/* HW handshaking */
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC3;		     hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC3;		}
			else if(htim->Instance ==TIM2)				                                                              
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC2;		     hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC3;		}
			else if(htim->Instance ==TIMG1)				                                                              
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC2;		     hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC3;		}                                                       
			else if(htim->Instance ==TIMG2)				                                                              
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC2;		     hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC3;		}                                                       
			else if(htim->Instance ==TIMG3)				                                                              
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC2;		   hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC3;		}                                                       
			else if(htim->Instance ==TIMG4)				                          
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC2;		   hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC3;		}
			break;
			
		case TIM_DMA_ID_CC4:	  
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC4;		    hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC4;			}
			else if(htim->Instance ==TIM2)				
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC4;		    hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC4;			}
			else if(htim->Instance ==TIMG1)				
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC4;			}                                                       
			else if(htim->Instance ==TIMG2)				                                                          
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC2;		    hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC4;			}                                                       
			else if(htim->Instance ==TIMG3)				                                                          
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC2;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC4;		}                                                       
			else if(htim->Instance ==TIMG4)				                         
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC2;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC4;		}					
			break;	
			
		case TIM_DMA_ID_UPDATE:
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_UDT;		    hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_UDT;			}
			else if(htim->Instance ==TIM2)				
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_UDT;		    hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_UDT;			}
			else if(htim->Instance ==TIMG1)				                                                      
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_UDT;		    hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_UDT;			}                                                       
			else if(htim->Instance ==TIMG2)				                                                        
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_UDT;		    hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_UDT;			}                                                       
			else if(htim->Instance ==TIMG3)				                                                          
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_UDT;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_UDT;		}                                                       
			else if(htim->Instance ==TIMG4)				                                                      
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_UDT;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_UDT;		}
			 
			break;
			
		case TIM_DMA_ID_COMMUTATION:
			if(htim->Instance ==TIM1)	
			{	hwifch = LL_DMA_SHIF_CFG_2_INDEX_TIMA1_TRG;	      hwifcfg =  LL_DMA_SHIF_CFG_2_CFG_TIMA1_TRG;		}
			else if(htim->Instance ==TIM2)			                  
			{	hwifch = LL_DMA_SHIF_CFG_4_INDEX_TIMA2_TRG;	      hwifcfg =  LL_DMA_SHIF_CFG_4_CFG_TIMA2_TRG;		}
			else if(htim->Instance ==TIMG1)			                                                      
			{	hwifch = LL_DMA_SHIF_CFG_3_INDEX_TIMG1_TRG;			  hwifcfg =  LL_DMA_SHIF_CFG_3_CFG_TIMG1_TRG;		}                                                       
			else if(htim->Instance ==TIMG2)			                                                    
			{	hwifch = LL_DMA_SHIF_CFG_8_INDEX_TIMG2_TRG;			  hwifcfg =  LL_DMA_SHIF_CFG_8_CFG_TIMG2_TRG;		}                                                       
			else if(htim->Instance ==TIMG3)			                                                              
			{	hwifch = LL_DMA_SHIF_CFG_12_INDEX_TIMG3_TRG;		  hwifcfg =  LL_DMA_SHIF_CFG_12_CFG_TIMG3_TRG;	}                                                       
			else if(htim->Instance ==TIMG4)			                                                        
			{	hwifch = LL_DMA_SHIF_CFG_13_INDEX_TIMG4_TRG;		  hwifcfg =  LL_DMA_SHIF_CFG_13_CFG_TIMG4_TRG;	}		 
			break;
			
		default:
			break;
	}
 
		LL_DMA_SetHWHSIFSelectByIndex(hwifch,		(hwifcfg & 0x3));
#if defined(XT32H0xxB)    
		SYSCFG->DMA_CFG_2 &= ~(3UL << (hwifch<<1));   
		SYSCFG->DMA_CFG_2 |= (((hwifcfg & 0xC) >>2) << (hwifch<<1));
#endif /* XT32H0xxB */
		__HAL_LINKDMA(htim,hdma[timchid], hTimaDmatx);
		/* HW handshaking */
		__HAL_DMA_CONFIG_DSTHS(htim->hdma[timchid], DMA_DSTHS_POL_HIGH|DMA_DSTHS_HW, (hwifch << DMA_CH_CHCFG_DSTPER_Pos)); 

	return;
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
