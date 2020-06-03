#include "MultiplierNode.h"
#include <iostream>

int MultiplierNode::calculate(bool& inError) const
{
	std::cout << "(" << listOfInputs->at(0)->getOutputConnection()->getValue() << "*" << listOfInputs->at(1)->getOutputConnection()->getValue() << ")";
	return listOfInputs->at(0)->getOutputConnection()->getValue() * listOfInputs->at(1)->getOutputConnection()->getValue();
}

Node * MultiplierNode::returnMyType() const
{
	return new MultiplierNode();
}
