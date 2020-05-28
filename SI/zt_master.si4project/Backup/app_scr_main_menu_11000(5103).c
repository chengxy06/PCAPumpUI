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
#include "app_scr_main_menu_11000.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)

#define MAIN_MENU_ICON_X(x)     ((64 - x)/2)
#define MAIN_MENU_ICON_Y(y)     ((64 - y)/2)

#define MAIN_MENU_ICON_XSIZE	64
#define MAIN_MENU_ICON_YSIZE	64

#define SELECT_ICON_SUM_LEN			(8*9)
#define SELECT_ICON_X(index)    ((DISPLAY_WIDTH-SELECT_ICON_SUM_LEN)/2 + (index*16))
#define SELECT_ICON_Y           (DISPLAY_HEIGHT-16)

/*********************************************************************
*
*       Static data
*
***********************************************************************/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_main_menu_11000", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },
};

static bool flag_once_draw = 0;
/*********************************************************************
*
*       Static code
*
***********************************************************************/

static void put_menu_info(uint16_t cursor_index)
{
	const GUI_BITMAP *pbm;
	const char *pstr;
	GUI_RECT tile_rect = {MAIN_MENU_ICON_XSIZE, (DISPLAY_HEIGHT-16)/2, 
		                  DISPLAY_WIDTH - MAIN_MENU_ICON_XSIZE, (DISPLAY_HEIGHT-16)/2+16};
	const GUI_BITMAP *pSelecticon = get_image(kImgSelectedPointer);
	const GUI_BITMAP *pUnSelecticon = get_image(kImgUnselectedPointer);
	
	switch(cursor_index)
	{
		case 0://new task
		{
			pbm = get_image(kImgNewTask);
			pstr = get_string(kStrNewInfusionTask);
			break;
		}

		case 1://exhaust
		{
			pbm = get_image(kImgExhaust);
			pstr = get_string(kStrNewInfusionTask);
			break;
		}
		
		case 2://stop task
		{
			pbm = get_image(kImgStopInfusion);
			pstr = get_string(kStrNewInfusionTask);
			break;
		}
		
		case 3://sysytem setting
		{
			pbm = get_image(kImgSystemSetting);
			pstr = get_string(kStrNewInfusionTask);
			break;
		}

		case 4://histroy log
		{
			pbm = get_image(kImgHistoryLog);
			pstr = get_string(kStrNewInfusionTask);
			break;
		}
		
		default:
	  		return;
	}
	

	GUI_DrawBitmap(pbm, MAIN_MENU_ICON_X(pbm->XSize), MAIN_MENU_ICON_X(pbm->YSize));
	GUI_SetFont(get_font(14));
	GUI_DispStringInRect(pstr, &tile_rect, GUI_TA_HCENTER|GUI_TA_VCENTER);

	for(int i=0; i<5; i++)
	{
		if(i == cursor_index)
		{
			GUI_DrawBitmap(pSelecticon, SELECT_ICON_X(i), SELECT_ICON_Y);
		}
		else
		{
			GUI_DrawBitmap(pUnSelecticon, SELECT_ICON_X(i), SELECT_ICON_Y+7);
		}	
	}
}

static void _cbDialog(WM_MESSAGE * pMsg) 
{
	uint8_t data;
	GUI_RECT rect = {193, 48, 256, 64}; 
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			break;
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);
			GUI_SetFont(get_font(14));
		  
			if(flag_once_draw ==0)
			{
				GUI_DispStringInRect(get_string(kStrEnter), &rect, GUI_TA_RIGHT|GUI_TA_VCENTER);
				flag_once_draw = 1;
			}
			WM_GetUserData(pMsg->hWin, (uint8_t *)&data, 1);
			put_menu_info(data&0x07);
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

WM_HWIN app_main_menu_11000_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	WM_SetUserData(hWin, (uint8_t *)&msg->DItem[0], 4);
	return hWin;
}


int app_main_menu_11000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
	GUI_RECT rect = {0, 0, DISPLAY_WIDTH - MAIN_MENU_ICON_XSIZE, DISPLAY_HEIGHT}; 
	switch(msg->OpMethod)
	{
		case SCR_CURSER_MOVE:
			break;

		case SCR_VALUE_ALTER:
			WM_SetUserData(hwin, (uint8_t *)&msg->CursorIndex, 1);
			WM_InvalidateRect(hwin, &rect);
			break;

		default:
			break;
	}

 	return 0;	
}

void app_main_menu_11000_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}


/*************************** End of file ****************************/
