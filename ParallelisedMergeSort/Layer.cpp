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

void Layer::split() {

	// This will turn 1 array into 2 smaller halves, and copy them onto the new task list.
}

void Layer::combine() {

	// This will use the 2 child pointers defined during split() to alter its own array into a sorted combo.
}

int Layer::getLayerNum() {return layerNum; }
int Layer::getSize() { return arrSize; }
int* Layer::getArrayPointer() { return subArray; }