#pragma once
#include <string>
#include <gdal.h>  // GDAL 헤더 파일 포함
#include <ogrsf_frmts.h>  // GeoTIFF 처리 위한 헤더

#ifdef MAPGIS_EXPORTS
#define MAPGIS_API __declspec(dllexport)  // 내보내기
#else
#define MAPGIS_API __declspec(dllimport)  // 가져오기
#endif


class MAPGIS_API CGDALManager
{
public:
    CGDALManager();  // 생성자
    ~CGDALManager();  // 소멸자

    bool LoadGeoTiff(const std::string& tiffFilePath);  // GeoTIFF 파일 로드
    bool SaveGeoTiff(const std::string& tiffFilePath);  // GeoTIFF 파일 저장
    void SetCoordinates(double lat, double lon, int coordinateSystem);  // 좌표값 설정 (하드코딩 값 사용)

private:
    GDALDataset* m_poDataset;  // GDAL 데이터셋
    double m_latitude;  // 위도
    double m_longitude;  // 경도
};
