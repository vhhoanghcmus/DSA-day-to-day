#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct staff
{
    string staff_id;
    string staff_name;
    string relationship;
    short childrent_number = 0;
    string education_level;
    int base_salary = 0;
    short absent_legal = 0;
    short absent_illegal = 0;
    short ot_day = 0;
    string result[2];
    double income;
};

vector<staff>& removed_employeer_to_list(vector<staff>& list);
vector<staff>& add_employeer_to_list(vector<staff>& list);
void show_salary_of_staff(staff employeer);
void show_detail(vector<staff> list, int index);
void show_detail(staff employeer);
void choice_option_1();
void Choice_table();
staff creater_staff();
double net_salary(staff employeer);
int search(vector<staff> list);