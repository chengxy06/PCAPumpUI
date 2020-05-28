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
**********************************************************************/


#include "DIALOG.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>
#include "app_scr_unlock_password_12100.h"
#include <stdio.h>
#include "ssz_common.h"

/*********************************************************************
*
*       Defines
*
***********************************************************************/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)

#define IMG_SET_ARROW_WIDTH		(8)	
#define IMG_SET_ARROE_HEIGH     (16)



/*********************************************************************
*
*       Static data
*
***********************************************************************/

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, " app_scr_unlock_password_12100", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },

};



void get_image_coordinate(uint8_t cursor_index, GUI_RECT *rect)
{
	uint8_t data_width, sum_len;
	uint8_t one_image_and_data_with;
	uint8_t image_start_x, y;
	GUI_RECT rt;

	ssz_assert(cursor_index < 3);
	
	GUI_SetFont(get_font(60));
	data_width = GUI_GetStringDistX("1");
	
	one_image_and_data_with = data_width + IMG_SET_ARROW_WIDTH;
	sum_len = one_image_and_data_with*3 + IMG_SET_ARROW_WIDTH*3;

	image_start_x = (DISPLAY_WIDTH - sum_len)/2 + cursor_index*(one_image_and_data_with + IMG_SET_ARROW_WIDTH);
	y = 12;

	ui_rect_init_by_size(rt, image_start_x, y, one_image_and_data_with, DISPLAY_HEIGHT - 12);
	*rect = rt;
}



static void put_select_password(uint8_t cursor_index, uint8_t data)
{
	GUI_RECT rect, rt;
	char *p;
	
	for(int i=0; i<3; i++)
	{
		get_image_coordinate(i, &rect);
		if(i == cursor_index)
		{
			GUI_DrawBitmap(get_image(kImgSetArrow), rect.x0, (DISPLAY_HEIGHT - rect.y0)/2+3);
		}
		else
		{
			ui_rect_init_by_size(rt, rect.x0, rect.y0, 8, DISPLAY_HEIGHT-12);			
			GUI_ClearRectEx(&rt);
		}
	}

	get_image_coordinate(cursor_index, &rect);
	ui_rect_init_by_size(rt, rect.x0+IMG_SET_ARROW_WIDTH, rect.y0, 
		                     (rect.x1 - rect.x0) - IMG_SET_ARROW_WIDTH, rect.y1-rect.y0);
	
	p = get_dynamic_string(kStrDynamic1);
	sprintf(p, "%d", data); 
	GUI_DispStringInRect(p, &rt, GUI_TA_VCENTER|GUI_TA_HCENTER);					 
}


/*********************************************************************
*
*       Static code
*
***********************************************************************/
static void _cbDialog(WM_MESSAGE * pMsg) 
{
	uint16_t user_data, strlen;
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
				
				ptr = get_string(kStrInputPasswordToUnlock);
				strlen = GUI_GetStringDistX(ptr);
				ui_rect_init_by_size(rect, 0, 0, strlen, 12);
				GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

				ptr = get_string(kStrReturn);
				strlen = GUI_GetStringDistX(ptr);
				ui_rect_init_by_size(rect, 0, DISPLAY_HEIGHT-16, strlen, 16);
				GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

				ptr = get_string(kStrConfirm);
				strlen = GUI_GetStringDistX(ptr);
				ui_rect_init_by_size(rect, DISPLAY_WIDTH-strlen, DISPLAY_HEIGHT-16, strlen, 16);
				GUI_DispStringInRect(ptr, &rect, GUI_TA_RIGHT|GUI_TA_VCENTER);

				ui_set_init_once_flag();
			}

			WM_GetUserData(pMsg->hWin, (uint16_t *)&user_data, sizeof(user_data));
			put_select_password((user_data>>8)&0xff, user_data&0xff);
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
WM_HWIN app_scr_unlock_password_12100_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	ui_clear_init_once_flag();
	return hWin;
}

int app_scr_unlock_password_12100_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
	GUI_RECT rect; 
	uint16_t user_data;
	switch(msg->OpMethod)
	{
		case SCR_CURSER_MOVE:
			break;

		case SCR_VALUE_ALTER:
			user_data = (uint16_t)(msg->CursorIndex<<8)|msg->DItem[0];
			WM_SetUserData(hwin, (uint8_t *)&user_data, sizeof(user_data));
			get_image_coordinate(msg->CursorIndex, &rect);
			WM_InvalidateRect(hwin, &rect);
			break;

		default:
			break;
	}

 	return 0;	
}

void app_scr_unlock_password_12100_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}


/*************************** End of file ****************************/
