#include <iostream>
#include<array>

void displayArray(int*, int);

int main() {

	// Unknown array size definer stolen off cplusplus.net - https://cplusplus.com/forum/beginner/7961/#msg36878
	//Create a user input size
	int size;
	std::cout << "Enter Size Of Array : ";
	std::cin >> size;

	//Create the array with the size the user input
	int* myArray = new int[size];

	//Populate the array with whatever you like..
	for (int i = 0; i < size; ++i)
	{
		myArray[i] = rand() % 100;
	}

	//Display whats in the array...

	displayArray(myArray, size);
	/* for (int i = 0; i < size; ++i)
	{
		std::cout << "Item In Element " << i << " of the array = : " << myArray[i] << std::endl;
	}
	
	std::cout << "[" << myArray[0];
	for (int i = 1; i < size; ++i)
	{
		std::cout << "," << myArray[i];
	}
	std::cout << "]";
	*/

	//Delete the array
	delete[] myArray;


	return 0;
}

void displayArray(int* myArray, int length) {

	std::cout << "[" << myArray[0];
	for (int i = 1; i < length; ++i)
	{
		std::cout << "," << myArray[i];
	}
	std::cout << "]";
}