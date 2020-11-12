#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#define ROWS 20 //occupies no location in memory and can't change in program
const unsigned int COLS = 10;//declare a constant in a different syntax and is stored in memory and can't change in program

void print_array(int array[][COLS], int rows, int cols);//function prototype
void initialize(int array[][COLS], int rows, int cols);
int sum_of_elements(int array[][COLS], int rows, int cols);
int minimum(int array[][COLS], int rows, int cols);
double average_of_elements(int array[][COLS], int rows, int cols);
int maximum(int array[][COLS], int rows, int cols);

int main() {


	//declare a 2 dimensional array
	int items[3][10] = {//3 rows and 4 columns int numbers[3][8][9][8][8][8]....infinite until run out of memory,
						{ 2,4,6,8 },
						{10,12,14,16},
						{18,20,22,24}
						};



	float value[20][15] = { 0 };//every element set to 0

	int numbers[ROWS][COLS] = { 0 };





	unsigned int sum_row, sum_col, max, min, sum = 0, num = 0;
	double average = 0;

	cout << "TWO DIMENSIONAL ARRAY OPERATIONS" << endl << endl;

	cout << "INITIALIZING THE ARRAY" << endl << endl;

	initialize(numbers, ROWS, COLS);

	cout << "ARRAY CONTENTS" << endl;

	print_array(numbers, ROWS, COLS);
	//print_array(items, 3, 3);//cannot do because the array only has 4 columns and the function only takes 10 columns
	//changes items to [3][10] so it will work
	print_array(items, 3, 10);//the extra space will be set to 0
	// Add all the elements

	cout << endl;
	cout << "ADD ALL THE ELEMENTS" << endl;
	sum = sum_of_elements(numbers, ROWS, COLS);//sum is the variable that takes the return in the function

	cout << "The sum of the elements in the array = is " << sum << endl;

	// Compute the average value

	cout << endl;
	cout << "COMPUTE AVERAGE" << endl;


	cout << "The average of the elements in the array = is " << average << endl;


	average =  average_of_elements(numbers, ROWS, COLS);
	cout << fixed << setw(2);
	// The Maximum and minimum valyes are
	cout << endl;
	cout << "FIND MAX AND MIN VALUES" << endl;

	cout << "Max is: " << maximum(numbers, ROWS, COLS)
		<< " Min is: " << minimum(numbers, ROWS, COLS) << endl;

	cout << endl << endl << endl;
	system("pause");

}

//functions
void initialize(int array[][COLS], int rows, int cols)//in 2 dimensional arrays, you have to initialize the second array
{
	unsigned int i,j,z;
	for (i = 0; i < rows; i++)//we will get the value of rows from the function
	{
		for (j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 100;//prints random numbers in each column horizontal values
		}

	}
	return;//don't have to do in a void function but it is good practice
}

void print_array(int array[][COLS], int rows, int cols)//in 2 dimensional arrays, you have to initialize the second array
{
	unsigned int i, j;
	for (i = 0; i < rows; i++)//we will get the value of rows from the function
	{
		for (j = 0; j < cols; j++)
		{
			cout << setw(3) << array[i][j];//prints random numbers in each column horizontal values
		}
		cout << endl;
	}
	cout << endl;
	return;//don't have to do in a void function but it is good practice
}

int sum_of_elements(int array[][COLS], int rows, int cols)
{
	unsigned int i, j, sum = 0; 

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			sum += array[i][j];//sum = sum + array[i][j] sum of all the numbers in the array
		}
	}return sum;//since it returns a value, there must be a variable in the main to take that value
}

double average_of_elements(int array[][COLS], int rows, int cols)
{
	unsigned int i, j, sum = 0;
	double avg = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			sum += array[i][j];
		}
	}
	avg = (double)sum / (rows * cols);
	return avg;
}

int minimum(int array[][COLS], int rows, int cols)
{
	unsigned int i, j;
	int min = array[0][0];

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (min > array[i][j])
				min = array[i][j];
		}
	}return min;
}

int maximum(int array[][COLS], int rows, int cols)
{
	unsigned int i, j;
	int max = array[0][0];

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)//iterating through all the values of the array
		{
			if (max < array[i][j])
				max = array[i][j];//if the max is less than the array value, the array value is now the max
		}
	}return max;
}