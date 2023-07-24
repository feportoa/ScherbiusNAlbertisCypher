#include <iostream>
#include <vector>
#include <string>
#include <termios.h>
#include <ncurses.h>
#include <fstream>

#define ALPHABET {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};



int main() {
    std::string decryptionKey {};
    std::vector<char> encryptedMessage {0};
    std::vector<char> plainText {0};
    bool isEncrypting {true};

    initscr();
    cbreak();
    keypad(stdscr, TRUE);

    do{
        char userInput = getch();
        if(userInput != ' '){
            //clear();
            if(userInput == '\n'){
                char fileName[50];
                bool encKeyAsPlainText {false};

                printw("Enter file name: ");
                getstr(fileName);
                printw("File name: %s\n", fileName);

                printw("Do you want to include your Encryption Key as plain text? \n **WARNING** Including your Encryption Key as plain text will weaken the security and privacity of your document! (y/n): ");
                if(getch() == 'y'){
                    encKeyAsPlainText = true;
                } else {
                    printw("Encryption Key will NOT be included as plain text");
                    encKeyAsPlainText = false;
                }
                std::ofstream message(fileName);
                message << "Test content, remove and modify before releasing!"; // WIP
                message.close();
                isEncrypting = false;
            }
        } else {
            clear();
            printw("Invalid input");
        }
    }while(isEncrypting);

    endwin();
    return 0;
}