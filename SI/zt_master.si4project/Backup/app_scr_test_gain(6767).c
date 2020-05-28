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
#include "app_scr_test_gain.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>
#include "ssz_common.h"


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)

#define ID_GAIN_1		(GUI_ID_USER + 0x01)
#define ID_GAIN_2		(GUI_ID_USER + 0x02)
#define ID_GAIN_3		(GUI_ID_USER + 0x03)
#define ID_GAIN_4		(GUI_ID_USER + 0x04)
#define ID_GAIN_5		(GUI_ID_USER + 0x05)

#define ID_IMG_SELECT	(GUI_ID_USER + 0x06)


/*********************************************************************
*
*       Static data
*
*********************************************************************/


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_test_gain", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },
};

static uint8_t g_scr_gain[5];
/*********************************************************************
*
*       Static code
*
**********************************************************************/
static int get_item_x(int index)
{
	int dlen, charlen, plen, x;
	const char *ptr;
	if((index < 1)&&(index > 5)) return -1;
	GUI_SetFont(get_font(40));
	ptr = "00.000";
	dlen = GUI_GetStringDistX(ptr);
	ptr = "0";
	charlen = GUI_GetStringDistX(ptr);
	ptr = ".";
	plen = GUI_GetStringDistX(ptr);

	x = (DISPLAY_WIDTH - dlen)/2;	

	if(index < 4)
	{
		return(x + (plen+1) + (5 - index)*(charlen + 1));
	}
	else
	{
		return(x + (5 - index)*(charlen + 1));
	}
}


static int get_image_x(int index)
{
	int dx, charlen;
	GUI_CONST_STORAGE GUI_BITMAP* bitmap;	
	
	bitmap = get_image(kImgSelectedPointer);
	
	GUI_SetFont(get_font(40));
	charlen = GUI_GetStringDistX("0");
	dx = (charlen - bitmap->XSize)/2;

	return (get_item_x(index) + dx);
}

static void move_gain_cusor(int cursor)
{
	WM_HWIN hWin;
	if((cursor < 1) || (cursor > 5)) return;
	hWin = WM_GetDialogItem(ui_get_current_hwin(), ID_IMG_SELECT);
	WM_MoveChildTo(hWin, get_image_x(cursor), 52);
}

static void change_gain_data(int cursor, int data)
{
	WM_HWIN hWin;
	char buff[4];
	if((cursor < 1) || (cursor > 5)) return;
	hWin = WM_GetDialogItem(ui_get_current_hwin(), GUI_ID_USER+cursor);	

	sprintf(buff, "%d", data);
	TEXT_SetText(hWin, buff);
}

static void _cbDialog(WM_MESSAGE * pMsg)
{
	int i, charlen;
	GUI_RECT rect; 
	WM_HWIN hWin;
	GUI_CONST_STORAGE GUI_BITMAP* bitmap;

	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			//str
			GUI_SetFont(get_font(40));
			charlen = GUI_GetStringDistX("0");
			for(i=1; i<=5; i++)
			{
				hWin = TEXT_CreateEx(get_item_x(i), 16, charlen, 40, pMsg->hWin, 
					                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER,  GUI_ID_USER+i, "0");
				TEXT_SetFont(hWin, get_font(40));
				TEXT_SetBkColor(hWin, GUI_BLACK);
				TEXT_SetTextColor(hWin, GUI_WHITE);
			}
		
			//select image
			bitmap = get_image(kImgSelectedPointer);
			hWin = IMAGE_CreateEx(get_image_x(0), 52, bitmap->XSize, bitmap->YSize, pMsg->hWin, 
				                  WM_CF_SHOW,  IMAGE_CF_AUTOSIZE, ID_IMG_SELECT);
			IMAGE_SetBitmap(hWin, bitmap);

			break;
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);
		
			//tile
			GUI_SetFont(get_font(14));
			ui_rect_init_by_size(rect, 0, 0, DISPLAY_WIDTH, 16);
			GUI_DispStringInRect("GAIN", &rect, GUI_TA_HCENTER|GUI_TA_VCENTER);
			//.
			GUI_SetFont(get_font(40));
			charlen = GUI_GetStringDistX("0");
			ui_rect_init_by_size(rect, get_item_x(4)+charlen+1, 16, GUI_GetStringDistX("."), 40);
			GUI_DispStringInRect(".", &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

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
WM_HWIN app_scr_test_gain_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	
	return hWin;
}


int app_scr_test_gain_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
	switch(msg->OpMethod)
	{
		case SCR_CURSER_MOVE:
			move_gain_cusor(msg->CursorIndex);
			break;

		case SCR_VALUE_ALTER:
			change_gain_data(msg->CursorIndex, msg->DItem[msg->CursorIndex-1]);
			break;
		default:
			break;
	}
 	return 0;	
}

void app_scr_test_gain_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}



/*************************** End of file ****************************/
