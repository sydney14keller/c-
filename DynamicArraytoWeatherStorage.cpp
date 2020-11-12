//
// Create a dynamic array for the prcp data. Sort it too.
// The data file "AL_Weather_Station.txt" must be located in the C:/Data folder
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
void selection_sort(float array_in[], int elements);//function

int main(void)
{
	string dataline = "";
	ifstream infile;
	string s_prcp;
	int pos_prcp = 0;
	unsigned int records = 0;
	unsigned int k = 0;

	// Pointer for prcp array
	float* prcp;//pointer



	cout << "WEATHER STATION DATA" << endl << endl;

	// Open the data file
	infile.open("C:\\Users\\sydne\\Documents\\AL_Weather_Station.txt");

	if (!infile)
	{
		cout << "Unable to open file." << endl;
		system("pause");
		return 1;
	}
	else
		cout << "File opened for read." << endl;


	cout << "Read the first line from the file. " << endl;
	getline(infile, dataline);
	cout << dataline << endl;


	//search for prcp
	pos_prcp = dataline.find("PRCP");
	if (pos_prcp != string::npos)
	{
		cout << "PRCP begins at position" << pos_prcp << endl;
	}
	else
	{
		cout << "String PRCP not found. " << endl;
		system("pause");
		return 4;
	}

	cout << "Read the second line from the file. " << endl;
	getline(infile, dataline);
	cout << dataline << endl;


	cout << "Now get first line of data." << endl << endl;
	getline(infile, dataline);
	cout << dataline << endl;

	// First pass through the data file. Count number of valid prcp values.
	while (!infile.eof())
	{
		s_prcp = dataline.substr(pos_prcp, 5);
		if (s_prcp != "-9999")//making sure not a bad record
		{
			records++;//count that good value
		}
		getline(infile, dataline);//read next line and go to the top of the loop
	}
	cout << "There are " << records << " records with good PRCP data." << endl;

	// Now make a dynamic array for the prcp data

	prcp = new float[records]; //dynamic array for prcp bc their will be thousands of good values for prcp

	// Now reset the file and copy the prcp data into the array

	infile.seekg(0, ios::beg);
	infile.clear();

	// Read and ignore the first two lines in the file
	getline(infile, dataline);//header
	getline(infile, dataline);//dashes



	getline(infile, dataline); // Get first line of data
	k = 0;
	while (!infile.eof())//go through entire file again and copy the data into an array
	{
		s_prcp = dataline.substr(pos_prcp, 5);
		if (s_prcp != "-9999")
		{
			prcp[k++] = stof(s_prcp);//convert string to float and store each value in the file into an array 
		}
		getline(infile, dataline);
	}

	// Close the file
	infile.close();

	cout << fixed << setprecision(2);

	// Sort the prcp data

	selection_sort(prcp, k);//k is how many numbers the selection sort will sort


	// Print the ten highest rainfall values

	for (k = 0; k < 10; k++)
		cout << prcp[k] << endl;
	

	cout << endl << endl;
	system("pause");
	return 0;
}


void selection_sort(float array_in[], int elements)
{
	int pass = 0, index_of_smallest = 0, count = 0, k = 0;
	float hold = 0;

	for (pass = 0; pass < elements - 1; pass++) // Loop to control number of passes
	{
		index_of_smallest = pass; // Start at index 0

		// Find the index of the smallest element
		for (k = pass + 1; k < elements; k++)
		{
			if (array_in[k] > array_in[index_of_smallest])
			{
				index_of_smallest = k;
			} // End If

		} // End Inner for loop

		hold = array_in[index_of_smallest];
		array_in[index_of_smallest] = array_in[pass];
		array_in[pass] = hold;
		count++; // Count number of swaps
	}
	cout << "There were " << count << " element exchanges during the sort. " << endl << endl;
	return;
}