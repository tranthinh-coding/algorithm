
#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <string>
#include <vector>

#define VChar std::vector<char>
#define VInt std::vector<int>
#define PMatrix std::vector<VChar>

PMatrix createMatrix(const std::string&);

struct Playfair {
	static std::string encryption(const std::string&, const std::string&);

	static std::string decryption(const std::string&, const std::string&);
};

#endif // !PLAYFAIR_H
