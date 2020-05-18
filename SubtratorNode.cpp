#include "SubtratorNode.h"

int SubtractorNode::calculate(bool& inError) const
{
	return listOfInputs.at(0)->getOutputConnection()->getValue() - listOfInputs.at(1)->getOutputConnection()->getValue();
}

Node * SubtractorNode::returnMyType() const
{
	return new SubtractorNode();
}
