#include "Pane.h"
#include <random>

Pane::Pane(std::vector<Node*>*& inUsableNodes, unsigned int inMinRandomNodes, unsigned int inMaxRandomNodes, unsigned int inRewireTries) : usableNodes(inUsableNodes)
{
	myBrain = new std::deque<std::list<Node*>*>();
	listOfOutputs = new std::deque<std::list<Output*>*>();
	everythingWithZeroScore = new std::list<Node*>();
	inputTerminals = new std::list<InputTerminal*>();
	outputTerminals = new std::vector<OutputTerminal*>();
	minNumberOfRandomNodesToAdd = inMinRandomNodes;
	maxNumberOfRandomNodesToAdd = inMaxRandomNodes;
	numberOfRewireTries = inRewireTries;
	myScore = 0;
	currentID = 1;
	zeroPosition = 0;
}

Pane::~Pane()
{
	everythingWithZeroScore->clear();
	delete everythingWithZeroScore;
	everythingWithZeroScore = 0;

	inputTerminals->clear();
	delete inputTerminals;
	inputTerminals = 0;

	for (OutputTerminal* outputTerminalsToDelete : *outputTerminals)
	{
		delete outputTerminalsToDelete;
		outputTerminalsToDelete = 0;
	}
	outputTerminals->clear();
	delete outputTerminals;
	outputTerminals = 0;

	for (std::list<Output*>* outputListToDelete : *listOfOutputs)
	{
		outputListToDelete->clear();
		delete outputListToDelete;
		outputListToDelete = 0;
	}
	listOfOutputs->clear();
	delete listOfOutputs;
	listOfOutputs = 0;

	for (std::list<Node*>* nodeListToDelete : *myBrain)
	{
		for (Node* deleteMe : *nodeListToDelete)
		{
			delete deleteMe;
			deleteMe = 0;
		}
		nodeListToDelete->clear();
		delete nodeListToDelete;
		nodeListToDelete = 0;
	}
	myBrain->clear();
	delete myBrain;
	myBrain = 0;
}

void Pane::train()
{
	addRandomNodes();
	reWire();
}

void Pane::setMaxNumberOfRandomNodesToAdd(unsigned int inMaxNumber)
{
	maxNumberOfRandomNodesToAdd = inMaxNumber;
}

void Pane::setMinNumberOfRandomNodesToAdd(unsigned int inMinNumber)
{
	minNumberOfRandomNodesToAdd = inMinNumber;
}

void Pane::setNumberOfRewireTries(unsigned int inNumberOfTries)
{
	numberOfRewireTries = inNumberOfTries;
}

void Pane::addInputTerminal(InputTerminal * inInputTerminal)
{
	inputTerminals->push_back(inInputTerminal);
}

void Pane::createNewOutputTerminal()
{
	outputTerminals->push_back(new OutputTerminal());
}

void Pane::setTerminalValue(unsigned int whichTerminal, int inValue)
{
	std::list<InputTerminal*>::iterator iterCount = inputTerminals->begin();
	for (unsigned int i = 0; i <= inValue; i++)
	{
		iterCount++;
	}
	(*iterCount)->setValue(inValue);
}

void Pane::addRandomNodes()
{
	std::random_device r;
	std::mt19937 randomEngine(65);
	std::uniform_int_distribution<int> numberOfNodesRandomDistribution(minNumberOfRandomNodesToAdd, maxNumberOfRandomNodesToAdd);
	std::uniform_int_distribution<int> pickRandomNodeToAdd(0, usableNodes->size() - 1);
	unsigned int randomNode = 0;
	unsigned int numberOfNodesToAdd = numberOfNodesRandomDistribution(randomEngine);
	for (unsigned int i = 0; i < numberOfNodesToAdd; i++)
	{
		randomNode = pickRandomNodeToAdd(randomEngine);
		Node* newNode = usableNodes->at(randomNode)->getClone();

		std::uniform_int_distribution<int> pickNodePlacement(0, myBrain->size() + 1);
		unsigned int nodePlacement = pickNodePlacement(randomEngine);
		if (nodePlacement == 0)
		{
			std::list<Node*>* newList = new std::list<Node*>();
			std::list<Output*>* newOutputList = new std::list<Output*>();
			newList->push_back(newNode);
			for (unsigned int j = 0; j < newNode->getListOfOutputs()->size(); j++)
			{
				newOutputList->push_back(newNode->getListOfOutputs()->at(j));
			}
			listOfOutputs->push_front(newOutputList);
			zeroPosition++;
			myBrain->push_front(newList);
			newNode->addMyOuputLocationInTheList(-(int)zeroPosition + 1);
		}
		else if (nodePlacement == myBrain->size() + 1)
		{
			std::list<Node*>* newList = new std::list<Node*>();
			std::list<Output*>* newOutputList = new std::list<Output*>();
			newList->push_back(newNode);
			for (unsigned int j = 0; j < newNode->getListOfOutputs()->size(); j++)
			{
				newOutputList->push_back(newNode->getListOfOutputs()->at(j));
			}
			listOfOutputs->push_back(newOutputList);
			myBrain->push_back(newList);
			newNode->addMyOuputLocationInTheList(listOfOutputs->size() - zeroPosition);
		}
		else
		{
			std::deque<std::list<Node*>*>::iterator nodeIter = myBrain->begin();
			std::deque < std::list<Output*>*>::iterator outputIter = listOfOutputs->begin();
			unsigned int count;
			for (count = 1; count < nodePlacement; count++)
			{
				nodeIter++;
				outputIter++;
			}
			(*nodeIter)->push_back(newNode);
			for (unsigned int j = 0; j < newNode->getListOfOutputs()->size(); j++)
			{
				(*outputIter)->push_back(newNode->getListOfOutputs()->at(j));
			}
			newNode->addMyOuputLocationInTheList(nodePlacement - zeroPosition);

		}
		everythingWithZeroScore->push_back(newNode);

	}
}

void Pane::reWire()
{
	std::list<Output*>* sendInInputTerminals = (std::list<Output*>*)inputTerminals;
	listOfOutputs->push_front(sendInInputTerminals);
	zeroPosition++;
	outputTerminals->at(0)->makeRandomConnection(currentID++, listOfOutputs, listOfOutputs->size() - (zeroPosition - 1), zeroPosition);
	listOfOutputs->pop_front();
	zeroPosition--;
}
