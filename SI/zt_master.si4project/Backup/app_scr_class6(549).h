/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "uiDisp.h"
/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


WM_HWIN app_main_menu_11000_create(type_MsgBody4UICtrlMsg *msg); 
int app_main_menu_11000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_main_menu_11000_destroy(WM_HWIN win_id); 




#ifdef __cplusplus
}
#endif
