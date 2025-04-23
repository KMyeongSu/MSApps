#pragma once
#include <string>
#include <gdal.h>
#include <ogrsf_frmts.h>

#ifdef MAPGIS_EXPORTS
#define MAPGIS_API __declspec(dllexport)
#else
#define MAPGIS_API __declspec(dllimport)
#endif

class MAPGIS_API CGDALManager
{
public:
    CGDALManager();
    ~CGDALManager();

    bool LoadGeoTiff(const std::string& tiffFilePath);
    bool SaveGeoTiff(const std::string& tiffFilePath);
    GDALDataset* GetDataset();  // 데이터셋 외부 접근 허용

protected:
    GDALDataset* m_poDataset;
};
