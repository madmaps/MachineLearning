#pragma once
#ifndef __DIVIDERNODE__
#define __DIVIDERNODE__
#include "TwoInOneOutSimpleNode.h"

class DividerNode : public TwoInOneOutSimpleNode
{
protected:
	virtual int calculate(bool& inError)const;
};

#endif
