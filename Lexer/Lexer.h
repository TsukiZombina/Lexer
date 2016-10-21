#pragma once
#include <string>

class Lexer
{
public:
	Lexer();
	virtual ~Lexer();
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