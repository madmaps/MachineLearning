#include "Pane.h"
#include <random>

Pane::Pane(std::vector<Node*>*& inUsableNodes, unsigned int inMinRandomNodes, unsigned int inMaxRandomNodes, unsigned int inRewireTries) : usableNodes(inUsableNodes)
{
	myBrain = new std::list<std::list<Node*>*>();
	listOfOutputs = new std::list<std::list<Output*>*>();
	everythingWithZeroScore = new std::list<Node*>();
	minNumberOfRandomNodesToAdd = inMinRandomNodes;
	maxNumberOfRandomNodesToAdd = inMaxRandomNodes;
	numberOfRewireTries = inRewireTries;
	myScore = 0;
}

Pane::~Pane()
{
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

void Pane::addRandomNodes()
{
	std::random_device r;
	std::mt19937 randomEngine(r);
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
			myBrain->push_front(newList);
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
		}
		else
		{
			std::list<std::list<Node*>*>::iterator nodeIter = myBrain->begin();
			std::list < std::list<Output*>*>::iterator outputIter = listOfOutputs->begin();
			for (unsigned int count = 0; count < nodePlacement; count++)
			{
				nodeIter++;
				outputIter++;
			}
			(*nodeIter)->push_back(newNode);
			for (unsigned int j = 0; j < newNode->getListOfOutputs()->size; j++)
			{
				(*outputIter)->push_back(newNode->getListOfOutputs()->at(j));
			}

		}

	}
}
