#pragma once
#ifndef __ADDERNODE__
#define __ADDERNODE__
#include "TwoInOneOutSimpleNode.h"

class AdderNode : public TwoInOneOutSimpleNode
{
protected:
	virtual int calculate(bool& inError) const;
};

#endif
