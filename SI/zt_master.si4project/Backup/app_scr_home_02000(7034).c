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
#include "app_scr_home_02000.h"
#include <stdio.h>
#include "ssz_common.h"


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
  { WINDOW_CreateIndirect, "app_home_02000", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
***********************************************************************/

static void put_left_time(uint16_t time)
{
	char *ptr;
	int strlen;
	GUI_RECT rect, rt;
	const char *p;

	ptr = get_dynamic_string(kStrDynamic1);
	sprintf(ptr, "%d", time);
	strlen = GUI_GetStringDistX(ptr);

	ui_rect_init_by_size(rect, 0, 0, DISPLAY_WIDTH/2, DISPLAY_HEIGHT);
	GUI_SetFont(get_font(88));
	GUI_DispStringInRect(ptr, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);

	p = get_string(kStrHour);
	strlen = GUI_GetStringDistX(p);	
	ui_rect_init_by_size(rt, rect.x1, DISPLAY_HEIGHT - 16, strlen, 16);
	GUI_SetFont(get_font(14));
	GUI_DispStringInRect(p, &rt, GUI_TA_VCENTER|GUI_TA_HCENTER);
}

static void put_infusion_state(uint8_t state)
{



}


static void put_infusion_dose(uint8_t total_dose, uint8_t infusioned_dose)
{



}


static void put_infusion_seed(uint8_t infusion_speed)
{



}

static void _cbDialog(WM_MESSAGE * pMsg)
{
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			break;
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);
			put_left_time(145);
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
WM_HWIN app_home_02000_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}


int app_home_02000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
	switch(msg->OpMethod)
	{
		case SCR_CURSER_MOVE:

			WM_InvalidateWindow(hwin);
			break;

		case SCR_VALUE_ALTER:

			WM_InvalidateWindow(hwin);
			break;
		default:
			break;
	}

 	return 0;	
}

void app_home_02000_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}

/*************************** End of file ****************************/
