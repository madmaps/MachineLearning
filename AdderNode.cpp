#include "AdderNode.h"
#include <iostream>


int AdderNode::calculate(bool& inError) const
{
	//std::cout << "(" << listOfInputs->at(0)->getOutputConnection()->getValue() << "+" << listOfInputs->at(1)->getOutputConnection()->getValue() << ")";
	return listOfInputs->at(0)->getOutputConnection()->getValue() + listOfInputs->at(1)->getOutputConnection()->getValue();
}

Node * AdderNode::returnMyType() const
{
	return new AdderNode();
}
