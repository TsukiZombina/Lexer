#include "DFA.h"

DFA::DFA(unsigned totalStates, const std::vector<unsigned>& finalS)
{
	TransitionSet transitionSet;
	for (unsigned i = 0; i < totalStates; i++)
		transitionFunction.push_back(transitionSet);
	for (auto& state : finalS)
		finalStates.push_back(state);
}

DFA::~DFA()
{

}

void DFA::setTransition(unsigned src, char input, unsigned dest)
{
	Transition transition(input, dest);
	transitionFunction[src].push_back(transition);
}

void DFA::orderTransitions()
{
	for (auto& transitionSet : transitionFunction)
	{
		std::unique(transitionSet.begin(), transitionSet.end());
		std::sort(transitionSet.begin(), transitionSet.end());
	}
}

bool DFA::is_accepting(const std::string&) {

}
