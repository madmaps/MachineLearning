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
	inputTerminal = false;
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
	if (!inputTerminal)
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
}

void Output::giveScore(unsigned int inID, unsigned int inScore)
{
	if (!inputTerminal)
	{
		if (inID > currentID)
		{
			myNode->giveScore(inID, inScore);
			currentID = inID;
		}
	}
}

void Output::setID(unsigned int inID, unsigned int& newID)
{
	if (!inputTerminal)
	{
		if (inID > currentID)
		{
			currentID = inID;
			myID = newID++;
			myNode->setID(inID, newID);
		}
	}
}

void Output::storeConnectionIDs(unsigned int inID)
{
	if (!inputTerminal)
	{
		if (inID > currentID)
		{
			currentID = inID;
			myNode->storeConnectionIDs(inID);
		}
	}
}

void Output::setValue(int inValue)
{
	myValue = inValue;
}

unsigned int Output::getID() const
{
	return myID;
}

void Output::addNodeToAdvancedCircuit(unsigned int inID, Node * inCircuitToAddTo)
{
	if (!inputTerminal)
	{
		if (inID > currentID)
		{
			currentID = inID;
			inCircuitToAddTo->addNode(inID, myNode->getClone());
			myNode->addNodeToAdvancedCircuit(inID, inCircuitToAddTo);
		}
	}
}

void Output::makeRandomConnection(unsigned int inID, std::deque<std::list<Output*>*>* inListOfOutputs, unsigned int inZeroPosition)
{
	if (!inputTerminal)
	{
		if (inID > currentID)
		{
			currentID = inID;
			myNode->makeRandomConnection(inID, inListOfOutputs, inZeroPosition);
		}
	}
}

void Output::setAsInputTerminal(bool inValue)
{
	inputTerminal = inValue;
}
