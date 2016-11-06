#include "DFA.h"

DFA::DFA()
{
	F = nullptr;
}

DFA::DFA(unsigned totalStates, const std::vector<unsigned>& finalStates)
{
	TransitionSet transitionSet;
	for (unsigned i = 0; i < totalStates; i++)
		graph.push_back(transitionSet);
	F = new std::vector<unsigned>(finalStates);
}

DFA::~DFA()
{
	if(F) {
		delete F;
		F = nullptr;
	}
}

void DFA::setTransition(unsigned src, unsigned dest, char symbol)
{
	Transition transition(dest, symbol);
	graph[src].push_back(transition);
}

//Sort by symbols, not the next state
void DFA::sortTransitions()
{
	Compare compare;
	for (auto& transitionSet : graph)
		std::sort(transitionSet.begin(), transitionSet.end(), compare);
}

bool DFA::isAccepting(const std::string& input, 
                      unsigned actualPosition, 
											unsigned& nextPosition)
{
	Compare compare;
	nextPosition = actualPosition;
	unsigned state = 0;
	for (auto& character : input)
	{
		//States a transition with q0 since this method search for the next state
		//by means of symbols
		Transition transition(state, character);
		//Finds if there is a symbol O(n)
		auto it = std::search_n(graph[state].begin(), 
														graph[state].end(),
														1,
														transition,
														compare);
		if (it != graph[state].end()) 
		{
			std::cout << "Current state: " << state << std::endl;
			state = it->first;
			nextPosition++;
			std::cout << "Next state: " << state << std::endl;
		}
		else
			break;
	}
	return std::binary_search(F->begin(), F->end(), state);
}

bool DFA::Compare::operator()(const Transition& lhs, const Transition& rhs)
{
	return lhs.second == rhs.second;
}

void DFA::printGraph() 
{
	for (auto it = graph.begin(); it != graph.end(); it++)
	{
		for (auto jt = it->begin(); jt != it->end(); jt++)
			std::cout << '(' << jt->first << ',' << jt->second << ')' << ' ';
		std::cout << std::endl;
	}
}