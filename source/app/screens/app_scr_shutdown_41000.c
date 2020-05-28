/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
***********************************************************************/



#include "DIALOG.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>
#include "app_scr_shutdown_41000.h"
#include <stdio.h>
#include "ssz_common.h"
#include "widget_text.h"
#include "widget_image.h"
#include "record_log_config.h"
#include "ert_RTC.h"
#include "param.h"
#include "record_log_text.h"


/*********************************************************************
*
*       Defines
*
***********************************************************************/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)



/*********************************************************************
*
*       Static data
*
***********************************************************************/


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_shotdown_41000", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },

};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/


static void _cbDialog(WM_MESSAGE * pMsg)
{
	GUI_RECT rect;

	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			break;
	
		case WM_PAINT:
			GUI_SetFont(get_font(14));

			ui_rect_init_by_size(rect, 0, 0, DISPLAY_WIDTH/2, 16);
			GUI_DispStringInRect(get_string(kStrPowerOffConfirm), &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

			ui_rect_init_by_size(rect, 0, DISPLAY_HEIGHT-16, DISPLAY_WIDTH/2, 16);
			GUI_DispStringInRect(get_string(kStrReturn), &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

			ui_rect_init_by_size(rect, DISPLAY_WIDTH/2, DISPLAY_HEIGHT-16, DISPLAY_WIDTH/2, 16);
			GUI_DispStringInRect(get_string(kStrConfirm), &rect, GUI_TA_RIGHT|GUI_TA_VCENTER);


			ui_rect_init_by_size(rect, 0, 16, DISPLAY_WIDTH, 32);
			GUI_DispStringInRect(get_string(kStrIsConfirm), &rect, GUI_TA_HCENTER|GUI_TA_VCENTER);

			break; 
			
		default:
			  WM_DefaultProc(pMsg);
			  break;
	}

}

/*********************************************************************
*
*       Public code
*
***********************************************************************/

WM_HWIN app_scr_shotdown_41000_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	
	return hWin;
}


int app_scr_shotdown_41000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
//	switch(msg->OpMethod)
//	{
//		case SCR_CURSER_MOVE:
//			
//			break;
//
//		case SCR_VALUE_ALTER:
//
//			break;
//		default:
//			break;
//	}
 	return 0;	
}

void app_scr_shotdown_41000_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}

/*************************** End of file ****************************/