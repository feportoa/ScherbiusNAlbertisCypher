#include <iostream>
#include <fstream>

int main() {
    std::ofstream Letter("filename.txt");

    Letter << "Letters from the Nazi during WWII, encrypted by enigma";

    Letter.close();

    return 0;
}