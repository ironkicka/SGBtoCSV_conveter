
// mfctest1View.h : Cmfctest1View �N���X�̃C���^�[�t�F�C�X
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cmfctest1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	Cmfctest1View();
	DECLARE_DYNCREATE(Cmfctest1View)

public:
	enum{ IDD = IDD_MFCTEST1_FORM };

// ����
public:
	Cmfctest1Doc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual void OnInitialUpdate(); // �\�z��ɏ��߂ČĂяo����܂��B

// ����
public:
	virtual ~Cmfctest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonhioki();
	afx_msg void OnBnClickedButton2();
	CButton m_button1;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // mfctest1View.cpp �̃f�o�b�O �o�[�W����
inline Cmfctest1Doc* Cmfctest1View::GetDocument() const
   { return reinterpret_cast<Cmfctest1Doc*>(m_pDocument); }
#endif

