#include "SubtratorNode.h"
#include <iostream>

int SubtractorNode::calculate(bool& inError) const
{
	std::cout << "(" << listOfInputs->at(0)->getOutputConnection()->getValue() << "-" << listOfInputs->at(1)->getOutputConnection()->getValue() << ")";
	return listOfInputs->at(0)->getOutputConnection()->getValue() - listOfInputs->at(1)->getOutputConnection()->getValue();
}

Node * SubtractorNode::returnMyType() const
{
	return new SubtractorNode();
}
