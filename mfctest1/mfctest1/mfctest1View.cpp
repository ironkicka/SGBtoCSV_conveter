
// mfctest1View.cpp : Cmfctest1View �N���X�̎���
//

#include "stdafx.h"
// SHARED_HANDLERS �́A�v���r���[�A�T���l�C���A����ь����t�B���^�[ �n���h���[���������Ă��� ATL �v���W�F�N�g�Œ�`�ł��A
// ���̃v���W�F�N�g�Ƃ̃h�L�������g �R�[�h�̋��L���\�ɂ��܂��B
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

// Cmfctest1View �R���X�g���N�V����/�f�X�g���N�V����

Cmfctest1View::Cmfctest1View()
	: CFormView(Cmfctest1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

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
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

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


// Cmfctest1View �f�f

#ifdef _DEBUG
void Cmfctest1View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest1Doc* Cmfctest1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest1Doc)));
	return (Cmfctest1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest1View ���b�Z�[�W �n���h���[


void Cmfctest1View::OnBnClickedButtonhioki()
{
	AfxMessageBox("hello,world");
	m_button1.EnableWindow(FALSE);
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	SetTimer(1,1000,NULL);


}


void Cmfctest1View::OnBnClickedButton2()
{
	KillTimer(1);
	m_button1.EnableWindow(TRUE);
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}


void Cmfctest1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	if(nIDEvent==1) {AfxMessageBox("bye");}
	CFormView::OnTimer(nIDEvent);
}
