
// locationTIFFView.cpp: ClocationTIFFView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "locationTIFF.h"
#endif

#include "locationTIFFDoc.h"
#include "locationTIFFView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClocationTIFFView

IMPLEMENT_DYNCREATE(ClocationTIFFView, CView)

BEGIN_MESSAGE_MAP(ClocationTIFFView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ClocationTIFFView 생성/소멸

ClocationTIFFView::ClocationTIFFView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

ClocationTIFFView::~ClocationTIFFView()
{
}

BOOL ClocationTIFFView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// ClocationTIFFView 그리기

void ClocationTIFFView::OnDraw(CDC* /*pDC*/)
{
	ClocationTIFFDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void ClocationTIFFView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ClocationTIFFView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ClocationTIFFView 진단

#ifdef _DEBUG
void ClocationTIFFView::AssertValid() const
{
	CView::AssertValid();
}

void ClocationTIFFView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ClocationTIFFDoc* ClocationTIFFView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ClocationTIFFDoc)));
	return (ClocationTIFFDoc*)m_pDocument;
}
#endif //_DEBUG


// ClocationTIFFView 메시지 처리기
