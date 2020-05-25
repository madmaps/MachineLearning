#include "AdderNode.h"


int AdderNode::calculate(bool& inError) const
{
	return listOfInputs->at(0)->getOutputConnection()->getValue() + listOfInputs->at(1)->getOutputConnection()->getValue();
}

Node * AdderNode::returnMyType() const
{
	return new AdderNode();
}
