#include <iostream>
#include "Global.h"
#include "Playfair.h"

// return [row, column]
VInt position(const PMatrix& matrix, const char& c) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (matrix[i][j] == c) return { i, j };
		}
	}

	return {-1, -1};
}

/** 5x5 */
PMatrix createMatrix(const std::string& k) {
	PMatrix result;
	result.push_back(VChar());

	int CHARACTER_FLAG[255];
	for (int i = 0; i < 255; ++i) CHARACTER_FLAG[i] = 0;

	for (auto& c : k) {
		if (CHARACTER_FLAG[c] == 1) continue;

		result.back().push_back(c);
		CHARACTER_FLAG[c] = 1;

		if (result.back().size() == 5) {
			result.push_back(VChar());
		}
	}
	
	{
		int i = 0;
		while (true) {
			while (result.back().size() < 5) {
				if (CHARACTER_FLAG[PLAYFAIR_CHARACTER_LOWER_MAP[i]] == 0) {
					result.back().push_back(PLAYFAIR_CHARACTER_LOWER_MAP[i]);
				}
				++i;
			}
			if (result.size() == 5) break;
			result.push_back(VChar());
		}
	}
	
	return result;
}

std::string Playfair::encryption(const std::string& plainText, const std::string& k) {
	const std::string plainTextLower = toStrLower(plainText);
	const std::string kLower = toStrLower(k);

	std::string result = "";

	PMatrix matrix = createMatrix(kLower);
	
	for (int i = 0; i < plainTextLower.length() - 1; i -=- 2) {
		const char left = plainTextLower[i],
			char right = plainTextLower[i + 1];

		VInt positionLeft = position(matrix, left);
		VInt positionRight = position(matrix, right);


	}

	return "";
}

std::string Playfair::decryption(const std::string& plainText, const std::string& k) {
	return "";
}
