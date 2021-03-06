// StarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Step1.h"
#include "StarDlg.h"
#include "afxdialogex.h"


// CStarDlg dialog

IMPLEMENT_DYNAMIC(CStarDlg, CDialog)

CStarDlg::CStarDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STAR, pParent)
	, m_xcen(0)
	, m_ycen(0)
	, m_len(0)
	, m_rot(0)
{

}

CStarDlg::~CStarDlg()
{
}

void CStarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_XCEN, m_xcen);
	DDX_Text(pDX, IDC_YCEN, m_ycen);
	DDX_Text(pDX, IDC_LEN, m_len);
	DDX_Text(pDX, IDC_ROT, m_rot);
}


BEGIN_MESSAGE_MAP(CStarDlg, CDialog)
END_MESSAGE_MAP()


// CStarDlg message handlers
