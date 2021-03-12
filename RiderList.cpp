/*
Sydney Morgan Keller
CS221 - 02
02/23/2021
Purpose:This is a .cpp file for the implementation of RiderList.h file. 

*/


#include "RiderList.h"


RiderList::RiderList() : m_length{ 0 }
{
	//Post: Length of array list is initialized to 0	
}

void RiderList::reset()
{
	//Post: currentPos has been initialized

	m_currentPos = -1;
}

void RiderList::addItem(MotoGpRider rider)//same as insert item into list
{
	//  Pre: List has been initialized. List is not full.  
	// item is not in list.
	// Post:  item is in the list.
	
	riders[m_length] = rider; 
	m_length++;

}


bool RiderList::isFull()
{
	//Post: boolean returned that determines if list is full

	if (m_length == MAX_SIZE)
	{
		return true;
	}
	else
		return false;
}

int RiderList::getLength()
{
	return m_length;
}

bool RiderList::isEmpty()
{
	//Post: List is empty

	if (m_length == 0)
	{
		return true;
	}
	else
		return false;
}

MotoGpRider RiderList::GetNextItem()
{
	// Pre: ResetList was called to initialize iteration.
	//      No transformer has been executed since last call.
	//      currentPos is defined.
	// Post: item is current item.
	//       Current position has been updated.
	
	m_currentPos++;
	return riders[m_currentPos];
}


