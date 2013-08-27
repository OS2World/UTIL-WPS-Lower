/* LOWER, written by Matthew Austern (matt@physics.berkeley.edu), 1993.
   This program is public domain.
*/

/* Very simple program that lowers whatever object the user clicks on.

   It grabs the mouse and changes the cursor to something recognizably
   different.  It doesn't let go until the user clicks the mouse somewhere;
   if the user clicks button 1, it uses WinSetWindowPos to lower that window,
   and if the user clicks any other button, the program quits without doing
   anything.  Either way, the program exits as soon as a mouse button is
   clicked.
*/

#define INCL_PM
#include <os2.h>

int main(void)
{
  HAB hab = WinInitialize(0);
  HMQ Queue = WinCreateMsgQueue (hab, 0);
  HPOINTER XPtr = WinLoadPointer(HWND_DESKTOP, 0, 2);
  
  if (!WinQuerySysValue(HWND_DESKTOP, SV_MOUSEPRESENT) ||
      !WinSetCapture(HWND_DESKTOP, HWND_THREADCAPTURE)) 
      WinMessageBox(HWND_DESKTOP, HWND_DESKTOP,	/* Notify the user. */
		    "Error: can't access the mouse.",
		    "Lower", 0, MB_ERROR | MB_OK | MB_MOVEABLE);
  else {
    QMSG Msg;
    WinSetPointer(HWND_DESKTOP, XPtr);
    while(WinGetMsg(hab, &Msg, 0, 0, 0)) {
      switch(Msg.msg) {
      case WM_BUTTON1DOWN: {
	POINTL thePosition;
	HWND theWin = HWND_DESKTOP;

	thePosition.x = SHORT1FROMMP(Msg.mp1);
	thePosition.y = SHORT2FROMMP(Msg.mp1);
	theWin = WinWindowFromPoint(HWND_DESKTOP, &thePosition, 0);
	if (theWin && theWin != HWND_DESKTOP)
	  WinSetWindowPos(theWin,
			  HWND_BOTTOM,
			  0, 0, 0, 0,
			  SWP_ZORDER | SWP_DEACTIVATE);
	goto EndLoop;
      }
      case WM_BUTTON2DOWN:
      case WM_BUTTON3DOWN:
	goto EndLoop;
      default:
	WinDispatchMsg(hab, &Msg);
      }
    }
  EndLoop:
    WinSetCapture(HWND_DESKTOP, 0);
  }

  WinDestroyMsgQueue(Queue);
  WinTerminate(hab);
  return 0;
}
		   
