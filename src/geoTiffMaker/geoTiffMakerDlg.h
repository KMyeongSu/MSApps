﻿
// geoTiffMakerDlg.h: 헤더 파일
//

#pragma once


// CgeoTiffMakerDlg 대화 상자
class CgeoTiffMakerDlg : public CDialogEx
{
// 생성입니다.
public:
	CgeoTiffMakerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GEOTIFFMAKER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CEdit m_rpcFilePath;
	CMFCEditBrowseCtrl m_TiffFilePath;
	CButton m_btnGeoTiffApply;
	afx_msg void MoveCursorToEnd();
	afx_msg void OnBtnGeoTiffApply();
};
