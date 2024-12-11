#ifndef HEADER_H
#define HEADER_H

#include <string>

// Функция для проверки, состоит ли строка только из цифр
bool isNumber(const std::string& str);

// Функция для генерации случайного числа в заданном диапазоне
int RandomNumber(int minRange, int maxRange);

#endif // HEADER_H