#pragma once
#ifndef __ADVANCEDNODE__
#define __ADVANCEDNODE__
#include <vector>
#include "Node.h"
class Node;

class AdvanceNode : public Node
{
public:
	void addNode(Node* inNode);
	virtual int calculateCircuit(unsigned int inID, bool& inError);
protected:
private:
};




#endif