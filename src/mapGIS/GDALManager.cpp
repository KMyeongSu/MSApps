#include "pch.h"
#include "GDALManager.h"
#include <iostream>

CGDALManager::CGDALManager() : m_poDataset(nullptr)
{
    GDALAllRegister();
}

CGDALManager::~CGDALManager()
{
    if (m_poDataset) {
        GDALClose(m_poDataset);
        m_poDataset = nullptr;
    }
}

bool CGDALManager::LoadGeoTiff(const std::string& tiffFilePath)
{
    m_poDataset = static_cast<GDALDataset*>(GDALOpen(tiffFilePath.c_str(), GA_Update));
    if (m_poDataset == nullptr) {
        std::cerr << "GeoTIFF 파일 열기 실패: " << tiffFilePath << std::endl;
        return false;
    }
    return true;
}

bool CGDALManager::SaveGeoTiff(const std::string& savePath)
{
    if (!m_poDataset) return false;

    GDALDriver* poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
    if (!poDriver) return false;

    GDALDataset* poNew = poDriver->CreateCopy(savePath.c_str(), m_poDataset, FALSE, nullptr, nullptr, nullptr);
    if (!poNew) {
        std::cerr << "CreateCopy 실패: 저장 실패" << std::endl;
        return false;
    }

    GDALClose(poNew);
    return true;
}


GDALDataset* CGDALManager::GetDataset()
{
    return m_poDataset;
}
