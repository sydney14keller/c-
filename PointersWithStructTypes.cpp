//
// Examples of structures with pointers and functions
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct date
{
	unsigned int month;
	unsigned int day;
	unsigned int year;
};

struct student_record
{
	string firstname;
	string lastname;
	date birthdate;
	float gpa;
	double exam;
	double homework;
	float grade;
};


student_record enter_data_by_value(student_record student);
void enter_data_by_reference(student_record &student);
void compute_grade(student_record &student);
void print_record(student_record student);
student_record enter_data_by_value_ptr(student_record *student);

int main(void)
{
	// Varaibles of type student record
	student_record Alice, Bob;

	// Pointers to student_record types

	student_record* ptr_Alice;

	// Initialize the pointers

	ptr_Alice = &Alice;

	cout << "Enter Student Data for Alice." << endl;

	*ptr_Alice = enter_data_by_value(*ptr_Alice);


	// Compute Grade for Alice.
	compute_grade(*ptr_Alice);//same as if you would just put compute grade Alice

	// Print data record
	cout << "Data Record for Alice" << endl << endl;

	print_record(*ptr_Alice);


	cout << endl << endl;

	// Use call by reference to input data for Bob
	cout << "Enter Student Data for Bob." << endl;



	//create a pointer to use in the function

	student_record *ptr_Bob = &Bob;
	enter_data_by_reference(*ptr_Bob);

	// Compute Grade for Bob.

	compute_grade(*ptr_Bob);

	cout << "Data Record for Bob" << endl << endl;
	print_record(*ptr_Bob);


	system("pause");

	// Handling pointers to structs


	cout << "Call enter_data_by_value to initialize ptr_Alice" << endl;


	cout << "Data Record for Alice Modified" << endl << endl;


	cout << endl << endl;


	//create a dynamic record
	student_record* ptr_student = new student_record;//allocates space for student record basically creates *ptr_student of the struct type student_record

	//populate our members
	ptr_student->firstname = "Mary";
	ptr_student->lastname = "Wilson";
	ptr_student->birthdate.month = 4;
	ptr_student->birthdate.year = 1997;
	ptr_student->gpa = 3.1;
	ptr_student->exam = 87.6;
	ptr_student->homework = 91.0;

	compute_grade(*ptr_student);//pass by reference using & in the function

	//print data
	cout << endl << endl;
	print_record(*ptr_student);


	cout << "Call enter_data_by_value_ptr to initialize ptr_student" << endl;
	//this wipes out the statements to gather data above in main and use the function to get the data
	*ptr_student = enter_data_by_value_ptr(ptr_student);//call by valur so we need something to collect this data

	cout << "Data Record for student" << endl << endl;
	print_record(*ptr_student);
	cout << endl << endl;


	cout << endl << endl;
	system("pause");
}

student_record enter_data_by_value_ptr(student_record *student)//pass pointer into function
{
	cout << "Enter first and last name: " << endl;
	cin >> student->firstname >> student->lastname;
	cout << "Enter Date of Birth as MM DD YYYY" << endl;
	cin >> student->birthdate.month >> student->birthdate.day >> student->birthdate.year;
	cout << "Enter GPA: ";
	cin >> student->gpa;
	cout << endl;
	cout << "Enter exam average: ";
	cin >> student->exam;
	cout << endl;
	cout << "Enter homework average: ";
	cin >> student->homework;
	cout << endl;

	return *student;  // Return filled data record using dereferenced pointer
}

student_record enter_data_by_value(student_record student)
{
	cout << "Enter first and last name: " << endl;
	cin >> student.firstname >> student.lastname;
	cout << "Enter Date of Birth as MM DD YYYY" << endl;
	cin >> student.birthdate.month >> student.birthdate.day >> student.birthdate.year;
	cout << "Enter GPA: ";
	cin >> student.gpa;
	cout << endl;
	cout << "Enter exam average: ";
	cin >> student.exam;
	cout << endl;
	cout << "Enter homework average: ";
	cin >> student.homework;
	cout << endl;

	return student;  // Return filled data record
}


void enter_data_by_reference(student_record &student)
{
	cout << "Enter first and last name: " << endl;
	cin >> student.firstname >> student.lastname;
	cout << "Enter Date of Birth as MM DD YYYY" << endl;
	cin >> student.birthdate.month >> student.birthdate.day >> student.birthdate.year;
	cout << "Enter GPA: ";
	cin >> student.gpa;
	cout << endl;
	cout << "Enter exam average: ";
	cin >> student.exam;
	cout << endl;
	cout << "Enter homework average: ";
	cin >> student.homework;
	cout << endl;

	return; // Nothing returned in call by reference
}


void compute_grade(student_record &student)
{
	cout << "In function compute grade." << endl;
	cout << "Exam = " << student.exam << endl;
	cout << "Homework = " << student.homework << endl;
	student.grade = student.exam / 100 * 60 + student.homework / 100 * 30 + 10;
	cout << "Grade = " << student.grade << endl;

	return;
}

void print_record(student_record student)
{
	cout << student.firstname << " " << student.lastname << endl;
	cout << "Date of birth "
		<< setw(3) << student.birthdate.month
		<< setw(3) << student.birthdate.day
		<< setw(5) << student.birthdate.year
		<< endl;
	cout << "GPA: " << student.gpa << endl;
	cout << "Exam: " << student.exam << endl;
	cout << "Homework: " << student.homework << endl;
	cout << "Grade: " << student.grade << endl;
	return;
}