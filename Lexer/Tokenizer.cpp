#include "Tokenizer.h"



Tokenizer::Tokenizer()
{
}


Tokenizer::~Tokenizer()
{
}

std::string Tokenizer::readWS(std::string code, const char* filename) {
	std::ifstream ifs(filename);
	char character;
	if (ifs.is_open())
	{
		while (ifs >> std::skipws >> character)
			code.push_back(character);
		ifs.close();
	}
	else std::cerr << "Unable to open file" << std::endl;
	return code;
}

std::string readIdentifier(std::string code)
{
	int state;
	std::string str = code, temp;
	std::vector<unsigned> final;
	final.push_back(1);
	final.push_back(2);
	DFA identifier(3, final, str);
	identifier.setTransition(0, '_', 1);
	identifier.setTransition(0, 'a', 1);
	identifier.setTransition(1, '_', 2);
	identifier.setTransition(1, 'a', 2);
	identifier.setTransition(1, '1', 2);
	identifier.setTransition(2, '_', 2);
	identifier.setTransition(2, 'a', 2);
	identifier.setTransition(2, '1', 2);
	identifier.orderTransitions();
	int size = code.size();
	if (state = identifier.isAccepting(str))
		std::string str2 = str.substr(3, size-3);
}