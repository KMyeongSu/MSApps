#pragma once
#include <string>
class CgeoTiffMakerDlg : public CDialogEx
{
public:
	CgeoTiffMakerDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GEOTIFFMAKER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog(); // 온 초기화 시 호출되는 함수
	DECLARE_MESSAGE_MAP()

public:
	CMFCEditBrowseCtrl m_TiffFilePath;  // TIFF 파일 경로
	CButton m_btnGeoTiffApply;          // GeoTIFF 적용 버튼
	CComboBox m_CorSysSelect;           // 좌표계 선택 ComboBox
	CEdit m_latitude;                   // 위도 입력 필드
	CEdit m_longitude;                  // 경도 입력 필드

	afx_msg void OnBtnGeoTiffApply();   // start버튼
	afx_msg void OnCbnSelchangeCombo1(); // 좌표계 드롭박스
	afx_msg void MoveCursorToEnd();      // 커서 끝으로 이동
	afx_msg void OnBtnCreateEmptyGeoTiff();  // 빈 GeoTIFF 생성 버튼 클릭 이벤트

	void CreateBlackTiff(const std::string& filePath);  // 빈 TIFF 생성 함수


	void test();
};
