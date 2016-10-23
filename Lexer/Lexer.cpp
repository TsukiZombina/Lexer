#include "Lexer.h"



Lexer::Lexer()
{
}


Lexer::~Lexer()
{
}

std::string Lexer::readWS(std::string code, const char* filename) {
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