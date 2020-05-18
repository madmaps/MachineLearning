#pragma once
#ifndef __INPUT__
#define __INPUT__
#include <list>
#include "Output.h"

class Output;

class Input
{
public:
	Input();
	~Input();
	void setConnection(Output* inNewOutputConnection);
	Output* getOutputConnection() const;
	virtual void giveScore(unsigned int inID, unsigned int inScore);

protected:
	struct ConnectionScore
	{
		Output* connection;
		unsigned int score;
	};
	std::list<ConnectionScore*>* listOfConnectionScores;
	Output* outputConnection;

private:
};




#endif

