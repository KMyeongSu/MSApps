#pragma once
//#include "gdal.h"
#include "GDALManager.h"

// 확장성을 고려한 구조체 사용
struct tGeoTiff
{
	// input
	std::string rpcPath = "";
	std::string rawFile = "";

	// output path
	std::string geotiffPath = "";

};

//-----------------------------------------------
class CGDALMakeGeotiff : public CGDALManager
{
public:
	CGDALMakeGeotiff(tGeoTiff _params);
	virtual ~CGDALMakeGeotiff();

public:
	//
	bool makeTiffbySUJ();

private:
	tGeoTiff m_params;
};
