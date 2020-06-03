#pragma once
#ifndef __PANE__
#define __PANE__
#include <list>
#include <deque>
#include <vector>
#include "Node.h"
#include "Output.h"
#include "InputTerminal.h"
#include "OutputTerminal.h"

class Pane
{
public:
	Pane(std::vector<Node*>*& inUsableNodes, unsigned int inMinRandomNodes = 1, unsigned int inMaxRandomNodes = 5, unsigned int inRewireTries = 100);
	~Pane();
	
	virtual void train();

	void setMaxNumberOfRandomNodesToAdd(unsigned int inMaxNumber);
	void setMinNumberOfRandomNodesToAdd(unsigned int inMinNumber);
	void setNumberOfRewireTries(unsigned int inNumberOfTries);
	void addInputTerminal(InputTerminal* inInputTerminal);
	void createNewOutputTerminal();
	void setTerminalValue(unsigned int whichTerminal, int inValue);
protected:
	std::deque<std::list<Node*>*>* myBrain;
	std::deque<std::list<Output*>*>* listOfOutputs;
	std::list<Node*>* everythingWithZeroScore;
	std::vector<Node*>*& usableNodes;
	std::list<InputTerminal*>* inputTerminals;
	std::vector<OutputTerminal*>* outputTerminals;
	unsigned int maxNumberOfRandomNodesToAdd;
	unsigned int minNumberOfRandomNodesToAdd;
	unsigned int numberOfRewireTries;
	unsigned int myScore;
	unsigned int currentID;
	unsigned int zeroPosition;
private:
	void addRandomNodes();
	void reWire();
};



#endif
