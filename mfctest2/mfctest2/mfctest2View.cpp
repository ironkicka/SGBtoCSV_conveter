
// mfctest2View.cpp : Cmfctest2View クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、サムネイル、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "mfctest2.h"
#endif

#include "mfctest2Doc.h"
#include "mfctest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest2View

IMPLEMENT_DYNCREATE(Cmfctest2View, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest2View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cmfctest2View コンストラクション/デストラクション

Cmfctest2View::Cmfctest2View()
	: CFormView(Cmfctest2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

Cmfctest2View::~Cmfctest2View()
{
}

void Cmfctest2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL Cmfctest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cmfctest2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmfctest2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cmfctest2View 診断

#ifdef _DEBUG
void Cmfctest2View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest2Doc* Cmfctest2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest2Doc)));
	return (Cmfctest2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest2View メッセージ ハンドラー
