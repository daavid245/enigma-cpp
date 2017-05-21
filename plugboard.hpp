#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <iostream>
#include <algorithm>

namespace Enigma
{
	class CPlugboard
	{
	public:
		CPlugboard(std::string table = "");
		
		char map(char letter);
		
	private:
		std::string substitutionTable;
	};
}

#endif
