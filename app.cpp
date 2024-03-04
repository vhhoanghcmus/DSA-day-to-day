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

double net_salary(staff employeer) {
    double additional = 0;
    double net_salary = 0;
    if (employeer.childrent_number > 2) {
        additional += employeer.base_salary * 0.05;
    }
    additional += employeer.ot_day * 0.04 * employeer.base_salary;
    additional += employeer.absent_illegal * 0.05 * employeer.base_salary;
    if (employeer.education_level == "CH") {
        additional += employeer.base_salary * 0.1;
    }
    net_salary = additional + employeer.base_salary;

    return net_salary;
}

staff creater_staff() {
    staff employeer_staff;
    cout << "Nhap ma so nhan vien: " << endl;
    cin >> employeer_staff.staff_id;
    while (employeer_staff.staff_id.size() > 8) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap ma so nhan vien : " << endl;
        cin >> employeer_staff.staff_id;
    }

    cout << "Nhap ten nhan vien: " << endl;
    cin >> employeer_staff.staff_name;
    while (employeer_staff.staff_name.size() > 20) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap ten nhan vien : " << endl;
        cin >> employeer_staff.staff_name;
    }

    cout << "Nhap tinh trang gia dinh: " << endl;
    cin >> employeer_staff.relationship;
    while(employeer_staff.relationship != "M" && employeer_staff.relationship != "S") {
        cout << "Tinh trang gia dinh khong hop le!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cin >> employeer_staff.relationship;
    }
   

    cout << "Nhap so con: " << endl;
    cin >> employeer_staff.childrent_number;
    while (employeer_staff.childrent_number > 20) {
        cout << "So con khong hop le!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap so con: " << endl;
        cin >> employeer_staff.childrent_number;
    }

    cout << "Nhap trinh do van hoa: " << endl;
    cin >> employeer_staff.education_level;

    cout << "Nhap luong can ban" << endl;
    cin >> employeer_staff.base_salary;
    while (employeer_staff.base_salary > 1000000) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap luong can ban" << endl;
        cin >> employeer_staff.base_salary;
    }

    cout << "Nhap so ngay nghi co phep: " << endl;
    cin >> employeer_staff.absent_legal;
    while (employeer_staff.absent_legal > 28) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap so ngay nghi co phep: " << endl;
        cin >> employeer_staff.absent_legal;
    }

    cout << "Nhap so ngay nghi khong phep: " << endl;
    cin >> employeer_staff.absent_illegal;
    while (employeer_staff.absent_illegal > 28) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap so ngay nghi khong phep: " << endl;
        cin >> employeer_staff.absent_illegal;
    }

    cout << "Nhap so ngay lam them: " << endl;
    cin >> employeer_staff.ot_day;
    while (employeer_staff.absent_illegal > 28) {
        cout << "Nhap loi!!!" << endl;
        cout << "Vui long nhap lai" << endl;
        cout << "Nhap so ngay lam them: " << endl;
        cin >> employeer_staff.ot_day;;
    }

    employeer_staff.income = net_salary(employeer_staff);

    return employeer_staff;
}

void Choice_table() {
    cout << "=============================" << endl;
    cout << "1. Cap nhap danh sach" << endl;
    cout << "2. Xem bang luong hang thang" << endl;
    cout << "3. Tim thong tin ( voi ID)" << endl;
}
void choice_option_1() {
    cout << "1. Them nhan vien" << endl;
    cout << "2. Xoa nhan vien" << endl;
    cout << "Nhap lua chon cua ban: " << endl;
}
void show_detail(staff employeer) {
    cout << "Ma nhan vien: " << employeer.staff_id << endl;
    cout << "Ten: " << employeer.staff_name << endl;
    cout << "Tinh trang gia dinh: " << employeer.relationship << endl;
    cout << "So con: " << employeer.childrent_number << endl;
    cout << "Trinh do van hoa: " << employeer.education_level << endl;
    cout << "Luong co ban: " << employeer.base_salary << endl;
}
void show_detail(vector<staff> list, int index) {
    if (index == -1) cout << "Nhan vien khong ton tai" << endl;
    else {
        show_detail(list[index]);
    }
}
void show_salary_of_staff(staff employeer) {
    cout << "Ma nhan vien: " << employeer.staff_id << endl;
    cout << "Ten: " << employeer.staff_name << endl;
    cout << "Luong hang thang: " << employeer.income << endl;
    cout << "=============================" << endl;
}

vector<staff>& add_employeer_to_list(vector<staff>& list) {
    staff employeer = creater_staff();
    list.push_back(employeer);
    return list;
}

 vector<staff>& removed_employeer_to_list(vector<staff>& list) {
     cout << "Nhap ma nhan vien can xoa: ";
     int temporatory_index = search(list);
     if (temporatory_index == -1) cout << "Nhan vien khong ton tai";
     else {
         list.erase(list.begin() + temporatory_index);
         cout << "Da xoa thanh cong" << endl;
     }
     return list;
 }



