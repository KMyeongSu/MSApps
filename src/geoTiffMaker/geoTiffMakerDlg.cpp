#include "pch.h"
#include "framework.h"
#include "geoTiffMaker.h"
#include "geoTiffMakerDlg.h"
#include "afxdialogex.h"
#include <string>
#include "GDALManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 생성자 및 기본 기능
CgeoTiffMakerDlg::CgeoTiffMakerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GEOTIFFMAKER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgeoTiffMakerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, m_TiffFilePath);
	DDX_Control(pDX, IDC_BUTTON2, m_btnGeoTiffApply);
	DDX_Control(pDX, IDC_COMBO1, m_CorSysSelect);
	DDX_Control(pDX, IDC_EDIT4, m_latitude);
	DDX_Control(pDX, IDC_EDIT3, m_longitude);
}

// 메시지 맵
BEGIN_MESSAGE_MAP(CgeoTiffMakerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CgeoTiffMakerDlg::OnBtnGeoTiffApply)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CgeoTiffMakerDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

// 좌표계 ComboBox 초기화
BOOL CgeoTiffMakerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 좌표계 선택 ComboBox 초기화
	m_CorSysSelect.AddString(_T("WGS84"));
	m_CorSysSelect.AddString(_T("UTM"));
	m_CorSysSelect.SetCurSel(0); // 기본값 WGS84 선택

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 좌표계 변경 시 호출되는 함수
void CgeoTiffMakerDlg::OnCbnSelchangeCombo1()
{
	// 좌표계 선택값 읽기
	int coordinateSystem = m_CorSysSelect.GetCurSel();
	// 좌표계 변경 시 추가 작업을 여기서 처리할 수 있습니다.
}

// 커서를 텍스트 박스 끝으로 이동
void CgeoTiffMakerDlg::MoveCursorToEnd()
{
	// CEdit의 끝으로 커서 이동
	m_TiffFilePath.SetSel(-1, -1);
}


// 파일 경로 및 좌표 읽기
void CgeoTiffMakerDlg::OnBtnGeoTiffApply()
{
	// m_TiffFilePath에서 경로 읽어오기
	CString tiffFilePath;
	m_TiffFilePath.GetWindowText(tiffFilePath);
	std::string tiffFilePathStr = std::string(CT2A(tiffFilePath));

	// 위도와 경도 읽기
	CString latitudeStr, longitudeStr;
	m_latitude.GetWindowText(latitudeStr);  // 위도
	m_longitude.GetWindowText(longitudeStr); // 경도
	double latitude = atof(CT2A(latitudeStr));
	double longitude = atof(CT2A(longitudeStr));

	// 좌표계 선택값 읽기
	int coordinateSystem = m_CorSysSelect.GetCurSel();  // 좌표계 선택 (0: WGS84, 1: UTM 등)

	// std::string 받아옴 (디버깅)
	AfxMessageBox(tiffFilePathStr.c_str());

	// 이후 로직에 해당 경로를 사용하는 코드 추가
	test();
}


