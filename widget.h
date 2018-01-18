#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <iostream>
#include <string>
#include <Windows.h>
#include <QSignalMapper>
#include "cheatsettings.h"
using namespace std;



class Widget: public QWidget
{
	Q_OBJECT
private:
	QSignalMapper *mapper;
	QLabel *labelInfo;
	QLabel *labelText;
	QLabel *labelCaption0;
	QLabel *labelCaption1;
	QLabel *labelAbout;
	QGridLayout *layout;
	//HookProc *hookProc;
	HHOOK g_hKeyboard;
	QComboBox *cbCheatSettings;
	CheatSettings *cheatSettings;
public:
	Widget(QWidget *parent = 0);
	~Widget();
	void init();
	//void setHookProc(HookProc *arg);
	void setHHOOK(HHOOK arg);
	//return cheat code of specific combobox.
	void setCheatSettings(CheatSettings *arg);
public slots:
	void saveSetting(int arg);
};

#endif // WIDGET_H
