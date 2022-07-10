#if !defined(AFX_DLGRGN_H__904173CF_ED1C_47A5_8D04_8C3F1FC5E2C7__INCLUDED_)
#define AFX_DLGRGN_H__904173CF_ED1C_47A5_8D04_8C3F1FC5E2C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRgn.h : ヘッダー ファイル
//
#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// DlgRgn ダイアログ

class DlgRgn : public CDialog
{
// コンストラクション
public:
	DlgRgn(CWnd* pParent = NULL);   // 標準のコンストラクタ

    int m_bmpHeight;
	int m_bmpWidth;
	BITMAP m_bmInfo;
	CRgn* m_rDone;
    CPoint m_p;
	BOOL m_fDrag;

// ダイアログ データ
	//{{AFX_DATA(DlgRgn)
	enum { IDD = IDD_REGN };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(DlgRgn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DlgRgn)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DLGRGN_H__904173CF_ED1C_47A5_8D04_8C3F1FC5E2C7__INCLUDED_)
