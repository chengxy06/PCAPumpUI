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
*********************************************************************/


#include "DIALOG.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>
#include "app_scr_set_dose_12300.h"
#include <stdio.h>


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)

/*********************************************************************
*
*       Static data
*
***********************************************************************/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_set_dose_12300", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
***********************************************************************/

static void _cbDialog(WM_MESSAGE * pMsg)
{
	uint8_t data, strlen, dlen;
	GUI_RECT rect; 
	const char *ptr;
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			break;
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);
			if(ui_is_set_once_flag() == 0)
			{
				GUI_SetFont(get_font(14));
				
				ptr = get_string(kStrSetTotalDose);
				strlen = GUI_GetStringDistX(ptr);
				ui_rect_init_by_size(rect, 0, 0, strlen, 12);
				GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

				ptr = get_string(kStrReturn);
				strlen = GUI_GetStringDistX(ptr);
				ui_rect_init_by_size(rect, 0, DISPLAY_HEIGHT-16, strlen, 16);
				GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

				ptr = get_string(kStrConfirm);
				strlen = GUI_GetStringDistX(ptr);
				ui_rect_init_by_size(rect, 0, DISPLAY_WIDTH-strlen, strlen, 16);
				GUI_DispStringInRect(ptr, &rect, GUI_TA_RIGHT|GUI_TA_VCENTER);

				ptr = get_string(kStrMililiter);
				strlen = GUI_GetStringDistX(ptr);
				GUI_SetFont(get_font(60));
				dlen = GUI_GetStringDistX("250");
				ui_rect_init_by_size(rect, 0, (DISPLAY_WIDTH+dlen)/2, strlen, 16);
				GUI_SetFont(get_font(14));
				GUI_DispStringInRect(ptr, &rect, GUI_TA_TOP|GUI_TA_HCENTER);
				
				ui_set_init_once_flag();
			}

			WM_GetUserData(pMsg->hWin, (uint8_t *)&data, 1);
			GUI_SetFont(get_font(60));
			char *p = get_dynamic_string(kStrDynamic1);
			sprintf(p, "%d", data);
			dlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, (DISPLAY_WIDTH-dlen)/2, 12, dlen, 60);
			GUI_SetFont(get_font(14));
			GUI_DispStringInRect(p, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);

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
WM_HWIN app_scr_set_dose_12300_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	WM_SetUserData(hWin, (uint8_t *)&msg->DItem[0], 4);
	ui_clear_init_once_flag();
	return hWin;
}


int app_scr_set_dose_12300_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
	GUI_RECT rect; 
	switch(msg->OpMethod)
	{
		case SCR_CURSER_MOVE:
			break;

		case SCR_VALUE_ALTER:
			GUI_SetFont(get_font(60));
			uint8_t dlen = GUI_GetStringDistX("250");
		    ui_rect_init_by_size(rect, (DISPLAY_WIDTH-dlen)/2, 12, dlen, 60);
			WM_SetUserData(hwin, (uint8_t *)&msg->CursorIndex, 1);
			WM_InvalidateRect(hwin, &rect);
			break;

		default:
			break;
	}

 	return 0;	
}

void app_scr_set_dose_12300_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}

/*************************** End of file ****************************/
