#include "Output.h"

Output::Output()
{
}

Output::Output(Node * inMyNode)
{
	myNode = inMyNode;
	validInput = false;
	currentID = 0;
}

Output::~Output()
{
}

int Output::getValue() const
{
	return myValue;
}

void Output::runCircuit(unsigned int inID, bool& inError)
{
	validInput = false;
	if (inID > currentID)
	{
		int value = myNode->calculateCircuit(inID, inError);
		if (!inError)
		{
			myValue = value;
			validInput = true;
			currentID = inID;
		}
	}
}

void Output::giveScore(unsigned int inID, unsigned int inScore)
{
	if (inID > currentID)
	{
		myNode->giveScore(inID, inScore);
		currentID = inID;
	}
}
