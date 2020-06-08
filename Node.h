#pragma once
#ifndef __NODE__
#define __NODE__
#include <vector>
#include <deque>
#include "Input.h"
#include "Output.h"
class Output;
class Input;

class Node
{
public:
	Node();
	~Node();
	virtual Node* getClone();
	virtual int calculateCircuit(unsigned int inID, bool& inError) = 0;
	virtual void setInput(unsigned int whichInput, Output* inOutput);
	virtual Output* getOutput(unsigned int whichOutput)const;
	virtual void giveScore(unsigned int inID, unsigned int inScore);
	virtual void setID(unsigned int inID, unsigned int& newID);
	virtual void storeConnectionIDs(unsigned int inID);
	virtual void addNode(unsigned int inID, Node* inNode);
	virtual void addNodeToAdvancedCircuit(unsigned int inID, Node * inCircuitToAddTo);
	virtual std::vector<Input*>* getListOfInputs()const;
	virtual std::vector<Output*>* getListOfOutputs()const;
	virtual void makeRandomConnection(unsigned int inID, std::deque<std::list<Output*>*>* inListOfOutputs, unsigned int inZeroPosition);
	virtual void addMyOuputLocationInTheList(int inMyOuputLocationInTheList);
	virtual unsigned int getNodeHoops(unsigned int inID);
	virtual unsigned int getSizeOfInternalNodes()const;
	virtual void resetID(unsigned int inID);

	
protected:
	virtual int calculate(bool& inError) const = 0;
	virtual Node* returnMyType() const = 0;
	std::vector<Input*>* listOfInputs;
	std::vector<Output*>* listOfOutputs;
	std::vector<Node*>* internalNodes;
	int myOutputLocationInTheList;
	unsigned int score;
private:

};


#endif