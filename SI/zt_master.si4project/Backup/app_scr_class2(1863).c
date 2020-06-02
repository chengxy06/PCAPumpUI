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
#include "app_scr_class2.h"
#include <stdio.h>


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0         		 (GUI_ID_USER + 0x00)
#define STOP_INFUSION_ID_STR_YES     (GUI_ID_USER + 0x01)
#define STOP_INFUSION_ID_STR_NO      (GUI_ID_USER + 0x02)
#define STOP_INFUSION_ID_IMG         (GUI_ID_USER + 0x03)
#define MessageID (GUI_ID_USER + 0x04)


/*********************************************************************
*
*       Static data
*
**********************************************************************
*/


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_class2", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
static void put_select_stop_infusion(bool is_stop)
{
	WM_HWIN hWin;
    const char *ptr;
        
	if(is_stop == 1)
	{
            hWin = WM_GetDialogItem(ui_get_current_hwin(), MessageID);
            //sprintf(buff, "%s", get_string(kStrWhetherToStopInfuse));
            TEXT_SetText(hWin, get_string(kStrWhetherToContinueInfuse));		
	}
	else if(is_stop == 0)
	{
            hWin = WM_GetDialogItem(ui_get_current_hwin(), MessageID);
            //sprintf(buff, "%s", get_string(kStrInfusionEnd));
            TEXT_SetText(hWin, get_string(kStrWhetherToStopInfuse));	
	}
}


static void _cbDialog(WM_MESSAGE * pMsg)
{
	uint8_t strlen;
	GUI_RECT rect; 
	const char *ptr;
	WM_HWIN hWin;
	int x,y;


	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);

			GUI_SetFont(get_font(14));
			ptr = get_string(kStrWhetherToStopInfuse);
			strlen = GUI_GetStringDistX(ptr);
			
			hWin = TEXT_CreateEx(75, 18, strlen, 14, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER, MessageID, 0);
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin,GUI_BLACK );
			TEXT_SetTextColor(hWin, GUI_WHITE);
			WM_BringToTop(hWin);
			
			break;
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);
			GUI_SetFont(get_font(14));
				
			ptr = get_string(kStrpresscanclekey);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, 6, 44, strlen, 12);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

			ptr = get_string(kStrpressselectkey);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, 182, 44, strlen, 16);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);
			
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
WM_HWIN app_scr_class2_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;
	//msg->SItem.DataValArray[1]
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}


int app_scr_class2_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
        put_select_stop_infusion(msg->SItem.DataValArray[1]);
 	return 0;	
}

void app_scr_class2_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}


/*************************** End of file ****************************/

