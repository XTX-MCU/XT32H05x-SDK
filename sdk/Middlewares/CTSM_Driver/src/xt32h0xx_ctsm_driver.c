/**
  ******************************************************************************
  * @file    xt32t0xx_evb_ts.c
  * @author  Software Team
  * @brief   This file provides set of firmware functions to manage:
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */ 
  
/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"
/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup XT32T0XX_EVB
  * @{
  */   

/** @addtogroup XT32T0XX_EVB_TS
  * @{
  */   

/** @defgroup XT32H0XX_EVB_Private_Defines Private Defines
  * @{
  */ 
#define TOUCH_OFF_VALUE                       (0xFFFF)	
	
#define TOUCH_SLIDER_ELEMENTS_MIN             (3)
#define TOUCH_SLIDER_ELEMENTS_MAX             (10)
#define TOUCH_WHEEL_ELEMENTS_SMALL            (4)
#define TOUCH_WHEEL_ELEMENTS_LARGE            (8)
#define TOUCH_SLIDER_RESOLUTION               (100)
#define TOUCH_WHEEL_RESOLUTION                (360)
#define TOUCH_DECIMAL_POINT_PRECISION         (100)

#define BSP_SLIDER_NUM                        (1) 
#define BSP_WHEELR_NUM                        (1) 
/**
  * @}
  */ 

/** @defgroup XT32H0XX_EVB_Private_Variables Private Variables
  * @{
  */ 
uint16_t raw_data[TOUCH_SLIDER_ELEMENTS_MAX] = {0};

uint16_t slider_data[TOUCH_SLIDER_ELEMENTS_MAX];
uint16_t slider_position;

uint16_t wheel_data[TOUCH_WHEEL_ELEMENTS_LARGE];
uint16_t wheel_position;

const uint16_t slider_element_num = 5;
const uint16_t slider_threshold = 800;

const uint16_t wheel_element_num = 4;
const uint16_t wheel_threshold = 800;
/**
  * @}
  */ 

/** @defgroup XT32H0XX_EVB_Private_Functions Private Functions
  * @{
  */ 
static void touch_slider_decode(uint16_t * p_sinfo,
                                uint16_t            * slider_data,
                                uint8_t               num_elements);

static void touch_wheel_decode(uint16_t * p_winfo,
                               uint16_t           * wheel_data,
                               uint8_t              num_elements);

/**
  * @}
  */ 

/** @defgroup XT32H0XX_EVB_Exported_Functions Exported Functions
  * @{
  */ 

/**
  * @brief  Initialize TS.
  * @param  None
  * @retval None
  */
void             BSP_TS_Init(void)
{}

/**
  * @brief  Uninitialize TS.
  * @param  None
  * @retval None
  */
void             BSP_TS_DeInit(void)
{}

/**
  * @brief  Write TS Raw data.
  * @param  None
  * @retval None
  */
void             BSP_TS_WriteRawData(uint16_t* pData, uint16_t size)
{
  uint16_t* pin = pData;
  int i;
  for(i=0; i<size; i++)
  {
    raw_data[i] = *pin++;
  }
}

/**
  * @brief  Check key.
  * @param  None
  * @retval None
  */
uint32_t             BSP_TS_Key(uint32_t Key)
{
	uint32_t ret = 0;
	if(raw_data[Key] > 12800)
	{
		ret =1;
	}
	return ret;
}
/**
  * @brief  Check slider.
  * @param  None
  * @retval None
  */
uint32_t             BSP_TS_Slider(void)
{
	int element_id;
	uint16_t sensor_val;
 
	/* Create slider position */
  for (element_id = 0; element_id < slider_element_num; element_id++)
  {
      sensor_val              = raw_data[element_id];
      slider_data[element_id] = sensor_val;
  }

  touch_slider_decode(&slider_position, slider_data, slider_element_num);
	
	return (uint32_t)slider_position;
}
/**
  * @brief  Check wheel.
  * @param  None
  * @retval None
  */
uint32_t             BSP_TS_Wheel(void)
{
	int element_id;
	uint16_t sensor_val;

	for (element_id = 0; element_id < wheel_element_num; element_id++)
  {
      sensor_val             = raw_data[element_id];
      wheel_data[element_id] = sensor_val;
  }

  touch_wheel_decode(&wheel_position, wheel_data, wheel_element_num);

	return (uint32_t)wheel_position;
}

/**
  * @brief touch_slider_decode
  *        Slider decode function
  * @param touch_slider_info_t  p_sinfo : Pointer to Slider Information structure
  * @param uint16_t *slider_data        : Pointer to Slider data array
  * @param uint8_t  num_elements        : Number of element on slider
  * @param: uint8_t  slider_id           : Slider ID
  * @retval None
  */
void touch_slider_decode (uint16_t * p_sinfo, uint16_t * slider_data, uint8_t num_elements)
{
    uint8_t  loop;
    uint8_t  max_data_num;
    uint16_t d1;
    uint16_t d2;
    uint16_t d3;
    uint16_t slider_rpos;
    uint16_t resol_plus;
    uint16_t dsum;

    if (num_elements < 3)
    {
        return;
    }

    /* Search max data in slider */
    max_data_num = 0;
    for (loop = 0; loop < (num_elements - 1); loop++)
    {
        if (slider_data[max_data_num] < slider_data[loop + 1])
        {
            max_data_num = (uint8_t) (loop + 1);
        }
    }

    /* Array making for slider operation-------------*/
    /*     |    Maximum change CH_No -----> Array"0"    */
    /*     |    Maximum change CH_No + 1 -> Array"2"    */
    /*     |    Maximum change CH_No - 1 -> Array"1"    */
    if (0 == max_data_num)
    {
        d1 = (uint16_t) (slider_data[0] - slider_data[2]);
        d2 = (uint16_t) (slider_data[0] - slider_data[1]);
    }
    else if ((num_elements - 1) == max_data_num)
    {
        d1 = (uint16_t) (slider_data[num_elements - 1] - slider_data[num_elements - 2]);
        d2 = (uint16_t) (slider_data[num_elements - 1] - slider_data[num_elements - 3]);
    }
    else
    {
        d1 = (uint16_t) (slider_data[max_data_num] - slider_data[max_data_num - 1]);
        d2 = (uint16_t) (slider_data[max_data_num] - slider_data[max_data_num + 1]);
    }

    dsum = (uint16_t) (d1 + d2);

    /* Constant decision for operation of angle of slider */
    /* Scale results to be 0-TOUCH_SLIDER_RESOLUTION */
    if (dsum > slider_threshold)
    {
        if (0 == d1)
        {
            d1 = 1;
        }

        /* x : y = d1 : d2 */
        d3 = (uint16_t) (TOUCH_DECIMAL_POINT_PRECISION + ((d2 * TOUCH_DECIMAL_POINT_PRECISION) / d1));

        slider_rpos = (uint16_t) (((TOUCH_DECIMAL_POINT_PRECISION * TOUCH_SLIDER_RESOLUTION) / d3) +
                                  (TOUCH_SLIDER_RESOLUTION * max_data_num));

        resol_plus = (uint16_t) (TOUCH_SLIDER_RESOLUTION * (num_elements - 1));

        if (0 == slider_rpos)
        {
            slider_rpos = 1;
        }
        else if (slider_rpos >= resol_plus)
        {
            slider_rpos = (uint16_t) (((slider_rpos - resol_plus) * 2) + resol_plus);
            if (slider_rpos > (TOUCH_SLIDER_RESOLUTION * num_elements))
            {
                slider_rpos = TOUCH_SLIDER_RESOLUTION;
            }
            else
            {
                slider_rpos = (uint16_t) (slider_rpos / num_elements);
            }
        }
        else if (slider_rpos <= TOUCH_SLIDER_RESOLUTION)
        {
            if (slider_rpos < (TOUCH_SLIDER_RESOLUTION / 2))
            {
                slider_rpos = 1;
            }
            else
            {
                slider_rpos = (uint16_t) (slider_rpos - (TOUCH_SLIDER_RESOLUTION / 2));
                if (0 == slider_rpos)
                {
                    slider_rpos = 1;
                }
                else
                {
                    slider_rpos = (uint16_t) ((slider_rpos * 2) / num_elements);
                }
            }
        }
        else
        {
            slider_rpos = (uint16_t) (slider_rpos / num_elements);
        }
    }
    else
    {
        slider_rpos = TOUCH_OFF_VALUE;
    }

    *(p_sinfo) = slider_rpos;
}                                      /* End of function touch_slider_decode() */

/**
  * @brief touch_wheel_decode
  *        Wheel Decode function
  * @param touch_wheel_info_t  p_sinfo : Pointer to Wheel Information structure
  * @param uint16_t *wheel_data        : Pointer to Wheel data array
  * @param uint8_t  num_elements       : Number of element on wheel
  * @param uint8_t  wheel_id           : Wheel ID
  * @retval None
  */
void touch_wheel_decode (uint16_t * p_winfo, uint16_t * wheel_data, uint8_t num_elements)
{
    uint8_t  loop;
    uint8_t  max_data_num;
    uint16_t d1;
    uint16_t d2;
    uint16_t d3;
    uint16_t wheel_rpos;
    uint16_t dsum;
    uint16_t unit;

    if (num_elements < 3)
    {
        return;
    }

    /* Search max data in slider */
    max_data_num = 0;
    for (loop = 0; loop < (num_elements - 1); loop++)
    {
        if (wheel_data[max_data_num] < wheel_data[loop + 1])
        {
            max_data_num = (uint8_t) (loop + 1);
        }
    }

    /* Array making for wheel operation          */
    /*    Maximum change CH_No -----> Array"0"    */
    /*    Maximum change CH_No + 1 -> Array"2"    */
    /*    Maximum change CH_No - 1 -> Array"1"    */
    if (0 == max_data_num)
    {
        d1 = (uint16_t) (wheel_data[0] - wheel_data[num_elements - 1]);
        d2 = (uint16_t) (wheel_data[0] - wheel_data[1]);
    }
    else if ((num_elements - 1) == max_data_num)
    {
        d1 = (uint16_t) (wheel_data[num_elements - 1] - wheel_data[num_elements - 2]);
        d2 = (uint16_t) (wheel_data[num_elements - 1] - wheel_data[0]);
    }
    else
    {
        d1 = (uint16_t) (wheel_data[max_data_num] - wheel_data[max_data_num - 1]);
        d2 = (uint16_t) (wheel_data[max_data_num] - wheel_data[max_data_num + 1]);
    }

    dsum = (uint16_t) (d1 + d2);

    if (0 == d1)
    {
        d1 = 1;
    }

    /* Constant decision for operation of angle of wheel    */
    if (dsum > wheel_threshold)
    {
        d3 = (uint16_t) (TOUCH_DECIMAL_POINT_PRECISION + ((d2 * TOUCH_DECIMAL_POINT_PRECISION) / d1));

        unit       = (uint16_t) (TOUCH_WHEEL_RESOLUTION / num_elements);
        wheel_rpos = (uint16_t) (((unit * TOUCH_DECIMAL_POINT_PRECISION) / d3) + (unit * max_data_num));

        /* Angle division output */
        /* diff_angle_ch = 0 -> 359 ------ diff_angle_ch output 1 to 360 */
        if (0 == wheel_rpos)
        {
            wheel_rpos = TOUCH_WHEEL_RESOLUTION;
        }
        else if ((TOUCH_WHEEL_RESOLUTION + 1) < wheel_rpos)
        {
            wheel_rpos = 1;
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        wheel_rpos = TOUCH_OFF_VALUE;
    }

    *(p_winfo) = wheel_rpos;
}                                      /* End of function touch_wheel_decode() */


/**
  * @}
  */ 

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
