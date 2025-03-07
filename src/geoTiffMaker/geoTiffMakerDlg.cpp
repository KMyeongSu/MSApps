﻿
// geoTiffMakerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "geoTiffMaker.h"
#include "geoTiffMakerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgeoTiffMakerDlg 대화 상자



CgeoTiffMakerDlg::CgeoTiffMakerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GEOTIFFMAKER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgeoTiffMakerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_rpcFilePath);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, m_TiffFilePath);
	DDX_Control(pDX, IDC_BUTTON2, m_btnGeoTiffApply);
}

BEGIN_MESSAGE_MAP(CgeoTiffMakerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CgeoTiffMakerDlg::OnBtnGeoTiffApply)
END_MESSAGE_MAP()


// CgeoTiffMakerDlg 메시지 처리기

BOOL CgeoTiffMakerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CgeoTiffMakerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CgeoTiffMakerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CgeoTiffMakerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CgeoTiffMakerDlg::MoveCursorToEnd()
{
	// m_rpcFilePath는 'RPC File' 입력 필드 (CEdit 컨트롤)
	// m_TiffFilePath는 'GeoTIFF File' 입력 필드 (CMFCEditBrowseCtrl)

	// CEdit의 끝으로 커서 이동
	m_rpcFilePath.SetSel(-1, -1);
	m_TiffFilePath.SetSel(-1, -1);

	//CEdit* pEdit = m_TiffFilePath.GetEditCtrl();
	//if (pEdit)
	//{
	//	pEdit->SetSel(-1, -1);  // CEdit의 끝으로 커서 이동
	//}
}

#include <string>
#include "GDALManager.h"
void CgeoTiffMakerDlg::OnBtnGeoTiffApply()
{
	// m_rpcFilePath에서 경로 읽어오기
	CString rpcFilePath;
  	m_rpcFilePath.GetWindowText(rpcFilePath);
	std::string rpcFilePathStr = std::string(CT2CA(rpcFilePath));
	//std::string rpcFilePathStr((CT2A(rpcFilePath)); // <- casting type 이 없어서 변환이 안됨
	//std::string rpcFilePathStr(std::string(CT2CA(rpcFilePath))); // 안됨
	//std::string rpcFilePathStr = std::string(CT2CA(rpcFilePath.operator LPCTSTR())); // 성공. TCHR 자동으로 
	
	
	// m_TiffFilePath에서 경로 읽어오기
	CString tiffFilePath;
	m_TiffFilePath.GetWindowText(tiffFilePath);
	std::string tiffFilePathStr = std::string(CT2A(tiffFilePath));
	//std::string tiffFilePathStr(CT2A(tiffFilePath)); // <- casting type 이 없어서 변환이 안됨

	// CString 받아옴
 	//AfxMessageBox(rpcFilePath);
	//AfxMessageBox(tiffFilePath);

	// std::string 받아옴
	AfxMessageBox(rpcFilePathStr.c_str());
	AfxMessageBox(tiffFilePathStr.c_str());

	test();
	// 이후 로직에 해당 경로를 사용하는 코드 추가
}

