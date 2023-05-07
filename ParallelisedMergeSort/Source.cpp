#include <iostream>
#include<array>
#include <cmath>
#include <list>
#include <stack>

#include "Layer.h"

void displayArray(int*, int);

int main() {

	// Unknown array size definer stolen off cplusplus.net (see comments without space) - https://cplusplus.com/forum/beginner/7961/#msg36878
	//Create a user input size
	int size;
	std::cout << "Enter Size Of Array : ";
	std::cin >> size;

	// User input detection.
	if (size <= 1) {
		std::cout << "Your array does not need sorting.";
		return 0;
	}

	//Create the array with the size the user input
	int* myArray = new int[size];

	//Populate the array with whatever you like..
	for (int i = 0; i < size; ++i)
	{
		myArray[i] = rand() % 100;
	}

	// This is a frankly weird way to organise a mergesort but it'll be in parallel.
	// Excuse the mix of capitalised and non-capitalised words, It's a thing I do when thinking with myself.

	/* DEFINE STACK HERE, GIVE EACH ARRAY A LAYER NUMBER.
	* 
	* Generation:
	*	SET MAIN ARRAY AS "NEW TASK"
	*	loop
	*	COPY LIST OF NEW TASKS TO SORT STACK.
	*	MOVE "New Tasks" TO "Current tasks".
	*	SPLIT ARRAYS AND ADD NEW SUB ARRAYS TO "NEW TASKS" LIST AS TASK.
	*	Arrays of size one are skipped and not added as new jobs. 
	*	To prevent odd arrays triggering this, a pass would be done to see if any new jobs are created.
	*	if no new jobs are created then end subarray generation.
	* 
	* Sorting:
	*	MANAGER THREAD GIVES JOBS off the stack UNTIL THE stack task LAYER NUMBER IS LESS THAN the manager thread's CURRENT task NUMBER.
	*	CALL BARRIER UNTIL ALL THREADS AVALIABLE, THEN PROCEED ON NEXT/PREVIOUS LAYER and assign jobs until out.
	*	THIS SHOULD AVOID RACE CONDITIONS AND SATISFY REQUIREMENTS.
	*	Kill subarrays as they're finished sorting to save memory.
	*	Once tasks have run out (the array sorted): Kill/Merge/Join threads into main and display sorted result.
	*/

	// "Tasks" are just pointers to objects.
	std::list<Layer*> newTasks;
	std::list<Layer*> currentTasks;
	std::stack<Layer*> allTasks;

	// MAKE NEW ARRAY OBJECT TEST
	Layer objArray(myArray, size, 0);
	allTasks.push(&objArray);

	// DEBUG outputs memory address
	std::cout << allTasks.top() << std::endl;

	// Hopefully should match the bottom
	displayArray(allTasks.top()->getArrayPointer(), allTasks.top()->getSize());
	std::cout << "\n";

	// Display object in list test
	displayArray(objArray.getArrayPointer(), objArray.getSize());


	objArray.split(&newTasks);

	int listSize = newTasks.size();

	std::cout << "Size of newtasks: " << listSize << std::endl;
	std::cout << "Address of newtasks: " << newTasks.front() << std::endl;
	std::cout << "Address of newtasks first subarray: " << newTasks.front()->getArrayPointer() << std::endl;


	if (listSize != 0) {

		std::cout << "\nTest of outputting newTasks list\n";

		// Fancy output, this code would not be included in the final version.
		for (int i = 0; i < listSize; i++) {

			displayArray(newTasks.front()->getArrayPointer(), newTasks.front()->getSize());
			if (i != newTasks.size() - 1) {
				std::cout << ", ";
			}
			newTasks.pop_front();

		}
	}
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