/* 
Program Description: This program creates a structure to save all the information of a citizen into. THen, functions are implemented to store and print the data of the citizen.
Class: CS 121
Date: 11-2-20
Sydney Morgan Keller

*/




#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//enum
#define SKIP2 (cout << endl << endl);


struct ID {								//define structure used for personal ID
	string firstName, lastName;
	//date
	char sex;
	int height;
	string eyeColor;
};


ID enter_data(ID citizen);
void print_record(ID person);


int main(void) {

	//variables of type ID

	ID citizen;

	cout << "Data record for a citizen."; 
	SKIP2
	cout << "Please enter your data." << endl;
	SKIP2
		
	citizen = enter_data(citizen); //using a variable to catch the data. Must be of the same type as the struct

	//print out the data

	cout << "Data Record for citizen: "; 
	SKIP2

	print_record(citizen);


}

//functions 

ID enter_data(ID person)
{
	cout << "First Name: ";
	cin >> person.firstName;
	SKIP2
	cout << "Last Name: ";
	cin >> person.lastName;
	SKIP2
	cout << "Sex M or F: ";
	cin >> person.sex;
	SKIP2
	cout << "Height in inches: ";
	cin >> person.height;
	SKIP2
	cout << "Eye Color: ";
	cin >> person.eyeColor;
	SKIP2

		return person;
}

void print_record(ID person)
{
	SKIP2
	cout << person.firstName << " " << person.lastName << endl;
	cout << "Sex: " << person.sex << endl;
	cout << "Height: " << person.height << endl;
	cout << "Eye Color: " << person.eyeColor << endl;

	return;
	SKIP2
}