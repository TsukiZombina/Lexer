#pragma once
#include "DFA.h"

class DFAFalse :
	public DFA
{
public:
	DFAFalse();
	virtual ~DFAFalse();
private:
	const unsigned cardinality = 5;
	const char* lexema = "False";
};
