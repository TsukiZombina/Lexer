#pragma once
#include "DFA.h"
class DFABool :
	public DFA
{
public:
	DFABool();
	virtual ~DFABool();
private:
	unsigned finalStates[1] = {4};
	const unsigned totalStates = 5;
	char* lexema = "true";
};

