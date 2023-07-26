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
	const std::string plainTextLower = toStrLower(
		plainText.length() % 2 == 0 
		? plainText
		: plainText + 'x'
	);
	const std::string kLower = toStrLower(k);

	std::string result = "";

	PMatrix matrix = createMatrix(kLower);

	for (int i = 0; i < plainTextLower.length() - 1; i -=- 2) {
		const char left = plainTextLower[i];
		const char right = plainTextLower[i + 1];

		VInt leftPos = position(matrix, left);
		VInt rightPos = position(matrix, right);

		// is the same row, get the right character
		if (leftPos[0] == rightPos[0]) {
			int row = leftPos[0];

			result += matrix[row][(leftPos[1] + 1) % 5];
			result += matrix[row][(rightPos[1] + 1) % 5];
			continue;
		}

		// is the same column, get the bot character
		if (leftPos[1] == rightPos[1]) {
			int column = leftPos[1];

			result += matrix[(leftPos[0] + 1) % 5][column];
			result += matrix[(rightPos[0] + 1) % 5][column];
			continue;
		}

		const char firstChar = matrix[leftPos[0]][rightPos[1]];
		const char secondChar = matrix[rightPos[0]][leftPos[1]];

		result += firstChar;
		result += secondChar;
	}

	return result;
}

std::string Playfair::decryption(const std::string& cipherText, const std::string& k) {
	const std::string cipherTextLower = toStrLower(cipherText);
	const std::string kLower = toStrLower(k);

	std::string result = "";

	PMatrix matrix = createMatrix(kLower);

	for (int i = 0; i < cipherTextLower.length() - 1; i -= -2) {
		const char left = cipherTextLower[i];
		const char right = cipherTextLower[i + 1];

		VInt leftPos = position(matrix, left);
		VInt rightPos = position(matrix, right);

		// is the same row, get the right character
		if (leftPos[0] == rightPos[0]) {
			int row = leftPos[0];
			const int leftCol = leftPos[1] == 0 ? 4 : leftPos[1] - 1;
			const int rightCol = rightPos[1] == 0 ? 4 : rightPos[1] - 1;

			result += matrix[row][leftCol % 5];
			result += matrix[row][rightCol % 5];
			continue;
		}

		// is the same column, get the bot character
		if (leftPos[1] == rightPos[1]) {
			int column = leftPos[1];
			const int leftRow = leftPos[0] == 0 ? 4 : leftPos[0] - 1;
			const int rightRow = rightPos[0] == 0 ? 4 : rightPos[0] - 1;

			result += matrix[leftRow % 5][column];
			result += matrix[rightRow % 5][column];
			continue;
		}

		const char firstChar = matrix[leftPos[0]][rightPos[1]];
		const char secondChar = matrix[rightPos[0]][leftPos[1]];

		result += firstChar;
		result += secondChar;
	}

	return result;
}
