#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Реализация функции для проверки, состоит ли строка только из цифр
bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {  // Проверяем, что каждый символ является цифрой
            return false;
        }
    }
    return true;
}

// Реализация функции для генерации случайного числа в заданном диапазоне
int RandomNumber(int minRange, int maxRange) {
    return rand() % (maxRange - minRange + 1) + minRange;
}
