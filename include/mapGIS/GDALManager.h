#pragma once

// DLL 내보내기
#ifdef MAPGIS_EXPORTS
    #define MAPGIS_API __declspec(dllexport)
#else
    #define MAPGIS_API __declspec(dllimport)
#endif

// 예시 함수
MAPGIS_API void test();
