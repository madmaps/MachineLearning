#pragma once
#ifndef __MODULARNODE__
#define __MODULARNODE__
#include "TwoInOneOutSimpleNode.h"

class ModularNode : public TwoInOneOutSimpleNode
{
protected:
	virtual int calculate(bool& inError)const;
	virtual Node* returnMyType() const;

};

#endif
