
// mfctest2View.h : Cmfctest2View �N���X�̃C���^�[�t�F�C�X
//

#pragma once

#include "resource.h"


class Cmfctest2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	Cmfctest2View();
	DECLARE_DYNCREATE(Cmfctest2View)

public:
	enum{ IDD = IDD_MFCTEST2_FORM };

// ����
public:
	Cmfctest2Doc* GetDocument() const;

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
	virtual ~Cmfctest2View();
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
};

#ifndef _DEBUG  // mfctest2View.cpp �̃f�o�b�O �o�[�W����
inline Cmfctest2Doc* Cmfctest2View::GetDocument() const
   { return reinterpret_cast<Cmfctest2Doc*>(m_pDocument); }
#endif

