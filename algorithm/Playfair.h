
#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <string>
#include <vector>

#define VChar std::vector<char>
#define VInt std::vector<int>
#define PMatrix std::vector<VChar>

PMatrix createMatrix(const std::string&);

struct Playfair {
	static std::string encryption(const std::string& plainText, const std::string& k);

	static std::string decryption(const std::string& cipherText, const std::string& k);
};

#endif // !PLAYFAIR_H
