// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#define NAMESIZE 128
#define NUMSIZE 10
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
    string input;
    bool isZero = true;
    int n_assignments;
    string::size_type st;
    // Set up pointers
    student.f_name = new char[NAMESIZE];
    student.l_name = new char[NAMESIZE];
    // Sequence of user input -> store in fields of `student`
    cout << "Please enter the student's id number: ";
    cin >> input;
    while(cin.fail() || input.find_first_not_of("0123456789") != string::npos){
      cout << "Sorry, I cannot understand your answer" << endl;
      if( input.find_first_not_of("0123456789") == string::npos){
	cin.clear();
	cin.ignore();
      }

      cout << "Please enter the student's id number: ";
      
      cin >> input;
    }
    
    student.id = stoi(input,&st);
    
    //printf("We have an ID: %d\n",student.id);
    
    //First name
    cout << "Please enter the student's first name: ";
    cin >> input;
    strcpy(student.f_name,input.c_str());


    //Last name
    cout << "Please enter the student's last name: ";
    cin >> input;
    strcpy(student.l_name,input.c_str());
    //printf("\n\nStudent: %s %s [%d]\n",student.f_name,student.l_name,student.id);

    
    //Number of Assignments
    do{
      cout << "Please enter how many assignments were graded: ";
      input = "";
      cin >> input;
      //printf("getting input %s\n",input.c_str());
      while(cin.fail() || input.find_first_not_of("0123456789") != string::npos){
	cout << "Sorry, I cannot understand your answer" << endl;
	if( input.find_first_not_of("0123456789") == string::npos){
	  cin.clear();
	  cin.ignore();
	}
	cout << "Please enter how many assignments were graded: ";
	
	cin >> input;
      }//while failed

      n_assignments = stoi(input, &st);
      if(n_assignments != 0){
	isZero = false;
      }
    }while(isZero);
      student.n_assignments = stoi(input,&st);
      student.grades = new double[student.n_assignments];
      cout<<endl;

    
    //Scores
    for(int i = 0; i < student.n_assignments; i++)
    {
      cout << "Please enter grade for assignment "<<i<<": ";
      cin >> input;
      while(cin.fail() || input.find_first_not_of("0123456789.") != string::npos || count(input.begin(),input.end(),'.') > 1){
	cout << "Sorry, I cannot understand your answer" << endl;
	if( input.find_first_not_of("0123456789.") == string::npos || count(input.begin(),input.end(),'.') > 1){
	  cin.clear();
	  cin.ignore();
	  input = "";
	}
	cout << "Please enter grade for assignment "<<i<<": ";
	cin >> input;
      }
      //printf("Our input is %s\n",input.c_str());
      student.grades[i] = std::stod(input);
      //printf("Our input is %s, the value is %f\n",input.c_str(),student.grades[i]);
    }
    cout<<endl;




    
    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, &average);
    // Output `average`
    printf("Student: %s %s [%d]\n  Average grade: %.1f\n",student.f_name,student.l_name,student.id,average);
    // */
    return 0;
}

void calculateStudentAverage(void *object, double *avg)
{
    Student* student = (Student*)object;//Get my student formatted right;
    // Code to calculate and store average grade
    for(int i = 0; i < student->n_assignments; i++)
    {
        *avg = *avg + student->grades[i];
    }
    *avg = *avg / student->n_assignments;
}
