#include "DFATrue.h"

DFATrue::DFATrue()
{
	//Step1: initialize F
	unsigned finalState = 4;
	F = new std::vector<unsigned>(FCardinality, finalState);
	//Step2: initialize an empty graph
	TransitionSet transitionSet;
	for (unsigned i = 0; i < cardinality; i++)
		graph.push_back(transitionSet);
	//Step3: establish transitions
	setTransition(0, 1, 't');
	setTransition(1, 2, 'r');
	setTransition(2, 3, 'u');
	setTransition(3, 4, 'e');
	//Step4: sort transitions by symbol

	
	sortTransitions();
}

DFATrue::~DFATrue()
{
	if (F) {
		delete F;
		F = nullptr;
	}
}
