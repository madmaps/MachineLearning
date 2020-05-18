#include "MultiplierNode.h"

int MultiplierNode::calculate(bool& inError) const
{
	return listOfInputs.at(0)->getOutputConnection()->getValue() * listOfInputs.at(1)->getOutputConnection()->getValue();
}

Node * MultiplierNode::returnMyType() const
{
	return new MultiplierNode();
}
