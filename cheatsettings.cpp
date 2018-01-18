#include "cheatsettings.h"

CheatSettings::CheatSettings()
{
	setting[0].code = "ASPIRINE";
	setting[0].info = "血量全滿";
	setting[1].code = "PRECIOUSPROTECTION";
	setting[1].info = "裝甲全滿";
	setting[2].code = "YOUWONTTAKEMEALIVE";
	setting[2].info = "提昇追捕等級";
	setting[3].code = "LEAVEMEALONE";
	setting[3].info = "降低追捕等級";
	setting[4].code = "THUGSTOOLS";
	setting[4].info = "獲得輕型武器";
	setting[5].code = "PROFESSIONALTOOLS";
	setting[5].info = "獲得中型武器";
	setting[6].code = "NUTTERTOOLS";
	setting[6].info = "獲得重型武器";
	setting[7].code = "SEAWAYS";
	setting[7].info = "車輛可水上行走";
	setting[8].code = "BIGBANG";
	setting[8].info = "炸掉週邊車輛";
	setting[9].code = "COMEFLYWITHME";
	setting[9].info = "Cars can fly";
	setting[10].code = "GRIPISEVERYTHING";
	setting[10].info = "Perfect Handling";
	setting[11].code = "BETTERTHANWALKING";
	setting[11].info = "變出高爾夫球車Caddie";
	setting[12].code = "RUBBISHCAR";
	setting[12].info = "變出垃圾車Trashmaster";
	setting[13].code = "ROCKANDROLLCAR";
	setting[13].info = "變出Love Fist's Limo";
	setting[14].code = "THELASTRIDE";
	setting[14].info = "變出Romero's Hearse";
	setting[15].code = "GETTHEREVERYFASTINDEED";
	setting[15].info = "變出Hotring Racer";
	setting[16].code = "GETTHEREAMAZINGLYFAST";
	setting[16].info = "變出Hotring Racer #2";
	setting[17].code = "GETTHEREFAST";
	setting[17].info = "變出Sabre Turbo";
	setting[18].code = "TRAVELINSTYLE";
	setting[18].info = "變出Bloodring Banger";
	setting[19].code = "GETTHEREQUICKLY";
	setting[19].info = "變出Bloodring Banger #2";
	setting[20].code = "PANZER";
	setting[20].info = "變出戰車";
	setting[21].code = "STILLLIKEDRESSINGUP";
	setting[21].info = "更換衣服";
	setting[22].code = "DEEPFRIEDMARSBARS";
	setting[22].info = "Makes Tommy fatter";
}

char *CheatSettings::getCheatSetting(int arg)
{
	return setting[data[arg]].code;
}
