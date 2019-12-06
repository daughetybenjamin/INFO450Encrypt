#include <iostream>
#include <string>
#include "Cipher.h"
#include <fstream>


Cipher::Cipher()
{
	key = 0;
	fileContents = "";
}

Cipher::~Cipher()
{
}

void Cipher::encrypt(string inputPath, string outputPath)
{
	int i, length, asc;
	fstream file;
	file.open(inputPath, ios::in);
	if (!file)
	{
		cout << "Could not open file. Make sure the file exists and you entered it correctly." << endl;
		return;
	}
	getline(file, fileContents, '|');
	char str[1000];
	length = fileContents.length();

	for (i = 0; i < length; i++)
	{
		asc = fileContents[i];
		asc += key;
		if (asc > 122)
		{
			asc = asc - 26;
		}
		str[i] = (char)asc;
	}
	str[i] = '\0';
	file.close();

	file.open(outputPath, ios::trunc | ios::out);
	file << str;
	file.close();
}

void Cipher::decrypt (string inputPath, string outputPath)
{
	int i, length, asc;
	fstream file;
	file.open(inputPath, ios::in);
	if (!file)
	{
		cout << "Could not open file. Make sure the file exists and you entered it correctly." << endl;
		return;
	}
	getline(file, fileContents, '|');
	char str[1000];
	length = fileContents.length();

	for (i = 0; i < length; i++)
	{
		asc = fileContents[i];
		asc -= key;
		if (asc < 97)
		{
			asc = asc + 26;
		}
		str[i] = (char)asc;
	}
	str[i] = '\0';
	file.close();

	file.open(outputPath, ios::trunc | ios::out);
	file << str;
	file.close();
}

void Cipher::setKey(int k)
{
	key = k;
}