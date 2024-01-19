#include "cipher.h"
#include <QString>

using namespace std;

cipher::cipher() {}

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

string cipher::EncryptMessage(QString decryptionKey, QString plainText)
{
    string message = "";
    int indexDecrKey = 0, indexPlainText = 0, indexEncr = 0;
    for (int i = 0; i < plainText.size(); i++) {
        if(i < decryptionKey.size()-1){
            indexDecrKey = ALPHABET.find(decryptionKey.toLower().toStdString()[i]);
        } else {
            indexDecrKey = ALPHABET.find(decryptionKey.toLower().toStdString()[i-decryptionKey.size()]);
        }

        indexPlainText = ALPHABET.find(plainText.toLower().toStdString()[i]);

        if(indexPlainText >= 0)
        {
            if(indexPlainText + indexDecrKey < ALPHABET.size())
            {
                indexEncr = indexPlainText + indexDecrKey;
            }
            else
            {
                indexEncr = indexPlainText + indexDecrKey - ALPHABET.size();
            }
            message = message + (ALPHABET[indexEncr]);
        }
        else
        {
            // TODO error message etc
            message = "error";
        }
    }
    return message;
}

string cipher::DecryptMessage(QString decryptionKey, QString encrText)
{
    string message = "";
    ToLowerCase(encrText.toStdString());
    ToLowerCase(decryptionKey.toStdString());
    int indexDecrKey = 0, indexEncr = 0, indexPlainText = 0;
    for(int i = 0; i < encrText.size(); i++) {
        if(i < decryptionKey.size()-1){
            indexDecrKey = ALPHABET.find(decryptionKey.toLower().toStdString()[i]);
        } else {
            indexDecrKey = ALPHABET.find(decryptionKey.toLower().toStdString()[i-decryptionKey.size()]);
        }
        indexEncr = ALPHABET.find(encrText.toLower().toStdString()[i]);

        if(indexEncr >= 0){
            indexPlainText = (indexEncr - indexDecrKey + ALPHABET.size()) % ALPHABET.size();
        } else {
            indexPlainText = indexDecrKey + indexEncr;
        }

        message = message + (ALPHABET[indexPlainText]);
    }
    return message;
}

void cipher::ToLowerCase(string str){
    for(char& c : str){
        c = tolower(c);
    }
}
