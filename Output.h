#pragma once
#ifndef __OUTPUT__
#define __OUTPUT__
#include "Node.h"
class Node;

class Output
{
public:
	Output();
	Output(Node* inMyNode);
	~Output();

	int getValue() const;

	virtual void runCircuit(unsigned int inID, bool& inError);
	virtual void giveScore(unsigned int inID, unsigned int inScore);
	virtual void setID(unsigned int inID, unsigned int& newID);
	virtual void storeConnectionIDs(unsigned int inID);
	virtual unsigned int getID()const;
	virtual void addNodeToAdvancedCircuit(unsigned int inID, Node* inCircuitToAddTo);

protected:
	unsigned int currentID;
	bool validInput;
	int myValue;
	Node* myNode;
	unsigned int myID;
private:
};




#endif
