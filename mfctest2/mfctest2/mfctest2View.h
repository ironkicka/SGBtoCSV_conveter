
// mfctest2View.h : Cmfctest2View クラスのインターフェイス
//

#pragma once

#include "resource.h"


class Cmfctest2View : public CFormView
{
protected: // シリアル化からのみ作成します。
	Cmfctest2View();
	DECLARE_DYNCREATE(Cmfctest2View)

public:
	enum{ IDD = IDD_MFCTEST2_FORM };

// 属性
public:
	Cmfctest2Doc* GetDocument() const;

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
	virtual ~Cmfctest2View();
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
};

#ifndef _DEBUG  // mfctest2View.cpp のデバッグ バージョン
inline Cmfctest2Doc* Cmfctest2View::GetDocument() const
   { return reinterpret_cast<Cmfctest2Doc*>(m_pDocument); }
#endif

