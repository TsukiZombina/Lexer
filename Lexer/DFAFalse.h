#pragma once
#include "DFA.h"

class DFAFalse :
	public DFA
{
public:
	DFAFalse();
	virtual ~DFAFalse();
private:
	const unsigned FCardinality = 1; //|F|
	const unsigned cardinality = 6;  //|Q|
};
