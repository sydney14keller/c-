/*
Sydney Morgan Keller
CS221 - 02
02/23/2021
Purpose: This file implements the MotoGpRider header file. It initializes the member variables and functions.

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "MotoGpRider.h"


#define skip (std::cout << std::endl << std::endl << std::endl);


MotoGpRider::MotoGpRider() //default constructor
{
	m_lastName = "";
	m_firstName = "";

}

MotoGpRider::MotoGpRider(std::string lname, std::string fname, int number, std::string nation, std::string make, int points, int position) //non-default constructor
	: m_lastName{ lname }, m_firstName{ fname }, m_number{ number }, m_nation{ nation } ,m_make{ make }, m_points{ points }, m_position{ position }

{
}

std::string MotoGpRider::getLastName()const
{
	//Pre create class member variable to return
	//Post: class member variable returned
	
	return m_lastName;
}
std::string MotoGpRider::getFirstName()const //used in main for printing
{
	//Pre create class member variable to return
	//Post: class member variable returned
	
	return m_firstName;
}
std::string MotoGpRider::getNation()const
{
	//Pre create class member variable to return
	//Post: class member variable returned
	
	return m_nation;
}
std::string MotoGpRider::getMake()const 
{
	//Pre create class member variable to return
	//Post: class member variable returned
	
	return m_make;
}

int MotoGpRider::getPosition()const
{
	//Pre create class member variable to return
	//Post: class member variable returned
	
	return m_position;
}

int MotoGpRider::getNumber()const
{
	//Pre create class member variable to return
	//Post: class member variable returned

	return m_number;
}

int MotoGpRider::getPoints()const
{
	//Pre create class member variable to return
	//Post: class member variable returned
	
	return m_points;
}

std::string MotoGpRider::ToString()const
{
	//Pre: out has been opened
	//Post: value has been set to the stream out

	std::stringstream info;

	info << std::string(30,'-')
		<< "\n" << std::left << std::setw(15) << getFullName() << "\n" << std::string(30, '-') << "\nMake : " << std::setw(15) << getMake() << "\nNation : "
		<< std::setw(15) << getNation() << "\nPostition : " << std::setw(15) << getPosition() << "\nPoints : " << std::setw(15)
		<< getPoints()  << std::endl << std::endl << std::endl << std::endl;

	return info.str();
}
	

std::string MotoGpRider::getFullName()const
{
	//Pre: member variables are declared for lastname and firstname
	//Post: last and firstname member variables are ass
	
	return m_lastName + " " + m_firstName;
}

int MotoGpRider::compareTo(MotoGpRider& other)
{
	//we want to compare the m_position of the class
	//return -1 if THIS is less than other
	//return 0 if they are the same
	//return 1 if THIS is greater than other. 
	if (other.getPosition() > this->m_position)
	{
		return -1; // because THIS would be less than OTHER
	}
	else if (other.getPosition() < this->m_position)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool MotoGpRider::operator>(const MotoGpRider& rhs) //operator overloading are JUST functions that allows you to change the behavior of an operator in your program
//if the lhs is greater than the rhs return true
{
	MotoGpRider other;
	bool less = false;
	if (other.getPosition())
	{
		(m_position > other.m_position);
		less = true;
		return less;
	}
}
bool MotoGpRider::operator<(const MotoGpRider& rhs) //operator overloading are JUST functions that allows you to change the behavior of an operator in your program
//if the lhs position is less than the rhs return true
{
	MotoGpRider other;
	bool greater = false;
	if (other.getPosition() == -1) // if it returns 1
	{
		(m_position < other.m_position);
		greater = true;
		return greater;
	}

}
bool MotoGpRider::operator==(const MotoGpRider& rhs) //operator overloading are JUST functions that allows you to change the behavior of an operator in your program
//if the positions are equal return true
{
	MotoGpRider other;
	bool equals = false;
	if (other.getPosition() == 0)
	{
		(m_position == other.m_position);
		equals = true;
		return equals;
	}
}