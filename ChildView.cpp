
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Step1.h"
#include "ChildView.h"
#include "StarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView
CChildView::CChildView()
{
	m_linefmx = 0.5;
	m_linefmy = 0.5;
	m_linetox = 0.2;
	m_linetoy = 0.55;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
	ON_COMMAND(ID_STEPSTUFF_LINEDIALOG, &CChildView::OnStepstuffLinedialog)
	ON_COMMAND(ID_STEPSTUFF_STAR, &CChildView::OnStepstuffStar)
	ON_COMMAND(ID_STEPSTUFF_ROTATE25DEGREES, &CChildView::OnStepstuffRotate25degrees)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}



void CChildView::OnGLDraw(CDC * pDC)
{
	///Offsets for rectangle
	m_offset = (m_len / 2);
	double hght_fac = 1.1;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// TODO: Add your implementation code here.
	// Simple rectangle example
	int width, height;
	GetSize(width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, // left
		1.0, // right
		0.0, // bottom
		GLdouble(height) / GLdouble(width), // top
		1.0, // near
		-1.0); // far

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	
	glBegin(GL_LINES);
	glColor3d(0., 1., 0.);
	///top line
	glVertex2d(RotateX(m_xcen - m_offset, m_ycen + m_offset), RotateY(m_xcen - m_offset, m_ycen + m_offset));
	glVertex2d(RotateX(m_xcen + m_offset, m_ycen + m_offset), RotateY(m_xcen + m_offset, m_ycen + m_offset));
	///right line
	glVertex2d(RotateX(m_xcen + m_offset, m_ycen + m_offset), RotateY(m_xcen + m_offset, m_ycen + m_offset));
	glVertex2d(RotateX(m_xcen + m_offset, m_ycen - m_offset), RotateY(m_xcen + m_offset, m_ycen - m_offset));
	///bottom line
	glVertex2d(RotateX(m_xcen + m_offset, m_ycen - m_offset), RotateY(m_xcen + m_offset, m_ycen - m_offset));
	glVertex2d(RotateX(m_xcen - m_offset, m_ycen - m_offset), RotateY(m_xcen - m_offset, m_ycen - m_offset));
	///left line
	glVertex2d(RotateX(m_xcen - m_offset, m_ycen - m_offset), RotateY(m_xcen - m_offset, m_ycen - m_offset));
	glVertex2d(RotateX(m_xcen - m_offset, m_ycen + m_offset), RotateY(m_xcen - m_offset, m_ycen + m_offset));
	///top down to left
	glVertex2d(RotateX(m_xcen, m_ycen + m_offset), RotateY(m_xcen, m_ycen + m_offset));
	glVertex2d(RotateX(m_xcen - (m_offset/2), m_ycen - m_offset), RotateY(m_xcen - (m_offset/2), m_ycen - m_offset));
	///top down to right
	glVertex2d(RotateX(m_xcen, m_ycen + m_offset), RotateY(m_xcen, m_ycen + m_offset));
	glVertex2d(RotateX(m_xcen + (m_offset / 2), m_ycen - m_offset), RotateY(m_xcen + (m_offset / 2), m_ycen - m_offset));
	///line across
	glVertex2d(RotateX(m_xcen - m_offset, m_ycen * hght_fac), RotateY(m_xcen - m_offset, m_ycen * hght_fac));
	glVertex2d(RotateX(m_xcen + m_offset, m_ycen * hght_fac), RotateY(m_xcen + m_offset, m_ycen * hght_fac));
	///bottom to right
	glVertex2d(RotateX(m_xcen - (m_offset / 2), m_ycen - m_offset), RotateY(m_xcen - (m_offset / 2), m_ycen - m_offset));
	glVertex2d(RotateX(m_xcen + m_offset, m_ycen * hght_fac), RotateY(m_xcen + m_offset, m_ycen * hght_fac));
	///bottom to left
	glVertex2d(RotateX(m_xcen + (m_offset / 2), m_ycen - m_offset), RotateY(m_xcen + (m_offset / 2), m_ycen - m_offset));
	glVertex2d(RotateX(m_xcen - m_offset, m_ycen * hght_fac), RotateY(m_xcen - m_offset, m_ycen * hght_fac));
	glEnd();

}


void CChildView::OnStepstuffLineendto0()
{
	m_linetox = 0.1;
	m_linetoy = 0.1;

	Invalidate();
	// TODO: Add your command handler code here
}


void CChildView::OnStepstuffLinedialog()
{
	CLineDlg dlg;

	dlg.m_fmx = m_linefmx;
	dlg.m_fmy = m_linefmy;
	dlg.m_tox = m_linetox;
	dlg.m_toy = m_linetoy;

	if (dlg.DoModal() == IDOK)
	{
		m_linefmx = dlg.m_fmx;
		m_linefmy = dlg.m_fmy;
		m_linetox = dlg.m_tox;
		m_linetoy = dlg.m_toy;

		Invalidate();
	}
	// TODO: Add your command handler code here
}


void CChildView::OnStepstuffStar()
{
	CStarDlg dlg;

	dlg.m_xcen = m_xcen;
	dlg.m_ycen = m_ycen;
	dlg.m_len = m_len;
	dlg.m_rot = m_rot;

	if (dlg.DoModal() == IDOK)
	{
		m_xcen = dlg.m_xcen;
		m_ycen = dlg.m_ycen;
		m_len = dlg.m_len;
		m_rot = dlg.m_rot;

		Invalidate();
	}
	// TODO: Add your command handler code here
}


double CChildView::RotateX(double xpos, double ypos)
{
	if (m_rot > 0) {
		return cos(DegreeToRadian()) * (xpos - m_xcen) - sin(DegreeToRadian()) * (ypos - m_ycen) + m_xcen;
	}
	else {
		return xpos;
	}
}

double CChildView::RotateY(double xpos, double ypos)
{
	if (m_rot > 0) {
		return sin(DegreeToRadian()) * (xpos - m_xcen) + cos(DegreeToRadian()) * (ypos - m_ycen) + m_ycen;
	}
	else {
		return ypos;
	}
}

double CChildView::DegreeToRadian()
{
	double pi = 3.14;
	return m_rot * (pi / 180);
}



void CChildView::OnStepstuffRotate25degrees()
{
	m_rot += 25;
	Invalidate();
}
