#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <iostream>

class DFA
{
public:
	typedef std::pair<char, unsigned> Transition;
	typedef std::vector<Transition> TransitionSet;
	typedef std::vector<TransitionSet> TransitionFunction;
	DFA(unsigned, const std::vector<unsigned> &, std::string);
	~DFA();
	void setTransition(unsigned, char, unsigned);
	void orderTransitions();
	unsigned isAccepting(const std::string&);

private:
	std::string readable;
	TransitionFunction transitionFunction;
	std::vector<unsigned> finalStates;
	class Compare
	{
	public:
		bool operator()(const Transition& lhs, const Transition& rhs);
	};
};
