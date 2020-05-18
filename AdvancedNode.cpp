#include "AdvancedNode.h"


void AdvanceNode::addNode(Node * inNode)
{
	internalNodes->push_back(inNode);
}

int AdvanceNode::calculateCircuit(unsigned int inID, bool & inError)
{
	for (Input* currentInput : listOfInputs)
	{
		currentInput->getOutputConnection()->runCircuit(inID, inError);
	}
	if (!inError)
	{
		for (Output* currentOutput : listOfOutputs)
		{
			currentOutput->runCircuit(inID, inError);
		}
	}
	return 0;
}
