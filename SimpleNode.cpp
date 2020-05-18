#include "SimpleNode.h"
#include <iterator>

SimpleNode::SimpleNode()
{
}

SimpleNode::~SimpleNode()
{
}

int SimpleNode::calculateCircuit(unsigned int inID, bool& inError)
{
	for (Input* currentInput : listOfInputs)
	{
		currentInput->getOutputConnection()->runCircuit(inID, inError);
	}
	if (!inError)
	{
		return calculate(inError);
	}
	return 0;
}
