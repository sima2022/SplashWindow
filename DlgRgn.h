#if !defined(AFX_DLGRGN_H__904173CF_ED1C_47A5_8D04_8C3F1FC5E2C7__INCLUDED_)
#define AFX_DLGRGN_H__904173CF_ED1C_47A5_8D04_8C3F1FC5E2C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRgn.h : �w�b�_�[ �t�@�C��
//
#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// DlgRgn �_�C�A���O

class DlgRgn : public CDialog
{
// �R���X�g���N�V����
public:
	DlgRgn(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    int m_bmpHeight;
	int m_bmpWidth;
	BITMAP m_bmInfo;
	CRgn* m_rDone;
    CPoint m_p;
	BOOL m_fDrag;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DlgRgn)
	enum { IDD = IDD_REGN };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(DlgRgn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DlgRgn)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DLGRGN_H__904173CF_ED1C_47A5_8D04_8C3F1FC5E2C7__INCLUDED_)
