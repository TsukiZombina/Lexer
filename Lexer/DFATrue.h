#pragma once
#include "DFA.h"

class DFATrue :
	public DFA
{
public:
	DFATrue();
	virtual ~DFATrue();
private:
	const unsigned FCardinality = 1; //|F|
	const unsigned cardinality = 5;  //|Q|
};

