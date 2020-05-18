// Matthew Applin
// Machine Learning

#include <iostream>
#include "InputTerminal.h"
#include "AdderNode.h"
#include "SubtratorNode.h"
#include "ModularNode.h"

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

	adderOne->setInput(0,value1);
	adderOne->setInput(1, value2);
	subberOne->setInput(0,adderOne->getOutput(0));
	subberOne->setInput(1, value3);
	modOne->setInput(0, adderOne->getOutput(0));
	modOne->setInput(1, subberOne->getOutput(0));

	Output* Answer = modOne->getOutput(0);
	
	bool error = false;
	Answer->runCircuit(1, error);
	Answer->giveScore(2, 5);

	error = false;
	modOne->setInput(1, value4);
	Answer->runCircuit(3, error);
	Answer->giveScore(4, 2);

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