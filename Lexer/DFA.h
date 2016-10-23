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
	DFA(){}
	DFA(unsigned, const std::vector<unsigned> &);
	virtual ~DFA();
	virtual void setTransition(unsigned, char, unsigned);
	virtual void orderTransitions();
	virtual bool isAccepting(const std::string&, unsigned, unsigned&);

protected:
	TransitionFunction transitionFunction;
	std::vector<unsigned> finalStates;
	class Compare
	{
	public:
		bool operator()(const Transition& lhs, const Transition& rhs);
	};
};
