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
	virtual int calculate(bool& inError) const = 0;
private:
};


#endif

