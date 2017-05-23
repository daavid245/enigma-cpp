#include "enigma.hpp"

int main(int argc, char** argv)
{
	Enigma::CEnigma enigma("example-config.ini");
	std::cout << enigma.cipher("GITHUB");
}
