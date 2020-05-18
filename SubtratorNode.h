#pragma once
#ifndef __SUBTRACTORNODE__
#define __SUBTRACTORNODE__
#include "TwoInOneOutSimpleNode.h"

class SubtractorNode : public TwoInOneOutSimpleNode
{
protected:
	virtual int calculate(bool& inError) const;
};

#endif
