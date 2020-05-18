#pragma once
#ifndef __MULTIPLIERNODE__
#define __MULTIPLIERNODE__
#include "TwoInOneOutSimpleNode.h"

class MultiplierNode : public TwoInOneOutSimpleNode
{
protected:
	virtual int calculate(bool& inError)const;
	virtual Node* returnMyType() const;

};

#endif
