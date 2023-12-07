#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
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



    return 0;
}