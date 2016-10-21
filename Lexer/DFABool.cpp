#include "DFABool.h"



DFABool::DFABool()
{
	for (auto& state : finalStates)
	{
		DFA::finalStates.push_back(state);
	}
	TransitionSet transitionSet;
	for (unsigned i = 0; i < totalStates; i++)
		transitionFunction.push_back(transitionSet);
	setTransition(0, 't', 1);
	setTransition(1, 'r', 2);
	setTransition(2, 'u', 3);
	setTransition(3, 'e', 4);
}


DFABool::~DFABool()
{
}
