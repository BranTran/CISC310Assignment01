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
    string input;
    // Set up pointers
    student.f_name = new char[128];
    student.l_name = new char[128];
    // Sequence of user input -> store in fields of `student`
    cout << "Please enter the student's id number: ";
    getline(cin, input);
    while(cin.fail() || cin.eof() || input.find_first_not_of("0123456789") != string::npos){
      cout << "Sorry, I cannot understand your answer" << endl;
      if( input.find_first_not_of("0123456789") == string::npos){
	cin.clear();
	cin.ignore();
      }

      cout << "Please enter the student's id number: ";
      
      getline(cin,input);
    }
    string::size_type st;
    student.id = stoi(input,&st);
    
    printf("We have an ID: %d\n",student.id);
    
    cout << "Please enter the student's first name: ";
    cin >> student.f_name;
    cout << "Please enter the student's last name: ";
    cin >> student.l_name;

    cout << "Please enter how many assignments were graded: ";
    getline(cin, input);
    while(cin.fail() || cin.eof() || input.find_first_not_of("0123456789") != string::npos){
      cout << "Sorry, I cannot understand your answer" << endl;
      if( input.find_first_not_of("0123456789") == string::npos){
	cin.clear();
	cin.ignore();
      }
      cout << "Please enter how many assignments were graded: ";
      
      getline(cin,input);
    }
    student.n_assignments = stoi(input,&st);





    for(int i = 0; i < student.n_assignments; i++)
    {
      cout << "Please enter grade for assignment "<<i<<": ";
      getline(cin, input);
      while(cin.fail() || cin.eof() || input.find_first_not_of("0123456789.") != string::npos){
	cout << "Sorry, I cannot understand your answer" << endl;
	if( input.find_first_not_of("0123456789.") == string::npos){
	  cin.clear();
	  cin.ignore();
	}
	cout << "Please enter grade for assignment "<<i<<": ";
	
	getline(cin,input);
      }
      student.grades[i] = stof(input,&st);	
    }
    
    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, &average);
    // Output `average`
    printf("Student: %s %s [%d]\n\tAverage grade: %.1f\n",student.f_name,student.l_name,student.id,average);
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
