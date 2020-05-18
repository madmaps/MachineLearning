#include "TwoInOneOutSimpleNode.h"

TwoInOneOutSimpleNode::TwoInOneOutSimpleNode()
{
	Input* input1 = new Input();
	Input* input2 = new Input();
	listOfInputs.push_back(input1);
	listOfInputs.push_back(input2);

	Output* output1 = new Output(this);
	listOfOutputs.push_back(output1);

}

TwoInOneOutSimpleNode::~TwoInOneOutSimpleNode()
{
	Input* input2 = listOfInputs.at(1);
	listOfInputs.pop_back();
	Input* input1 = listOfInputs.at(0);
	listOfInputs.pop_back();
	delete input1;
	delete input2;

	Output* output1 = listOfOutputs.at(0);
	listOfOutputs.pop_back();
	delete output1;

}
