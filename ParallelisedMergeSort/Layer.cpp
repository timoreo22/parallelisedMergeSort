#include <list>
#include "Layer.h"

Layer::Layer(int* arr, int daSize, int layer) {

	// Copy variables into object class, and define new array.
	arrSize = daSize;
	layerNum = layer;

	subArray = new int[daSize];

	for (int i = 0; i < arrSize; i++) {
		subArray[i] = arr[i];
	}

}

Layer::~Layer() {

	delete[] subArray;

}

void Layer::split(std::list<Layer*>* ptrList) {
	// This will turn 1 array into 2 smaller halves, and copy them onto the new task list.
	// if the array is size one, DO NOT EXECUTE.
	if (arrSize != 1) {
		
		int leftSplit = (arrSize / 2);
		int rightSplit = (arrSize - leftSplit); // Can't assume halves are even.

		// Creation and recognition of sub arrays
		Layer leftArr(subArray, leftSplit, layerNum + 1);
		Layer rightArr(subArray + leftSplit, rightSplit, layerNum + 1);

		ptrLeftSplit = &leftArr;
		ptrRightSplit = &rightArr;

		/* CRITCAL SECTION START 
		* This is due to the fact the list pointer might change.
		*/

		// Adding to tasks list
		ptrList->push_back(ptrLeftSplit);
		ptrList->push_back(ptrRightSplit);

		/* CRITCAL SECTION END */
	}

}

void Layer::combine() {

	// NOTE: list.merge() would be ideal for this however for demonstration's sake I'll do it manually.

	// This will use the 2 child pointers defined during split() to alter its own array into a sorted combo.

}

int Layer::getLayerNum() {return layerNum; }
int Layer::getSize() { return arrSize; }
int* Layer::getArrayPointer() { return subArray; }