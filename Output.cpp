#include "Output.h"

Output::Output()
{
}

Output::Output(Node * inMyNode)
{
	myNode = inMyNode;
	validInput = false;
	currentID = 0;
	myID = 0;
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

void Output::setID(unsigned int inID, unsigned int& newID)
{
	if (inID > currentID)
	{
		currentID = inID;
		myID = ++newID;
		myNode->setID(inID, newID);
	}
}

void Output::storeConnectionIDs(unsigned int inID)
{
	if (inID > currentID)
	{
		currentID = inID;
		myNode->storeConnectionIDs(inID);
	}
}

unsigned int Output::getID() const
{
	return myID;
}

void Output::addNodeToAdvancedCircuit(unsigned int inID, Node * inCircuitToAddTo)
{
	if (inID > currentID)
	{
		currentID = inID;
		inCircuitToAddTo->addNode(inID, myNode->getClone());
		myNode->addNodeToAdvancedCircuit(inID, inCircuitToAddTo);
	}
}
