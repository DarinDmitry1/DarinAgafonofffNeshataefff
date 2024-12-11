#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// ���������� ������� ��� ��������, ������� �� ������ ������ �� ����
bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {  // ���������, ��� ������ ������ �������� ������
            return false;
        }
    }
    return true;
}

// ���������� ������� ��� ��������� ���������� ����� � �������� ���������
int RandomNumber(int minRange, int maxRange) {
    return rand() % (maxRange - minRange + 1) + minRange;
}
