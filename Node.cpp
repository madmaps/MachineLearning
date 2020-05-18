#include "Node.h"

Node::Node()
{
	score = 0;
}

Node::~Node()
{
}

void Node::setInput(unsigned int whichInput, Output * inOutput)
{
	listOfInputs.at(whichInput)->setConnection(inOutput);
}

Output * Node::getOutput(unsigned int whichOutput) const
{
	return listOfOutputs.at(whichOutput);
}

void Node::giveScore(unsigned int inID, unsigned int inScore)
{
	for (Input* currentInput : listOfInputs)
	{
		currentInput->giveScore(inID, inScore);
	}
	score += inScore;
}
