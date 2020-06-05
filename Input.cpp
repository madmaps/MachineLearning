#include "Input.h"
#include <random>
#include <iostream>

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

void Input::makeRandomConnection(unsigned int inID, std::deque<std::list<Output*>*>* inListOfOutputs, int inListPosition, unsigned int inZeroPosition)
{
	std::random_device r;
	std::mt19937 randomEngine(r());
	const unsigned int probability = 2;
	bool found = false;
	if (listOfConnectionScores->size() > 0)
	{
		unsigned int totalOutputScores = 0;
		for (ConnectionScore* currentScore : *listOfConnectionScores)
		{
			totalOutputScores += currentScore->score;
		}
		std::list<ConnectionScore*>::iterator scoreIter = listOfConnectionScores->begin();
		std::uniform_int_distribution<int> pickConnection(0, totalOutputScores + probability);
		unsigned int randomConnection = pickConnection(randomEngine);
		unsigned int i = (*scoreIter)->score;
		if (randomConnection < totalOutputScores)
		{
			while (i <= totalOutputScores && !found)
			{
				if (i >= randomConnection)
				{
					found = true;
				}
				else
				{
					scoreIter++;
					i += (*scoreIter)->score;
				}
			}
		}
		if (found)
		{
			outputConnection = (*scoreIter)->connection;
		}
	}
	if (!found)
	{
		unsigned int possibleOutputs = 0;
		for (int listCounter = (inListPosition - 1) + (inZeroPosition - 1); listCounter >= 0; listCounter--)
		{
			possibleOutputs += inListOfOutputs->at(listCounter)->size();
		}
		std::uniform_int_distribution<int> randomOutput(0, possibleOutputs - 1);
		unsigned int outputPick = randomOutput(randomEngine);
		bool gotAnOutput = false;
		unsigned int outputCount = 0;
		for (std::list<Output*>* outputList : *inListOfOutputs)
		{
			outputCount += outputList->size();
			if (outputPick <= outputCount && !gotAnOutput)
			{
				gotAnOutput = true;
				std::list<Output*>::iterator outputIter = outputList->begin();
				unsigned int counter = 1;
				while (counter < outputCount - outputPick)
				{
					outputIter++;
					counter++;
				}
				outputConnection = *outputIter;
			}
		}

	}
	outputConnection->makeRandomConnection(inID, inListOfOutputs, inZeroPosition);
}

unsigned int Input::getNodeHoops(unsigned int inID)
{
	return outputConnection->getNodeHoops(inID);
}
