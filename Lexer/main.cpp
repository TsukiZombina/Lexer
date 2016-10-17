#include <iostream>
#include "DFA.h"

int main(int argc, char* argv[])
{
	int state;
	std::string str(argv[1]);
	std::vector<unsigned> final;
	final.push_back(1);
	final.push_back(2);
	DFA oneChain(3,final,str);
	oneChain.setTransition(0,'0', 2);
	oneChain.setTransition(0, '1', 1);
	oneChain.setTransition(1, '1', 1);
	oneChain.setTransition(1, '0', 2);
	oneChain.setTransition(2, '0', 2);
	oneChain.orderTransitions();
	if (state = oneChain.isAccepting(str))
		std::cout << "Success: " << state << std::endl;
	int n;
	std::cin >> n;
	return 0;
}