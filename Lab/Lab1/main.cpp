#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct student
{
    string name;
    unsigned int studentID;
    double GPA;
};
void show(vector<student> L) {
    for( int i = 0; i < L.size(); i++) {
        cout << L[i].studentID << " ";
        cout << L[i].GPA <<  " ";
        cout << L[i].name << endl;
    }
}

student initStudentData(){
    student student_staff;
    cout << "Nhap ten sinh vien" << endl;
    cin >> student_staff.name;

    // while (student.name.size() > 20){
    //     cout << "Ten qua dai!! Vui long nhap lai" << endl;
    //     cin >> student.name;
    // }
    cout << "Nhap ma so sinh vien" << endl;
    cin >> student_staff.studentID;
    cout << "Nhap diem trung binh" << endl;
    cin >> student_staff.GPA;
    return student_staff;
}
void sortStudentList(vector<student> &L) {
    int i, j, n = L.size(); 
    int min_idx;

      // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < n - 1; i++) { 
  
        // Find the minimum element in 
        // unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) { 
            if (L[j].GPA < L[min_idx].GPA) 
                min_idx = j; 
        } 
  
        // Swap the found minimum element 
        // with the first element 
        if (min_idx != i) 
            swap(L[min_idx], L[i]); 
    }
    show(L);
}

void search(vector<student> L) {
    unsigned int IDstudent;
    cout << "Nhap ma so sinh vien can tim: ";
    cin >> IDstudent;
    for( int i = 0; i < L.size(); i++) {
        if(L[i].studentID = IDstudent) {
        cout << L[i].studentID << " ";
        cout << L[i].GPA <<  " ";
        cout << L[i].name << endl;
        }
    }

}

void Write_file(vector<student> L){
    ofstream outfile;  
    outfile.open("data.txt");
    outfile << L.size() << endl; 
    for( int i = 0; i < L.size(); i++) {
          outfile << L[i].studentID << " " << L[i].GPA << " " << L[i].name << endl; 
    }
    outfile.close();   
}

void read_file(){
    static vector<student> StudentList;
    ifstream infile;
    vector<string> temp; 
    infile.open("data.txt");
    if (infile.fail()) cout << "Failed to open this file!" << endl;
    while (!infile.eof())
{
	string n;
	if (infile >> n)
		temp.push_back(n);
}
  
    for( int i = 1; i < temp.size(); i+= 3) {
        student Student;
        istringstream iss(temp[i]);
        iss >> Student.studentID;
        StudentList.push_back(Student);
        }
    int count = 0;
        for( int i = 2; i < temp.size(); i+= 3) {
        StudentList[count].GPA = stod(temp[i]);
        count++;
        }
    count = 0;
        for( int i = 3; i < temp.size(); i+= 3) {
        StudentList[count].name = temp[i];
        count++;
        }
        sortStudentList(StudentList);
}




int main() {
    vector<student> List_student;
    initStudentList(List_student);
    read_file();
    return 1;
}