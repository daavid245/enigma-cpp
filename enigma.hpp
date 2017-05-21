#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include <Windows.h>

#include "rotor.hpp"
#include "reflector.hpp"
#include "plugboard.hpp"

using Rotors = std::vector<Enigma::CRotor>;

namespace Enigma
{
	class CEnigma
	{
	public:
		CEnigma(std::string filename);
		
		std::string cipher(std::string plain);
		
	private:
		Rotors rotors;
		CReflector reflector;
		CPlugboard plugboard;
		
		std::string ringSettings;
		std::string startingPosition;
		
		void setupRotors();
	};
}

#endif
