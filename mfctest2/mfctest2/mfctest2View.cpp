
// mfctest2View.cpp : Cmfctest2View �N���X�̎���
//

#include "stdafx.h"
// SHARED_HANDLERS �́A�v���r���[�A�T���l�C���A����ь����t�B���^�[ �n���h���[���������Ă��� ATL �v���W�F�N�g�Œ�`�ł��A
// ���̃v���W�F�N�g�Ƃ̃h�L�������g �R�[�h�̋��L���\�ɂ��܂��B
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

// Cmfctest2View �R���X�g���N�V����/�f�X�g���N�V����

Cmfctest2View::Cmfctest2View()
	: CFormView(Cmfctest2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

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
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

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


// Cmfctest2View �f�f

#ifdef _DEBUG
void Cmfctest2View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest2Doc* Cmfctest2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest2Doc)));
	return (Cmfctest2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest2View ���b�Z�[�W �n���h���[
