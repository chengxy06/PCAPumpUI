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
**********************************************************************
*/



#include "DIALOG.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>
#include "app_scr_lock_error_34000.h"
#include <stdio.h>
#include "ssz_common.h"



/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0         (GUI_ID_USER + 0x00)
#define VERSION_ID_TEXT		(GUI_ID_USER + 0x01)




/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_version_14140", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

static void put_version(uint32_t version)
{
	char buff[32];
	WM_HWIN hWin;
	hWin = WM_GetDialogItem(ui_get_current_hwin(), VERSION_ID_TEXT);
	sprintf(buff, "V %d.%d", version/10, version%10);
	TEXT_SetText(hWin, buff);
}

static void _cbDialog(WM_MESSAGE * pMsg) 
{
	GUI_RECT rect;
	WM_HWIN hWin;

	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);

			//alarm string
			hWin = TEXT_CreateEx(0, 16, DISPLAY_WIDTH, 32, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER,  VERSION_ID_TEXT, "V 1.0");
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin, GUI_WHITE);
			

			break;
	
		case WM_PAINT:
			GUI_SetFont(get_font(14));

			ui_rect_init_by_size(rect, 0, 0, DISPLAY_WIDTH, 16);
			GUI_SetBkColor(GUI_WHITE);
			GUI_FillRectEx(&rect);
			GUI_SetBkColor(GUI_BLACK);
			GUI_SetTextMode(GUI_TM_REV);
			GUI_DispStringInRect(get_string(kStrNotice), &rect, GUI_TA_HCENTER|GUI_TA_VCENTER);
			GUI_SetTextMode(GUI_TM_NORMAL);

			GUI_SetColor(GUI_WHITE);
			ui_rect_init_by_size(rect, DISPLAY_WIDTH/2, DISPLAY_HEIGHT -16 , DISPLAY_WIDTH/2, 16);
			GUI_DispStringInRect(get_string(kStrOk), &rect, GUI_TA_RIGHT|GUI_TA_VCENTER);
			
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
**********************************************************************
*/

WM_HWIN app_scr_version_14140_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	
	return hWin;
}


int app_scr_version_14140_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
//	switch(msg->OpMethod)
//	{
//		case SCR_CURSER_MOVE:
//			put_version(msg->DItem[0]);
//			break;
//
//		case SCR_VALUE_ALTER:
//			put_version(msg->DItem[0]);
//			break;
//		default:
//			break;
//	}
 	return 0;	
}

void app_scr_version_14140_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}

/*************************** End of file ****************************/
