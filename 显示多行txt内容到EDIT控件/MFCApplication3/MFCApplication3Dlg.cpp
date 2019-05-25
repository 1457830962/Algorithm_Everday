
// MFCApplication3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"

#include <locale>
#include <vector>
#include <string>
#include <codecvt>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 对话框



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication3Dlg::IDD, pParent)
	, m_strEDIT1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strEDIT1);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication3Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication3Dlg::OnBnClickedOk()
{


	//int* pNum = NULL;	 // Store index data.
	//float* pWave = NULL; // Store wave data.
	//float* pVal = NULL;  // Store val data.
	//CStdioFile file;
	//if (file.Open(_T(".\\example.txt"), CFile::modeRead | CFile::typeText))
	//{
	//	CString strLine;
	//	int iCount = -2;

	//	// Get line count.
	//	while (file.ReadString(strLine))
	//		iCount++;

	//	// Ensure at least 3 lines in file.
	//	if (iCount <= 0)
	//	{
	//		file.Close();
	//		return;
	//	}

	//	// Allocate enough memory.
	//	pNum = new int[iCount];
	//	pWave = new float[iCount];
	//	pVal = new float[iCount];

	//	file.SeekToBegin();
	//	// Ignore prefix lines.
	//	file.ReadString(strLine);
	//	file.ReadString(strLine);

	//	int iIndex = 0;				// Current index of valid data line.
	//	CString strSub;				// Current line.
	//	char lpszLine[128] = { 0 };   // Temp buffer for division.
	//	while (file.ReadString(strLine))
	//	{
	//		memset(lpszLine, 0, sizeof(lpszLine));
	//		strcpy(lpszLine, (LPCSTR)(LPCTSTR)strLine);
	//		int iSubIndex = 0;
	//		char* p = strtok(lpszLine, " ");
	//		while (p != NULL)
	//		{
	//			pNum[iIndex] = atoi(p);  p = strtok(NULL, " ");
	//			pWave[iIndex] = atof(p); p = strtok(NULL, " ");
	//			pVal[iIndex] = atof(p);  p = strtok(NULL, " ");
	//		}
	//		iIndex++;
	//	}
	//	file.Close();

	//	// Print array /////////////////////////////////////
	//	int iPrintIndex = 0;
	//	CString strPrint;
	//	while (iPrintIndex < iCount)
	//	{
	//		CString strTemp;
	//		strTemp.Format("num:%d wave:%.1f val:%.1f\n", pNum[iPrintIndex], pWave[iPrintIndex], pVal[iPrintIndex]);
	//		strPrint += strTemp;
	//		iPrintIndex++;
	//	}
	//	AfxMessageBox(strPrint);
	//	////////////////////////////////////////////////////


	//std::vector<CString> datalist;
	//CString str;
	//string msg;
	//char s[80];
	//ifstream infile;
	//infile.open(_T(".\\example.txt"), ios::in);
	//while (!infile.eof()){//文件没有结束则继续读取.
	//	infile.getline(s, 80);

	//	msg = UTF8ToGB(s);

	//	str = msg.c_str();
	//	datalist.push_back(str);
	//	
	//}
	//infile.close();
	//SetDlgItemText(IDC_EDIT1, datalist);
	//SetDlgItemText(IDC_EDIT1, str);
	//file.Close();

	CString strLine, strTemp, result;
	int row = 0;
	CString filename = _T(".\\example.txt");
	CStdioFile file(filename, CFile::modeRead);
	string msg;

	while (file.ReadString(strLine))
	{
		//char *str = strLine.GetBufferSetLength(strLine.GetLength());
		char *str = (char *)strLine.GetBufferSetLength(strLine.GetLength());
		//char *p;
		if (strLine != "")
		{
			result += _T("\r\n") + strLine;
			//result += strLine;		
			msg = utf8_to_gb2312(result.GetBuffer());
			GetDlgItem(IDC_EDIT1)->SetWindowText(msg.c_str());		
			GetDlgItem(IDC_EDIT1)->UpdateWindow();
			//result = " ";
			row++;
		}
	}
	file.Close();
	

	/************************************************************************/
	/* 功能：显示单行                                                                     */
	/************************************************************************/
	/*char txt[100];
	string msg;
	ifstream infile;
	CString str;
	infile.open(".\\example.txt");
	if (!infile.is_open())
	{
	cout << "" << endl;
	exit(0);
	}
	while (!infile.eof())
	{
	infile.getline(txt, 100);
	msg = UTF8ToGB(txt);
	str = msg.c_str();
	cout << msg << endl;
	SetDlgItemText(IDC_EDIT1, str);
	}
	infile.close();*/


}
void CMFCApplication3Dlg::readTxt(string file)
{
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());
	string s;
	while (getline(infile, s))
	{
		cout << s << endl;
	}
	infile.close();
}

string CMFCApplication3Dlg::UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);
	result = szRes;
	delete[]strSrc;
	delete[]szRes;
	return result;
}


string CMFCApplication3Dlg::utf8_to_gb2312(std::string const &strUtf8)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
	std::wstring wTemp = cutf8.from_bytes(strUtf8);
#ifdef _MSC_VER
	std::locale loc("zh-CN");
#else
	std::locale loc("zh_CN.GB18030");
#endif
	const wchar_t* pwszNext = nullptr;
	char* pszNext = nullptr;
	mbstate_t state = {};

	std::vector<char> buff(wTemp.size() * 2);
	int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t> >
		(loc).out(state,
		wTemp.data(), wTemp.data() + wTemp.size(), pwszNext,
		buff.data(), buff.data() + buff.size(), pszNext);

	if (std::codecvt_base::ok == res)
	{
		return std::string(buff.data(), pszNext);
	}
	return "";
}