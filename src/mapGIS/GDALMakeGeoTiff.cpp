#include "pch.h"
#include "GDALMakeGeotiff.h"
#include <iostream>

CGDALMakeGeotiff::CGDALMakeGeotiff(tGeoTiff _params)
    : CGDALManager(), m_params(_params), m_latitude(0), m_longitude(0)
{
}

CGDALMakeGeotiff::~CGDALMakeGeotiff()
{
}

bool CGDALMakeGeotiff::SetCoordinates(double lat, double lon)
{
    m_latitude = lat;
    m_longitude = lon;
    return true;
}

bool CGDALMakeGeotiff::ApplyGeoTransformFromCoord()
{
    GDALDataset* poDataset = GetDataset();
    if (!poDataset) return false;

    double adfGeoTransform[6] = {
        m_longitude, 0.0001, 0,
        m_latitude,  0,     -0.0001
    };

    if (poDataset->SetGeoTransform(adfGeoTransform) != CE_None) {
        std::cerr << "GeoTransform 설정 실패" << std::endl;
        return false;
    }

    OGRSpatialReference oSRS;
    oSRS.SetWellKnownGeogCS("WGS84");
    char* pszWKT = nullptr;
    oSRS.exportToWkt(&pszWKT);
    poDataset->SetProjection(pszWKT);
    CPLFree(pszWKT);

    return true;
}

bool CGDALMakeGeotiff::makeGeoTiff()
{
    if (!LoadGeoTiff(m_params.geotiffPath))
        return false;

    if (!ApplyGeoTransformFromCoord())
        return false;

    // 저장 파일 이름에 _result 붙이기
    std::string resultPath = m_params.geotiffPath;
    size_t dot = resultPath.find_last_of('.');
    if (dot != std::string::npos) {
        resultPath.insert(dot, "_result");
    }
    else {
        resultPath += "_result.tif";
    }

    return SaveGeoTiff(resultPath);
}
