#pragma once

#include<stdio.h>
#include<vector>
#include"structual_divisions.h"
#include"employees.h"
using namespace std;
class employees {
    std::string name;// имя
    int age;// возраст
    std::string pol;// пол
    double experience;//стаж в годах
    int salary;//зарплата
    int hoursweek;
public:
    employees();
    employees(std::string name, int age, string pol, double experience, int salary, int hoursweek);
    bool operator<(const employees& other) const;
    void edit_data();
    static void addemployee(std::set<employees>& employees_list);
    static void delete_employee(std::set<employees>& employees_set);
    void print() const;  
};
