#include<iostream>
#include<Windows.h>
#include <time.h>
#include <ATLComTime.h>

#pragma warning(disable:4996)
using namespace std;

#define ID_TIMER 0
void CALLBACK printSTR(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTimer)
{
	cout << "hello world!\n";
}

//��ȡ��������ʱ�����ע��time_tͬunsigned int,����ͨ��ֱ�ӱȽϴ�С���ж�ʱ���Ⱥ�
time_t getMorningTime()
{
	time_t t = time(NULL);
	struct tm * tm = localtime(&t);
	tm->tm_hour = 0;
	tm->tm_min = 0;
	tm->tm_sec = 0;
	return  mktime(tm);
}

time_t getCurrentTime()
{
	////COleDateTime ת time_t 
	COleDateTime m_dtLastUpateLoginTime = COleDateTime::GetCurrentTime();
	time_t tLastUpateLoginTime;
	SYSTEMTIME systime;
	m_dtLastUpateLoginTime.GetAsSystemTime(systime);
	CTime cctime(systime);
	tLastUpateLoginTime = cctime.GetTime();
	return tLastUpateLoginTime;
}

int main()
{
	/*===============================================================*/
	////����̨�����ж�ʱ��ʵ��
	//int iId;
	//MSG msg;
	//iId = SetTimer(NULL, ID_TIMER, 1000, printSTR);
	//while (GetMessage(&msg, NULL, 0, 0))
	//{
	//	DispatchMessage(&msg);
	//}
	//KillTimer(NULL, iId);
	/*---------------------------------------------------------------*/

	/*===============================================================*/	
	time_t tCurrentTime = getCurrentTime();
	cout << "��ǰʱ�䣺" << tCurrentTime << endl;
	time_t tMorningTime = getMorningTime();
	cout << "���ʱ�䣺" << tMorningTime << endl;
	/*---------------------------------------------------------------*/
	system("pause");
	return 0;
}