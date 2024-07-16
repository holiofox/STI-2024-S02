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

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "GUI.h"
#include "MainTask.h"
/* FreeRTOS头文件 */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

extern SemaphoreHandle_t BinarySem_Handle_R;
extern SemaphoreHandle_t BinarySem_Handle_L;
extern SemaphoreHandle_t BinarySem_Handle_C_START;


extern GUI_CONST_STORAGE GUI_FONT GUI_FontMicrosoftJhengHeiUI20;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontMicrosoftJhengHeiUI32;
extern GUI_CONST_STORAGE GUI_BITMAP bmimage;
extern GUI_CONST_STORAGE GUI_BITMAP bmimage1;
WM_HWIN hFrame;

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
* 
*/
// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 480, 380, 140, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 630, 380, 140, 50, 0, 0x0, 0 },
  { IMAGE_CreateIndirect, "Image", ID_IMAGE_0, 10, 10, 800, 161, 0, 0, 0 },
  { TEXT_CreateIndirect, "TEXT", ID_TEXT_1, 630, 180, 140, 32, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "TEXT", ID_TEXT_0, 480, 180, 140, 32, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "TEXT", ID_TEXT_4, 480, 280, 140, 32, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "TEXT", ID_TEXT_2, 480, 230, 140, 32, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "TEXT", ID_TEXT_3, 630, 230, 140, 32, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "TEXT", ID_TEXT_6, 480, 330, 140, 32, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "TEXT", ID_TEXT_5, 630, 280, 140, 32, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "TEXT", ID_TEXT_7, 630, 330, 140, 32, 0, 0x64, 0 },
  { IMAGE_CreateIndirect, "Image", ID_IMAGE_1, 24, 165, 420, 280, 0, 0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/


// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN      hItem;
  int          NCode;
  int          Id;
	BaseType_t xReturn = pdPASS;/* 定义一个创建信息返回值，默认为pdPASS */
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Framewin'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetTitleHeight(hItem, 32);
    FRAMEWIN_SetText(hItem, "                                      \xE5\x90\x8C\xE8\xBD\xB4\xE7\x94\xB5\xE7\xBC\x86\xE9\x95\xBF\xE5\xBA\xA6\xE4\xB8\x8E\xE8\xB4\x9F\xE8\xBD\xBD\xE6\xA3\x80\xE6\xB5\x8B\xE8\xA3\x85\xE7\xBD\xAE");
    FRAMEWIN_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI32);
    //
    // Initialization of 'Image_0'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_0);
    IMAGE_SetBitmap(hItem, &bmimage);
	  //
	  // Initialization of 'Image_1'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_1);
    IMAGE_SetBitmap(hItem, &bmimage1);
	  //
    // Initialization of '长度检测'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
	  BUTTON_SetText(hItem, "\xE9\x95\xBF\xE5\xBA\xA6\xE6\xA3\x80\xE6\xB5\x8B");
	  BUTTON_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
	  //
    // Initialization of '负载检测'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
	  BUTTON_SetText(hItem, "\xE8\xB4\x9F\xE8\xBD\xBD\xE6\xA3\x80\xE6\xB5\x8B");
	  BUTTON_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
    //
    // Initialization of '工作状态'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "\xE5\xB7\xA5\xE4\xBD\x9C\xE7\x8A\xB6\xE6\x80\x81:");
		TEXT_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
		TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER);
    //
    // Initialization of '设备就绪'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetText(hItem, "\xE8\xAE\xBE\xE5\xA4\x87\xE5\xB0\xB1\xE7\xBB\xAA");
		TEXT_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
		TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER);
    //
    // Initialization of '线缆长度'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetText(hItem, "\xE7\xBA\xBF\xE7\xBC\x86\xE9\x95\xBF\xE5\xBA\xA6:");
		TEXT_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
		TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER);
    //
    // Initialization of '？？？？'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
    TEXT_SetText(hItem, "");
		TEXT_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
		TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER);
    //
    // Initialization of '负载类型'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
    TEXT_SetText(hItem, "\xE8\xB4\x9F\xE8\xBD\xBD\xE7\xB1\xBB\xE5\x9E\x8B:");
		TEXT_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
		TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER);
    //
    // Initialization of '\xE7\x94\xB5\xE9\x98\xBB（电阻）\xE7\x94\xB5\xE5\xAE\xB9（电容）\xE5\xBC\x80\xE8\xB7\xAF(开路)'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
    TEXT_SetText(hItem, "");
		TEXT_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
		TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER);
    //
    // Initialization of '负载参数'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);
    TEXT_SetText(hItem, "\xE8\xB4\x9F\xE8\xBD\xBD\xE5\x8F\x82\xE6\x95\xB0:");
		TEXT_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
		TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER);
    //
    // Initialization of '？？？？'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
    TEXT_SetText(hItem, "");
		TEXT_SetFont(hItem, &GUI_FontMicrosoftJhengHeiUI20);
		TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by '长度检测'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
			      xReturn = xSemaphoreGive( BinarySem_Handle_L );//给出二值信号量
      if( xReturn == pdTRUE )
        printf("BinarySem_Handle_L二值信号量释放成功!\r\n");
      else
        printf("BinarySem_Handle_L二值信号量释放失败!\r\n");
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by '负载检测'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
			xReturn = xSemaphoreGive( BinarySem_Handle_R );//给出二值信号量
      if( xReturn == pdTRUE )
        printf("BinarySem_Handle_R二值信号量释放成功!\r\n");
      else
        printf("BinarySem_Handle_R二值信号量释放失败!\r\n");
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
   
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
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
/*********************************************************************
*
*       CreateFramewin
*/
WM_HWIN CreateFramewin(void);
WM_HWIN CreateFramewin(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
void MainTask(void)
{
	GUI_UC_SetEncodeUTF8();
  hFrame = CreateFramewin(); 
  
	while(1)
	{

		GUI_Delay(100);
	}
}
// USER END
/*************************** End of file ****************************/
