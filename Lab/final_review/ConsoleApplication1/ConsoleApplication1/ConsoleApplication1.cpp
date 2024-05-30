#include <iostream>
#include <vector>
#include <cstring> // Include this header for string manipulation

using namespace std;

struct Student {
    char fullName[20];
    char studentID[10];
    double finalGrade[5];
    double averagePoint = 0;
};

Student Nhap() {
    Student student;
    cout << "Nhap ten: ";
    cin.getline(student.fullName, 20);
    cout << "Nhap ID: ";
    cin.getline(student.studentID, 10);
    for (int i = 0; i < 5; i++) {
        cout << "Nhap diem mon thu " << i << " : ";
        cin >> student.finalGrade[i];
        student.averagePoint += student.finalGrade[i];
    }
    student.averagePoint /= 5;
    cin.ignore(); // Ignore the newline character left in the input buffer
    return student;
}

void Xuat(Student v) {
    cout << "Ten: " << v.fullName << endl;
    cout << "Student ID: " << v.studentID << endl;
    for (int i = 0; i < 5; i++) {
        cout << " Diem mon thu " << i << " : " << v.finalGrade[i] << endl;
    }
    cout << "Student average point: " << v.averagePoint << endl;
}

// Function to find a student by their student ID
//Student FindStudentByID(const vector<Student>& students, const char* targetID) {
//    for (const auto& student : students) {
//        if (strcmp(student.studentID, targetID) == 0) {
//            return student;
//        }
//    }
//    // Return an empty student if not found
//    Student emptyStudent;
//    emptyStudent.fullName[0] = '\0';
//    emptyStudent.studentID[0] = '\0';
//    return emptyStudent;
//}
//
//void FixStudentByID( vector<Student>& students, const char* targetID) {
//    for (auto& student : students) {
//        if (strcmp(student.studentID, targetID) == 0) {
//            cout << "Nhap ten moi: ";
//            cin.getline(student.fullName, 20);
//            cout << "Doi thanh cong !!";
//        }
//    }
//}

// Heap Max Sort


void heapify(vector<Student> LIST, int N, int i) {

    int lagest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < N && LIST[l].averagePoint > LIST[lagest].averagePoint) {
        lagest = l;
    }

    if (r < N && LIST[r].averagePoint > LIST[lagest].averagePoint) {
        lagest = r;
    }

    if (lagest != i) {
        swap(LIST[i], LIST[lagest]);
        heapify(LIST, N, lagest);
    }
}

void heapSort(vector<Student> LIST, int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(LIST, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(LIST[0], LIST[i]);
        cout << " Swap completer";
        // call max heapify on the reduced heap
        heapify(LIST, i, 0);
    }
    cout << "Complete!!";
}
int main() {
    vector<Student> List;
    List.push_back(Nhap());
    List.push_back(Nhap());
    // Example usage: Find a student by ID
    char targetID[10];
    cout << "Nhap student ID can tim: ";
    cin.getline(targetID, 10);

    /*Student foundStudent = FindStudentByID(List, targetID);
    if (foundStudent.fullName[0] != '\0') {
        cout << "Thong tin cua sinh vien co ID " << targetID << ":" << endl;
        Xuat(foundStudent);
    }
    else {
        cout << "Khong tim thay sinh vien co ID " << targetID << endl;
    }
    cout << "Nhap student ID can doi: ";
    cin.getline(targetID, 10);
    FixStudentByID(List, targetID);*/

    for (auto v : List) Xuat(v);

    int N = List.size();

    heapSort(List, 2);

    for (auto v : List) Xuat(v);

    return 1;
}