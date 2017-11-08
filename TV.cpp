#include"TV.h"
#include<iostream>
#include<cstring>
#include<Windows.h>
using namespace std;


TV::TV(int channel) :
	m_channel(channel)
{
	//m_channel = channel;
}
TV::~TV()
{
	delete[] m_pName;
}
void TV::ShowMenu()
{
	cout << "\t\t\t\t" << m_pName <<"메뉴 안내" << endl << endl;
	cout << "\t\t1.전원 On\t" << "2.채널 변경\t" << endl;
	cout << "\t\t3.볼륨 조절\t" << "4.밝기 조정\t" << endl<<endl;

	cout << "=======================================================================\n\n";
	cout << "\t\t현재 상태" << endl;
	cout << "\t\t전원 : "<<(m_isPowerOn == true ? "On" : "Off");	
	cout << "\t\t볼륨 상태 : " << (m_volume <= 0? "Off" : "On"); 
	cout << endl;
	cout << "\t\t현재 채널 : " << m_channel << endl;
	cout << "\t\t현재 볼륨 크기 : " << m_volume << "\t화면 밝기 : " << m_bright << endl;
	cout << "=======================================================================\n\n";
	
	
}
void TV::ShowSelectMenu()
{
	cout << "\t\t원하시는 메뉴를 입력하세요" << endl;
}

void TV::InputMenu()
{
	
	cin >> m_input;
	
	//system("PAUSE");
	if (m_input == 1)
	{
		if (m_isPowerOn)
		{
			cout << "\t\tTV전원을" <<(m_isPowerOn == true ? "Off" : "On") << "합니다" << endl << endl;
			m_isPowerOn = false;
			Sleep(2000);
			system("cls");
			ShowMenu();
			cout << "\t\tTV전원을" << (m_isPowerOn == true ? "On" : "Off") << "합니다" << endl << endl;
			exit(1);
						
		}
		else if(!m_isPowerOn)
		{
			cout << "\t\tTV전원을" << (m_isPowerOn == true ? "Off" : "On") << "합니다" << endl << endl;
			m_isPowerOn = true;
			Sleep(2000);
			system("cls");
		}
	}
	else if (m_input == 2)
	{
		cout << "원하시는 채널 번호를 입력 하세요. : "; cin >> m_input;
		SetInputChannelNum(m_input);
		cout << m_input << "번 채널로 변경 합니다." << endl;
		Sleep(3000);
		system("cls");		
	}
	else if (m_input == 3)
	{		
		cout << "원하시는 볼륨을 입력 하세요. : "; cin >> m_input;
		Volume(m_input);
		cout << "볼륨을 " << m_volume << "으로 변경 합니다." <<endl;		
		Sleep(3000);
		system("cls");
	}
	else if (m_input == 4)
	{
		cout << "원하시는 화면 밝기를 입력 하세요. : "; cin >> m_input;
		Bright(m_input);
		cout << "화면 밝기를 " << m_bright << "으로 변경 합니다." << endl;
		Sleep(3000);
		system("cls");
	}
	else if (m_input)
	{
		cout << "잘못 입력 하셨습니다. 다시 입력해 주세요." << endl;
		Sleep(3000);
		system("cls");
	}


}
void TV::ShowPowerOffMenu()
{	
	cout << "=======================================================================\n\n";
	cout << "\t\t현재 상태" << endl;
	cout << "\t\t전원 : " << (m_isPowerOn == true ? "On" : "Off");
	cout << endl;
	cout << "=======================================================================\n\n";	
	
	cout << "\t\tTV 를 키려면 1을 입력 하세요." << endl;

}

void TV::SetName(char *pName)
{
	int len = strlen(pName) + 1;
	m_pName = new char[len];
	strcpy_s(m_pName, len, pName);
}
void TV::Power(bool isPowerOn)
{
	m_isPowerOn = isPowerOn;
}
void TV::SetInputChannelNum(int num)
{
	m_channel = num;
}
void TV::Channel(bool isUp)
{
	if (isUp)
	{
		m_channel++;
	}
	else
	{
		m_channel--;
	}
}
void TV::Volume(int vol)
{
	m_volume = vol;
}
void TV::Bright(int bright)
{
	m_bright = bright;
}
void TV::SoundOff()
{
	m_prevol = m_volume;
	m_volume = 0;
}
void TV::SoundOn()
{
	m_volume = m_prevol;
}
bool TV::GetPower()
{
	return m_isPowerOn;
}
void main()
{
	int nInput = 0;

	TV tv(7);
	tv.Power(false);
	tv.Volume(15);
	tv.SetName("삼성파브");
	tv.SoundOff();
	tv.SoundOn();
	tv.Bright(30);


	if(!tv.GetPower())
	{
		tv.ShowPowerOffMenu();
		tv.InputMenu();
	}
	while (tv.GetPower())
	{
		tv.ShowMenu();
		tv.ShowSelectMenu();
		tv.InputMenu();
	}
	

}