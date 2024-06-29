#include "employees.h"

employees::employees() {
        name = "";
        age = 0;
        pol = "";
        experience = 0;
        salary = 0;
        hoursweek = 0;
    }
employees::employees(std::string name, int age, string pol, double experience, int salary, int hoursweek) {
        this->name = name;
        this->age = age;
        this->pol = pol;
        this->experience = experience;
        this->salary = salary;
        this->hoursweek = hoursweek;
    }

    bool employees::operator<(const employees& other) const {
        return name < other.name;
    }

    void employees::edit_data() {
        std::string tmp = "";
        cout << "Что хотите изменить? (Name, Age, Pol, Experience, Salary, Hoursweek)" << endl;
        cin >> tmp;

        if (tmp == "Name" || tmp == "name") {
            cout << "Введите новое имя: ";
            cin >> name;
            cout << "Данные сотрудника обновлены!\n";
        }
        else if (tmp == "Age" || tmp == "age") {
            cout << "Введите новый возраст: ";
            cin >> age;
            cout << "Данные сотрудника обновлены!\n";
        }
        else if (tmp == "Pol" || tmp == "pol") {
            cout << "Введите новый пол: ";
            cin >> pol;
            cout << "Данные сотрудника обновлены!\n";
        }
        else if (tmp == "Experience" || tmp == "experience") {
            cout << "Введите новый стаж: ";
            cin >> experience;
            cout << "Данные сотрудника обновлены!\n";
        }
        else if (tmp == "Salary" || tmp == "salary") {
            cout << "Введите новую зарплату: ";
            cin >> salary;
            cout << "Данные сотрудника обновлены!\n";
        }
        else if (tmp == "Hoursweek" || tmp == "hoursweek") {
            cout << "Введите новое количество часов в неделю: ";
            cin >> hoursweek;
            cout << "Данные сотрудника обновлены!\n";
        }
        else {
            cout << "Вы ввели неверные данные, которые не обновлены у сотрудника!\n";
        }
    }

    void employees::addemployee(std::set<employees>& employees_list) {
        string tmp5="";
        int employee_count = 0;
        cout << "Введите, сколько сотрудников вы хотите добавить? ";
        cin >> tmp5;
        if (all_of(tmp5.begin(), tmp5.end(), ::isdigit)) {
            employee_count = stoi(tmp5);
            cin.ignore();
            for (int i = 0; i < employee_count; ++i) {
                string name = "", pol = "";
                int age = 0, salary = 0, hoursweek = 0;
                double experience = 0;
                
                string tmp1 = "", tmp2 = "", tmp3 = "", tmp4 = "";

                cout << "Введите имя сотрудника: " << i + 1 << ": ";
                if (i > 0) {
                    cin.ignore();
                }
                getline(cin, name);
                do {
                    
                    cout << "Введите возраст сотрудника: ";
                    cin >> tmp1;
                    if (all_of(tmp1.begin(), tmp1.end(), ::isdigit)) {
                        age = stoi(tmp1);
                        if (age <= 15 || age >= 120) {
                            cout << "Возраст невозможен! Пожалуйста, введите возраст от 16 до 119" << endl;

                        }
                    }
                    else {
                        cout << "Возраст таким быть не может, введите корректно!\n";
                    } 
                } while (age <= 15 || age >= 120);

                cout << "Введите пол сотрудника(m/j): ";
                cin >> pol;


                do {
                    cout << "Введите стаж(опыт) сотрудника: ";
                    cin >> tmp2;
                    if (all_of(tmp2.begin(), tmp2.end(), ::isdigit)) {
                        experience = stoi(tmp2);
                        if (experience <= 0 || experience >= 80) {
                            cout << "Стаж(опыт) таким быть не может!" << endl;
                        }
                    }
                    else {
                        cout << "Опыт таким быть не может, введите корректно!\n";
                    }
                } while (experience <= 0 || experience >= 80);

                do {

                    cout << "Введите зарплату сотрудника: ";
                    cin >> tmp3;
                    if (all_of(tmp3.begin(), tmp3.end(), ::isdigit)) {
                        salary = stoi(tmp3);
                        if (salary <= 0 || salary >= 4000000) {
                            cout << "Зарплата такой быть не может!" << endl;
                        }
                    }
                    else {
                        cout << "Зарплата такой быть не может, введите корректно!\n";
                    } 
                } while (salary <= 0 || salary >= 4000000);

                do {
                    cout << "Введите часы работы в неделю сотрудника: ";
                    cin >> tmp4;
                    if (all_of(tmp4.begin(), tmp4.end(), ::isdigit)) {
                        hoursweek = stoi(tmp4);
                        if (hoursweek > 40) {
                            cout << "Человек не может работать более 40 часов в неделю по закону!" << endl;
                        }
                    }
                    else {
                        cout << "Вводите часы работы корректно!\n";
                    } 
                } while (hoursweek <= 0 || hoursweek > 40);
                employees new_employee(name, age, pol, experience, salary, hoursweek);
                employees_list.insert(new_employee);
            }
            cout << "Сотрудники добавлены!\n";
        }
        else {
            cout << "Введите корректное число!\n";
        }
    }



    void employees::delete_employee(std::set<employees>& employees_set) {
        try {
            if (!employees_set.empty()) {

                cout << "Введите номер сотрудника для удаления: ";
                int index;
                cin >> index;
                if (index >= 1 && index <= employees_set.size()) {
                    auto it = employees_set.begin();
                    std::advance(it, index - 1); // Перемещаем итератор на нужную позицию
                    employees_set.erase(it); // Удаляем сотрудника из set
                    std::cout << "Сотрудник №" << index << " удален!\n";
                }
                else {
                    throw std::out_of_range("Неверный номер сотрудника! Допустимый диапазон: 1-" + std::to_string(employees_set.size()));
                }
            }
            else {
                throw std::runtime_error("Список сотрудников пуст!");
            }
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }


    void employees::print() const {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Pol: " << this->pol << endl;
        cout << "Experience: " << this->experience << endl;
        cout << "Salary: " << this->salary << endl;
        cout << "Hoursweek: " << this->hoursweek << endl;
        cout << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }
 
