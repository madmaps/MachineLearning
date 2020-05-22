// Matthew Applin
// Machine Learning

#include <iostream>
#include "InputTerminal.h"
#include "AdderNode.h"
#include "SubtratorNode.h"
#include "ModularNode.h"
#include "AdvancedNode.h"

int main()
{
	
	AdderNode* adderOne = new AdderNode();
	SubtractorNode* subberOne = new SubtractorNode();
	ModularNode* modOne = new ModularNode();

	InputTerminal* value1 = new InputTerminal();
	InputTerminal* value2 = new InputTerminal();
	InputTerminal* value3 = new InputTerminal();
	InputTerminal* value4 = new InputTerminal();
	
	value1->setValue(5);
	value2->setValue(4);
	value3->setValue(2);
	value4->setValue(5);

	adderOne->setInput(0, value1);
	adderOne->setInput(1, value2);
	subberOne->setInput(0,adderOne->getOutput(0));
	subberOne->setInput(1, value3);
	modOne->setInput(0, adderOne->getOutput(0));
	modOne->setInput(1, subberOne->getOutput(0));

	Output* Answer = modOne->getOutput(0);
	unsigned int currentID = 0;
	bool error = false;
	unsigned int inID = 0;
	Answer->runCircuit(currentID++, error);
	Answer->giveScore(currentID++, 5);
	Answer->setID(currentID++, inID);
	Answer->storeConnectionIDs(currentID++); // Problem HERE!!!
	AdvanceNode* newAdvancedNode = new AdvanceNode();
	Answer->addNodeToAdvancedCircuit(currentID++, newAdvancedNode);
	newAdvancedNode->linkConnections();
	newAdvancedNode->setInput(0, value1);
	newAdvancedNode->setInput(1, value2);
	newAdvancedNode->setInput(2, value3);

	if (error)
	{
		std::cout << "Error!!!";
	}
	else
	{
		std::cout << Answer->getValue();
	}
	int whatever;
	std::cin >> whatever;
	return 0;
}