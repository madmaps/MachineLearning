#include "Node.h"

Node::Node()
{
	internalNodes = new std::vector<Node*>();
	listOfInputs = new std::vector<Input*>();
	listOfOutputs = new std::vector<Output*>();
	score = 0;
}



Node::~Node()
{
	for (Node* deleteMe : *internalNodes)
	{
		delete deleteMe;
	}
	delete internalNodes;
	internalNodes = 0;
	for (Input* deleteMe : *listOfInputs)
	{
		delete deleteMe;
	}
	delete listOfInputs;
	listOfInputs = 0;
	for (Output* deleteMe : *listOfOutputs)
	{
		delete deleteMe;
	}
	delete listOfOutputs;
	listOfOutputs = 0;
}

Node * Node::getClone()
{
	Node* myClone = returnMyType();
	unsigned int counter = 0;
	for (Input* cloneInputs : *myClone->getListOfInputs())
	{
		cloneInputs->setConnectionID(listOfInputs->at(counter)->getConnectionID());
		counter++;
	}
	return myClone;
}

void Node::setInput(unsigned int whichInput, Output * inOutput)
{
	listOfInputs->at(whichInput)->setConnection(inOutput);
}

Output * Node::getOutput(unsigned int whichOutput) const
{
	return listOfOutputs->at(whichOutput);
}

void Node::giveScore(unsigned int inID, unsigned int inScore)
{
	for (Input* currentInput : *listOfInputs)
	{
		currentInput->giveScore(inID, inScore);
	}
	score += inScore;
}

void Node::setID(unsigned int inID, unsigned int& newID)
{
	for (Input* myInputs : *listOfInputs)
	{
		myInputs->setID(inID, newID);
	}
}

void Node::storeConnectionIDs(unsigned int inID)
{
	for (Input* myInputs : *listOfInputs)
	{
		myInputs->storeConnectionIDs(inID);
	}
}

void Node::addNode(unsigned int inID, Node * inNode)
{
}

void Node::addNodeToAdvancedCircuit(unsigned int inID, Node * inCircuitToAddTo)
{
	for (Input* myInputs : *listOfInputs)
	{
		myInputs->addNodeToAdvancedCircuit(inID, inCircuitToAddTo);
	}
}

std::vector<Input*>* Node::getListOfInputs() const
{
	return listOfInputs;
}

std::vector<Output*>* Node::getListOfOutputs() const
{
	return listOfOutputs;
}
