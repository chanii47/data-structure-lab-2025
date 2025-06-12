#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // �̹��� ���� ��θ� ���� ��η� ���� (���� ���)
    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    // �ִ� ȭ�� ��� ���
    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    // �ִ� ȭ�� ��� ���
    std::cout << maxVal << std::endl;

    return 0;
}


