#pragma once


// CStarDlg dialog

class CStarDlg : public CDialog
{
	DECLARE_DYNAMIC(CStarDlg)

public:
	CStarDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStarDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_xcen;
	double m_ycen;
	double m_len;
	double m_rot;
};
