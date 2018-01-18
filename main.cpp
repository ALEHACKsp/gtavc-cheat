
/**
 * GTAVC Cheat Tool.
 * @author Roy Lu(royvbtw)
 * @date 20130324
 *
*/
#include "widget.h"
#include "cheatsettings.h"
#include <Windows.h>
#include <QThread>
#include <QApplication>
#include <iostream>
using namespace std;

HHOOK g_hKeyboard;
CheatSettings *settings = new CheatSettings();

void sendText(const char *text){
	//cout << "sendKey=" << text << endl;
	KEYBDINPUT kb = {0};
	INPUT input = {0};	//a structure represents an event to be inserted into the keyboard input stream.

	for(unsigned int i = 0; i < strlen(text); ++i){
		input.type = INPUT_KEYBOARD;
		input.ki = kb;

		//cout << "out=" << (int)text[i] << " ";
		input.ki.wVk = (int)text[i];
		input.ki.dwFlags = 0;
		SendInput(1, &input, sizeof(INPUT));	//SendInput() defined in winuser.h

		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT));
	}
}

//hook procedure
//LPARAM lParam: A pointer to a KBDLLHOOKSTRUCT structure.
//PKBDLLHOOKSTRUCT: Defined in winuser.h
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0){
		switch(wParam){
		case WM_KEYUP:
			PKBDLLHOOKSTRUCT pKB = (PKBDLLHOOKSTRUCT) lParam;
			//cout << pKB->vkCode << endl;		//pressed key
			switch(pKB->vkCode){
			case 0x31:
			case VK_NUMPAD1:
				sendText(settings->getCheatSetting(1));
				break;
			case 0x32:
			case VK_NUMPAD2:
				sendText(settings->getCheatSetting(2));
				break;
			case 0x33:
			case VK_NUMPAD3:
				sendText(settings->getCheatSetting(3));
				break;
			case 0x34:
			case VK_NUMPAD4:
				sendText(settings->getCheatSetting(4));
				break;
			case 0x35:
			case VK_NUMPAD5:
				sendText(settings->getCheatSetting(5));
				break;
			case 0x36:
			case VK_NUMPAD6:
				sendText(settings->getCheatSetting(6));
				break;
			case 0x37:
			case VK_NUMPAD7:
				sendText(settings->getCheatSetting(7));
				break;
			case 0x38:
			case VK_NUMPAD8:
				sendText(settings->getCheatSetting(8));
				break;
			case 0x39:
			case VK_NUMPAD9:
				sendText(settings->getCheatSetting(9));
				break;
			case 0x30:
			case VK_NUMPAD0:
				sendText(settings->getCheatSetting(0));
				break;
			}
			break;
		}
	}
	return CallNextHookEx(g_hKeyboard, nCode, wParam, lParam);
}

void hookProcess(){
	//set window hook
	//WH_KEYBOARD_LL: type of hook procedure.
	//LowLevelKeyboardProc: hook procedure.
	g_hKeyboard = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(NULL), 0 );
	if(!g_hKeyboard) printf("Hook error: %d\n", GetLastError());

	//cout << "hookProcess() end" << endl;
	//把unhook之工作放到widget之解構式中
}



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	hookProcess();
	Widget w;

	w.setHHOOK(g_hKeyboard);
	w.setCheatSettings(settings);
	w.init();
	w.show();

	cout << "end of main()" << endl;
	return a.exec();
}


