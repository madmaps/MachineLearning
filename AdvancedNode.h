#pragma once
#ifndef __ADVANCEDNODE__
#define __ADVANCEDNODE__
#include <vector>
#include "Node.h"
class Node;

class AdvanceNode : public Node
{
public:
	virtual Node* getClone();
	//virtual void makeRandomConnection(unsigned int inID, std::deque<std::list<Output*>*>* inListOfOutputs, unsigned int inZeroPosition);
	virtual void addNode(unsigned int inID, Node* inNode);
	virtual int calculateCircuit(unsigned int inID, bool& inError);
	virtual void linkConnections();
	virtual void pushOnNode(Node* inNode);
	virtual void addMyOuputLocationInTheList(int inMyOuputLocationInTheList);

protected:
	virtual int calculate(bool& inError) const;
	virtual Node* returnMyType() const;


private:
};




#endif