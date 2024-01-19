#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <vector>
#include <string>

#include <QString>

using namespace std;

class cipher
{
public:
    cipher();
    string EncryptMessage(QString decryptionKey, QString plainText);
    string DecryptMessage(QString decryptionKey, QString encrText);
private:
    void ToLowerCase(string str);
};

#endif // CIPHER_H
