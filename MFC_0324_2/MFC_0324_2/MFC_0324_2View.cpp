
// MFC_0324_2View.cpp : CMFC_0324_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0324_2.h"
#endif

#include "MFC_0324_2Doc.h"
#include "MFC_0324_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0324_2View

IMPLEMENT_DYNCREATE(CMFC_0324_2View, CView)

BEGIN_MESSAGE_MAP(CMFC_0324_2View, CView)
	ON_COMMAND(ID_SHOWICON, &CMFC_0324_2View::OnShowicon)
END_MESSAGE_MAP()

// CMFC_0324_2View 构造/析构

CMFC_0324_2View::CMFC_0324_2View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFC_0324_2View::~CMFC_0324_2View()
{
}

BOOL CMFC_0324_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0324_2View 绘制

void CMFC_0324_2View::OnDraw(CDC* pDC)
{
	CMFC_0324_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0324_2View 诊断

#ifdef _DEBUG
void CMFC_0324_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0324_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0324_2Doc* CMFC_0324_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0324_2Doc)));
	return (CMFC_0324_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0324_2View 消息处理程序


void CMFC_0324_2View::OnShowicon()
{
	// TODO: 在此添加命令处理程序代码
}
