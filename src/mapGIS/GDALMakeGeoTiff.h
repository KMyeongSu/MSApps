#pragma once
#include "GDALManager.h"

struct tGeoTiff
{
    std::string geotiffPath = "";  // TIFF ���
};

class MAPGIS_API CGDALMakeGeotiff : public CGDALManager

{
public:
    CGDALMakeGeotiff(tGeoTiff _params);
    virtual ~CGDALMakeGeotiff();

    bool SetCoordinates(double lat, double lon);  // ��ǥ ����
    bool ApplyGeoTransformFromCoord();            // GeoTransform ��� �� ����
    bool makeGeoTiff();                          // ��ü ó��

private:
    tGeoTiff m_params;
    double m_latitude;
    double m_longitude;
};
