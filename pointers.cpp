// compile: g++ -std=c++11 -o pointers.o pointers.cpp

/***********************
Author: Brandon Tran
Date Created: Feb 05, 2020
Last Updated: Feb 12, 2020
Description:
  First assignment for CISC 310 Operating Systems.
 Program takes in user input and generates an 
 average grade for a student


************************/

#include <algorithm> // used for count function
#include <iostream> // cout and cin
#include <string> //For C++ String methods
#include <cstring> //For strcpy

#define NAMESIZE 128
using namespace std;

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;


//Function Prototyping
void calculateStudentAverage(void *object, double *avg);


int main(int argc, char **argv){
  // INITIALIZE VARIABLES
  Student student;
  double average;
  string input; //cin goes into this string
  bool isZero = true;//Assume is true to start
  string::size_type st;//Used in stoi/stod
  //-------------------------------------------------------
  // Sequence of user input -> store in fields of `student`
  //-------------------------------------------------------

  //STUDENT ID
  cout << "Please enter the student's id number: ";
  cin >> input;
  //CHECK FOR VALID ID
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

  //INITIALIZE FIRST NAME AND LAST NAME
  student.f_name = new char[NAMESIZE];
  student.l_name = new char[NAMESIZE];
  
  //FIRST NAME
  cout << "Please enter the student's first name: ";
  cin >> input;
  strcpy(student.f_name,input.c_str());
    
    
  //LAST NAME
  cout << "Please enter the student's last name: ";
  cin >> input;
  strcpy(student.l_name,input.c_str());
    
  //NUMBER OF ASSIGNMENTS
  do{
    //Do while number of assignments is not zero
    cout << "Please enter how many assignments were graded: ";
    cin >> input;
    while(cin.fail() || input.find_first_not_of("0123456789") != string::npos){
      cout << "Sorry, I cannot understand your answer" << endl;
      if( input.find_first_not_of("0123456789") == string::npos){
	cin.clear();
	cin.ignore();
      }
      cout << "Please enter how many assignments were graded: ";
      cin >> input;
    }
    
    if(stoi(input,&st) != 0){
      isZero = false;
    }    
  }while(isZero);
  student.n_assignments = stoi(input,&st);
  
  //Inialize struct with proper array
  student.grades = new double[student.n_assignments];

  //Add new line to match formatting
  cout<<endl;
  
  //SCORES
  for(int i = 0; i < student.n_assignments; i++){
    cout << "Please enter grade for assignment "<<i<<": ";
    cin >> input;
    while(cin.fail() || input.find_first_not_of("0123456789.") != string::npos || count(input.begin(),input.end(),'.') > 1){
      cout << "Sorry, I cannot understand your answer" << endl;
      if( input.find_first_not_of("0123456789.") == string::npos || count(input.begin(),input.end(),'.') > 1){
	cin.clear();
	cin.ignore();
      }
      cout << "Please enter grade for assignment "<<i<<": ";
      cin >> input;
    }
    student.grades[i] = std::stod(input);
  }

  //Add additional new line to match formatting
  cout<<endl;  
  
  // Call `CalculateStudentAverage(???, ???)`
  calculateStudentAverage(&student, &average);
  
  // Output `average`
  printf("Student: %s %s [%d]\n  Average grade: %.1f\n",student.f_name,student.l_name,student.id,average);
  return 0;
}// int main()

void calculateStudentAverage(void *object, double *avg){
    Student* student = (Student*)object;//Get pointer formatted right;
    // Code to calculate and store average grade
    for(int i = 0; i < student->n_assignments; i++){
        *avg = *avg + student->grades[i];
    }
    *avg = *avg / student->n_assignments;
}//calculateStudentAverage
