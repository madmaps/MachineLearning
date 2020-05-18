#include "Input.h"

Input::Input()
{

}

Input::~Input()
{
	for (ConnectionScore* currentConnection : listOfConnectionScores)
	{
		delete currentConnection;
	}
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
	for (ConnectionScore* currentConnectionScore : listOfConnectionScores)
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
		listOfConnectionScores.push_back(newConnectionScore);
	}
}

