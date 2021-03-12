/*
Sydney Morgan Keller
CS221 - 02
02/23/2021
Purpose: This is a Header file to declare RiderList class and member variables and functions. This class declares and Unsorted List.

*/


#ifndef RIDER_LIST_H
#define RIDER_LIST_H

#include <iostream>
#include "MotoGpRider.h"
#define MAX_SIZE 10

class RiderList//essentially creating a RiderList to hold our 10 characters
{

	//stores riders using an internal array


	public:
		//page 146
		RiderList();
		
		void reset();//clears out list do this by making length 0
/*->*/void addItem( MotoGpRider rider);//return object 
		bool isFull();//return boolean value
		int getLength();
		bool isEmpty();
		MotoGpRider GetNextItem();
		
	private:
		int m_length,m_currentPos;//number of riders
		//an array of Items
		MotoGpRider riders[MAX_SIZE];//hidden array but accessible through RiderList::functions
		MotoGpRider operator>(const MotoGpRider& rhs)const; // operator overloading using compareTo() member function
	};









#endif