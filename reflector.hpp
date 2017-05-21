#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <iostream>
#include <algorithm>

namespace Enigma
{
	class CReflector
	{
	public:
		CReflector(char type = 'B');
		
		char map(char letter);
		
	private:
		std::string substitutionTable;
	};
}

#endif
