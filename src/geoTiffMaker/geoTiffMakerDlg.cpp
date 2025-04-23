#include "pch.h"
#include "framework.h"
#include "geoTiffMaker.h"
#include "geoTiffMakerDlg.h"
#include "afxdialogex.h"
#include <string>
#include "GDALManager.h"
#include "GDALMakeGeoTiff.h"
#include <ogrsf_frmts.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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

BEGIN_MESSAGE_MAP(CgeoTiffMakerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CgeoTiffMakerDlg::OnBtnGeoTiffApply)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CgeoTiffMakerDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CgeoTiffMakerDlg::OnBtnCreateEmptyGeoTiff)
END_MESSAGE_MAP()

// 좌표계 ComboBox 초기화
BOOL CgeoTiffMakerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 좌표계 선택 ComboBox 초기화
	m_CorSysSelect.AddString(_T("WGS84"));
	m_CorSysSelect.AddString(_T("EPSG:4326"));
	m_CorSysSelect.AddString(_T("EPSG:32652"));
	//m_CorSysSelect.AddString(_T("UTM"));
	//m_CorSysSelect.InsertString(5,"UTM"); // InsertString 순서지정 가능
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

void CgeoTiffMakerDlg::test()
{
	// 위도와 경도 읽기
	CString latStr, lonStr;
	m_latitude.GetWindowText(latStr);   // 위도
	m_longitude.GetWindowText(lonStr);  // 경도

	// CString -> double로 변환
	double latitude = _ttof(latStr);
	double longitude = _ttof(lonStr);

	// 확인용
	CString lat, lon;
	lat.Format(_T("Latitude: %f"), latitude);
	lon.Format(_T("Longitude: %f"), longitude);

	AfxMessageBox(lat);  // 위도 출력
	AfxMessageBox(lon);  // 경도 출력
}



// 파일 경로 및 좌표 읽기
void CgeoTiffMakerDlg::OnBtnGeoTiffApply()
{
	// TIFF 파일 경로 읽기
	CString tiffFilePath;
	m_TiffFilePath.GetWindowText(tiffFilePath);
	std::string tiffFilePathStr = std::string(CT2A(tiffFilePath));

	// 위도/경도 읽기
	CString latitudeStr, longitudeStr;
	m_latitude.GetWindowText(latitudeStr);
	m_longitude.GetWindowText(longitudeStr);
	double latitude = atof(CT2A(latitudeStr));
	double longitude = atof(CT2A(longitudeStr));

	// GeoTIFF 생성 파라미터 구조체 설정
	tGeoTiff params;
	params.geotiffPath = tiffFilePathStr;

	// DLL 객체 생성 및 좌표 설정
	CGDALMakeGeotiff geo(params);
	geo.SetCoordinates(latitude, longitude);

	// GeoTransform 적용 및 저장 시도
	if (geo.makeGeoTiff()) {
		AfxMessageBox(_T("GeoTransform 적용 완료"));
	}
	else {
		AfxMessageBox(_T("GeoTransform 적용 실패"));
	}
}



void CgeoTiffMakerDlg::OnBtnCreateEmptyGeoTiff()
{
	// 임시로 빈 GeoTIFF 파일을 생성하는 함수 호출
	CreateBlackTiff("test_empty_tiff.tif");

	// 생성 완료 메시지 출력
	AfxMessageBox(_T("빈 TIFF 파일 생성 완료!"));
}

void CgeoTiffMakerDlg::CreateBlackTiff(const std::string& filePath)
{
	GDALAllRegister();

	GDALDriver* poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
	if (poDriver == NULL)
	{
		AfxMessageBox(_T("GeoTIFF 드라이버가 없습니다."));
		return;
	}

	int nXSize = 1000;
	int nYSize = 1000;

	char* papszOptions[] = {
		const_cast<char*>("TILED=YES"),
		const_cast<char*>("COMPRESS=LZW"),
		const_cast<char*>("BIGTIFF=YES"),
		NULL
	};

	GDALDataset* poDataset = poDriver->Create(filePath.c_str(), nXSize, nYSize, 1, GDT_Byte, papszOptions);
	if (poDataset == NULL)
	{
		AfxMessageBox(_T("TIFF 파일 생성 실패."));
		return;
	}

	GDALRasterBand* poBand = poDataset->GetRasterBand(1);
	poBand->Fill(0);

	GDALClose(poDataset);
}
