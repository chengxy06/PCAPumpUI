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
#include "app_scr_exhaust_11200.h"
#include <stdio.h>
#include "ssz_common.h"


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)

#define IMAGE_BAG_HEIGHT	(24)

//medsbag
#define BAG_A			1
#define BAG_B			2

//exhaust start or stop
#define EXHAUST_START	1
#define EXHAUST_STOP	2

/*********************************************************************
*
*       Static data
*
***********************************************************************/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_exhaust_11200", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },

};

static uint8_t flag_exhaust_medsbag = BAG_A;
static uint8_t flag_exhaust_start = EXHAUST_START;

static void put_exhaust_select_bag_and_action(uint8_t bag, uint8_t start_or_stop)
{
	GUI_RECT  rect;
	const char *ptr;
	int strlen;

	GUI_SetFont(get_font(14));
	GUI_SetColor(GUI_WHITE);
	if(start_or_stop == EXHAUST_START)
	{
		ptr = get_string(kStrPressPauseToStopClearAir);
	}
	else if(start_or_stop == EXHAUST_STOP)
	{
		ptr = get_string(kStrPressStartToStartClearAir);
	}
	strlen = GUI_GetStringDistX(ptr);
	ui_rect_init_by_size(rect, 0, 0, strlen, (DISPLAY_HEIGHT - 24)/2);
	GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

	ptr = get_string(kStrReturn);
	strlen = GUI_GetStringDistX(ptr);
	ui_rect_init_by_size(rect, 0, (DISPLAY_HEIGHT - 24)/2 + IMAGE_BAG_HEIGHT, strlen, (DISPLAY_HEIGHT - 24)/2);
	GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

	if(bag == BAG_A)
	{
		ui_rect_init_by_size(rect, 0, (DISPLAY_HEIGHT - 24)/2, DISPLAY_WIDTH/2, IMAGE_BAG_HEIGHT);
		GUI_DrawBitmap(get_image(kImgSelect1), rect.x0, rect.y0);
		ptr = get_string(kStrMedsBag1);
		GUI_SetTextMode(GUI_TM_REV);
		GUI_DispStringInRect(ptr, &rect, GUI_TA_HCENTER|GUI_TA_HCENTER);
		GUI_SetTextMode(GUI_TM_NORMAL);

		ui_rect_init_by_size(rect, DISPLAY_WIDTH/2, (DISPLAY_HEIGHT - 24)/2, DISPLAY_WIDTH/2, IMAGE_BAG_HEIGHT);
		GUI_DispStringInRect(get_string(kStrMedsBag2), &rect, GUI_TA_HCENTER|GUI_TA_HCENTER);
	}
	else if(bag == BAG_B)
	{

		ui_rect_init_by_size(rect, 0, (DISPLAY_HEIGHT - 24)/2, DISPLAY_WIDTH/2, IMAGE_BAG_HEIGHT);
		GUI_DrawBitmap(get_image(kImgSelect2), rect.x0, rect.y0);
		GUI_DispStringInRect(get_string(kStrMedsBag1), &rect, GUI_TA_HCENTER|GUI_TA_HCENTER);

		ui_rect_init_by_size(rect, DISPLAY_WIDTH/2, (DISPLAY_HEIGHT - 24)/2, DISPLAY_WIDTH/2, IMAGE_BAG_HEIGHT);
		GUI_SetTextMode(GUI_TM_REV);
		GUI_DispStringInRect(get_string(kStrMedsBag2), &rect, GUI_TA_HCENTER|GUI_TA_HCENTER);
		GUI_SetTextMode(GUI_TM_NORMAL);
	}
	//display start or stop image
	if(start_or_stop == EXHAUST_START)
	{
		GUI_DrawBitmap(get_image(kImgInfusionPause), rect.x0+4, rect.y0+4);
	}
	else if(start_or_stop == EXHAUST_STOP)
	{
		GUI_DrawBitmap(get_image(kImgInfusionRun), rect.x0+4, rect.y0+4);
	}
}

/*********************************************************************
*
*       Static code
*
***********************************************************************/
static void _cbDialog(WM_MESSAGE * pMsg)
{
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			break;
	
		case WM_PAINT:
			put_exhaust_select_bag_and_action(flag_exhaust_medsbag, flag_exhaust_start);
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
WM_HWIN app_scr_exhaust_11200_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}


int app_scr_exhaust_11200_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
	switch(msg->OpMethod)
	{
		case SCR_CURSER_MOVE:
			flag_exhaust_medsbag = msg->CursorIndex;
			WM_InvalidateWindow(hwin);
			break;

		case SCR_VALUE_ALTER:
			flag_exhaust_start = msg->DItem[0];
			WM_InvalidateWindow(hwin);
			break;
		default:
			break;
	}

 	return 0;	
}

void app_scr_exhaust_11200_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}


/*************************** End of file ****************************/
