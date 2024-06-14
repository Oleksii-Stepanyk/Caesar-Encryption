#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char* encrypt(char* rawText, int key) {
    char* encryptedText = new char[strlen(rawText) + 1];
    for (int i = 0; i <= strlen(rawText); i++) {
        if (isupper(rawText[i])) {
            encryptedText[i] = char(int(rawText[i] + key - 65) % 26 + 65);
        }
        else if (islower(rawText[i])) {
            encryptedText[i] = char(int(rawText[i] + key - 97) % 26 + 97);
        }
        else {
			encryptedText[i] = rawText[i];
		}
    }
    encryptedText[strlen(rawText)] = '\0';
    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    key = 26 - key;
    char* decryptedText = new char[strlen(encryptedText) + 1];
    for (int i = 0; i <= strlen(encryptedText); i++) {
        if (isupper(encryptedText[i])) {
            decryptedText[i] = char(int(encryptedText[i] + key - 65) % 26 + 65);
        }
        else if (islower(encryptedText[i])) {
            decryptedText[i] = char(int(encryptedText[i] + key - 97) % 26 + 97);
        }
        else {
            decryptedText[i] = encryptedText[i];
        }
    }
    decryptedText[strlen(encryptedText)] = '\0';
    return decryptedText;
}

int main()
{
    char* rawText = (char*)malloc(64);
    int key = 0;
    cout << "Enter the text to encrypt: ";
    cin.getline(rawText, 64);
    cout << "Enter encryption key: ";
    cin >> key;
    key = key % 26;
    char* encryptedText = encrypt(rawText, key);
    cout << "Encrypted text: " << encryptedText << endl;
    cout << "Decrypted text: " << decrypt(encryptedText, key) << endl;

    return 0;
}