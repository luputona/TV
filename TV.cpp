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
	cout << "\t\t\t\t" << m_pName <<"�޴� �ȳ�" << endl << endl;
	cout << "\t\t1.���� On\t" << "2.ä�� ����\t" << endl;
	cout << "\t\t3.���� ����\t" << "4.��� ����\t" << endl<<endl;

	cout << "=======================================================================\n\n";
	cout << "\t\t���� ����" << endl;
	cout << "\t\t���� : "<<(m_isPowerOn == true ? "On" : "Off");	
	cout << "\t\t���� ���� : " << (m_volume <= 0? "Off" : "On"); 
	cout << endl;
	cout << "\t\t���� ä�� : " << m_channel << endl;
	cout << "\t\t���� ���� ũ�� : " << m_volume << "\tȭ�� ��� : " << m_bright << endl;
	cout << "=======================================================================\n\n";
	
	
}
void TV::ShowSelectMenu()
{
	cout << "\t\t���Ͻô� �޴��� �Է��ϼ���" << endl;
}

void TV::InputMenu()
{
	
	cin >> m_input;
	
	//system("PAUSE");
	if (m_input == 1)
	{
		if (m_isPowerOn)
		{
			cout << "\t\tTV������" <<(m_isPowerOn == true ? "Off" : "On") << "�մϴ�" << endl << endl;
			m_isPowerOn = false;
			Sleep(2000);
			system("cls");
			ShowMenu();
			cout << "\t\tTV������" << (m_isPowerOn == true ? "On" : "Off") << "�մϴ�" << endl << endl;
			exit(1);
						
		}
		else if(!m_isPowerOn)
		{
			cout << "\t\tTV������" << (m_isPowerOn == true ? "Off" : "On") << "�մϴ�" << endl << endl;
			m_isPowerOn = true;
			Sleep(2000);
			system("cls");
		}
	}
	else if (m_input == 2)
	{
		cout << "���Ͻô� ä�� ��ȣ�� �Է� �ϼ���. : "; cin >> m_input;
		SetInputChannelNum(m_input);
		cout << m_input << "�� ä�η� ���� �մϴ�." << endl;
		Sleep(3000);
		system("cls");		
	}
	else if (m_input == 3)
	{		
		cout << "���Ͻô� ������ �Է� �ϼ���. : "; cin >> m_input;
		Volume(m_input);
		cout << "������ " << m_volume << "���� ���� �մϴ�." <<endl;		
		Sleep(3000);
		system("cls");
	}
	else if (m_input == 4)
	{
		cout << "���Ͻô� ȭ�� ��⸦ �Է� �ϼ���. : "; cin >> m_input;
		Bright(m_input);
		cout << "ȭ�� ��⸦ " << m_bright << "���� ���� �մϴ�." << endl;
		Sleep(3000);
		system("cls");
	}
	else if (m_input)
	{
		cout << "�߸� �Է� �ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << endl;
		Sleep(3000);
		system("cls");
	}


}
void TV::ShowPowerOffMenu()
{	
	cout << "=======================================================================\n\n";
	cout << "\t\t���� ����" << endl;
	cout << "\t\t���� : " << (m_isPowerOn == true ? "On" : "Off");
	cout << endl;
	cout << "=======================================================================\n\n";	
	
	cout << "\t\tTV �� Ű���� 1�� �Է� �ϼ���." << endl;

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
	tv.SetName("�Ｚ�ĺ�");
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