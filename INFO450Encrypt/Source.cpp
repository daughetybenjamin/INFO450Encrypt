#include <iostream>
#include <string>
#include <fstream>
#include "Cipher.h"
using namespace std;

int main()
{
	int choice = 1;
	int key = 0;
	cout << "This application will allow you to encrypt or decrypt a file." << endl;
	Cipher cipher1;
	string filePath;
	string text;

	do
	{
		cout << "1. Encrypt a file." << endl;
		cout << "2. Decrypt a file." << endl;
		cout << "0. Exit." << endl;
		cout << "Enter a number to choose from the above options: ";
		cin >> choice;
		cin.ignore();

		if (choice == 0)
		{
			break;
		}
		else if (choice == 1)
		{
			cout << "Enter a key to use. This will be an integer between 1 and 26: ";
			cin >> key;
			cipher1.setKey(key);
			cin.ignore();

			cout << "Enter the full file path: ";
			getline(cin, filePath);
			cipher1.encrypt(filePath, filePath);
			cout << "\nSuccessfully encrypted file.\n";
		}
		else if (choice == 2)
		{
			cout << "Enter a key to use. This will be an integer between 1 and 26: ";
			cin >> key;
			cipher1.setKey(key);
			cin.ignore();

			cout << "Enter the full file path: ";
			getline(cin, filePath);
			cipher1.decrypt(filePath, filePath);
			cout << "\nSuccessfully decrypted file.\n";
		}
		else
		{
			cout << "Invalid response. Try again." << endl;
		}
	} while (choice != 0);

	system("pause");
	return 0;
}