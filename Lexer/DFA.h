#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <iostream>

class DFA
{
public:
	typedef std::pair<unsigned, char> Transition;
	typedef std::vector<Transition> TransitionSet;
	typedef std::vector<TransitionSet> Graph;
	DFA();
	DFA(unsigned, const std::vector<unsigned>&);
	virtual ~DFA();
	virtual void setTransition(unsigned, unsigned, char);
	virtual void sortTransitions();
	virtual bool isAccepting(const std::string&, unsigned, unsigned&);
	virtual void printGraph();
protected:
	Graph graph;
	std::vector<unsigned>* F;
	class Compare
	{
	public:
		bool operator()(const Transition& lhs, const Transition& rhs);
	};
};
