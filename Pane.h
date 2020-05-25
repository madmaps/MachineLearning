#pragma once
#ifndef __PANE__
#define __PANE__
#include <list>
#include <vector>
#include "Node.h"
#include "Output.h"
#include "InputTerminal.h"

class Pane
{
public:
	Pane(std::vector<Node*>*& inUsableNodes, unsigned int inMinRandomNodes = 1, unsigned int inMaxRandomNodes = 5, unsigned int inRewireTries = 100);
	~Pane();
	
	virtual void train();

	void setMaxNumberOfRandomNodesToAdd(unsigned int inMaxNumber);
	void setMinNumberOfRandomNodesToAdd(unsigned int inMinNumber);
	void setNumberOfRewireTries(unsigned int inNumberOfTries);
protected:
	std::list<std::list<Node*>*>* myBrain;
	std::list<std::list<Output*>*>* listOfOutputs;
	std::list<Node*>* everythingWithZeroScore;
	std::vector<Node*>*& usableNodes;
	std::vector<InputTerminal*> inputTerminals;
	unsigned int maxNumberOfRandomNodesToAdd;
	unsigned int minNumberOfRandomNodesToAdd;
	unsigned int numberOfRewireTries;
	unsigned int myScore;
private:
	void addRandomNodes();
};



#endif
