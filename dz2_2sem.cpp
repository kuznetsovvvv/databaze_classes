#include<set>
#include <iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include"structual_divisions.h"
#include"employees.h"
#include<fstream>
#include <algorithm>
#include <sstream>
#include <cctype>
#ifdef max
#undef max
#endif
using namespace std;
HANDLE hConsole;
void menu();

int main()
{
    setlocale(LC_ALL, "RU");
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::set<employees> employees_set;
    std::set<structual_divisions> divisions_set;

    fstream inputFile("inputfile.txt");
    fstream secondinputFile("secondinputfile.txt");

    if (!inputFile.is_open() && !secondinputFile.is_open()) {
        cerr << "Error with files!!!" << endl;
        return 1; // Возвращаем код ошибки
    }
    else {
        cout << "Files are open!" << endl;
        SetConsoleTextAttribute(hConsole, 6);
        cout << "\t\t\t\t\tМеню отдела кадров организации:" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        int n = 0;
        string name, head, tmp;
        int value;
        vector<string> names;
        inputFile >> n; // Считываем количество отделов
        inputFile.ignore();
        for (int i = 0; i < n; i++) {

            getline(inputFile, name);
            getline(inputFile, head);
            inputFile >> value;
            names.clear(); // Очищаем вектор имен для каждого отдела
            inputFile.ignore();
            // Считываем имена сотрудников из secondinputFile, по одному имени в каждой строке
            for (int j = 0; j < value; j++) {
                getline(inputFile, tmp); // Используем getline для считывания всей строки
                names.push_back(tmp);
            }

            divisions_set.insert(structual_divisions(name, head, value, names));
        }

        //
        string Name, pol;
        int age, salary, hoursweek;
        double experience;
        int l = 0;

        secondinputFile >> l;
        secondinputFile.ignore();
        for (int k = 0; k < l; k++) {
            getline(secondinputFile, Name);
            secondinputFile >> age;
            secondinputFile.ignore();
            getline(secondinputFile, pol);
            secondinputFile >> experience;
            secondinputFile >> salary;
            secondinputFile >> hoursweek;
            secondinputFile.ignore();
            employees new_employee(Name, age, pol, experience, salary, hoursweek);
            employees_set.insert(new_employee);
        }





        while (true) {
            menu();
            string input = "";
            getline(cin, input);

            try {
                if (all_of(input.begin(), input.end(), ::isdigit)) {
                    int choice = stoi(input);
                    if (choice >= 1 && choice <= 9) {

                        if (choice == 1) {
                            structual_divisions::add_division(divisions_set);
                        }
                        else if (choice == 2) {

                            structual_divisions::print_divisions(divisions_set);
                        }
                        else if (choice == 3) {
                            structual_divisions::print_employee_count(divisions_set);
                        }
                        else if (choice == 4) {
                            structual_divisions::remove_division(divisions_set);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else if (choice == 5) {
                            employees::addemployee(employees_set);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');// очищаем буфер после ввода данных с пробелами
                        }
                        else if (choice == 6) {
                            if (employees_set.empty()) {
                                cout << "Список сотрудников пуст!\n";
                            }
                            else {
                                cout << "Введите номер сотрудника для редактирования: ";
                                int index;
                                cin >> index;
                                if (index >= 1 && index <= employees_set.size()) {
                                    auto it = employees_set.begin(); // Получаем итератор на начало set
                                    advance(it, index - 1); // Перемещаем итератор на нужную позицию
                                    employees employee_to_edit = *it; // Копируем сотрудника во временный объект
                                    employees_set.erase(it);
                                    employee_to_edit.edit_data(); // Редактируем данные во временном объекте

                                    employees_set.insert(employee_to_edit); // Добавляем обновленного сотрудника
                                }
                                else {
                                    cout << "Неверный номер сотрудника!\n";
                                }

                            }
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else if (choice == 7) {
                            if (employees_set.empty()) {
                                cout << "Список сотрудников пуст!\n";
                            }
                            else {
                                int i = 1;
                                for (const employees& employee : employees_set) {
                                    cout << "Сотрудник №" << i << ":\n";
                                    employee.print(); // Вызываем метод print() для каждого сотрудника
                                    i++;
                                }
                            }
                        }
                        else if (choice == 8) {

                            // Вызываем метод delete_employee как статический метод класса 
                            employees::delete_employee(employees_set);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        else if (choice == 9) {
                            break;  // Выход из цикла
                        }
                    }
                    else {
                        throw std::invalid_argument("Ошибка: Число должно быть в диапазоне от 1 до 9.");
                    }
                }
                else {
                    throw std::invalid_argument("Ошибка: Введите корректное числовое значение.");
                }

            }
            catch (const std::invalid_argument& e) {
                SetConsoleTextAttribute(hConsole, 4);
                cout << e.what() << endl;
                SetConsoleTextAttribute(hConsole, 7);
            }

        }


    }

    cout << "end of program" << endl;
    //_getch(); // удерживает закрытие консоли
    return 0;
}






void menu() {

    cout << "Выберите действие:\n";
    cout << "1. Добавить подразделение\n";
    cout << "2. Вывести список структурных подразделений\n";
    cout << "3. Вывести количество сотрудников структурных подразделений\n";
    cout << "4. Удалить подразделение\n";
    cout << "5. Добавить сотрудника\n";
    cout << "6. Редактировать данные сотрудника\n";
    cout << "7. Вывести список сотрудников\n";
    cout << "8. Удалить сотрудника\n";
    cout << "9. Выход\n";
    SetConsoleTextAttribute(hConsole, 6);
    cout << "действие: ";
    SetConsoleTextAttribute(hConsole, 7);
}