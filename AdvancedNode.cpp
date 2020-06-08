#include "AdvancedNode.h"
#include <iostream>


Node * AdvanceNode::getClone()
{
	AdvanceNode* myClone = (AdvanceNode*)returnMyType();
	for (Node* currentNode : *internalNodes)
	{
		myClone->pushOnNode(currentNode->getClone());
	}
	myClone->linkConnections();
	unsigned int counter = 0;
	for (Input* cloneInputs : *myClone->getListOfInputs())
	{
		cloneInputs->setConnectionID(listOfInputs->at(counter)->getConnectionID());
		counter++;
	}
	return myClone;
}


void AdvanceNode::addNode(unsigned int inID, Node * inNode)
{
	internalNodes->push_back(inNode);
}

int AdvanceNode::calculateCircuit(unsigned int inID, bool & inError)
{
	for (Input* currentInput : *listOfInputs)
	{
		currentInput->getOutputConnection()->runCircuit(inID, inError);
	}
	if (!inError)
	{
		/*for (Output* currentOutput : *listOfOutputs)
		{
			currentOutput->runCircuit(inID, inError);
		}*/
		internalNodes->at(0)->getOutput(0)->runCircuit(inID, inError);
	}
	return 0;
}

void AdvanceNode::linkConnections()
{
	for (Node* myNodes : *internalNodes)
	{
		for (Input* nodeInput : *myNodes->getListOfInputs())
		{
			if (nodeInput->getConnectionID() != 0)
			{
				nodeInput->setConnection(internalNodes->at(nodeInput->getConnectionID())->getListOfOutputs()->at(0));
			}
			else
			{
				listOfInputs->push_back(nodeInput);
			}
		}
	}
	listOfOutputs->push_back(new Output(this));
}

void AdvanceNode::pushOnNode(Node * inNode)
{
	internalNodes->push_back(inNode);
}

//void AdvanceNode::addMyOuputLocationInTheList(int inMyOuputLocationInTheList)
//{
	//internalNodes->at(0)->addMyOuputLocationInTheList(inMyOuputLocationInTheList);
//}

int AdvanceNode::calculate(bool & inError) const
{
	return 0;
}

Node * AdvanceNode::returnMyType() const
{
	return new AdvanceNode();
}
