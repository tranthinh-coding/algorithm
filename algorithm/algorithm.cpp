#include <iostream>
#include "Global.h"
#include "Caesar.h"
#include "Playfair.h"
#include "Vingenere.h"

int main()
{
    /*
    const std::string plainText = "kinhtekythuatcongnghiep";

    const std::string caesarCipherText = Caesar::encryption(plainText, 1);

    std::cout << "Cipher text: = " << caesarCipherText << std::endl;

    const std::string caesarPlainText = Caesar::decryption(caesarCipherText, 1);

    std::cout << "Plain text: " << caesarPlainText << std::endl;

    const std::string playFairKey = "khoacntt";
    
    const std::string playfairCipherText = Playfair::encryption(plainText, playFairKey);

    std::cout << playfairCipherText << std::endl;

    const std::string playfairPlainText = Playfair::decryption(playfairCipherText, playFairKey);

    std::cout << playfairPlainText << std::endl;
*/
    const std::string vingenereText = "unetistudent";
    const std::string vingenereKey = "people";

    const std::string vinCipher = Vingenere::encryption(vingenereText, vingenereKey);
    const std::string vinDecrypt = Vingenere::decryption (vinCipher, vingenereKey);
    
    std::cout << vinDecrypt;
}


