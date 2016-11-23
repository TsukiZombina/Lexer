#include <iostream>
#include "DFAFalse.h"

int main(int argc, char* argv[])
{
	std::string str(argv[1]), lexem;
	DFAFalse dfa;
	unsigned actualPosition = 0, nextPosition;
	if (dfa.isAccepting(str, actualPosition, nextPosition))
	{
		lexem = str.substr(actualPosition, nextPosition - actualPosition);
	 	std::cout << lexem.c_str() << std::endl;
	}
	return 0;
}