
// MFCApplication3Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


// CMFCApplication3Dlg �Ի���



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


// CMFCApplication3Dlg ��Ϣ�������

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	//while (!infile.eof()){//�ļ�û�н����������ȡ.
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
	/* ���ܣ���ʾ����                                                                     */
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