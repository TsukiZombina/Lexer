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
		std::sort(transitionSet.begin(), transitionSet.end());
}

bool DFA::isAccepting(const std::string& input, unsigned actualPosition, unsigned& nextPosition)
{
	Compare compare;
	nextPosition = actualPosition;
	unsigned state = 0;
	for (auto& character : input)
	{
		Transition transition(character, 0);
		auto it = std::lower_bound(transitionFunction[state].begin(), transitionFunction[state].end(), transition, compare);
		if (it != transitionFunction[state].end()) 
		{
			std::cout << "Current state: " << state << std::endl;
			state = it->second;
			nextPosition++;
			std::cout << "Next state: " << state << std::endl;
		}
		else
			break;
	}
	return std::binary_search(finalStates.begin(), finalStates.end(), state);
}

bool DFA::Compare::operator()(const Transition& lhs, const Transition& rhs)
{
	return lhs.first < rhs.first;
}
