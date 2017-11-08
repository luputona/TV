#pragma once
#ifndef __TV_H__
#define __TV_H__



#include <iostream>
#include<cstring>

using namespace std;

class TV
{
private:
	int m_channel;		//채널
	int m_volume;		//볼륨
	int m_bright;		//화면 밝기
	int m_prevol;		//이전 볼륨 백업
	int m_input;		//메뉴 입력
	bool m_isSoundOff;	//음소거
	bool m_isPowerOn;	//전원 
	char *m_pName;
public:
	TV(int channel);
	~TV();

	void SetName(char *pName);
	void Power(bool isPowerOn);
	void Channel(bool isUp);
	void SetInputChannelNum(int num);
	void Volume(int vol);
	void Bright(int bright);
	void SoundOff();
	void SoundOn();
	
	void InputMenu();
	void ShowMenu();
	void ShowSelectMenu();
	void ShowPowerOffMenu();

	
	bool GetPower();
};
#endif // !__TV_H__