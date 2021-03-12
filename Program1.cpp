/*

Sydney Morgan Keller
CS221 - 02
02/23/2021
Purpose: This .cpp file includes the main function and carries out the implementation of our class member variables and functions. 
It takes a filename from the user and inputs that data into our declared objects. The rider objects are saved into an Unsorted List 
called RiderList. This program then outputs all of that data into an output text file in a table format.

*/


// Preprocessor Direectives
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>


// header files
#include "MotoGpRider.h"
#include "RiderList.h"


// function definitions
void usingFileIO();
std::string getFilename(std::string prompt);


int main()
{
	
	
	 usingFileIO(); // function call


	

	return 0;
}



// functions

void usingFileIO()
{
	// Open input file 
	std::string inputFileName = getFilename("Enter name of input file: ");
	std::fstream inData{ inputFileName, std::ios_base::in };


	// Test if the file was opened properly. If it could not be opened,
	// then print an error message and return.
	if (!inData) {
		std::cout << "File could not be opened: " << inputFileName << std::endl;
		return;
	}


	std::string outFileName = getFilename("Enter name of output file: ");
	std::fstream outData{ outFileName, std::ios_base::out | std::ios_base::app };


	// If there was a problem opening the file, print an error message and return
	if (!outData) {
		std::cout << "File could not be opened: " << outFileName << std::endl;
		return;
	}


	MotoGpRider m_rider , item;// create objects of class MotoGpRider to call class member functions
	RiderList riderList; 
	std::string fname, lname, nation, make; // string variables to take data from input file
	int position, points, number; // int variables to take data frim the input file


	
	int listLength = riderList.getLength(); // Get length of list to use in your loop conditions.

	// Create a loop to take in 10 riders into array of class Rider.
	while(!inData.eof())
	
	{
		if (riderList.isFull()) // Check to see if list is full.
		{
			break; // Exit the program if the list is full

		}


		// Take in item from the input file and then add to list using additem.
		inData >> lname >> fname >> number >> nation >> make >> points >> position;


		// Create objects of MotoGpRider using non-default constructor.
		MotoGpRider item{ lname , fname , number,  nation, make,  points, position };
		// Add items to the list.
		riderList.addItem(item); // increments m_length by 1
		listLength = riderList.getLength();
		

	}
	// Close the input file when finished accessing it.
	inData.close(); 




	riderList.reset(); // This sets currentPos to -1 and we need this to access our information inside the list.

	
	outData << std::setw(50) << "2020 World Championship Statistics" << "\n" << std::string(80, '-') << "\n"
		<< std::setw(20) << "Rider Name" << std::setw(13) << " Number" << std::setw(13) << " Points" << std::setw(14) << "Position\n" 
		<< std::string(80, '-')	// This adds '-' , 80 times in the output.
		<< "\n"; 

	listLength = riderList.getLength(); // Get length of list to use in your loop conditions.
	for (int k = 0; k < listLength; k++)
	{
		m_rider = riderList.GetNextItem();
		outData << std::right << std::setw(18) << m_rider.getFullName() << " : " << std::setw(12) << m_rider.getNumber() 
		<< std::setw(12) << m_rider.getPoints() << std::setw(12) << m_rider.getPosition() << std::endl << std::endl;
	}



	// Summary of Riders pulled from the list
	riderList.reset();
	listLength = riderList.getLength();


	
	outData << std::endl << std::endl << "RIDERS" << std::endl;

	for (int i = 0; i < listLength; i++)
	{
		// Write the values you just read into the output file.
		

		m_rider = riderList.GetNextItem();

		
 
		outData << m_rider.ToString() << std::endl;
		

	}


	
	// Close the output file when finished using it
	outData.close();    

}



std::string getFilename(std::string prompt)
{

	// Get the name of the input file from the user
	std::cout << prompt << std::endl; 
	std::string fileName; std::cout << std::endl;
	std::cin >> fileName; std::cout << std::endl;

	return fileName;
}



