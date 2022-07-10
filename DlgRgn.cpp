// DlgRgn.cpp : �C���v�������e�[�V���� �t�@�C��
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
// DlgRgn �_�C�A���O


DlgRgn::DlgRgn(CWnd* pParent /*=NULL*/)
	: CDialog(DlgRgn::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgRgn)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
    m_p.x=m_p.y=0;
}


void DlgRgn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgRgn)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
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
// DlgRgn ���b�Z�[�W �n���h��

BOOL DlgRgn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
    CRgn *m_rTemp, *m_rPixel;
	CBitmap bmp;
	CDC tempDC;
	POINT p;
	COLORREF transpColor;
//	m_bmpHeight = 188+1;
//	m_bmpWidth = 193+1;
	int x, y;

	tempDC.CreateCompatibleDC(NULL);	// DC���쐬���ăr�b�g�}�b�v��I��
	bmp.LoadBitmap(IDB_BITMAP1);
	tempDC.SelectObject(&bmp);

	bmp.GetObject(sizeof(BITMAP), &m_bmInfo);//bitmap���������擾�B
	m_bmpHeight = m_bmInfo.bmHeight;
	m_bmpWidth = m_bmInfo.bmWidth;

	p.x = 0;							// ����̃s�N�Z���̐F���擾
	p.y = 0;
	transpColor = tempDC.GetPixel(p);

	m_rDone = new CRgn;					// ���[�W�����̏�����
	m_rDone->CreateRectRgn(0, 0, 0, 0);	// ������ŋ�̃��[�W�����ɂȂ�悤�ł��B
	m_rTemp = new CRgn;
	m_rTemp->CreateRectRgn(0, 0, 0, 0);

	for (y = 0; y < m_bmpHeight; y++)			// �s�N�Z���𒲂ׂă��[�W�������쐬
	{
		p.y = y;
		for (x = 0; x < m_bmpWidth; x++)
		{
			p.x = x;
			if (tempDC.GetPixel(p) != transpColor)
			{
				m_rPixel = new CRgn;
				m_rPixel->CreateRectRgn(x, y, x + 1, y + 1); // 1�s�N�Z���̃��[�W����

				m_rTemp->CopyRgn(m_rDone);
				
				m_rDone->CombineRgn(m_rTemp, m_rPixel, RGN_OR);	// ��������B

				delete m_rPixel;	// �B
			}
		}
	}

	SetWindowRgn(*m_rDone, true);	// ���[�W������K�p
	delete m_rDone;					// ���[�W�����̏�����
	delete m_rTemp;
	m_fDrag = FALSE;
    SetTimer(50000,1,NULL);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DlgRgn::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
        CBitmap bmp;
		CDC *pDC, tempDC;
		pDC = GetDC();
		ASSERT_VALID(pDC);

		tempDC.CreateCompatibleDC(NULL);	// DC���쐬���ăr�b�g�}�b�v��I��
		bmp.LoadBitmap(IDB_BITMAP1);
		tempDC.SelectObject(&bmp);

		//pDC->BitBlt(m_p.x,m_p.y,m_p.x+200,m_p.y+180, &tempDC,0,0, SRCCOPY);		// Blt����B
		//pDC->BitBlt(m_p.x, m_p.y, m_p.x + 193, m_p.y + 188, &tempDC, 0, 0, SRCCOPY);		// Blt����B
		pDC->BitBlt(m_p.x, m_p.y, m_p.x + m_bmpWidth, m_p.y + m_bmInfo.bmWidth, &tempDC, 0, 0, SRCCOPY);		// Blt����B

	// �`��p���b�Z�[�W�Ƃ��� CDialog::OnPaint() ���Ăяo���Ă͂����܂���
}

void DlgRgn::OnTimer(UINT nIDEvent) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
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
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
    SendMessage(WM_CLOSE);
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
