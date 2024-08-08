#pragma once
#include<set>
#include <iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;
class structual_divisions {
    string department_name;
    string department_head;
    int number_of_employees;
    vector<string> employee_names;
public:
    structual_divisions(const string& name, const string& head, int number, std::vector<string> names);
    static void add_division(set<structual_divisions>& divisions_set); 
    static void print_employee_count(const set<structual_divisions>& divisions_set);
    static void remove_division(set<structual_divisions>& divisions_set);
    void print() const;
    static void print_divisions(const set<structual_divisions>& divisions_set);
    bool operator<(const structual_divisions& other) const;    
};
