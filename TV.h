#pragma once
#ifndef __TV_H__
#define __TV_H__



#include <iostream>
#include<cstring>

using namespace std;

class TV
{
private:
	int m_channel;		//ä��
	int m_volume;		//����
	int m_bright;		//ȭ�� ���
	int m_prevol;		//���� ���� ���
	int m_input;		//�޴� �Է�
	bool m_isSoundOff;	//���Ұ�
	bool m_isPowerOn;	//���� 
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