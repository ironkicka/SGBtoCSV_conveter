
// mfctest1View.cpp : Cmfctest1View クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、サムネイル、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "mfctest1.h"
#endif

#include "mfctest1Doc.h"
#include "mfctest1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest1View

IMPLEMENT_DYNCREATE(Cmfctest1View, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest1View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_hioki, &Cmfctest1View::OnBnClickedButtonhioki)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmfctest1View::OnBnClickedButton2)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cmfctest1View コンストラクション/デストラクション

Cmfctest1View::Cmfctest1View()
	: CFormView(Cmfctest1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

Cmfctest1View::~Cmfctest1View()
{
}

void Cmfctest1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_hioki, m_button1);
}

BOOL Cmfctest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void Cmfctest1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmfctest1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cmfctest1View 診断

#ifdef _DEBUG
void Cmfctest1View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest1Doc* Cmfctest1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest1Doc)));
	return (Cmfctest1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest1View メッセージ ハンドラー


void Cmfctest1View::OnBnClickedButtonhioki()
{
	AfxMessageBox("hello,world");
	m_button1.EnableWindow(FALSE);
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	SetTimer(1,1000,NULL);


}


void Cmfctest1View::OnBnClickedButton2()
{
	KillTimer(1);
	m_button1.EnableWindow(TRUE);
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void Cmfctest1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	if(nIDEvent==1) {AfxMessageBox("bye");}
	CFormView::OnTimer(nIDEvent);
}
