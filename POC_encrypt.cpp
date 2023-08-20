#include <iostream>
#include <vector>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

std::vector<std::string> Code(std::string decKey);
std::string encryptMessage(std::vector<std::string> vecPolyalph, std::string plainText);

int main() 
{    
    
    std::string str, messageToEncrypt {"GOODBYE"}, encryptedMessage;
    std::cin >> str;
    std::vector<std::string> strVector = Code(str);
    int choice {0};

    std::cout << "1. Encrypt | 2. Decrypt" << std::endl;
    std::cin >> choice;
    if(choice == 1){
        std::cout << encryptMessage(strVector, messageToEncrypt) << std::endl;
    } else if(choice == 2){
        // std::cout << decrypt;
    }

    return 0;
}

std::vector<std::string> Code(std::string decKey)
{
    std::vector<std::string> alphabetKeys;
    for(size_t i {0}; i < decKey.size(); i++){
        size_t found = std::string(ALPHABET).find(decKey[i]);
        alphabetKeys.push_back(std::string(ALPHABET).substr(found));
        alphabetKeys.at(i) += std::string(ALPHABET).substr(0, found);
        std::cout << std::string(ALPHABET).substr(0, found) << " | " << i << std::endl;
    }
    
    return alphabetKeys;
}

std::string encryptMessage(std::vector<std::string> vecPolyalph, std::string plainText)
{
    size_t charCount {0};
    std::string encrypted {"initialized"};
    encrypted.clear();
    for(size_t i {0}; i < plainText.size(); i++){
        if(charCount >= vecPolyalph.size()){
            charCount = 0;
        }
        // std::cout << vecPolyalph.at(charCount);
        auto arrPosition {std::string(ALPHABET).find(plainText[i])};
        encrypted += vecPolyalph.at(charCount)[arrPosition];

        charCount++;
    }

    return encrypted;
}
