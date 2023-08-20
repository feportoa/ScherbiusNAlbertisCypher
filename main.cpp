#include <iostream>
#include <vector>
#include <string>
#include <termios.h>
#include <ncurses.h>
#include <fstream>

#define ALPHABET {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

void fileSave(std::string plainText, std::string decryptionKey);
std::string typeDecryptionKey();
void encryptMessage(std::string decryptionKey, std::string plainText);
void decryptMessage(std::string decryptionKey, std::string encryptedMessage);

int main() 
{
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
        printw("Choose an option:              |\n 1. Type in Decryption Key     |\n 2. Encrypt Message            |\n 3. Decrypt Message            |\n 4. Exit program               |\n");
        userChoice = getch();
        switch(userChoice)
        {
            /*
            1 Type in Decryption Key
            2 Encrypt Message
            3 Decrypt Message
            4 Exit Program
            */

            case '1': // Type in Decryption Key
                decryptionKey.clear();
                decryptionKey = typeDecryptionKey();
                break; 
            
            case '2': // Encrypt Message
                clear();
                encryptMessage(decryptionKey, plainText);
                clear();
                break;
            
            case '3': // Decrypt Message
                clear();
                //decryptMessage(decryptionKey, encryptedMessage);
                clear();
                break;
            
            case '4': // Exit Program
                clear();
                isRunning = false;
                clear();
                break;
            
            default:
                printw("\n[ERROR] Invalid Option: %c | Returning to menu...\n", userChoice);
                break;
        }    
    }while(isRunning);

    endwin();
    return 0;
}

void fileSave(std::string plainText, std::string decryptionKey)
{
    char fileName[50];
    bool decKeyAsPlainText {false};

    clear();
    printw("Enter file name: ");
    getstr(fileName);
    printw("File name: %s\n", fileName);

    flushinp();
    printw("Do you want to include your Encryption Key as plain text? \n **WARNING** Including your Encryption Key as plain text will weaken the security and privacity of your document! (y/n): ");
    if(getch() == 'y' || getch() == 'Y'){
        decKeyAsPlainText = true;
    } else {
        printw("Encryption Key will NOT be included as plain text");
        decKeyAsPlainText = false;
    }
    std::ofstream message(fileName);
    message << "Test content, remove and modify before releasing! \n"; // WIP
    for(size_t i {0}; i <= plainText.size(); i++){
        message << plainText[i];
        if(i == plainText.size())
            message << "\n";
    }
    if(decKeyAsPlainText)
        message << decryptionKey << "\n";
    message.close();
}

std::string typeDecryptionKey()
{
    std::string decKey;
    bool isTyping {true};
    
    clear();
    printw("Use only alphabetic characters with no spaces \n");
    while(isTyping){
        int userInput = getch();

        if(userInput == KEY_BACKSPACE){
            if(!decKey.empty()){
                decKey.pop_back();
            }
        } else if(userInput == '\n'){
            isTyping = false;
        } else {
            decKey += userInput;
        }
    }
    clear();
    return decKey;
}

void encryptMessage(std::string decryptionKey, std::string plainText)
{
    bool isEncrypting {true};

    printw("Use only alphabetic characters with no spaces \n");
    do{
        int userInput = getch();
        if(userInput != ' '){
            if(userInput == KEY_BACKSPACE){
                if(!plainText.empty()){
                    plainText.pop_back();
                }
            } else{
                printw("%s", plainText.c_str());
                plainText += userInput;
            }

            if(userInput == '\n'){
                if(decryptionKey.empty()){
                    printw("Looks like you don't have a decryption key, would you like to type your decryption key? [Y/N]\n");
                    if(getch() == 'y' || getch() == 'Y'){
                        decryptionKey = typeDecryptionKey();
                    }
                }
                fileSave(plainText, decryptionKey);
                isEncrypting = false;
            }
        } else {
            clear();
            printw("Invalid input");
        }
    }while(isEncrypting);
}