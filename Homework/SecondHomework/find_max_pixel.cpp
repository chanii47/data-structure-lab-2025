#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 이미지 파일 경로를 절대 경로로 설정 (예시 경로)
    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    // 최대 화소 밝기 계산
    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    // 최대 화소 밝기 출력
    std::cout << maxVal << std::endl;

    return 0;
}


