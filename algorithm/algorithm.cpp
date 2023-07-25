#include <iostream>
#include "Global.h"
#include "Caesar.h"
#include "Playfair.h"

int main()
{
    const std::string plainText = "TruongDaiHocUneti";

    const std::string caesarCipherText = Caesar::encryption(plainText, 1);

    std::cout << "Cipher text: = " << caesarCipherText << std::endl;

    const std::string caesarPlainText = Caesar::decryption(caesarCipherText, 1);

    std::cout << "Plain text: " << caesarPlainText << std::endl;

    const std::string playFairKey = "ThinkTran";
    
    Playfair::encryption(plainText, playFairKey);
}
