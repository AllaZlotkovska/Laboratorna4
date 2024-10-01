#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;

// Структура Student, що представляє студента
struct Student {
    string PIB;
    string group;
    int year;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int numStudents = 10;
    Student Students[numStudents];

    // Введення даних в масив студентів за допомогою вказівників на структуру
    for (int i = 0; i < numStudents; i++) {
        Student* studentPtr = &Students[i]; // Вказівник на структуру Auto

        cout << "Введіть дані для студента " << i + 1 << ":" << endl;
        cout << "ПІБ: ";
        cin >> studentPtr->PIB;
        cout << "Номер групи: ";
        cin >> studentPtr->group;
        cout << "Рік народження: ";
        cin >> studentPtr->year;
    }

    // Впорядкування записів у масиві за зростанням номеру групи
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (Students[i].group > Students[j].group) {
                // Обмін елементів місцями за допомогою вказівників
                Student temp = Students[i];
                Students[i] = Students[j];
                Students[j] = temp;
            }
        }
    }

    // Виведення впорядкованого списку автомобілів
    cout << "\nСписок студентів після сортування за номером групи:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "ПІБ: " << Students[i].PIB << ", Номер групи: " << Students[i].group <<  ", Рік народження: " << Students[i].year << endl;
    }


    // Виведення даних про  ПІБ і номерів груп для всіх студентів одного року народження
    cout << "\nВиведення даних про студентів:" << endl;
    bool found = false;
    for (int i = 0; i < numStudents-1; i++) {
        if (Students[i].year == 2004) {
            cout << "ПІБ: " << Students[i].PIB << ", Номер групи: " << Students[i].group << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Немає студентів одного року народження." << endl;
    }

    return 0;
}

