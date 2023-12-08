#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
#include "StudentService.h"
#include "StudentServiceImpl.h"
#include <vector>

using namespace std;

int main() {
    Student student(1,"Nagy", "Henrietta");
    student.addGrade("Math", 9.75);
    student.addGrade("Romanian", 8.7);
    student.addGrade("Hungarian", 7.5);
    cout << student << endl;
    student.computeAverage();
    cout << student << endl;


    Student student2(2,"Nagy", "Alpar");
    student2.addGrade("Math", 5);
    student2.addGrade("Romanian", 5.1);
    student2.addGrade("Hungarian", 6.30);
    cout << student2 << endl;
    student.computeAverage();
    cout << student2 << endl;

    Student student3(3,"Nagy", "Kinga");
    student3.addGrade("Math", 5);
    student3.addGrade("Romanian", 4.1);
    student3.addGrade("Hungarian", 6.30);
    cout << student3 << endl;
    student.computeAverage();
    cout << student3 << endl;

    cout << "----------------------------------" << endl;

    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    vector<string> subjects = {"Math", "Romanian", "Hungarian"};
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < subjects.size(); ++i) {
        dao.saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;

    cout<< "*******************************"<< endl;

    StudentService* service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector<string> subjects = service->getSubjects(id);
        for (int i = 0; i < subjects.size(); ++i) {
            cout << "\t" << subjects[i] << ": " <<
                 service->getResultBySubject(id, subjects[i]) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }
    delete service;

    return 0;
}