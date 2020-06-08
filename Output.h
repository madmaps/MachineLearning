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
	virtual void setValue(int inValue);
	virtual unsigned int getID()const;
	virtual void addNodeToAdvancedCircuit(unsigned int inID, Node* inCircuitToAddTo);
	virtual void makeRandomConnection(unsigned int inID, std::deque<std::list<Output*>*>* inListOfOutputs, unsigned int inZeroPosition);
	virtual void setAsInputTerminal(bool inValue);
	virtual unsigned int getNodeHoops(unsigned int inID);
	virtual unsigned int getSizeOfInternalNodes()const;
	virtual void resetID(unsigned int inID);

protected:
	unsigned int currentID;
	bool validInput;
	int myValue;
	Node* myNode;
	unsigned int myID;
	bool inputTerminal;
private:
};




#endif
