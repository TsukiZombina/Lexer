#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include "TokenIdentifier.h"
#include "DFAInteger.h"
#include "DFAReal.h"
#include "DFAArithmetic.h"
#include "DFALogic.h"
#include "DFAFalse.h"
#include "DFATrue.h"
#include "DFARelational.h"
#include "DFAWhile.h"
#include "DFAIf.h"
#include "DFAAssociation.h"
#include "DFAIdentifier.h"

class Lexer
{
public:
	Lexer();
	virtual ~Lexer();
	typedef std::pair<std::string, TokenIdentifier> Token;
private:
	DFAIdentifier dfaId;
	DFAInteger dfaInteger;
	DFAReal dfaReal;
	DFAArithmetic dfaArithmetic;
	DFALogic dfaLogic;
	DFARelational dfaRelational;
	DFAAssociation dfaAssociation;
	DFATrue dfaTrue;
	DFAFalse dfaFalse;
	DFAIf dfaIf;
	DFAWhile dfaWhile;
private:
	std::list<Token>* tokenList;
	std::unordered_map<std::string, Token>* symbolTable;
	void processIdentifier();
	void processInteger();
	void processReal();
	void processAsigRelational();
	void processAritmetic();
	void processLogic();
	void processBool();
	void processReserved();
	void processAssociation();
};