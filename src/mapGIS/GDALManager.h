#pragma once
#include <string>
#include <gdal.h>
#include <ogrsf_frmts.h>

// DLL 호출
#ifdef MAPGIS_EXPORTS
    #define MAPGIS_API __declspec(dllexport)//내보내기
#else
    #define MAPGIS_API __declspec(dllimport)//가져오기
#endif

// test
MAPGIS_API void test();
#pragma once


class CGDALManager
{
public:
    //CGDALManager();  // 생성자
    //~CGDALManager();  // 소멸자

    //bool LoadGeoTiff(const std::string& tiffFilePath);  // GeoTIFF 파일 로드
    //bool SaveGeoTiff(const std::string& tiffFilePath);  // GeoTIFF 파일 저장
    //void SetCoordinates(double lat, double lon);  // 좌표값

    std::string getPath()
    {
        return m_path;
    }

private:
    GDALDataset* m_poDataset;  // GDAL 데이터셋
    double m_latitude;  // 위도
    double m_longitude;  // 경도

protected:
    std::string m_path = "";
        int aa = 0;

};