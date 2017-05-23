#include "enigma.hpp"

using namespace Enigma;

CEnigma::CEnigma(std::string filename)
{
	char path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, path);
	sprintf(path, "%s\\%s", path, filename.c_str());
	
	ringSettings = "AAA";
	startingPosition = "AAA";
	
	char r1[4], r2[4], r3[4];
	GetPrivateProfileString("PARTS", "L_ROTOR", "I", r1, 4, path);
	GetPrivateProfileString("PARTS", "M_ROTOR", "II", r2, 4, path);
	GetPrivateProfileString("PARTS", "R_ROTOR", "III", r3, 4, path);
	
	rotors.push_back(CRotor(std::string(r1)));
	rotors.push_back(CRotor(std::string(r2)));
	rotors.push_back(CRotor(std::string(r3)));

	char ref[2];
	GetPrivateProfileString("PARTS", "REFLECTOR", "B", ref, 2, path);
	reflector = CReflector(*ref);
	
	char rs[4];
	GetPrivateProfileString("SETTINGS", "RING", "AAA", rs, 4, path);
	ringSettings = std::string(rs);
	
	char sp[4];
	GetPrivateProfileString("SETTINGS", "START", "AAA", sp, 4, path);
	startingPosition = std::string(sp);
	
	char pb[27];
	GetPrivateProfileString("SETTINGS", "PLUGBOARD", "", pb, 27, path);
	plugboard = CPlugboard(std::string(pb));
	
	setupRotors();
}

std::string CEnigma::cipher(std::string plain)
{
	for(int i = 0; i < plain.length(); i++) plain[i] = toupper(plain[i]);
	
	std::string cipher = "";
	
	for (const char& letter : plain) {
		if (rotors[2].step() || rotors[1].doDoubleStep()) {
			if (rotors[1].step()) {
				rotors[0].step();
			}
		}
		
		char c = letter;
		
		c = plugboard.map(c);
		
		for (int i = rotors.size() - 1; i >= 0; i--) {
			c = rotors[i].map(c);
		}
		
		c = reflector.map(c);
		
		for (Enigma::CRotor& rotor : rotors) {
			c = rotor.inverseMap(c);
		}
		
		c = plugboard.map(c);

		cipher += c;
	}
	
	return cipher;
}

void CEnigma::setupRotors()
{
	for (unsigned i = 0; i < rotors.size(); i++) {
		rotors[i].moveInternalWiring(ringSettings[i]);
		rotors[i].setStartingPosition(startingPosition[i]);
	}
}
