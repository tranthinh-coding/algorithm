#ifndef VINGENERE_H
#define VINGENERE_H

#include <string>
#include "Global.h"

struct Vingenere
{
	static std::string encryption(const std::string& plainText, const std::string& k);

	static std::string decryption(const std::string& cipherText, const std::string& k);
};

#endif
