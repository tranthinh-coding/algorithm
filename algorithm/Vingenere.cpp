#include "Vingenere.h"
#include <iostream>

std::string Vingenere::encryption(const std::string& plainText, const std::string& k) {
	std::string result = "";

	const int kLength = k.length();
	const int textLength = plainText.length();

	for (int i = 0; i < textLength; ++i) {
		const char c = plainText[i];
		const char base = getBase(c);

		result += (c - base + k[i % kLength] - base) % 26 + base;
	}

	return result;
}

std::string Vingenere::decryption(const std::string& cipherText, const std::string& k) {
	std::string result = "";

	const int kLength = k.length();
	const int textLength = cipherText.length();

	for (int i = 0; i < textLength; ++i) {
		const char c = cipherText[i];
		const char ki = k[i % kLength];
		const char base = getBase(c);

		int cIndex = c - base, kIndex = ki - base;

		if (cIndex < kIndex) {
			cIndex += 26;
		}

		result += (cIndex - kIndex) % 26 + base;
	}

	return result;
}
