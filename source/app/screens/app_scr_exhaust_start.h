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


WM_HWIN app_exhaust_start_create(type_MsgBody4UICtrlMsg *msg); 
int app_exhaust_start_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_exhaust_start_destroy(WM_HWIN win_id); 




#ifdef __cplusplus
}
#endif
