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
};

#endif