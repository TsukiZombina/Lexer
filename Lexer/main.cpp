#include <iostream>
#include "DFA.h"

int main(int argc, char* argv[])
{
	std::string str(argv[1]), token;
	unsigned actualPosition = 0, nextPosition;
	std::vector<unsigned> final;
	final.push_back(1);
	final.push_back(2);
	DFA oneChain(3,final);
	oneChain.setTransition(0,'0', 2);
	oneChain.setTransition(0, '1', 1);
	oneChain.setTransition(1, '1', 1);
	oneChain.setTransition(1, '0', 2);
	oneChain.setTransition(2, '0', 2);
	oneChain.orderTransitions();
	if (oneChain.isAccepting(str, actualPosition, nextPosition))
	{
		token = str.substr(actualPosition, nextPosition - actualPosition);
		actualPosition = nextPosition;
		std::cout << token.c_str() << std::endl;
	}
	int n;
	std::cin >> n;
	return 0;
}