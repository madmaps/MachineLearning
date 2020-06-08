#include "AdvancedNode.h"
#include <iostream>


AdvanceNode::AdvanceNode()
{
	internalInputs = new std::list<Input*>();
	internalOutputs = new std::list<Output*>();
	internalOutputTerminals = new std::list<Output*>();
}

AdvanceNode::~AdvanceNode()
{
	internalInputs->clear();
	delete internalInputs;
	internalInputs = 0;

	internalOutputs->clear();
	delete internalOutputs;
	internalOutputs = 0;

	for (Output* currentOutput : *internalOutputTerminals)
	{
		delete currentOutput;
		currentOutput = 0;
	}
	internalOutputTerminals->clear();
	delete internalOutputTerminals;
	internalOutputTerminals = 0;
}

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
	//std::cout << " Running AdvancedNode! ";
	std::list<Output*>::iterator terminalIter = internalOutputTerminals->begin();
	for (Input* currentInput : *listOfInputs)
	{
		currentInput->getOutputConnection()->runCircuit(inID, inError);
		(*terminalIter)->setValue(currentInput->getOutputConnection()->getValue());
		terminalIter++;
	}
	if (!inError)
	{
		std::list<Output*>::iterator internalOutputIter = internalOutputs->begin();
		(*internalOutputIter)->runCircuit(inID, inError);
		return (*internalOutputIter)->getValue();
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
				Output* newOutputTerminal = new Output();
				newOutputTerminal->setAsInputTerminal(true);
				nodeInput->setConnection(newOutputTerminal);
				internalOutputTerminals->push_back(newOutputTerminal);
				internalInputs->push_back(nodeInput);
				listOfInputs->push_back(new Input());
			}
		}
	}
	internalOutputs->push_back(internalNodes->at(0)->getOutput(0));
	listOfOutputs->push_back(new Output(this));
}

void AdvanceNode::pushOnNode(Node * inNode)
{
	internalNodes->push_back(inNode);
}

int AdvanceNode::calculate(bool & inError) const
{
	return 0;
}

Node * AdvanceNode::returnMyType() const
{
	return new AdvanceNode();
}
