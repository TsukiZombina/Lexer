#pragma once
#include "DFA.h"
class DFAIdentifier :
	public DFA
{
public:
	DFAIdentifier();
	virtual ~DFAIdentifier();
private:
	const unsigned FCardinality = 7;
};

