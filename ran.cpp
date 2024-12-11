#include <iostream>
#include "Header.h"
#include <limits>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    bool valMin, valMax, valQ;

    // Установка случайного начального числа для генератора
    srand(static_cast<unsigned>(time(0)));

    // Диапазон чисел
    int minRange, maxRange;

    cout << "Введите минимальное значение диапазона: ";

    do {
        string input;
        cin >> input;

        if (isNumber(input)) {
            minRange = stoi(input);  // Преобразуем строку в число
            valMin = true;
        }
        else {
            cout << "Ошибка! Это не целое число. Попробуйте снова.\n";
            valMin = false;
        }
    } while (!valMin);

    do {
        cout << "\nВведите максимальное значение диапазона: ";
        string input;
        cin >> input;

        if (isNumber(input)) {
            maxRange = stoi(input);  // Преобразуем строку в число
            valMax = true;
        }
        else {
            cout << "Ошибка! Это не целое число. Попробуйте снова.\n";
            valMax = false;
        }
    } while (!valMax);

    if (minRange > maxRange) {
        cerr << "\nОшибка! Минимальное значение больше максимального...";
        return 1;
    }
    else {
        // Генерация случайного числа
        int randomNumber = RandomNumber(minRange, maxRange);

        cout << "\nКомпьютер загадал число! Попробуйте угадать.\n";

        int userGuess;
        int count = 0;

        do {
            cout << "\nВаше предположение: ";

            do {
                string input;
                cin >> input;

                if (isNumber(input)) {
                    userGuess = stoi(input);  // Преобразуем строку в число

                    // Проверка, что число в пределах допустимого диапазона
                    if (userGuess < minRange or userGuess > maxRange) {
                        cout << "Ошибка! Число выходит за пределы диапазона ["
                            << minRange << ", " << maxRange << "]. Попробуйте снова.\n";
                        valQ = false;  // Ввод неверен, продолжаем цикл
                    }
                    else {
                        valQ = true;  // Ввод корректен
                    }
                }
                else {
                    cout << "Ошибка! Это не целое число. Попробуйте снова.\n";
                    valQ = false;  // Ввод неверен, продолжаем цикл
                }
            } while (!valQ);

            count++;

            if (userGuess > randomNumber) {
                cout << "Загаданное число меньше.\n";
            }
            else if (userGuess < randomNumber) {
                cout << "Загаданное число больше.\n";
            }
            else {
                cout << "\nПоздравляем! Вы угадали число " << randomNumber
                    << " за " << count << " попыток!\n";
            }
        } while (userGuess != randomNumber);
    }
    cout << endl;
    cout << "____________________________________________\n";
    cout << "Игра завершена. Нажмите Enter, чтобы выйти.\n";
    cin.ignore();
    cin.get();
    return 0;
}
