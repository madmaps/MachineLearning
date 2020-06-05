#pragma once
#ifndef __INPUT__
#define __INPUT__
#include <list>
#include "Output.h"

class Output;
class Node;

class Input
{
public:
	Input();
	~Input();
	void setConnection(Output* inNewOutputConnection);
	Output* getOutputConnection() const;
	virtual void giveScore(unsigned int inID, unsigned int inScore);
	virtual void setID(unsigned int inID, unsigned int& newID);
	virtual void storeConnectionIDs(unsigned int inID);
	virtual unsigned int getConnectionID()const;
	virtual void setConnectionID(unsigned int inConnectionID);
	void addNodeToAdvancedCircuit(unsigned int inID, Node* inCircuitToAddTo);
	virtual void makeRandomConnection(unsigned int inID, std::deque<std::list<Output*>*>* inListOfOutputs, int inListPosition, unsigned int inZeroPosition);
	virtual unsigned int getNodeHoops(unsigned int inID);



protected:
	struct ConnectionScore
	{
		Output* connection;
		unsigned int score;
	};
	std::list<ConnectionScore*>* listOfConnectionScores;
	Output* outputConnection;
	unsigned int connectionID;

private:
};




#endif

