#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cipher
{
private:
	int key;
	string fileContents;
public:
	Cipher();
	~Cipher();
	void encrypt(string inputPath, string outputPath);
	void decrypt(string inputPath, string outputPath);
	void setKey(int k);
};

