#include "DFAFalse.h"

DFAFalse::DFAFalse() 
{
	//Step1: initialize F
	unsigned finalState = 5;
	F = new std::vector<unsigned>(FCardinality, finalState);
	//Step2: initialize an empty graph
	TransitionSet transitionSet;
	for (unsigned i = 0; i < cardinality; i++)
		graph.push_back(transitionSet);
	//Step3: establish transitions
	setTransition(0, 1, 'f');
	setTransition(1, 2, 'a');
	setTransition(2, 3, 'l');
	setTransition(3, 4, 's');
	setTransition(4, 5, 'e');
	//Step4: sort transitions by symbol


	sortTransitions();
}

DFAFalse::~DFAFalse() {}