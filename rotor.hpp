#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <iostream>
#include <algorithm>

namespace Enigma
{
	class CRotor
	{
	public:
		CRotor(std::string type);
		
		bool moveInternalWiring(int count);
		bool setStartingPosition(int count);
		bool step();
		bool doDoubleStep();
		char map(char letter);
		char inverseMap(char letter);
			
	private:
		std::string substitutionTable;
		char notch;
		bool doubleStep;
		
		std::string ioLayer;
		std::string hiddenLayer;
		std::string visibleLayer;
	};
}

#endif
