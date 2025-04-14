#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>
#include <iomanip>  // setprecision을 사용하기 위한 헤더

#define MAX_DEGREE 101  // 다항식의 처리 가능한 최대 차수 +1

class SparsePoly {
    int numTerm;  // 다항식 항의 개수
    std::vector<int> exponents;  // 각 항의 차수 저장 벡터
    std::vector<float> coefficients;  // 각 항의 계수 저장 벡터

public:
    SparsePoly() : numTerm(0) {}

    // 다항식 입력 함수
    void read() {
        std::cout << "항의 개수를 입력하세요: ";
        std::cin >> numTerm;

        for (int i = 0; i < numTerm; i++) {
            float coef;
            int exp;
            std::cout << i + 1 << "번째 항의 계수와 차수를 입력하세요  (예:계수 차수) : ";
            std::cin >> coef >> exp;

            coefficients.push_back(coef);
            exponents.push_back(exp);
        }
    }

    // 다항식 출력 함수
    void display(const char* str) {
        std::cout << std::fixed << std::setprecision(1);  // 소수점 1자리 출력
        std::cout << str;

        for (int i = 0; i < numTerm; i++) {
            if (i > 0 && coefficients[i] >= 0) std::cout << " + ";
            else if (coefficients[i] < 0) std::cout << " - ";

            float absCoef = std::abs(coefficients[i]);
            if (exponents[i] == 0) {
                std::cout << absCoef << "x^0";  // x^0을 명시적으로 출력
            }
            else if (exponents[i] == 1) {
                std::cout << absCoef << "x^1";  // 1차는 x^1로 출력
            }
            else {
                std::cout << absCoef << "x^" << exponents[i];
            }
        }
        std::cout << std::endl;
    }


    // 다항식 덧셈 함수
    void add(SparsePoly a, SparsePoly b) {
        int i = 0, j = 0;
        numTerm = 0;
        exponents.clear();
        coefficients.clear();

        while (i < a.numTerm && j < b.numTerm) {
            if (a.exponents[i] == b.exponents[j]) {
                float sumCoef = a.coefficients[i] + b.coefficients[j];
                if (sumCoef != 0) {
                    exponents.push_back(a.exponents[i]);
                    coefficients.push_back(sumCoef);
                    numTerm++;
                }
                i++;
                j++;
            }
            else if (a.exponents[i] > b.exponents[j]) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                i++;
                numTerm++;
            }
            else {
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                j++;
                numTerm++;
            }
        }

        // 남은 항 추가
        while (i < a.numTerm) {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            i++;
            numTerm++;
        }
        while (j < b.numTerm) {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            j++;
            numTerm++;
        }
    }
};
