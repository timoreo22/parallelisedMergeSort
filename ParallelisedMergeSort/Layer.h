#pragma once
#include <memory>
class Layer
{

private:

	// Vars
	std::shared_ptr<Layer> ptrLeftSplit = nullptr; // These will be overwritten as subsubarrays are made.
    std::shared_ptr<Layer> ptrRightSplit = nullptr;
	int* subArray; // Size will be defined in constructor.
	int arrSize;
	int layerNum;

public:

	// Constructor & Destructor
	Layer(int*, int, int);
	~Layer();

	// Functions
	void split(std::list<std::shared_ptr<Layer>>&);
	void combine(); // This should only be called on nodes with children to combine. 
	int getLayerNum();
	int getSize();
	int* getArrayPointer();

};

