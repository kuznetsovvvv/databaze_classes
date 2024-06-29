#include"structual_divisions.h"

structual_divisions::structual_divisions(const string& name, const string& head, int number, std::vector<string> names) {
        this->department_name = name;
        this->department_head = head;
        this->number_of_employees = number;
        this->employee_names = names;
    }

 void structual_divisions::add_division(set<structual_divisions>& divisions_set) {
     int division_count = 0;
     cout << "Сколько подразделений вы хотите добавить? ";
     cin >> division_count;
     cin.ignore(); 

     for (int i = 0; i < division_count; ++i) {
         string name, head;
         string value;
         vector<string> names; // Используем vector
         int number = 0;
         cout << "Введите название подразделения " << i + 1 << ": ";
         getline(cin, name);
         cout << "Введите имя руководителя: ";
         getline(cin, head);
         do {

             cout << "Введите количество сотрудников: ";
             cin >> value;
             if (all_of(value.begin(), value.end(), ::isdigit)) {
                 number = stoi(value);
                 if (number < 0 || number>100) {
                     cout << "Невозможное количество сотрудников!\n";
                 }
             }
             else {
                 cout << "Введите число!" << endl;
             }
         } while (number < 0 || number>100);

         cin.ignore(); // Игнорируем оставшийся символ новой строки

         // Запрос имен сотрудников
         names.reserve(number); // Выделяем память для эффективности
         for (int j = 0; j < number; j++) {
             cout << "Введите имя сотрудника " << j + 1 << ": ";
             string employee_name;
             getline(cin, employee_name);
             names.push_back(employee_name);
         }

         // Создание объекта подразделения и добавление в set
         divisions_set.insert(structual_divisions(name, head, number, names));
     }
     cout << "Подразделения добавлены!\n";
    }




     void structual_divisions::print_employee_count(const set<structual_divisions>& divisions_set) {
         try {
             if (!divisions_set.empty()) {


                 for (const auto& division : divisions_set) {
                     cout << division.department_name << ": " << division.number_of_employees << " сотрудникoв(а)\n";
                 }
             }
             else {
                 throw std::out_of_range("Список подразделений пуст!\n");
             }
         }
         catch (const std::out_of_range& e) {
             cerr << e.what();
         }
     }

     void structual_divisions::remove_division(set<structual_divisions>& divisions_set) {
         try {
             if (!divisions_set.empty()) {
                 int division_number;
                 cout << "Введите номер подразделения для удаления: ";
                 cin >> division_number;

                 if (!(division_number < 1 || division_number > divisions_set.size())) {

                     auto it = divisions_set.begin();
                     advance(it, division_number - 1); // Перемещаем итератор к нужному элементу
                     divisions_set.erase(it);
                     cout << "Подразделение №" << division_number << " удалено.\n";
                 }
                 else
                 {
                     throw std::invalid_argument("Неверный номер подразделения!\n");
                 }


             }
             else {
                 throw std::out_of_range("Список подразделений пуст!\n");
             }
         }
         catch (const std::out_of_range& e) {
             cerr << e.what();
         }
         catch (const std::invalid_argument& e) {
             cerr << e.what();
         }
    }


    void structual_divisions::print() const {
        cout << "Название: " << department_name << endl;
        cout << "Руководитель: " << department_head << endl;
        cout << "Количество сотрудников: " << number_of_employees << endl;
        if (!employee_names.empty()) {
            cout << "Сотрудники: ";
            for (const auto& name : employee_names) {
                cout << name << "; ";
            }
            cout << endl;
        }
    }

     void structual_divisions::print_divisions(const set<structual_divisions>& divisions_set) {
         try {
             if (!divisions_set.empty()) {



                 int i = 1;
                 for (const auto& division : divisions_set) {
                     cout << "Подразделение №" << i << ":\n";
                     division.print();
                     i++;
                 }
             }
             else {
                 throw std::out_of_range("Список подразделений пуст!\n");
             }
         }
         catch (const std::out_of_range& e) {
             cerr << e.what();
         }
     }

    bool structual_divisions::operator<(const structual_divisions& other) const {
        return department_name < other.department_name;
    }
