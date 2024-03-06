#include "app.h"
#include <vector>
using namespace std;

int search(vector<staff> list) {
    string ID;
    cin >> ID;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].staff_id == ID) return i;
    }
    return -1;
}

double net_salary(staff employee) {
    double additional = 0;
    double net_salary = 0;
    if (employee.childrent_number > 2) {
        additional += employee.base_salary * 0.05;
    }
    additional += employee.ot_day * 0.04 * employee.base_salary;
    additional += employee.absent_illegal * 0.05 * employee.base_salary;
    if (employee.education_level == "CH") {
        additional += employee.base_salary * 0.1;
    }
    net_salary = additional + employee.base_salary;

    return net_salary;
}

// Staff object
staff creater_staff() {
    staff employee_staff; // init staff

    //Staff ID
    cout << "Nhap ma so nhan vien: " << endl;
    cin >> employee_staff.staff_id;
    while (employee_staff.staff_id.size() > 8) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap ma so nhan vien : " << endl;
        cin >> employee_staff.staff_id;
    }

    //Staff name
    cout << "Nhap ten nhan vien: " << endl;
    cin >> employee_staff.staff_name;
    while (employee_staff.staff_name.size() > 20) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap ten nhan vien : " << endl;
        cin >> employee_staff.staff_name;
    }
    //Staff relationship
    cout << "Nhap tinh trang gia dinh: " << endl;
    cin >> employee_staff.relationship;
    while(employee_staff.relationship != "M" && employee_staff.relationship != "S") {
        cout << "Tinh trang gia dinh khong hop le!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cin >> employee_staff.relationship;
    }
   
    // Staff's children
    cout << "Nhap so con: " << endl;
    cin >> employee_staff.childrent_number;
    while (employee_staff.childrent_number > 20) {
        cout << "So con khong hop le!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap so con: " << endl;
        cin >> employee_staff.childrent_number;
    }

    // Staff' degree
    cout << "Nhap trinh do van hoa: " << endl;
    cin >> employee_staff.education_level;

    // Staff's salary
    cout << "Nhap luong can ban" << endl;
    cin >> employee_staff.base_salary;
    while (employee_staff.base_salary > 1000000) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap luong can ban" << endl;
        cin >> employee_staff.base_salary;
    }

    //Staff's absent legal
    cout << "Nhap so ngay nghi co phep: " << endl;
    cin >> employee_staff.absent_legal;
    while (employee_staff.absent_legal > 28) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap so ngay nghi co phep: " << endl;
        cin >> employee_staff.absent_legal;
    }

    //Staff's absent legal
    cout << "Nhap so ngay nghi khong phep: " << endl;
    cin >> employee_staff.absent_illegal;
    while (employee_staff.absent_illegal > 28) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap so ngay nghi khong phep: " << endl;
        cin >> employee_staff.absent_illegal;
    }
    // Staff' OT day
    cout << "Nhap so ngay lam them: " << endl;
    cin >> employee_staff.ot_day;
    while (employee_staff.absent_illegal > 28) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap so ngay lam them: " << endl;
        cin >> employee_staff.ot_day;;
    }

    //Calculate net income 
    employee_staff.income = net_salary(employee_staff);

    return employee_staff;
}

// Automatically sorting by income
vector<staff>& sorting( vector<staff>& LIST ) {
         for (int i = LIST.size(); i >= 0; i--) {
             for (int j = 1; j < i; j++) {  
                 if (LIST[j - 1].income > LIST[j].income) {
             staff test_band = LIST[j - 1];
                    LIST[j - 1] = LIST[j];
                    LIST[j] = test_band;
                    }
                }
           }

    return LIST;
}

// Choice table
void Choice_table() {
    cout << "=============================" << endl;
    cout << "1. Cap nhap danh sach" << endl;
    cout << "2. Xem bang luong hang thang" << endl;
    cout << "3. Tim thong tin ( voi ID)" << endl;
}

// Change list table 
void choice_option_1() {
    cout << "1. Them nhan vien" << endl;
    cout << "2. Xoa nhan vien" << endl;
    cout << "Nhap lua chon cua ban: " << endl;
}

// Display details
void show_detail(staff employee) {
    cout << "Ma nhan vien: " << employee.staff_id << endl;
    cout << "Ten: " << employee.staff_name << endl;
    cout << "Tinh trang gia dinh: " << employee.relationship << endl;
    cout << "So con: " << employee.childrent_number << endl;
    cout << "Trinh do van hoa: " << employee.education_level << endl;
    cout << "Luong co ban: " << employee.base_salary << endl;
}

// Special case for show details
void show_detail(vector<staff> list, int index) {
    if (index == -1) cout << "Nhan vien khong ton tai" << endl;
    else {
        show_detail(list[index]);
    }
}

// Show salary
void show_salary_of_staff(staff employee) {
    cout << "Ma nhan vien: " << employee.staff_id << endl;
    cout << "Ten: " << employee.staff_name << endl;
    cout << "Luong hang thang: " << employee.income << endl;
    cout << "=============================" << endl;
}

// Add more employer into list
vector<staff>& add_employee_to_list(vector<staff>& list) {
    staff employee = creater_staff();
    list.push_back(employee);
    list = sorting(list);
    return list;
}

// Remove employ to list
 vector<staff>& removed_employee_to_list(vector<staff>& list) {
     cout << "Nhap ma nhan vien can xoa: ";
     int temporatory_index = search(list);
     if (temporatory_index == -1) cout << "Nhan vien khong ton tai";
     else {
         list.erase(list.begin() + temporatory_index);
         cout << "Da xoa thanh cong" << endl;
     }
     return list;
 }



