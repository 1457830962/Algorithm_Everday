
// MFCApplication3Dlg.h : ͷ�ļ�
//

#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;
// CMFCApplication3Dlg �Ի���
class CMFCApplication3Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strEDIT1;
	afx_msg void OnBnClickedOk();
	void readTxt(string file);
    string UTF8ToGB(const char* str);
	string utf8_to_gb2312(std::string const &strUtf8);
};
