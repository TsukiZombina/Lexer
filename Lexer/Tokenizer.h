#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "DFA.h"

class Tokenizer
{
public:
	Tokenizer();
	virtual ~Tokenizer();
	std::string readWS(std::string code, const char* filename);
	std::string readIdentifier(std::string code);
	std::string readInteger();
	std::string readReal();
	std::string readAsigRelational();
	std::string readAritmetic();
	std::string readLogic();
	std::string readBool();
	std::string readReserved();
	std::string readAssociation();
private:
	std::string code;
};

