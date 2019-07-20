
// mfctest1View.h : Cmfctest1View クラスのインターフェイス
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class Cmfctest1View : public CFormView
{
protected: // シリアル化からのみ作成します。
	Cmfctest1View();
	DECLARE_DYNCREATE(Cmfctest1View)

public:
	enum{ IDD = IDD_MFCTEST1_FORM };

// 属性
public:
	Cmfctest1Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual void OnInitialUpdate(); // 構築後に初めて呼び出されます。

// 実装
public:
	virtual ~Cmfctest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
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

#ifndef _DEBUG  // mfctest1View.cpp のデバッグ バージョン
inline Cmfctest1Doc* Cmfctest1View::GetDocument() const
   { return reinterpret_cast<Cmfctest1Doc*>(m_pDocument); }
#endif

