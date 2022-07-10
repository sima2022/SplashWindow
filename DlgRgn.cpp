// DlgRgn.cpp : インプリメンテーション ファイル
//
#include "pch.h"
//#include "stdafx.h"
#include "DlgRgn.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgRgn ダイアログ


DlgRgn::DlgRgn(CWnd* pParent /*=NULL*/)
	: CDialog(DlgRgn::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgRgn)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
    m_p.x=m_p.y=0;
}


void DlgRgn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgRgn)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgRgn, CDialog)
	//{{AFX_MSG_MAP(DlgRgn)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgRgn メッセージ ハンドラ

BOOL DlgRgn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
    CRgn *m_rTemp, *m_rPixel;
	CBitmap bmp;
	CDC tempDC;
	POINT p;
	COLORREF transpColor;
//	m_bmpHeight = 188+1;
//	m_bmpWidth = 193+1;
	int x, y;

	tempDC.CreateCompatibleDC(NULL);	// DCを作成してビットマップを選択
	bmp.LoadBitmap(IDB_BITMAP1);
	tempDC.SelectObject(&bmp);

	bmp.GetObject(sizeof(BITMAP), &m_bmInfo);//bitmap幅高さ等取得。
	m_bmpHeight = m_bmInfo.bmHeight;
	m_bmpWidth = m_bmInfo.bmWidth;

	p.x = 0;							// 左上のピクセルの色を取得
	p.y = 0;
	transpColor = tempDC.GetPixel(p);

	m_rDone = new CRgn;					// リージョンの初期化
	m_rDone->CreateRectRgn(0, 0, 0, 0);	// ←これで空のリージョンになるようです。
	m_rTemp = new CRgn;
	m_rTemp->CreateRectRgn(0, 0, 0, 0);

	for (y = 0; y < m_bmpHeight; y++)			// ピクセルを調べてリージョンを作成
	{
		p.y = y;
		for (x = 0; x < m_bmpWidth; x++)
		{
			p.x = x;
			if (tempDC.GetPixel(p) != transpColor)
			{
				m_rPixel = new CRgn;
				m_rPixel->CreateRectRgn(x, y, x + 1, y + 1); // 1ピクセルのリージョン

				m_rTemp->CopyRgn(m_rDone);
				
				m_rDone->CombineRgn(m_rTemp, m_rPixel, RGN_OR);	// 合成する。

				delete m_rPixel;	// 。
			}
		}
	}

	SetWindowRgn(*m_rDone, true);	// リージョンを適用
	delete m_rDone;					// リージョンの初期化
	delete m_rTemp;
	m_fDrag = FALSE;
    SetTimer(50000,1,NULL);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DlgRgn::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
        CBitmap bmp;
		CDC *pDC, tempDC;
		pDC = GetDC();
		ASSERT_VALID(pDC);

		tempDC.CreateCompatibleDC(NULL);	// DCを作成してビットマップを選択
		bmp.LoadBitmap(IDB_BITMAP1);
		tempDC.SelectObject(&bmp);

		//pDC->BitBlt(m_p.x,m_p.y,m_p.x+200,m_p.y+180, &tempDC,0,0, SRCCOPY);		// Bltする。
		//pDC->BitBlt(m_p.x, m_p.y, m_p.x + 193, m_p.y + 188, &tempDC, 0, 0, SRCCOPY);		// Bltする。
		pDC->BitBlt(m_p.x, m_p.y, m_p.x + m_bmpWidth, m_p.y + m_bmInfo.bmWidth, &tempDC, 0, 0, SRCCOPY);		// Bltする。

	// 描画用メッセージとして CDialog::OnPaint() を呼び出してはいけません
}

void DlgRgn::OnTimer(UINT nIDEvent) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
    static int i=0;
	if (i == 200) {
		//KillTimer(1);
		SendMessage(WM_CLOSE);
	}
	i++;
	
	CDialog::OnTimer(nIDEvent);
}

void DlgRgn::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
    SendMessage(WM_CLOSE);
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
