#include "pch.h"
#include "GDALManager.h"
#include <iostream>
#include <gdal.h>
#include <ogrsf_frmts.h>  // GeoTIFF 처리 

MAPGIS_API void test2() {
    MessageBox(NULL, "Success", "Test", MB_OK);
}

CGDALManager::CGDALManager()
    : m_poDataset(nullptr), m_latitude(0), m_longitude(0)
{
    // GDAL 초기화
    GDALAllRegister();
}

CGDALManager::~CGDALManager()
{
    // GDAL 자원 해제
    if (m_poDataset) {
        GDALClose(m_poDataset);
    }
}

bool CGDALManager::LoadGeoTiff(const std::string& tiffFilePath)
{
    // GeoTIFF 파일 열기
    m_poDataset = static_cast<GDALDataset*>(GDALOpen(tiffFilePath.c_str(), GA_ReadOnly));
    if (m_poDataset == nullptr) {
        std::cerr << "GeoTIFF 파일 열기 실패: " << tiffFilePath << std::endl;
        return false;
    }
    return true;
}

bool CGDALManager::SaveGeoTiff(const std::string& tiffFilePath)
{
    // GeoTIFF 파일을 저장하는 예시
    GDALDriver* poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
    if (poDriver == nullptr) {
        std::cerr << "GeoTIFF 드라이버를 찾을 수 없습니다." << std::endl;
        return false;
    }

    // 새로운 GeoTIFF 파일을 생성
    GDALDataset* poNewDataset = poDriver->Create(tiffFilePath.c_str(), 100, 100, 1, GDT_Float32, nullptr);
    if (poNewDataset == nullptr) {
        std::cerr << "새로운 GeoTIFF 파일 생성 실패." << std::endl;
        return false;
    }

    // 좌표 값 등을 사용하여 파일을 저장하는 코드 추가 필요
    GDALClose(poNewDataset);  // 파일 닫기
    return true;
}

void CGDALManager::SetCoordinates(double lat, double lon, int coordinateSystem)
{
    m_latitude = lat;
    m_longitude = lon;

    // 좌표계 처리 (예: WGS84, UTM 등)
    if (coordinateSystem == 0) {
        // WGS84 좌표계 처리
    }
    else if (coordinateSystem == 1) {
        // UTM 좌표계 처리
    }
    // 좌표계 적용 후 GeoTIFF 처리 로직
}

