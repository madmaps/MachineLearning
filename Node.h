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
	Node* getClone();
	virtual int calculateCircuit(unsigned int inID, bool& inError) = 0;
	virtual void setInput(unsigned int whichInput, Output* inOutput);
	virtual Output* getOutput(unsigned int whichOutput)const;
	virtual void giveScore(unsigned int inID, unsigned int inScore);
	
protected:
	virtual int calculate(bool& inError) const = 0;
	virtual Node* returnMyType() const = 0;
	std::vector<Input*> listOfInputs;
	std::vector<Output*> listOfOutputs;
	std::vector<Node*>* internalNodes;
	unsigned int score;
private:

};


#endif