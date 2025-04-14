#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>
#include <iomanip>  // setprecision�� ����ϱ� ���� ���

#define MAX_DEGREE 101  // ���׽��� ó�� ������ �ִ� ���� +1

class SparsePoly {
    int numTerm;  // ���׽� ���� ����
    std::vector<int> exponents;  // �� ���� ���� ���� ����
    std::vector<float> coefficients;  // �� ���� ��� ���� ����

public:
    SparsePoly() : numTerm(0) {}

    // ���׽� �Է� �Լ�
    void read() {
        std::cout << "���� ������ �Է��ϼ���: ";
        std::cin >> numTerm;

        for (int i = 0; i < numTerm; i++) {
            float coef;
            int exp;
            std::cout << i + 1 << "��° ���� ����� ������ �Է��ϼ���  (��:��� ����) : ";
            std::cin >> coef >> exp;

            coefficients.push_back(coef);
            exponents.push_back(exp);
        }
    }

    // ���׽� ��� �Լ�
    void display(const char* str) {
        std::cout << std::fixed << std::setprecision(1);  // �Ҽ��� 1�ڸ� ���
        std::cout << str;

        for (int i = 0; i < numTerm; i++) {
            if (i > 0 && coefficients[i] >= 0) std::cout << " + ";
            else if (coefficients[i] < 0) std::cout << " - ";

            float absCoef = std::abs(coefficients[i]);
            if (exponents[i] == 0) {
                std::cout << absCoef << "x^0";  // x^0�� ��������� ���
            }
            else if (exponents[i] == 1) {
                std::cout << absCoef << "x^1";  // 1���� x^1�� ���
            }
            else {
                std::cout << absCoef << "x^" << exponents[i];
            }
        }
        std::cout << std::endl;
    }


    // ���׽� ���� �Լ�
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

        // ���� �� �߰�
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
