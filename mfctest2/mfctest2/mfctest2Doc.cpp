
// mfctest2Doc.cpp : Cmfctest2Doc �N���X�̎���
//

#include "stdafx.h"
// SHARED_HANDLERS �́A�v���r���[�A�T���l�C���A����ь����t�B���^�[ �n���h���[���������Ă��� ATL �v���W�F�N�g�Œ�`�ł��A
// ���̃v���W�F�N�g�Ƃ̃h�L�������g �R�[�h�̋��L���\�ɂ��܂��B
#ifndef SHARED_HANDLERS
#include "mfctest2.h"
#endif

#include "mfctest2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cmfctest2Doc

IMPLEMENT_DYNCREATE(Cmfctest2Doc, CDocument)

BEGIN_MESSAGE_MAP(Cmfctest2Doc, CDocument)
END_MESSAGE_MAP()


// Cmfctest2Doc �R���X�g���N�V����/�f�X�g���N�V����

Cmfctest2Doc::Cmfctest2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

Cmfctest2Doc::~Cmfctest2Doc()
{
}

BOOL Cmfctest2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// Cmfctest2Doc �V���A����

void Cmfctest2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �i�[����R�[�h�������ɒǉ����Ă��������B
	}
	else
	{
		// TODO: �ǂݍ��ރR�[�h�������ɒǉ����Ă��������B
	}
}

#ifdef SHARED_HANDLERS

// �T���l�C���̃T�|�[�g
void Cmfctest2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ���̃R�[�h��ύX���ăh�L�������g�̃f�[�^��`�悵�܂�
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �����n���h���[�̃T�|�[�g
void Cmfctest2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// �h�L�������g�̃f�[�^���猟���R���e���c��ݒ肵�܂��B 
	// �R���e���c�̊e������ ";" �ŋ�؂�K�v������܂�

	// ��:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Cmfctest2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cmfctest2Doc �f�f

#ifdef _DEBUG
void Cmfctest2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cmfctest2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cmfctest2Doc �R�}���h
