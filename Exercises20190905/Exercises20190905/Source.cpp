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

//获取今天的零点时间戳（注意time_t同unsigned int,可以通过直接比较大小来判断时间先后）
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
	////COleDateTime 转 time_t 
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
	////控制台工程中定时器实现
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
	cout << "当前时间：" << tCurrentTime << endl;
	time_t tMorningTime = getMorningTime();
	cout << "零点时间：" << tMorningTime << endl;
	/*---------------------------------------------------------------*/
	system("pause");
	return 0;
}