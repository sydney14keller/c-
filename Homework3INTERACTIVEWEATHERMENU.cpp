// Homework3INTERACTIVEWEATHERMENU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;
#define SKIP2 (cout << endl << endl);
void find_max_min(float tmax[], float tmin[], int elements, float &max_val, float &min_val,float &max_avg, float &min_avg);//function prototype

int main(void)
{
	
	float totalprcp[3000] = { 0 };
	ifstream infile;//reads from file
	string infilename = "C:\\Users\\sydne\\OneDrive\\Desktop\\weather_station_five_column.txt";//our data and shows how to open a file with a string
	string dataline = "";
	string s_tmax, s_tmin, s_stationName, s_date, s_prcp;//use stod to convert these strings to doubles
	string choice = " ",name = "";
	float max = 0, min = 0, prcp = 0,pmax = 0,min_avg=0,max_avg=0;
	
	// Declare two arrays for the tmax and tmin data
	float tmax[4000] = { 0 }, tmin[4000] = { 0 };//2 arrays for the tmax and tmin data and less than 3000 values
	string stationName[4000];
	int date[4000] = { 0 };
	float PRCP[4000] = { 0 };
	
	int records = 0;
	int pos_tmax, pos_tmin;//finds the index of the position of both of these
	int pos_stationName, pos_date, pos_prcp; // finds the index of all of these
	cout << "WEATHER STATION DATA" << endl << endl;

	cout << "Open the filtered weather data file." << endl << endl;
	infile.open(infilename);

	if (!infile)
	{
		cout << "Error. Could not open file " << infilename << endl;//infilename is a string so we can do this
		system("pause");
		return 2;
	}

	cout << infilename << " opened for reading. " << endl << endl;
	SKIP2


	//cout << "Read the first line from the file. " << endl;
	getline(infile, dataline);//read in headers
	//cout << dataline << endl;
	

	pos_stationName = dataline.find("STATION NAME"); //takes beginning position of stationname and saves that integer value into pos_stationName

	if (pos_stationName != string::npos)//good programming makes sure the stationame is found  npos is the largest integer you can store
	{
		//cout << "The position of column STATION NAME is " << pos_stationName << endl;
	}
	else
	{
		cout << "Error: STATION NAME not found." << endl;
		system("pause");
		return 3;
	}


	pos_date = dataline.find("DATE");

	if (pos_date != string::npos)//good programming makes sure the date is found  npos is the largest integer you can store
	{
		//cout << "The position of column DATE is " << pos_date << endl;
	}
	else
	{
		cout << "Error: DATE not found." << endl;
		system("pause");
		return 3;
	}


	pos_prcp = dataline.find("PRCP");
	if (pos_prcp != string::npos)//good programming makes sure the prcp is found  npos is the largest integer you can store
	{
		//cout << "The position of column PRCP is " << pos_prcp << endl;
	}
	else
	{
		cout << "Error: PRCP not found." << endl;
		system("pause");
		return 3;
	}


	pos_tmax = dataline.find("TMAX");//find dataline and print out that index
	if (pos_tmax != string::npos)//good programming makes sure the TMAX is found  npos is the largest integer you can store
	{
		//cout << "The position of column TMAX is " << pos_tmax << endl;
	}
	else
	{
		cout << "Error: TMAX not found." << endl;
		system("pause");
		return 3;
	}


	pos_tmin = dataline.find("TMIN");
	if (pos_tmin != string::npos)//if we dont find tmin
	{
		//cout << "The position of column TMIN is " << pos_tmin << endl;
	}
	else
	{
		cout << "Error: TMIN not found." << endl;
		system("pause");
		return 4;
	}
	

	//cout << "Now get first line of data." << endl << endl;
	getline(infile, dataline);//get first line of actual data

	
	while (!infile.eof())//looping through the file
	{
		


		// Extract the TMAX and TMIN values and store them into the arrays

		s_tmax = dataline.substr(pos_tmax, 8);//get TMAX value and save into s_tmax
		s_tmin = dataline.substr(pos_tmin, 5);



		s_stationName = dataline.substr(pos_stationName, 51);
		s_prcp = dataline.substr(pos_prcp, 5);//starting at the position of prcp and getting that value and storing into a string called s_prcp to later be converted
		s_date = dataline.substr(pos_date, 9);




		//convert the strings to numbers but first test to see if it is -9999

		if (s_tmax != "-9999" && s_tmin != "-9999" &&s_prcp != "-9999" && s_date != "-9999" && s_stationName != "-9999") // TRUE = good record
		{
			//save the temps into arrays after converting the Celsius to tenths

			tmax[records] = stod(s_tmax) / 10.0;  //stod converts from string to double     //records begin at 0 and will be incremented to go through file
			tmin[records] = stod(s_tmin) / 10.0; //save result into tmin   //  divide by 10.0 bc the file is in tenths of a degree celsius

			stationName[records] = s_stationName; //save rows into a counter
			date[records] = stoi(s_date);//convert date string to integer
			PRCP[records] = stod(s_prcp);//convert prcp string to double



				//now convert to Farenheit
			tmax[records] = tmax[records] * 9.0 / 5.0 + 32.0;//taking our existing double we just got from above and converts it and saves into the array
	
			//after we do that for the FIRST value we got in our array, we increment our position for the next number

			records++;

		}


		getline(infile, dataline);//get the next line

	} // End While


	

	 //create menu for the user

	cout << "Please pick a choice in the table." << endl;

	SKIP2

		cout << setw(10) << "CHOICES" << endl
		<< setw(45) << "A: Total precipitation from all stations for 1 day." << endl
		<< setw(40) << "B: Total Precipitation over a range of dates." << endl
		<< setw(40) << "C: Total Precipitation by Station for March." << endl
		<< setw(45) << "D: Temperature Extremes and Average by Station." << endl
		<< setw(65) << "E: Temperature Extremes and Average by Station over a range of dates." << endl;

	cin >> choice;

	SKIP2
		double sum = 0, yyyymmdd = 0,yyyymmdd2=0;
	
	if (choice == "A" || choice == "a")//search the date format by converting using find 
	{

		
		cout << "Enter the yyyymmdd" << endl;
		//cin >> year >> month >> day;
		cin >> yyyymmdd;
		
		for (int i = 0; i <= records; i++)
		{
			if (date[i] == yyyymmdd)//compare that date inside the array to what the user entered THE DAY IS ALL THAT TRULY MATTERS BECAUSE IT IS THE UNIQUE ELEMENT
			{
				//save value into total prcp array
				totalprcp[i] += PRCP[i];
				sum += totalprcp[i];//add all precipitations up
			}	
		}
		cout << "The sum of the precipitation values for all stations in 1 day is:  " << sum << endl;
	}

	
	if (choice == "B" || choice == "b") 
	{

		cout << "Enter the yyyymmdd for the beginning date: \t";
		cin >> yyyymmdd;
		cout << endl;
		cout << "Enter the yyyymmdd for the ending date: \t";
		cin >> yyyymmdd2;

		for (int i = 0; i <= records; i++)
		{
			if (yyyymmdd != yyyymmdd2)
			{
				if (date[i] == yyyymmdd )//|| date[i] == yyyymmdd2)
				{
					//save value into total prcp array
					totalprcp[i] += PRCP[i];
					sum += totalprcp[i];//add all precipitations up
				}
			}
		}
		SKIP2
		cout << "The sum of the precipitation values over a range of these dates are:  " << sum << endl;
	}
	
	 if(choice == "C" || choice == "c")
	{
		 cout << "Enter station name: \t";
		 
			 cin >> name;
			 getline(cin, name);
			 name.find(name);

		 for (int i = 0; i <= records; i++)
		 {
			 if (stationName[i] == name)
			 {
				 //save value into total prcp array
				 totalprcp[i] += PRCP[i];
				 sum += totalprcp[i];//add all precipitations up
			 }
		 }
		 cout << "The total precipitation for the entire month of March for selected station is: \t" << sum << endl;

	}

	 if (choice == "D" || choice == "d")
	 {
		 cout << "Enter station name: \t";
		 cin >> name;
		 getline(cin, name);//gets the spaces in the name
		 //call function
		 for (int j = 0; j < name.length(); j++)
		 {
			 if (name == stationName[j])
			 {
				 continue;
			 }
		 }
		 for (int i = 0; i <= records; i++)
		 {
			 
					 find_max_min(tmax, tmin, records, max, min, max_avg, min_avg);

					
				 
			 
		 }
		 cout << "The max temperature is: \t" << max << endl;
		 cout << "The min temperature is: \t" << min << endl;
		 cout << "The max average temperature is: \t" << max_avg << endl;
		 cout << "The min average temperature is: \t" << min_avg << endl;
	}


	 if (choice == "E" || choice == "e")
	 {
		 cout << "Enter the station name, yyyymmdd for the beginning date, and yyyymmdd for the ending date: \t";
		 cin >> name >> yyyymmdd >> yyyymmdd2;
		 getline(cin, name);
		 for (int j = 0; j < name.length(); j++)
		 {
			 if (name == stationName[j])
			 {
				 continue;
			 }
		 }
		 for (int i = 0; i <= records; i++)
		 {
			if ((yyyymmdd != yyyymmdd2) && ((date[i] == yyyymmdd )|| (date[i] == yyyymmdd2)))
			{

						 find_max_min(tmax, tmin, records, max, min, max_avg, min_avg);

						
				
			}
		 }
		 cout << "The max temperature is: \t" << max << endl;
		 cout << "The min temperature is: \t" << min << endl;
		 cout << "The max average temperature is: \t" << max_avg << endl;
		 cout << "The min average temperature is: \t" << min_avg << endl;
	 }
	 
	cout << endl << endl;
	system("pause");
	return 0;

}

// Functions go here

void find_max_min(float tmax[], float tmin[], int elements, float &max_val, float &min_val,float &max_avg, float &min_avg)//function is going to calculate the max and minimum value and return them
{
	//start by initializing our max and min values
	max_val = tmax[0];//highest daytime temp
	min_val = tmin[0];//lowest night temp

	for (int k = 1; k < elements; k++)//k=1 because we already declared a 0 index above
	{
		
		if (tmax[k] > max_val)
			max_val = tmax[k];//goes through each value comparing it to the next and the last standin' greatest value is stored into max_val
		if (tmin[k] < min_val)//goes through each value comparing it to the next and the last standin' least value is stored into min_val
			min_val = tmin[k];
		//average high and low temperature add all temps together and divide by the number of temps
		//find average of tmax[k]
		max_avg += (tmax[k])/(k);
		min_avg += (tmin[k])/(k);
	}


	return;//call by reference in function declaration allows max and min to be used in main function
}
























