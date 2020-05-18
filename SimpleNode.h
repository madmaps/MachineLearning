#pragma once
#ifndef __SIMPLENODE__
#define __SIMPLENODE__
#include "Node.h"


class SimpleNode : public Node
{
public:
	SimpleNode();
	~SimpleNode();

	virtual int calculateCircuit(unsigned int inID, bool& inError);
protected:
private:
};


#endif

