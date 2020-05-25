// Matthew Applin
// Machine Learning

#include <iostream>
#include "InputTerminal.h"
#include "AdderNode.h"
#include "SubtratorNode.h"
#include "ModularNode.h"
#include "DividerNode.h"
#include "MultiplierNode.h"
#include "AdvancedNode.h"

int main()
{
	
	AdderNode* adderOne = new AdderNode();
	SubtractorNode* subberOne = new SubtractorNode();
	ModularNode* modOne = new ModularNode();
	DividerNode* divOne = new DividerNode();
	AdderNode* adderTwo = new AdderNode();
	SubtractorNode* subberTwo = new SubtractorNode();
	MultiplierNode* multiOne = new MultiplierNode();

	InputTerminal* value1 = new InputTerminal();
	InputTerminal* value2 = new InputTerminal();
	InputTerminal* value3 = new InputTerminal();
	InputTerminal* value4 = new InputTerminal();
	
	value1->setValue(2);
	value2->setValue(3);
	value3->setValue(2);
	value4->setValue(2);

	adderOne->setInput(0, value1);
	adderOne->setInput(1, value2);
	subberOne->setInput(0,adderOne->getOutput(0));
	subberOne->setInput(1, value3);
	modOne->setInput(0, adderOne->getOutput(0));
	modOne->setInput(1, subberOne->getOutput(0));
	divOne->setInput(0, value2);
	divOne->setInput(1, value4);
	adderTwo->setInput(0, value3);
	adderTwo->setInput(1, divOne->getOutput(0));
	subberTwo->setInput(0, adderOne->getOutput(0));
	subberTwo->setInput(1, adderTwo->getOutput(0));
	multiOne->setInput(0, modOne->getOutput(0));
	multiOne->setInput(1, subberTwo->getOutput(0));


	Output* Answer = multiOne->getOutput(0);
	unsigned int currentID = 1;
	bool error = false;
	unsigned int inID = 0;

	Answer->runCircuit(currentID++, error);
	
	if (error)
	{
		std::cout << "Error!!!" << std::endl;
	}
	else
	{
		std::cout << Answer->getValue() << std::endl;
	}

	Answer->giveScore(currentID++, 5);
	Answer->setID(currentID++, inID);
	Answer->storeConnectionIDs(currentID++);
	AdvanceNode* newAdvancedNode = new AdvanceNode();
	Answer->addNodeToAdvancedCircuit(currentID++, newAdvancedNode);
	newAdvancedNode->linkConnections();
	newAdvancedNode->setInput(0, value1);
	newAdvancedNode->setInput(1, value2);
	newAdvancedNode->setInput(2, value3);
	newAdvancedNode->setInput(3, value3);
	newAdvancedNode->setInput(4, value2);
	newAdvancedNode->setInput(5, value4);

	Answer = newAdvancedNode->getOutput(0);
	Answer->runCircuit(currentID++, error);

	if (error)
	{
		std::cout << "Error!!!" << std::endl;
	}
	else
	{
		std::cout << Answer->getValue() << std::endl;
	}
	int whatever;
	std::cin >> whatever;
	return 0;
}