#pragma once

#include <vector>
#include <utility>
#include <algorithm>

class DFA
{
public:
	typedef std::pair<char, unsigned> Transition;
	typedef std::vector<Transition> TransitionSet;
	typedef std::vector<TransitionSet> TransitionFunction;
	DFA(unsigned, const std::vector<unsigned> &);
	~DFA();
	void setTransition(unsigned, char, unsigned);
	void orderTransitions();
	bool is_accepting(const std::string&);

private:
	TransitionFunction transitionFunction;
	std::vector<unsigned> finalStates;
};
