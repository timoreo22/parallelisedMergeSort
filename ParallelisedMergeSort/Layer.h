#pragma once
class Layer
{
	// Vars
	Layer* ptrParent;
	Layer* ptrChildren[2];


	// Functions
	Layer();
	~Layer();
	void split();


};

