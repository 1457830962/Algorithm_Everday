#include<iostream>
#include<Windows.h>
#include <time.h>
#include <ATLComTime.h>

#include "shlobj.h"

#pragma warning(disable:4996)
using namespace std;

#define CSIDL_APPDATA                   0x001a        // <user name>\Application Data

#define ID_TIMER 0
#define PASSTYPE_IDEA	"enc3"
enum MAILOSVER
{
	OSVER_NONE = 0,//未定义
	OSVER_WINNT4,//winnt 4.0
	OSVER_WIN95,//win95
	OSVER_WIN98,//win98    
	OSVER_WINME,//winme
	OSVER_WIN2000,//win2000
	OSVER_WINXP,//winxp
	OSVER_WINXP_X64,//winxp x64
	OSVER_WIN2003,//win2003
	OSVER_WIN2003R2,//win2003 r2
	OSVER_VISTA,// vista
	OSVER_WIN2008,// win2008
	OSVER_WIN2008R2,// win2008 r2
	OSVER_WIN7,// win7
	OSVER_WIN2012,// win2012
	OSVER_WIN8,// win8
	OSVER_WIN2012R2,// win2012 r2
	OSVER_WIN81,// win8.1
	OSVER_WIN2016,// win2016
	OSVER_WIN10,// win10
};

MAILOSVER GetOSVersionNtdll();
CString GetOSVersionNew();
void CALLBACK printSTR(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTimer);
//获取今天的零点时间戳（注意time_t同unsigned int,可以通过直接比较大小来判断时间先后）
time_t getMorningTime();
time_t getCurrentTime();
CString GetMacAddress();
void InitLogging();
void CreateDirectoryIfNotExist(const std::wstring& wstrDirectory);
std::wstring GetLogDirectory();

typedef struct _ASTAT
{
	ADAPTER_STATUS   adapt;
	NAME_BUFFER      NameBuffer[30];
}ASTAT, *PASTAT;


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
	//time_t tCurrentTime = getCurrentTime();
	//cout << "当前时间：" << tCurrentTime << endl;
	//time_t tMorningTime = getMorningTime();
	//cout << "零点时间：" << tMorningTime << endl;
	/*---------------------------------------------------------------*/
	/*============================================================*/
	//CString cstrVerOs1 = GetOSVersionNew();
	/*------------------------------------------------------------*/

	/*============================================================*/
	//CString cstrMac = GetMacAddress();
	//cout << "当前电脑MAC地址：" << cstrMac << endl;
	/*------------------------------------------------------------*/

	std::string strEncPass = "{""enc3""}";
	std::string strEncPass1 = '{'+ PASSTYPE_IDEA +'}';

	std::string strXML = "<?xml version=\"";

	strXML += "\" ?>\r\n";
	InitLogging();

	system("pause");
	return 0;
}

BOOL GetNtVersionNumbers(DWORD&dwMajorVer, DWORD& dwMinorVer, DWORD& dwBuildNumber)
{
	BOOL bRet = FALSE;
	HMODULE hModNtdll = NULL;
	if (hModNtdll = ::LoadLibraryW(L"ntdll.dll"))
	{
		typedef void (WINAPI *pfRTLGETNTVERSIONNUMBERS)(DWORD*, DWORD*, DWORD*);
		pfRTLGETNTVERSIONNUMBERS pfRtlGetNtVersionNumbers = (pfRTLGETNTVERSIONNUMBERS)::GetProcAddress(hModNtdll, "RtlGetNtVersionNumbers");
		if (pfRtlGetNtVersionNumbers)
		{
			pfRtlGetNtVersionNumbers(&dwMajorVer, &dwMinorVer, &dwBuildNumber);
			dwBuildNumber &= 0x0ffff;
			bRet = TRUE;
		}

		::FreeLibrary(hModNtdll);
		hModNtdll = NULL;
	}
	return bRet;
}

CString GetOSVersionNew()
{
	CString csRet;
	MAILOSVER ver = GetOSVersionNtdll();
	if (ver == OSVER_NONE)
	{
		csRet = _T("操作系统未知");
	}
	else if (ver == OSVER_WIN10)
	{
		csRet = _T("Windows 10");
	}
	else if (ver == OSVER_WIN2016)
	{
		csRet = _T("Windows Server 2016");
	}
	else if (ver == OSVER_WIN81)
	{
		csRet = _T("Windows 8.1");
	}
	else if (ver == OSVER_WIN2012R2)
	{
		csRet = _T("Windows Server 2012 R2");
	}
	else if (ver == OSVER_WIN8)
	{
		csRet = _T("Windows 8");
	}
	else if (ver == OSVER_WIN2012)
	{
		csRet = _T("Windows Server 2012");
	}
	else if (ver == OSVER_WIN7)
	{
		csRet = _T("Windows 7");
	}
	else if (ver == OSVER_WIN2008R2)
	{
		csRet = _T("Windows Server 2008 R2");
	}
	else if (ver == OSVER_VISTA)
	{
		csRet = _T("Windows Vista");
	}
	else if (ver == OSVER_WIN2008)
	{
		csRet = _T("Windows Server 2008");
	}
	else if (ver == OSVER_WINXP_X64)
	{
		csRet = _T("Windows XP 64位");
	}
	else if (ver == OSVER_WIN2003)
	{
		csRet = _T("Windows Server 2003");
	}
	else if (ver == OSVER_WINXP)
	{
		csRet = _T("Windows XP");
	}

	return csRet;
}

MAILOSVER GetOSVersionNtdll()
{
	DWORD nMajorVer, nMinorVer, nBuildNum;
	GetNtVersionNumbers(nMajorVer, nMinorVer, nBuildNum);

	MAILOSVER ver = OSVER_NONE;
	switch (nMajorVer)
	{
	case 10:
	{
		switch (nMinorVer)
		{
		case 0:
			ver = OSVER_WIN10;
			break;
		default:
			break;
		}
	}
	break;
	case 6:
	{
		switch (nMinorVer)
		{
		case 3:
		{
			ver = OSVER_WIN81;
		}
		break;
		case 2:
		{
			ver = OSVER_WIN8;
		}
		break;
		case 1:
		{
			ver = OSVER_WIN7;
		}
		break;
		case 0:
		{
			ver = OSVER_VISTA;
		}
		break;
		default:
			break;
		}
	}
	break;
	case 5:
	{
		switch (nMinorVer)
		{
		case 2:
		{
			ver = OSVER_WINXP;
		}
		break;
		case 1:
		{
			ver = OSVER_WINXP;
		}
		break;
		case 0:
		{
			ver = OSVER_WIN2000;
		}
		break;
		default:
			break;
		}
	}
	break;
	}

	return ver;
}

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

CString GetMacAddress(){
	CString sMacNumber;
	sMacNumber = _T("unknowuser00");
	ASTAT Adapter;
	NCB Ncb;
	UCHAR   uRetCode;
	//char   NetName[50];   
	LANA_ENUM lenum;
	int i;
	memset(&Ncb, 0, sizeof(Ncb));
	Ncb.ncb_command = NCBENUM;
	Ncb.ncb_buffer = (UCHAR   *)&lenum;
	Ncb.ncb_length = sizeof(lenum);
	uRetCode = Netbios(&Ncb);
	for (i = 0; i < lenum.length; i++)
	{ 
		memset(&Ncb, 0, sizeof(Ncb));
		Ncb.ncb_command = NCBRESET;
		Ncb.ncb_lana_num = lenum.lana[i];
		uRetCode = Netbios(&Ncb);
		memset(&Ncb, 0, sizeof(Ncb));
		Ncb.ncb_command = NCBASTAT;
		Ncb.ncb_lana_num = lenum.lana[i];
		strcpy((char   *)Ncb.ncb_callname, "*                               ");
		Ncb.ncb_buffer = (unsigned   char   *)&Adapter;
		Ncb.ncb_length = sizeof(Adapter);
		uRetCode = Netbios(&Ncb);
		if (uRetCode == 0)
		{
			if (Adapter.adapt.adapter_address[0] +
				Adapter.adapt.adapter_address[1] +
				Adapter.adapt.adapter_address[2] +
				Adapter.adapt.adapter_address[3] +
				Adapter.adapt.adapter_address[4] +
				Adapter.adapt.adapter_address[5] != 0)
			{
				sMacNumber.Format(_T("%02x-%02x-%02x-%02x-%02x-%02x"),
					Adapter.adapt.adapter_address[0],
					Adapter.adapt.adapter_address[1],
					Adapter.adapt.adapter_address[2],
					Adapter.adapt.adapter_address[3],
					Adapter.adapt.adapter_address[4],
					Adapter.adapt.adapter_address[5]);
				break;
			}
		}
	}
	return sMacNumber;
}

std::wstring GetAPPDataPath()
{
	ITEMIDLIST* pidl;
	HRESULT hr = SHGetSpecialFolderLocation(NULL, CSIDL_APPDATA | CSIDL_FLAG_CREATE, &pidl);
	if (FAILED(hr))
		return std::wstring();

	TCHAR wstrPath[MAX_PATH] = { 0 };
	if (!SHGetPathFromIDList(pidl, wstrPath))
		return std::wstring();

	return std::wstring(wstrPath);
}

std::wstring GetLogDirectory()
{

	std::wstring wstr = GetAPPDataPath() + L"\\Coremail\\Outlook Addins\\PSTImplLog";

	//Log(true, LOG_DEBUG, _T("GetCoremailPSTFilePath, %s\n"), wstr.c_str());

	return wstr;
}

void InitLogging()
{
	std::wstring wstrLogDirectory = GetLogDirectory();
	CreateDirectoryIfNotExist(wstrLogDirectory);
}

void CreateDirectoryIfNotExist(const std::wstring& wstrDirectory)
{
	CreateDirectory(wstrDirectory.c_str(), NULL);
}