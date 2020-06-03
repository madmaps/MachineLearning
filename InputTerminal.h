#pragma once
#ifndef __INPUTTERMINAL__
#define __INPUTTERMINAL__
#include "Output.h"

class InputTerminal : public Output
{
public:
	void setValue(int inValue);
	virtual void runCircuit(unsigned int inID, bool& inError);
	virtual void giveScore(unsigned int inID, unsigned int inScore);
	virtual void setID(unsigned int inID, unsigned int& newID);
	virtual void storeConnectionIDs(unsigned int inID);
	virtual void addNodeToAdvancedCircuit(unsigned int inID, Node * inCircuitToAddTo);
	virtual void makeRandomConnection(unsigned int inID, std::list<std::list<Output*>*>* inListOfOutputs);


};

#endif