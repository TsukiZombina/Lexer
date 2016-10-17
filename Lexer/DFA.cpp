#include "DFA.h"

DFA::DFA(unsigned totalStates, const std::vector<unsigned>& finalS, std::string str)
{
	std::string readable = str;
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

unsigned DFA::isAccepting(const std::string& input) 
{
	Compare compare;
	unsigned state = 0;
	for (auto& character : input)
	{
		Transition transition(character, 0);
		auto it = std::lower_bound(transitionFunction[state].begin(), transitionFunction[state].end(), transition, compare);
		if (it != transitionFunction[state].end()) 
		{
			std::cout << "Current state: " << state << std::endl;
			state = it->second;
			std::cout << "Next state: " << state << std::endl;
		}
				
		else
			return state = 0;
	}
	return *std::lower_bound(finalStates.begin(), finalStates.end(), state);
}

bool DFA::Compare::operator()(const Transition& lhs, const Transition& rhs)
{
	return lhs.first < rhs.first;
}
