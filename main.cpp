#include <iostream>
#include <vector>
#include <string>
#include <termios.h>
#include <ncurses.h>
#include <fstream>

#define ALPHABET {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

void fileSave(std::string plainText);
void encryptMessage(std::string decryptionKey, std::string plainText);
void decryptMessage(std::string decryptionKey, std::string encryptedMessage);

int main() {
    bool isRunning {true};
    std::string decryptionKey {};
    std::string encryptedMessage {0};
    std::string plainText {0};
    bool isEncrypting {true};
    char userChoice;

    initscr(); // Start ncurses
    cbreak(); // No buffer
    keypad(stdscr, TRUE); // Read special keys (i.e. backspace, F1, F2...)
        
    
    do{
    printw("Choose an option:             |\n 1. Type in Decryption Key     |\n 2. Encrypt Message            |\n 3. Decrypt Message            |\n 4. Exit program               |\n");
    userChoice = getch();
    switch(userChoice)
    {
        case '1': // Type in Decryption Key
            bool isTyping = true;
            printw("Use only alphabetic characters with no spaces");
            while(isTyping){
                char userInput = getch();
                decryptionKey += userInput;
                if(userInput == '\n')
                    isTyping = false;
            }
            break; 
        
        case '2': // Encrypt Message
            encryptMessage(decryptionKey, plainText);
            break;
        
        case '3': // Decrypt Message
            decryptMessage(decryptionKey, encryptedMessage);
            break;
        
        case '4': // Exit Program
            isRunning = false;
            break;
        
        default:
            printw("[ERROR] Invalid Option: %c | Returning to menu...", userChoice);
            break;
    }    

    }while(isRunning);
        do{
            int userInput = getch();
            if(userInput != ' '){
                if(userInput == KEY_BACKSPACE){
                    plainText.pop_back();
                } else{
                    printw(plainText.c_str());
                    plainText += userInput;
                }

                if(userInput == '\n'){
                    fileSave(plainText);
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

void fileSave(std::string plainText){
    char fileName[50];
    bool encKeyAsPlainText {false};

    clear();
    printw("Enter file name: ");
    getstr(fileName);
    printw("File name: %s\n", fileName);

    flushinp();
    printw("Do you want to include your Encryption Key as plain text? \n **WARNING** Including your Encryption Key as plain text will weaken the security and privacity of your document! (y/n): ");
    if(getch() == 'y'){
        encKeyAsPlainText = true;
    } else {
        printw("Encryption Key will NOT be included as plain text");
        encKeyAsPlainText = false;
    }
    std::ofstream message(fileName);
    message << "Test content, remove and modify before releasing! \n"; // WIP
    for(size_t i {0}; i <= plainText.size(); i++){
        message << plainText[i];
        if(i == plainText.size())
            message << "\n";
    }
    message.close();
}