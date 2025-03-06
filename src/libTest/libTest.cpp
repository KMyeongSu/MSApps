// libTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <opencv2/opencv.hpp>
//#include "gdal.h"
//#include "gdal_priv.h"

//OpenCV TEST
int main()
{
    // 이미지 파일을 불러옵니다
    cv::Mat image = cv::imread("test.png", cv::IMREAD_COLOR);

    if (image.empty()) {
        std::cout << "fail" << std::endl;
        return -1;
    }

    // 이미지를 창에 띄웁니다
    cv::imshow("Test Image", image);

    // 키 입력을 기다립니다
    cv::waitKey(0);

    return 0;
}

// GDALTest.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.

//GDAL TEST
//int main()
//
//{
//
//    // register all drivers
//
//    GDALAllRegister();
//
//
//
//    // Dataset
//
//    GDALDataset* dataset = (GDALDataset*)GDALOpen(
//
//        "F:\\INFUSION_DATA\\WaterBody\\K3_20141023_RGBN_Resize.bin",
//
//        GA_ReadOnly);
//
//    printf("Description: %s\n", dataset->GetDescription());
//
//    printf("DriverName: %s\n", dataset->GetDriverName());
//
//    printf("Rater Count: %d\n", dataset->GetRasterCount());
//
//
//
//    // Band
//
//    GDALRasterBand* band = dataset->GetRasterBand(1);
//
//
//
//    int blockWidth, blockHeight;
//
//
//
//    printf("Data Type: %d", band->GetRasterDataType());
//
//    printf("Data Type Size: %d\n", GDALGetDataTypeSize(band->GetRasterDataType()));
//
//    band->GetBlockSize(&blockWidth, &blockHeight);
//
//
//
//    printf("Block Width: %d\n", blockWidth);
//
//    printf("Block Height: %d\n", blockHeight);
//
//
//
//    printf("Width: %d\n", band->GetXSize());
//
//    printf("Height: %d\n", band->GetYSize());
//
//
//
//    getchar();
//
//    return 0;
//
//}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
