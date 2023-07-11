#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Student {
private:
    string studentID;
    string fullName;
    string dateOfBirth;
    int admissionYear;
    float admissionScore;
    vector<pair<string, float>> academicRecords; // danh sách kết quả học tập

public:
    Student() {}
    Student(string id, string name, string dob, int year, float score) : studentID(id), fullName(name), dateOfBirth(dob), admissionYear(year), admissionScore(score) {}

    void input() {
        cout << "Enter student ID: ";
        getline(cin, studentID);
        cout << "Enter full name: ";
        getline(cin, fullName);
        cout << "Enter date of birth: ";
        getline(cin, dateOfBirth);
        cout << "Enter admission year: ";
        cin >> admissionYear;
        cout << "Enter admission score: ";
        cin >> admissionScore;
        cin.ignore(); // clear input buffer
    }

    void output() {
        cout << "Student ID: " << studentID << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Admission Year: " << admissionYear << endl;
        cout << "Admission Score: " << admissionScore << endl;
    }

    bool isRegularStudent() {
        // example condition to determine regular students
        return (admissionScore >= 8.0);
    }

    float getAverageScore(string semester) {
        float total = 0;
        int count = 0;

        for (const auto& record : academicRecords) {
            if (record.first == semester) {
                total += record.second;
                count++;
            }
        }

        if (count > 0) {
            return total / count;
        } else {
            throw invalid_argument("No records found for the given semester.");
        }
    }
};

class RegularStudent : public Student {
public:
    RegularStudent() {}
    RegularStudent(string id, string name, string dob, int year, float score) : Student(id, name, dob, year, score) {}
};

class PartTimeStudent : public Student {
private:
    string trainingLocation;
public:
    PartTimeStudent() {}
    PartTimeStudent(string id, string name, string dob, int year, float score, string location) : Student(id, name, dob, year, score), trainingLocation(location) {}
};

class Department {
private:
    string departmentName;
    vector<Student*> students;

public:
    Department() {}
    Department(string name) : departmentName(name) {}

    void addStudent(Student* student) {
        students.push_back(student);
    }

    int countRegularStudents() {
        int count = 0;

        for (const auto& student : students) {
            if (student->isRegularStudent()) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    // Your code goes here
    return 0;
}

