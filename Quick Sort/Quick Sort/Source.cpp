#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define arr_size 10
using namespace std;

void readArray(float* x, int size);
void printArray(float* x, int size);
pair<int, int> partitionArray(float* x, int lowerBound, int upperBound);
void quicksort(float* x, int lowerBound, int upperBound);


int main()
{// write code here
	/*
	*	Problem statement states the array is of 10 size but the function expects a variable as its size
	*	Hence array size allocated at runtime which can be something other than 10
	*/
	float* x;
	int size;

	cout << "Enter size of the array : ";
	cin >> size;									//Size input for memory allocation

	x = (float*)malloc(size * sizeof(float));		//Memory allocation typecasted to float

	readArray(x, size);
	quicksort(x, 0, size - 1);
	printArray(x, size);

}


void readArray(float* x, int size)	// this function will read array ‘x’ of size ‘size’
{
	
	cout << "\nEnter elements of the array saperated by space and press [Enter] after last element.\nElements : ";
	for (int i = 0; i < size; i++)
	{	cin >> x[i];
	}
}


void printArray(float* x, int size)		// This function will print array ‘x’ of size ‘size’
{
	int counter;
	cout << "\n\tSorted Array : [ ";

	for (counter = 0; counter < size; ++counter)
	{
		cout << x[counter] << " ";
	}
	cout << "]\n\n";

}


pair<int, int> partitionArray(float* x, int lowerBound, int upperBound)	   // This function will print array ‘x’ of size ‘size’ 
{// write code here
	int pivot = x[lowerBound];		//Randomly selected pivot aldready at 0th element
	int divider;
	int partition_counter_l = lowerBound;
	int counter;

	for (counter = lowerBound + 1; counter <= upperBound; counter++)	//Excliding first element, iterate till last element
	{
		if (x[counter] <= pivot)
		{
			partition_counter_l++;
			swap(x[counter], x[partition_counter_l]);
		}
	}
	swap(x[lowerBound], x[partition_counter_l]);
	divider = partition_counter_l - 1;


	for (counter = lowerBound; counter < partition_counter_l && divider >= lowerBound && divider > counter;)
	{
		if (x[partition_counter_l] == x[counter])
		{
			swap(x[counter], x[divider]);
			divider--;
		}
										
		else
			counter++;
	}
	divider++;
	return make_pair(divider, partition_counter_l);		//Allows returning 2 values
}


void quicksort(float* x, int lowerBound, int upperBound)//Recursive quick sort function
{// write code here
	if (lowerBound >= upperBound)	//Condition necessary to get out of recurssion 
	{
		return;
	}

	int pivot = lowerBound + rand() % (upperBound - lowerBound + 1);	//Randomized pivot (Faster times for nearly sorted array)
	swap(x[lowerBound], x[pivot]);		//swapping pivot with first element
	pair<int, int> after_partition = partitionArray(x, lowerBound, upperBound);		//Partition returns a pair

	quicksort(x, lowerBound, after_partition.first - 1);	//Recursive call of array 
	quicksort(x, after_partition.second + 1, upperBound);	//Recursive call of array 
}