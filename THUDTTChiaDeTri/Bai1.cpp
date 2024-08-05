#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int birthYear;
    string address;
};

bool compareByName(const Student& student1, const Student& student2) {
    if (student1.firstName == student2.firstName) {
        return student1.lastName < student2.lastName;
    }
    return student1.firstName < student2.firstName;
}

void displayStudents(const vector<Student>& students) {
    cout << "Danh sach hoc sinh:" << endl;
    for (const auto& student : students) {
        cout << "\tTen: " << student.firstName << " " << student.lastName << endl;
        cout << "\tNam sinh: " << student.birthYear << endl;
        cout << "\tDia chi: " << student.address << endl;
        cout << "-------------------" << endl;
    }
}

int findStudent(const vector<Student>& students, const string& name, int start, int end) {
    if (start > end) {
        return -1; 
    }

    int mid = (start + end) / 2;
    if (students[mid].firstName == name) {
        return mid;
    } else if (students[mid].firstName < name) {
        return findStudent(students, name, mid + 1, end);
    } else {
        return findStudent(students, name, start, mid - 1);
    }
}

int main() {
    vector<Student> students = {
        {"John", "Doe", 2000, "123 Main St"},
        {"Alice", "Smith", 2001, "456 Elm St"},
        {"Bob", "Johnson", 2002, "789 Oak St"},
        {"Alice", "Brown", 2003, "321 Pine St"},
        {"John", "Smith", 2004, "654 Maple St"},
        {"Eva", "Davis", 2005, "987 Cedar St"}
    };

    sort(students.begin(), students.end(), compareByName);
   	displayStudents(students);

    string searchName;
    cout << "Nhap ten hoc sinh can tim: ";
    cin >> searchName;

    int index = findStudent(students, searchName, 0, students.size() - 1);

    if (index != -1) {
        cout << "Thong tin hoc sinh:" << endl;
        cout << "\tTen: " << students[index].firstName << " " << students[index].lastName << endl;
        cout << "\tNam sinh: " << students[index].birthYear << endl;
        cout << "\tDia chi: " << students[index].address << endl;
    } else {
        cout << "Khôong tim thay." << endl;
    }

    return 0;
}