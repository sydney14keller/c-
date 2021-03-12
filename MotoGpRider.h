/*
Sydney Morgan Keller
CS221 - 02
02/23/2021
Purpose: This is a Header file to declare MotoGp class and member variables and functions.

*/




#ifndef MOTO_GP_RIDER_H
#define MOTO_GP_RIDER_H


#include <fstream>

class MotoGpRider
{

public:
	MotoGpRider();//default
	MotoGpRider(int position);
	MotoGpRider(std::string lname, std::string fname, int number, std::string nation, std::string make,int points , int position);//non-default constructor that reads file input

	//getter methods
	std::string getLastName()const;
	std::string getFirstName()const;
	std::string getNation()const;
	std::string getMake()const;
	int getPoints()const;
	int getPosition()const;
	int getNumber()const;
	int compareTo(MotoGpRider& rhs);
	//Summary Rider Information method to be printed in summary table
	std::string ToString()const;

	// operator overloading
	bool operator>(const MotoGpRider& rhs) ;
	bool operator<(const MotoGpRider& rhs);
	bool operator==(const MotoGpRider& rhs);


	//Return Rider's full name method
	std::string getFullName()const;


private:
	std::string m_lastName, m_firstName, m_nation, m_make;//member variables
	int m_points, m_position, m_length, m_number;

};

#endif MOTO_GP_RIDER_H

