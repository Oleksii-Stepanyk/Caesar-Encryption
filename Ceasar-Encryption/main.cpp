#include <iostream>
#include <windows.h>
#include "cipher.h"
using namespace std;

int main()
{
	typedef char* (*encrypt_ptr)(char*, int);
	typedef char* (*decrypt_ptr)(char*, int);

	HINSTANCE handle = LoadLibrary(TEXT("Cipher.dll")); if
		(handle == nullptr || handle == INVALID_HANDLE_VALUE)
	{
		cout << "Lib not found" << endl;
		return 1;
	}
	encrypt_ptr encrypt = (encrypt_ptr)GetProcAddress(handle, "encrypt");
	if (encrypt == nullptr)
	{
		cout << "Function not found" << endl;
		return 1;
	}
	decrypt_ptr decrypt = (decrypt_ptr)GetProcAddress(handle, "decrypt");
	if (decrypt == nullptr)
	{
		cout << "Function not found" << endl;
		return 1;
	}

	string text;
	cout << "Switch to static? (y/n): ";
	cin >> text;
	cin.ignore();
	if (text == "y") {
		while (true) {
			char* rawText = (char*)malloc(64);
			int key = 0;
			cout << "Enter the text to encrypt: ";
			cin.getline(rawText, 64);
			if (*rawText == '0')
				break;
			cout << "Enter encryption key: ";
			cin >> key;
			key = key % 26;
			char* encryptedText = Cipher::encrypt(rawText, key);
			cout << "Encrypted text: " << encryptedText << endl;
			cout << "Decrypted text: " << Cipher::decrypt(encryptedText, key) << endl;
			free(rawText);
			cin.ignore();
		}
	}
	else {
		while (true) {
			char* rawText = (char*)malloc(64);
			int key = 0;
			cout << "Enter the text to encrypt: ";
			cin.getline(rawText, 64);
			if (*rawText == '0')
				break;
			cout << "Enter encryption key: ";
			cin >> key;
			key = key % 26;
			char* encryptedText = encrypt(rawText, key);
			cout << "Encrypted text: " << encryptedText << endl;
			cout << "Decrypted text: " << decrypt(encryptedText, key) << endl;
			free(rawText);
			cin.ignore();
		}
	}

	FreeLibrary(handle);
	return 0;
}