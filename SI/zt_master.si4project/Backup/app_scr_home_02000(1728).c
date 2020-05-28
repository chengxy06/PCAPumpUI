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

//infusion state
#define INFUSION_STATE_IDLE		0
#define INFUSION_STATE_RUN		1
#define INFUSION_STATE_PAUSE	2


//child window id
#define INFUSION_ID_IMG_STATE	0
#define INFUSION_ID_STR_STATE	1 
#define INFUSION_ID_STR_DOSE	2
#define INFUSION_ID_STR_SPEED	3
#define INFUSION_ID_STR_TIME	5 




/*********************************************************************
*
*       Static data
*
***********************************************************************/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  {WINDOW_CreateIndirect, "app_home_02000", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0},
  
};

/*********************************************************************
*
*       Static code
*
***********************************************************************/

static void put_left_time(uint16_t time)
{





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
			break;
	}
	widget_text_set_str(ui_get_child_hwin(INFUSION_ID_STR_STATE), ptr);
	widget_image_set(ui_get_child_hwin(INFUSION_ID_IMG_STATE), bitmap);
}


static void put_infusion_dose(uint8_t total_dose, uint8_t infusioned_dose)
{
/*
	char str[32], *ptr;
	int len;
	GUI_RECT rect;

	ptr =get_string(kStrInfusionDose);
	len = GUI_GetStringDistX(ptr);
	ui_rect_init_by_size(rect, DISPLAY_WIDTH/2+16, 30, len, 16);
	GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

	memset(str, 0, sizeof(str));
	sprintf(str, "%d", );
*/



	


}


static void put_infusion_seed(uint8_t infusion_speed)
{



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
			hWin = widget_text_create(DISPLAY_WIDTH/2+16, 12, DISPLAY_WIDTH/2 - 16, 16, pMsg->hWin, WM_CF_SHOW, get_string(kStrInfusing));
			ui_set_child_hwin(INFUSION_ID_STR_STATE, hWin);
			widget_text_set_color(hWin, GUI_BLACK, GUI_WHITE);
			widget_text_set_font(hWin, get_font(14));
			widget_text_set_align(hWin, GUI_TA_VCENTER|GUI_TA_RIGHT);

			//state image
			hWin = widget_image_create(DISPLAY_WIDTH/2+16, 12, 16, 16, pMsg->hWin, WM_CF_SHOW, get_image(kImgInfusionRun));
			ui_set_child_hwin(INFUSION_ID_IMG_STATE, hWin);

			//dose
		 	GUI_SetFont(get_font(14));
			p = get_string(kStrInfusionDose);
			len = GUI_GetStringDistX(p);
			hWin = widget_text_create(DISPLAY_WIDTH/2+len, 30, DISPLAY_WIDTH/2 - len, 16, pMsg->hWin, WM_CF_SHOW, get_string(kStrInfusedDose));
			ui_set_child_hwin(INFUSION_ID_STR_DOSE, hWin);
			widget_text_set_font(hWin, get_font(14));
			widget_text_set_align(hWin, GUI_TA_VCENTER|GUI_TA_RIGHT);

		
			break;
	
		case WM_PAINT:
			//GUI_SetBkColor(GUI_WHITE);
			//GUI_Clear();
			//GUI_SetColor(GUI_BLACK);
			//GUI_SetFont(get_font(14));
			//put_infusion_state(INFUSION_STATE_RUN);

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
