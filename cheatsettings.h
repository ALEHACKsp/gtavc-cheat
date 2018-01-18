#ifndef CHEATSETTINGS_H
#define CHEATSETTINGS_H


class Setting{
public:
	char *code;
	char *info;
};


class CheatSettings
{
public:
	CheatSettings();

	Setting setting[23];	//setting負責儲存作弊密碼與說明
	int data[10];			//紀錄十組combobox之值, range: 0~22

	char* getCheatSetting(int arg);
};

#endif // CHEATSETTINGS_H
