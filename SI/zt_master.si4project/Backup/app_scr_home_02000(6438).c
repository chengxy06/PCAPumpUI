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
#include "widget_text.h"
#include "widget_image.h"


/*********************************************************************
*
*       Defines
*
***********************************************************************/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)
//child window id
#define INFUSION_ID_IMG_STATE	(GUI_ID_USER + 0x01)
#define INFUSION_ID_STR_STATE	(GUI_ID_USER + 0x02) 
#define INFUSION_ID_STR_DOSE	(GUI_ID_USER + 0x03)
#define INFUSION_ID_STR_SPEED	(GUI_ID_USER + 0x04)
#define INFUSION_ID_STR_TIME	(GUI_ID_USER + 0x05)
#define INFUSION_ID_STR_HR		(GUI_ID_USER + 0x06)


//infusion state
#define INFUSION_STATE_IDLE		0
#define INFUSION_STATE_RUN		1
#define INFUSION_STATE_PAUSE	2


/*********************************************************************
*
*       Static data
*
***********************************************************************/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  {WINDOW_CreateIndirect, "app_home_02000", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0},
  
};
static int g_home_left_time;
/*********************************************************************
*
*       Static code
*
***********************************************************************/
static void put_left_time(uint16_t time)
{
	GUI_RECT rect;
	int dlen, hlen;
	char *p;

	int x;
	
	GUI_SetFont(get_font(88));
	p = get_dynamic_string(kStrDynamic1);
	sprintf(p, "%d", time);
	dlen = GUI_GetStringDistX(p);

	GUI_SetFont(get_font(14));
	hlen = GUI_GetStringDistX(get_string(kStrHour));
	x = ((DISPLAY_WIDTH/2 + 24) - (dlen + hlen))/2;
	//data
	GUI_SetFont(get_font(88));
	ui_rect_init_by_size(rect, x, 0, dlen, DISPLAY_HEIGHT);
	GUI_DispStringInRect(p, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);	
	//hr
	GUI_SetFont(get_font(14));
	ui_rect_init_by_size(rect, x+dlen, 48, hlen, 16);
	GUI_DispStringInRect(get_string(kStrHour), &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);
}


static void put_infusion_state(uint8_t state)
{
	const GUI_BITMAP *bitmap;
	const char *ptr;

	
	switch(state)
	{
		case INFUSION_STATE_IDLE:
			bitmap = get_image(kImgInfusionStop);
			ptr = get_string(kStrInfusionStop);
			break;

		case INFUSION_STATE_RUN:
			bitmap = get_image(kImgInfusionRun);
			ptr = get_string(kStrInfusing);

			break;

		case INFUSION_STATE_PAUSE:
			bitmap = get_image(kImgInfusionPause);
			ptr = get_string(kStrInfusionPause);
			break;

		default:
			bitmap = NULL;
			ptr = NULL;
			return;
	}
	TEXT_SetText(WM_GetDialogItem(g_ui_common_param.win_id, INFUSION_ID_STR_STATE), ptr);
	IMAGE_SetBitmap(WM_GetDialogItem(g_ui_common_param.win_id, INFUSION_ID_IMG_STATE), bitmap);
}

static void put_infusion_dose(uint8_t total_dose, uint8_t infusioned_dose)
{
	char *p;
	p = get_dynamic_string(kStrDynamic2);
	sprintf(p, "%d", infusioned_dose);	
	strcat(p, "/");
	sprintf((p + strlen(p)), "%d", total_dose);
	strcat(p, "ml");
	TEXT_SetText(WM_GetDialogItem(g_ui_common_param.win_id, INFUSION_ID_STR_DOSE), p);
}

static void put_infusion_seed(uint8_t infusion_speed)
{
	char *p;
	p = get_dynamic_string(kStrDynamic3);
	sprintf(p, "%d", infusion_speed);	
	strcat(p, "ml/hr");
	TEXT_SetText(WM_GetDialogItem(g_ui_common_param.win_id, INFUSION_ID_STR_SPEED), p);
}

static void _cbDialog(WM_MESSAGE * pMsg)
{
	GUI_RECT rect;
	WM_HWIN hWin;
	int len;
	const char *p;
	
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			//state string
			hWin = TEXT_CreateAsChild(DISPLAY_WIDTH/2+24, 12, DISPLAY_WIDTH/2 - 24, 16, pMsg->hWin, INFUSION_ID_STR_STATE, 
				                      WM_CF_SHOW, get_string(kStrInfusing), GUI_TA_VCENTER|GUI_TA_RIGHT);
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin, GUI_WHITE);
			TEXT_SetTextColor(hWin, GUI_BLACK);

			//state image
			hWin = IMAGE_CreateEx(DISPLAY_WIDTH/2+24, 12, 16, 16, pMsg->hWin, WM_CF_SHOW,  IMAGE_CF_AUTOSIZE, INFUSION_ID_IMG_STATE);
			IMAGE_SetBitmap(hWin, get_image(kImgInfusionRun));
			
			//dose
		 	GUI_SetFont(get_font(14));
			p = get_string(kStrInfusionDose);
			len = GUI_GetStringDistX(p);
			hWin = TEXT_CreateAsChild(DISPLAY_WIDTH/2+24+len, 30, DISPLAY_WIDTH/2 - len-24, 16, pMsg->hWin, INFUSION_ID_STR_DOSE, 
				                      WM_CF_SHOW, "999/230ml", GUI_TA_VCENTER|GUI_TA_RIGHT);
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin, GUI_WHITE);
			TEXT_SetTextAlign(hWin, GUI_TA_VCENTER|GUI_TA_RIGHT);
	
			//speed
			p = get_string(kStrInfusionSpeed);
			len = GUI_GetStringDistX(p);
			hWin = TEXT_CreateAsChild(DISPLAY_WIDTH/2+24+len, 48, DISPLAY_WIDTH/2 - len-24, 16, pMsg->hWin, INFUSION_ID_STR_SPEED, 
				                      WM_CF_SHOW, "50ml/hr", GUI_TA_VCENTER|GUI_TA_RIGHT);
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin, GUI_WHITE);


			break;
	
		case WM_PAINT:
			GUI_SetFont(get_font(14));
			p = get_string(kStrInfusionDose);
			len = GUI_GetStringDistX(p);			
			ui_rect_init_by_size(rect, DISPLAY_WIDTH/2+24, 30, len, 16);
			GUI_DispStringInRect(p, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);	

			p = get_string(kStrSpeed);
			len = GUI_GetStringDistX(p);			
			ui_rect_init_by_size(rect, DISPLAY_WIDTH/2+24, 48, len, 16);
			GUI_DispStringInRect(p, &rect, GUI_TA_VCENTER|GUI_TA_BOTTOM);
				
			put_left_time(g_home_left_time);
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
			put_infusion_state(msg->CursorIndex);
		    put_infusion_dose(40, msg->CursorIndex);
			put_infusion_seed(msg->CursorIndex);

			g_home_left_time  = msg->CursorIndex;
			WM_InvalidateWindow(hwin);
			break;

		case SCR_VALUE_ALTER:

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
