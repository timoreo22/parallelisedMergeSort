#pragma once
class Layer
{

private:

	// Vars
	Layer* ptrLeftSplit = nullptr; // These will be overwritten as subsubarrays are made.
	Layer* ptrRightSplit = nullptr;
	int* subArray; // Size will be defined in constructor.
	int arrSize;
	int layerNum;

public:

	// Constructor & Destructor
	Layer(int*, int, int);
	~Layer();

	// Functions
	void split(std::list<Layer*>*); 
	void combine(); // This should only be called on nodes with children to combine. 
	int getLayerNum();
	int getSize();
	int* getArrayPointer();

};

