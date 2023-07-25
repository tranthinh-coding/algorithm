#include "Global.h"

const VChar PLAYFAIR_CHARACTER_LOWER_MAP = VChar({
	'a', 'b', 'c', 'd', 'e',
	'f', 'g', 'h', 'i', 'k', 
	'l', 'm', 'n', 'o',	'p', 
	'q', 'r', 's', 't',	'u', 
	'v', 'w', 'x', 'y',	'z',
});

const VChar CHARACTER_LOWER_MAP = VChar({
	'a', 'b', 'c', 'd', 'e',
	'f', 'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't',
	'u', 'v', 'w', 'x', 'y',
	'z',
});

const VChar CHARACTER_UPPER_MAP = VChar({
	'A', 'B', 'C', 'D', 'E',
	'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O',
	'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y',
	'Z',
});

// return first character, Upper or Lower
char getBase(const char& c) {
	return isupper(c) ? 'A' : 'a';
}


std::string toStrLower(const std::string& str) {
	std::string result = "";
	for (auto& c : str) {
		result.push_back(tolower(c));
	}
	return result;
}

std::string toStrUpper(const std::string& str) {
	std::string result = "";
	for (auto& c : str) {
		result.push_back(toupper(c));
	}
	return result;
}