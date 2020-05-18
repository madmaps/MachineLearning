#include "ModularNode.h"

int ModularNode::calculate(bool & inError) const
{
	int returnValue = 0;
	if (listOfInputs.at(1)->getOutputConnection()->getValue() == 0)
	{
		inError = true;
	}
	else
	{
		returnValue = listOfInputs.at(0)->getOutputConnection()->getValue() % listOfInputs.at(1)->getOutputConnection()->getValue();
	}
	return returnValue;
}

Node * ModularNode::returnMyType() const
{
	return new ModularNode();
}
