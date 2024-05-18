
#include <bits/stdc++.h>

using namespace std;

struct Student
{
    char name[25];
    unsigned int ID;
    float GPA;
    Student *pNext = NULL;
};

typedef struct Student STUDENT;

struct Link_list {
    STUDENT *pHead = NULL;
    STUDENT *pTail = NULL;
};

STUDENT* createStudent() {
    STUDENT *pStudent = new STUDENT;

    cout << "Nhap ID:  ";
    cin >> pStudent->ID;

    cout << "Nhap ten: ";
    cin >> pStudent->name;

    cout << "Nhap GPA: ";
    cin >> pStudent-> GPA;

    return pStudent;
}

typedef struct Link_list LIST;

void addStudentLeft(LIST &l, STUDENT *p) {
    if(l.pHead == NULL) l.pHead = l.pTail = p;
    else {
        l.pTail -> pNext = p;
        l.pTail = p;
    }
}

void addStudentRight(LIST &l, STUDENT *p) {
    if(l.pHead == NULL) l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void DeleteStudent(LIST &l, STUDENT *p) {
    STUDENT *pStudent = l.pHead;
    for(;pStudent != NULL; pStudent->pNext ) {
        if(pStudent == p) {
            pStudent->pNext = pStudent->pNext->pNext;
        }
    }
    delete pStudent;
}
void Search( LIST &l, unsigned int ID ) {
     STUDENT *pStudent = l.pHead;
     for(;pStudent != NULL; pStudent->pNext ) {
        if(pStudent->ID == ID) {
            cout << pStudent->ID << " " << endl;
            cout << pStudent->name << " " << endl;
            cout << pStudent->GPA << endl;
        }
    }
}
void showData( LIST l){
    STUDENT *pStudent = new Student;
    pStudent = l.pHead;
    for( ; pStudent != NULL; pStudent = pStudent->pNext)
    {
        cout << "ID: " << pStudent->ID << endl;
        cout << "Name: " << pStudent -> name << endl;
        cout << "GPA: " << pStudent -> GPA << endl;       
    }
    delete pStudent;
}

int getMax(LIST &l) {
    STUDENT *pStudent = new Student;
    pStudent = l.pHead;
    double max = 0;
    while (pStudent != NULL) {
        if (pStudent->GPA > max)
            max = pStudent->GPA;
        pStudent = pStudent->pNext;
    }
    return max;
}

void AppendList(LIST  &l, LIST &l1) {
    if(l.pHead) {
        l.pTail -> pNext = l.pHead;
        l.pTail = l1.pTail;
    }
    else l = l1;
}

int getDigit(long N, int k) {
    switch (k)
    {
    case 0: return (N % 10);
    case 1: return ((N % 100) % 10);
    case 2: return ((N % 1000) % 10);
    case 3: return ((N % 10000) % 10);
    case 4: return ((N % 100000) % 10);
    case 5: return ((N % 1000000) % 10);
    case 6: return ((N % 10000000) % 10);
    case 7: return ((N % 100000000) % 10);
    case 8: return ((N % 1000000000) % 10);
    case 9: return ((N % 10000000000) % 10);
    }
}
void ListRadixSort(LIST & l, int m) {
    LIST B[10];
    STUDENT *p;
    int i, k;
    if(l.pHead == l.pTail) return;
    for( i = 0; i < 10; i++){
        B[i].pHead = B[i].pTail = NULL;
    }
    for( k = 0; k < m; k++){
        while(l.pHead) {
            p = l.pHead;
            l.pHead = p->pNext;
            p->pNext = NULL;
            i = getDigit(p->GPA, k);
            addStudentRight(B[i], p);
        }
        l = B[0];
        for( i = 1; i < 10; i++) {
            AppendList(l, B[i]);
        }
    }
}


void Distribute(LIST &l, LIST &l1, LIST &l2) {
    cout << "2";
    STUDENT *p;
    do
    {
        p = l.pHead;
        l.pHead = p->pNext;
        p->pNext = NULL;

        addStudentRight(l1,p);
    } while ((l.pHead) && (p->GPA <= l.pHead->GPA));
    if(l.pHead) {
        Distribute(l, l1, l2);
    }
    else l.pTail = NULL;
}

void MergeList( LIST &l, LIST &l1, LIST &l2) {
    cout << 3;
    STUDENT *p;
    while((l1.pHead) && (l2.pHead)) {
        if(l1.pHead->GPA <= l2.pHead->GPA) {
            p = l1.pHead;
            l1.pHead = p->pNext;
        }
        else {
            p = l2.pHead;
            l2.pHead = p->pNext;
        }
        p->pNext = NULL;
        addStudentRight(l,p);
    }
    if(l1.pHead) {
        l.pTail->pNext = l1.pHead;
        l.pTail = l1.pTail;
    }
    else if( l2.pHead ) {
        l.pTail->pNext = l2.pHead;
        l.pTail = l2.pTail;
    }
}

void ListMergeSort(LIST &l) {
    cout << "1";
    LIST l1, l2;
    if(l.pHead == l.pTail ) return;
    Distribute(l, l1, l2);
    ListMergeSort(l1);
    ListMergeSort(l2);
    MergeList(l, l1,l2);
}

int main () {
    LIST l;
    STUDENT a, b;

    a.GPA = 2;
    b.GPA = 10;

    addStudentRight(l, &a);
    addStudentRight(l, &b);
    showData(l);

    ListRadixSort(l, 3);
    showData(l);
    return 1;
}