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

protected:
	unsigned int currentID;
	bool validInput;
	int myValue;
	Node* myNode;
private:
};




#endif
