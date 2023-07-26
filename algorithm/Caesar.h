#ifndef CAESAR_H
#define CAESAR_H
#include <string>

struct Caesar {
	static std::string encryption(const std::string& plainText, const int& k);

	static std::string decryption(const std::string& cipherText, const int& k);
};

#endif