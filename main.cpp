#include <iostream>
#include "app.h"
#include <conio.h>

using namespace std;
int choice_flag = 0;

int main() {
    vector<staff> list_employ;
    while (1) {
        Choice_table();
        cout << "Nhap lua chon: " << endl;
        cin >> choice_flag;
        switch (choice_flag)
        {
        case 1:
            choice_option_1();
            int tflag;
            cin >> tflag;
            if (tflag == 1) add_employeer_to_list(list_employ);
            if (tflag == 2) removed_employeer_to_list(list_employ);
            break;
        case 2:
        case 3:
            cout << " Nhap ma nhan vien can tim kiem: ";
            show_detail(list_employ, search(list_employ));
            break;
            
        default:
            break;
        }
    }
    return 0;
}