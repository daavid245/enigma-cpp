#include "plugboard.hpp"

using namespace Enigma;

CPlugboard::CPlugboard(std::string table)
{
	substitutionTable = table;
}

char CPlugboard::map(char letter)
{
	auto pos = substitutionTable.find(letter);
	if (pos == std::string::npos)
		return letter;
		
	return (pos % 2 == 0 ? substitutionTable[pos + 1] : substitutionTable[pos - 1]);
}
