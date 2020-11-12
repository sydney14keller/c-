//
// Program to read and process weather station data 
// Data is input one full line at a time and then processed with
// string manipulation functions
//
// It demonstrates fstream, iomanip, file open, file read, file close,
// getline, eof, substr, at, lenght and find.
//
// Actual weather station data is employed
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib> 

using namespace std;

int main(void)
{
	// Variables

	string dataline = "";

	string station = "";
	string station_name = "";
	string date = "";
	int mdpr = 0, dapr = 0, prcp = 0, snwd = 0, snow = 0, tmax = 0, tmin = 0, tobs = 0;
	int i = 0;

	string month = "";
	string day = "";
	string year = "";

	char letter;
	unsigned int pos_station_name = 0;
	unsigned int pos_date = 0;
	unsigned int pos_tmax = 0;
	unsigned int pos_tmin = 0;

	ifstream infile;
	ofstream outfile;

	cout << "WEATHER STATION DATA" << endl << endl;
	cout << "Open the data file." << endl << endl;
	infile.open("C:\\Users\\sydne\\Documents\\AL_Weather_Station.txt");

	// What is !infile anyway ?

	//cout << "infile has the value: "<< infile << endl; 
	cout << "!infile has the value: " << !infile << endl;

	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return(1);
	}
	else
	{
		cout << "Data file opened." << endl;
	}

	outfile.open("C:\\Users\\sydne\\Documents\\Filtered_AL_Weather_Station.txt");

	if (!outfile)
	{
		cout << "Unable to open the output file. " << endl;
		system("pause");
		return(1);
	}
	else
	{
		cout << "Output file opened." << endl;
	}

	cout << "Use the first line of the file to find the column positions. " << endl;
	getline(infile, dataline);

	cout << "Read the second line from the file. " << endl;
	getline(infile, dataline);

	cout << "Read the data items one at a time." << endl;
	infile >> station;

	// Try this 4th: It works.
	for (i = 18; i <= 68; i++)
	{
		infile.get(letter);
		station_name = station_name + letter;
	}
	//	Try this second: station_name = infile.substr(18,50);
	//	Just skip it for now: infile.ignore(51);
	//	Try this first: infile >> station_name;
	infile >> date;
	infile >> mdpr >> dapr >> prcp >> snwd >> snow >> tmax >> tmin >> tobs;


	cout << endl;
	cout << station << endl;
	cout << station_name << endl;
	cout << date << endl;
	cout << mdpr << endl;
	cout << dapr << endl;
	cout << prcp << endl;
	cout << snwd << endl;
	cout << snow << endl;
	cout << tmax << endl;
	cout << tmin << endl;
	cout << tobs << endl;

	// Separate Month Day and Year

	year = date.substr(0, 4);
	month = date.substr(4, 2);
	day = date.substr(6, 2);

	cout << setw(3) << month << setw(3) << day << setw(5) << year << endl;




	// Close the files
	infile.close();
	outfile.close();

	cout << "New file created with bad records filtered out. " << endl;

	cout << "\n\n";
	system("pause");
	return 0;
}