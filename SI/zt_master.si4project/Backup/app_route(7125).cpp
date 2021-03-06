/************************************************
 * DESCRIPTION:
 *
 * 	route for screen show
 *
 ************************************************/
#include "app_route.h"
#include "config.h"
#include "WM.h"
#include "ssz_common.h"
#include "app_scr_logo_01000.h"
#include "app_scr_main_menu_11000.h"
#include "app_scr_set_dose_12300.h"
#include "app_scr_unlock_password_12100.h"
#include "app_scr_exhaust_tip_11100.h"
#include "app_scr_exhaust_11200.h"
#include "app_scr_home_02000.h"
#include "app_scr_alarm_21000.h"
#include "app_scr_histroy_15100.h"
#include "app_scr_shutdown_41000.h"
#include "app_scr_lock_error_34000.h"
#include "app_scr_error_22000.h"
#include "app_scr_check_12500.h"
#include "app_scr_infusion_speed_12400.h"
#include "app_scr_set_date_14120.h"
#include "app_scr_set_time_14110.h"
#include "app_scr_set_14100.h"
#include "app_scr_set_year_14130.h"
#include "app_scr_stop_infusion_13100.h"
#include "app_scr_version_14140.h"
#include "app_scr_stop_infusion_13100.h"
#include "app_scr_set_14100.h"
#include "app_scr_set_year_14130.h"
#include "app_scr_set_date_14120.h"
#include "app_scr_test_gain.h"




/************************************************
 * Declaration
 ************************************************/



/************************************************
 * Variable
 ************************************************/
const ScreenInfo g_scr_routes[SCREEN_NUMBER_TOTAL]= {
    {{0,1,0,0,0}, app_logo_01000_create, app_logo_01000_update, app_logo_01000_destroy},  
	{{1,1,0,0,0}, app_main_menu_11000_create, app_main_menu_11000_update, app_main_menu_11000_destroy},
	{{1,2,3,0,0}, app_scr_set_dose_12300_create, app_scr_set_dose_12300_update, app_scr_set_dose_12300_destroy},
    {{1,2,1,0,0}, app_scr_unlock_password_12100_create, app_scr_unlock_password_12100_update, app_scr_unlock_password_12100_destroy},
    {{1,4,1,4,0}, app_scr_version_14140_create, app_scr_version_14140_update, app_scr_version_14140_destroy},
    
    {{1,1,1,0,0}, app_exhaust_tip_11100_create, app_exhaust_tip_11100_update, app_exhaust_tip_11100_destroy},
    {{1,1,2,0,0}, app_scr_exhaust_11200_create, app_scr_exhaust_11200_update, app_scr_exhaust_11200_destroy},   
	{{0,2,0,0,0}, app_home_02000_create, app_home_02000_update, app_home_02000_destroy},
	{{2,1,0,0,0}, app_scr_alarm_21000_create, app_scr_alarm_21000_update, app_scr_alarm_21000_destroy},
	{{2,2,0,0,0}, app_scr_error_22000_create, app_scr_error_22000_update, app_scr_error_22000_destroy},
	
	{{1,5,1,0,0}, app_scr_histroy_15100_create, app_scr_histroy_15100_update, app_scr_histroy_15100_destroy},
	{{4,1,0,0,0}, app_scr_shotdown_41000_create, app_scr_shotdown_41000_update, app_scr_shotdown_41000_destroy},
    {{3,2,0,0,0}, app_scr_lock_error_34000_create, app_scr_lock_error_34000_update, app_scr_lock_error_34000_destroy},   
	{{3,3,0,0,0}, app_scr_lock_error_34000_create, app_scr_lock_error_34000_update, app_scr_lock_error_34000_destroy},
	{{3,4,0,0,0}, app_scr_lock_error_34000_create, app_scr_lock_error_34000_update, app_scr_lock_error_34000_destroy},



	//{{1,2,5,0,0}, app_scr_alarm_21000_create, app_scr_alarm_21000_update, app_scr_alarm_21000_destroy},
	//{{1,2,4,0,0}, app_scr_error_22000_create, app_scr_error_22000_update, app_scr_error_22000_destroy},
	
	{{1,4,1,0,0}, app_scr_set_14100_create, app_scr_set_14100_update, app_scr_set_14100_destroy},
	{{1,4,1,2,0}, app_scr_set_date_14120_create, app_scr_set_date_14120_update, app_scr_set_date_14120_destroy},
    {{1,4,1,1,0}, app_scr_set_time_14110_create, app_scr_set_time_14110_update, app_scr_set_time_14110_destroy},   
	{{1,4,1,3,0}, app_scr_set_year_14130_create, app_scr_set_year_14130_update, app_scr_set_year_14130_destroy},
	{{1,3,1,0,0}, app_scr_stop_infusion_13100_create, app_scr_stop_infusion_13100_update, app_scr_stop_infusion_13100_destroy},


	{{5,1,1,0,0}, app_scr_test_gain_create, app_scr_test_gain_update, app_scr_test_gain_destroy},
	//{{1,3,1,0,0}, app_scr_stop_infusion_13100_create, app_scr_stop_infusion_13100_update, app_scr_stop_infusion_13100_destroy},
	//{{1,3,1,0,0}, app_scr_stop_infusion_13100_create, app_scr_stop_infusion_13100_update, app_scr_stop_infusion_13100_destroy},
	//{{1,3,1,0,0}, app_scr_stop_infusion_13100_create, app_scr_stop_infusion_13100_update, app_scr_stop_infusion_13100_destroy},
	//{{1,3,1,0,0}, app_scr_stop_infusion_13100_create, app_scr_stop_infusion_13100_update, app_scr_stop_infusion_13100_destroy},

	
};




/************************************************
 * Function
 ************************************************/

void ert_uiDisp(uint8_t UIOpCode, type_MsgBody4UICtrlMsg *UIDispData)
{
  	int i;
	ScreenCreateFunc createfunc;
	ScreenUpdateFunc updatefun;
	ScrennDestroyFunc destroyfun;


	for (i = 0; i < ssz_array_size(g_scr_routes); i++) {
		if (memcmp(UIDispData->UIID, g_scr_routes[i].screen_id, 5) == 0) 
		{
			createfunc = g_scr_routes[i].create_func; 
			updatefun = g_scr_routes[i].update_fun;
			destroyfun = g_scr_routes[i].destroy_fun;
			break;
		}
	}

	if(i == ssz_array_size(g_scr_routes))
	{//no screen is finded
		return;
	}

	if(createfunc == NULL || updatefun== NULL || destroyfun==NULL)
	{//any api is null renturn
		return;
	}

	switch(UIOpCode)
	{
		case SCR_CREATE:
			if((memcmp(g_ui_common_param.uiid, UIDispData->UIID, sizeof(g_ui_common_param.uiid)) != 0))
			{
				if(g_ui_common_param.win_id != 0)
				{
					destroyfun(g_ui_common_param.win_id);	
				}
				g_ui_common_param.win_id = createfunc(UIDispData);
				memcpy(g_ui_common_param.uiid, UIDispData->UIID, 5);
				g_ui_common_param.opcode = UIDispData->OpMethod;
			}
			break;
		
		case SCR_CURSER_MOVE:	
		case SCR_VALUE_ALTER:
			if((memcmp(g_ui_common_param.uiid, UIDispData->UIID, sizeof(g_ui_common_param.uiid)) != 0))
			{
				if(g_ui_common_param.win_id != 0)
				{
					destroyfun(g_ui_common_param.win_id);	
				}
				g_ui_common_param.win_id = createfunc(UIDispData);
				memcpy(g_ui_common_param.uiid, UIDispData->UIID, 5);
			}
			
			updatefun(g_ui_common_param.win_id, UIDispData);
			g_ui_common_param.opcode = UIDispData->OpMethod;
			
			break;
		default:
			break;
	}

}






































