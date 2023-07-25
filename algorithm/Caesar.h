#ifndef CAESAR_H
#define CAESAR_H
#include <string>

struct Caesar {
	static std::string encryption(const std::string&, const int&);

	static std::string decryption(const std::string&, const int&);
};

#endif