#pragma once
#ifndef __NODE__
#define __NODE__
#include <vector>
#include "Input.h"
#include "Output.h"
class Output;
class Input;

class Node
{
public:
	Node();
	~Node();
	virtual int calculateCircuit(unsigned int inID, bool& inError) = 0;
	void setInput(unsigned int whichInput, Output* inOutput);
	Output* getOutput(unsigned int whichOutput)const;
	virtual void giveScore(unsigned int inID, unsigned int inScore);
	
protected:
	std::vector<Input*> listOfInputs;
	std::vector<Output*> listOfOutputs;
	unsigned int score;
private:

};


#endif