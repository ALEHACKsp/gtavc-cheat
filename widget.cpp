#include "widget.h"

Widget::Widget(QWidget *parent):
	QWidget(parent)
{}

Widget::~Widget()
{
	cout << "~Widget" << endl;
	//unhook
	UnhookWindowsHookEx(g_hKeyboard);

	delete [] labelText;
	delete [] cbCheatSettings;
	delete labelInfo;
	delete labelCaption0;
	delete labelCaption1;
	delete labelAbout;
	delete layout;
	delete cheatSettings;
}

void Widget::init()
{
	setWindowTitle("GTA Vice City Cheat Tool.");
	setFixedSize(350, 340);

	layout = new QGridLayout();
	labelInfo = new QLabel();
	labelInfo->setText(QString::fromLocal8Bit("按下下列數字鍵即可啟動密技."));
	layout->addWidget(labelInfo, 0, 0);

	labelCaption0 = new QLabel();
	labelCaption0->setText(QString::fromLocal8Bit("熱鍵"));
	layout->addWidget(labelCaption0, 1, 0);

	labelCaption1 = new QLabel();
	labelCaption1->setText(QString::fromLocal8Bit("對應功能"));
	layout->addWidget(labelCaption1, 1, 1);

	labelAbout = new QLabel();
	labelAbout->setText(QString::fromLocal8Bit("Roy Lu(royvbtw) 2013 TW"));
	layout->addWidget(labelAbout, 12, 1);

	labelText = new QLabel[10];
	cbCheatSettings = new QComboBox[10];

	mapper = new QSignalMapper(this);

	for(int i = 0; i < 10; ++i){
		//set label
		QString str = QString::fromLocal8Bit("數字鍵 ");
		str.append(QString::number(i));
		labelText[i].setText(str);

		//set combo box
		for(int j = 0; j < 23; ++j){
			(cbCheatSettings + i)->addItem(QString::fromLocal8Bit(cheatSettings->setting[j].info));
		}

		//set signal mapper with qcombobox
		connect(cbCheatSettings + i, SIGNAL(activated(int)), mapper, SLOT(map()));
		mapper->setMapping(cbCheatSettings + i, i);

		//add widgets to layout
		if(i == 0){
			layout->addWidget(labelText + i, 11, 0);
			layout->addWidget((cbCheatSettings + i), 11, 1);
		}else{
			layout->addWidget(labelText + i, i + 1, 0);
			layout->addWidget(cbCheatSettings + i, i + 1, 1);
		}
	}

	(cbCheatSettings + 1)->setCurrentIndex(0);
	(cbCheatSettings + 2)->setCurrentIndex(1);
	(cbCheatSettings + 3)->setCurrentIndex(3);
	(cbCheatSettings + 4)->setCurrentIndex(4);
	(cbCheatSettings + 5)->setCurrentIndex(5);
	(cbCheatSettings + 6)->setCurrentIndex(6);
	(cbCheatSettings + 7)->setCurrentIndex(16);
	(cbCheatSettings + 8)->setCurrentIndex(17);
	(cbCheatSettings + 9)->setCurrentIndex(18);
	(cbCheatSettings + 0)->setCurrentIndex(19);
	for(int i = 0; i < 10; ++i){
		saveSetting(i);
	}

	connect(mapper, SIGNAL(mapped(int)), this, SLOT(saveSetting(int)));

	setLayout(layout);
}

void Widget::setHHOOK(HHOOK arg)
{
	g_hKeyboard = arg;
}

void Widget::setCheatSettings(CheatSettings *arg)
{
	cheatSettings = arg;
}

/**
 * @brief Widget::saveSetting 當combo box變換時會呼叫此method來設定cheatSetting之data value
 *		main.cpp中的hook precedure會根據CheatSetting.data來做key mapping.
 *		此method是用signal mapper將combo box的signal都轉來這裡
 * @param arg
 */
void Widget::saveSetting(int arg)
{
	cout << "#" << arg << " setting processing." << endl;
	cout << "index is " << (cbCheatSettings + arg)->currentIndex() << endl;

	cheatSettings->data[arg] = (cbCheatSettings + arg)->currentIndex();
	cout << "info is " << cheatSettings->setting[cheatSettings->data[arg]].info << endl;
	//dataValue[arg] = (cbCheatSettings + arg)->currentIndex();

}
