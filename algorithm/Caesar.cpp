#include <iostream>
#include "Caesar.h"
#include "Global.h"

std::string Caesar::encryption(const std::string& plainText, const int& k) {
	if (k < 0) {
		std::cout << "Error: K > 0, given k = " << k;
		return "Error: K > 0, given k = " + k;
	}

	std::string result = "";

	for (auto& c : plainText) {
		const char base = getBase(c);
		result += (c - base + k) % 26 + base;
	}

	return result;
}

std::string Caesar::decryption(const std::string& ciphertext, const int& k) {
	if (k < 0) {
		std::cout << "Error: K > 0, given k = " << k;
		return "Error: K > 0, given k = " + k;
	}

	std::string result = "";

	for (auto& c : ciphertext) {
		const char base = getBase(c);
		result += (c - base - k) % 26 + base;
	}

	return result;
}
