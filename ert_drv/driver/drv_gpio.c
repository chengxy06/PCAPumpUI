/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "bsp_gpio.h"
#include "drv_common.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/

int8_t ERT_drv_gpio_init(void)
{
	return (int8_t)drv_common_get_error_code(bsp_gpio_init());
}


















