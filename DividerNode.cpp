#include "DividerNode.h"
#include <iostream>

int DividerNode::calculate(bool& inError) const
{
	int returnValue = 0;
	if (listOfInputs->at(1)->getOutputConnection()->getValue() == 0)
	{
		std::cout << "(" << listOfInputs->at(0)->getOutputConnection()->getValue() << "/" << listOfInputs->at(1)->getOutputConnection()->getValue() << ")";
		inError = true;
	}
	else
	{
		std::cout << "(" << listOfInputs->at(0)->getOutputConnection()->getValue() << "/" << listOfInputs->at(1)->getOutputConnection()->getValue() << ")";
		returnValue =  listOfInputs->at(0)->getOutputConnection()->getValue() / listOfInputs->at(1)->getOutputConnection()->getValue();
	}
	return returnValue;
}

Node * DividerNode::returnMyType() const
{
	return new DividerNode();
}
