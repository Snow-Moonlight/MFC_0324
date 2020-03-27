
// MFC_0324_3View.cpp : CMFC_0324_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0324_3.h"
#endif

#include "MFC_0324_3Doc.h"
#include "MFC_0324_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0324_3View

IMPLEMENT_DYNCREATE(CMFC_0324_3View, CView)

BEGIN_MESSAGE_MAP(CMFC_0324_3View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_PAINTLINE, &CMFC_0324_3View::OnPaintline)
	ON_COMMAND(ID_PAINTRECT, &CMFC_0324_3View::OnPaintrect)
	ON_COMMAND(ID_PAINTECLIPSE, &CMFC_0324_3View::OnPainteclipse)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_0324_3View 构造/析构

CMFC_0324_3View::CMFC_0324_3View()
{
	// TODO: 在此处添加构造代码
	a = 0;
	b = 0;
	c = 0;
}

CMFC_0324_3View::~CMFC_0324_3View()
{
}

BOOL CMFC_0324_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0324_3View 绘制

void CMFC_0324_3View::OnDraw(CDC* /*pDC*/)
{
	CMFC_0324_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0324_3View 诊断

#ifdef _DEBUG
void CMFC_0324_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0324_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0324_3Doc* CMFC_0324_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0324_3Doc)));
	return (CMFC_0324_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0324_3View 消息处理程序

void CMFC_0324_3View::OnPaintline()
{
	// TODO: 在此添加命令处理程序代码
	a = 1;

}


void CMFC_0324_3View::OnPaintrect()
{
	// TODO: 在此添加命令处理程序代码
	b = 1;
}

void CMFC_0324_3View::OnPainteclipse()
{
	// TODO: 在此添加命令处理程序代码
	c = 1;
}

void CMFC_0324_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_ptOrigin = point;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_0324_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	npoint = point;
	cr.right = point.x;
	cr.bottom = point.y;
	if (a == 1)
	{
		CClientDC dc(this);
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(npoint);
		a = 0;
	}
	else if (b == 1)
	{
		CClientDC dc(this);
		dc.Rectangle(cr.left, cr.top, cr.right, cr.bottom);
		b = 0;
	}
	else if (c == 1)
	{
		CClientDC dc(this);
		dc.Ellipse(cr.left, cr.top, cr.right, cr.bottom);
		c = 0;
	}
	CView::OnLButtonUp(nFlags, point);
}
