#include "Input.h"

Input::Input()
{
	listOfConnectionScores = new std::list<ConnectionScore*>();
}

Input::~Input()
{
	for (ConnectionScore* currentConnection : *listOfConnectionScores)
	{
		delete currentConnection;
	}
	delete listOfConnectionScores;
}

void Input::setConnection(Output * inNewOutputConnection)
{
	outputConnection = inNewOutputConnection;
}

Output * Input::getOutputConnection() const
{
	return outputConnection;
}

void Input::giveScore(unsigned int inID, unsigned int inScore)
{
	outputConnection->giveScore(inID, inScore);
	bool foundConnection = false;
	for (ConnectionScore* currentConnectionScore : *listOfConnectionScores)
	{
		if (outputConnection == currentConnectionScore->connection)
		{
			currentConnectionScore->score += inScore;
			foundConnection = true;
		}
	}
	if (!foundConnection)
	{
		ConnectionScore* newConnectionScore = new ConnectionScore();
		newConnectionScore->connection = outputConnection;
		newConnectionScore->score = inScore;
		listOfConnectionScores->push_back(newConnectionScore);
	}
}

void Input::setID(unsigned int inID, unsigned int& newID)
{
	outputConnection->setID(inID, newID);
}

void Input::storeConnectionIDs(unsigned int inID)
{
	connectionID = outputConnection->getID();
	outputConnection->storeConnectionIDs(inID);
}

unsigned int Input::getConnectionID()const
{
	return connectionID;
}

void Input::setConnectionID(unsigned int inConnectionID)
{
	connectionID = inConnectionID;
}

void Input::addNodeToAdvancedCircuit(unsigned int inID, Node * inCircuitToAddTo)
{
	outputConnection->addNodeToAdvancedCircuit(inID, inCircuitToAddTo);
}
