#include <iostream>
#include <vector>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
std::vector<std::string> Code(std::string decKey);

int main() {
    std::string str {"test"};
    
    std::cin >> str;
    
    size_t find = str.find('b');
    std::cout << find;
    std::vector<std::string> strVector = Code(str);
    for(size_t i {0}; i < strVector.size(); i++){
        //std::cout << strVector[i] << std::endl;
    }
    return 0;
}

std::vector<std::string> Code(std::string decKey)
{
    std::vector<std::string> alphabetKeys;
    for(size_t i {0}; i < decKey.size(); i++){
        size_t found = std::string(ALPHABET).find(decKey[i]);
        alphabetKeys.push_back(std::string(ALPHABET).substr(0, found));
        std::cout << std::string(ALPHABET).substr(0, found) << " | " << i << std::endl;
    }
    return alphabetKeys;
}