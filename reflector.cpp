#include "reflector.hpp"

using namespace Enigma;

CReflector::CReflector(char type)
{
	switch (type) {
		case 'B':
			substitutionTable = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
			break;
			
		case 'C':
			substitutionTable = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
			break;
	}
}

char CReflector::map(char letter)
{
	return substitutionTable[letter - 65];
}
