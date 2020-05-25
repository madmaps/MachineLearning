#include "DividerNode.h"

int DividerNode::calculate(bool& inError) const
{
	int returnValue = 0;
	if (listOfInputs->at(1)->getOutputConnection()->getValue() == 0)
	{
		inError = true;
	}
	else
	{
		returnValue =  listOfInputs->at(0)->getOutputConnection()->getValue() / listOfInputs->at(1)->getOutputConnection()->getValue();
	}
	return returnValue;
}

Node * DividerNode::returnMyType() const
{
	return new DividerNode();
}
