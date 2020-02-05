// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
using namespace std;

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    cout << "Please enter the student's id number: ";
    cout << "Please enter the student's first name: ";
    cout << "Please enter the student's last name: ";
    cout << "Please enter how many assignments were graded: ";
    for(int i = 0; i < student.n_assignments; i++)
    {
        cout << "Please enter grade for assignment "<<i<<": ";
    }
    
    // Call `CalculateStudentAverage(???, ???)`
    CalculateStudentAverage(&student, &average);
    // Output `average`
    printf("Student: %s %s [%d]\d\tAverage grade: %.1f",student.f_name,student.l_name,student.id,average);
    return 0;
}

void calculateStudentAverage(void *object, double *avg)
{
    Student* student = (Student*)object;//Get my student formatted right;
    // Code to calculate and store average grade
    for(int i = 0; i < student.n_assignments; i++)
    {
        *avg = *avg + student.grades[i];
    }
    *avg = *avg / student.n_assignments;
}
