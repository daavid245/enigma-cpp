#include "rotor.hpp"

using namespace Enigma;

CRotor::CRotor(std::string type)
{
	if (type == "I") {
		substitutionTable = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
		notch = 'Q';
	} else if (type == "II") {
		substitutionTable = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
		notch = 'E';
	} else if (type == "III") {
		substitutionTable = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
		notch = 'V';
	} else if (type == "IV") {
		substitutionTable = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
		notch = 'J';
	} else if (type == "V") {
		substitutionTable = "VZBRGITYUPSDNHLXAWMJQOFECK";
		notch = 'Z';
	}
	
	doubleStep = false;
	
	ioLayer = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	hiddenLayer = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	visibleLayer = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

bool CRotor::moveInternalWiring(int count)
{
	for (int i = 0; i < count - 65; i++) {
		hiddenLayer.insert(hiddenLayer.begin(), hiddenLayer.back());
		hiddenLayer.pop_back();
	}
}

bool CRotor::setStartingPosition(int count)
{
	for (int i = 0; i < count - 65; i++) {
		step();
	}
}

bool CRotor::step()
{
	bool notched = visibleLayer.front() == notch;
	
	visibleLayer.push_back(visibleLayer.front());
	visibleLayer.erase(visibleLayer.begin());
	
	hiddenLayer.push_back(hiddenLayer.front());
	hiddenLayer.erase(hiddenLayer.begin());
	
	doubleStep = visibleLayer.front() == notch;
	
	return notched;
}

bool CRotor::doDoubleStep()
{
	return doubleStep;
}

char CRotor::map(char letter)
{
	auto pos = ioLayer.find(letter);
	
	char hidden = hiddenLayer[pos];
	pos = ioLayer.find(hidden);
	
	char substitute = substitutionTable[pos];
	pos = hiddenLayer.find(substitute);
	
	return ioLayer[pos];
}

char CRotor::inverseMap(char letter)
{
	auto pos = ioLayer.find(letter);
	
	char hidden = hiddenLayer[pos];
	pos = substitutionTable.find(hidden);
	
	char substitute = ioLayer[pos];
	pos = hiddenLayer.find(substitute);
	
	return ioLayer[pos];
}
