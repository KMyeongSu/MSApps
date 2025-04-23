#pragma once
#include "GDALManager.h"

struct tGeoTiff
{
    std::string geotiffPath = "";  // TIFF 경로
};

class MAPGIS_API CGDALMakeGeotiff : public CGDALManager

{
public:
    CGDALMakeGeotiff(tGeoTiff _params);
    virtual ~CGDALMakeGeotiff();

    bool SetCoordinates(double lat, double lon);  // 좌표 저장
    bool ApplyGeoTransformFromCoord();            // GeoTransform 계산 및 적용
    bool makeGeoTiff();                          // 전체 처리

private:
    tGeoTiff m_params;
    double m_latitude;
    double m_longitude;
};
