#include "Output.h"
#include <iostream>

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
			currentID = inID;
			int value = myNode->calculateCircuit(inID, inError);
			if (!inError)
			{
				myValue = value;
				validInput = true;
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
			currentID = inID;
			myNode->giveScore(inID, inScore);
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

unsigned int Output::getNodeHoops(unsigned int inID)
{
	if (!inputTerminal)
	{
		if (inID > currentID)
		{
			currentID = inID;
			return myNode->getNodeHoops(inID);
		}
	}
	return 0;
}

unsigned int Output::getSizeOfInternalNodes() const
{
	if (!inputTerminal)
	{
		return myNode->getSizeOfInternalNodes();
	}
	return 0;
}

void Output::resetID(unsigned int inID)
{
	if (!inputTerminal)
	{
		if (inID > currentID)
		{
			currentID = inID;
			myID = 0;
			myNode->resetID(inID);
		}
	}
}
