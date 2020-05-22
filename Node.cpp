#include "Node.h"

Node::Node()
{
	internalNodes = new std::vector<Node*>();
	score = 0;
}



Node::~Node()
{
	for (Node* deleteMe : *internalNodes)
	{
		delete deleteMe;
	}
	delete internalNodes;
}

Node * Node::getClone()
{
	Node* myClone = returnMyType();
	unsigned int counter = 0;
	for (Input* cloneInputs : myClone->listOfInputs)
	{
		cloneInputs->setConnectionID(listOfInputs.at(counter)->getConnectionID());
	}
	return myClone;
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

void Node::setID(unsigned int inID, unsigned int& newID)
{
	for (Input* myInputs : listOfInputs)
	{
		myInputs->setID(inID, newID);
	}
}

void Node::storeConnectionIDs(unsigned int inID)
{
	for (Input* myInputs : listOfInputs)
	{
		myInputs->storeConnectionIDs(inID);
	}
}

void Node::addNode(unsigned int inID, Node * inNode)
{
}

void Node::addNodeToAdvancedCircuit(unsigned int inID, Node * inCircuitToAddTo)
{
	for (Input* myInputs : listOfInputs)
	{
		myInputs->addNodeToAdvancedCircuit(inID, inCircuitToAddTo);
	}
}

std::vector<Input*> Node::getListOfInputs() const
{
	return listOfInputs;
}

std::vector<Output*> Node::getListOfOutputs() const
{
	return listOfOutputs;
}
