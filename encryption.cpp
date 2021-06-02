/*
Author: Carlos Caballero
Course: csci 136
Instructor: Katherine Howitt
Assignment: Lab6D

This program will take the user's plain text, encrypt it using both Caesar cipher
and Vigenere cypher and then decypt both of them
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char CaesarShiftChar(char c, int rshift)
{
	int newchar;
	if ((int)c <= 90 && (int)c >= 65)
	//check if the letter is upper case
	{
		newchar = (int)c + rshift;
		if (newchar > 90) //if the shift surpasses the upper case alphabet, then it will loop around it.
		{
			newchar = newchar % 90 + 64 ;
			c = newchar;
			return c;
		}
		if (newchar < 65)
		{
			newchar = 90 - (64 - newchar); //Loops around in order to reverse the alphabet with upper case letters
			c = newchar;
			return c;
		}
		c = newchar;
		return c;
	}
	if ((int)c <= 122 && (int)c >= 97)
	//check if the letter is lower case.
	{
		newchar = (int)c + rshift;
		if (newchar > 122) //if the shift surpasses the lower cas alphabet, then it will loop around.
		{
			newchar = newchar % 122 + 96 ;
			c = newchar;
			return c;
		}
		if (newchar < 97)
		{
			newchar = 122 - (96 - newchar);//Loops around in order to reverse the alphabet with lower case letters
		}
		c = newchar;
		return c;
	}
	return c;
}

char VigenereShiftChar(char c, int rshift)
{
	int newchar;
	rshift = rshift%97;
	if ((int)c <= 90 && (int)c >= 65)
	//check if the letter is upper case
	{
		newchar = (int)c + rshift;
		if (newchar > 90) //if the shift surpasses the upper case alphabet, then it will loop around it.
		{
			newchar = newchar % 90 + 64 ;
			c = newchar;
			return c;
		}
		if (newchar < 65)
		{
			newchar = 90 - (64 - newchar); 
			c = newchar;
			return c;
		}
		c = newchar;
		return c;
	}
	if ((int)c <= 122 && (int)c >= 97)
	//check if the letter is lower case.
	{
		newchar = (int)c + rshift;
		if (newchar > 122) //if the shift surpasses the lower cas alphabet, then it will loop around.
		{
			newchar = newchar % 122 + 96 ;
			c = newchar;
			return c;
		}
		if (newchar < 97)
		{
			newchar = 122 - (96 - newchar);
		}
		c = newchar;
		return c;
	}
	return c;
}

string encryptCaesar(string plaintext, int rshift)
{
	string line = "";
	string letter;
	char a;
	for (int i = 0; i < plaintext.length(); i++)
	//for every letter in the line, the shift will occur. Except for any non-alphabetic characters.
	{
		a = plaintext[i];
		letter = CaesarShiftChar(a, rshift);
		line += letter; //Puts the whole line together, but all shifted.
	}
	return line;
}

string encryptVigenere(string plaintext, string keyword)
{
	string line = "";
	string letter;
	char a;
	int KeywordIndex = 0;
	for (int i = 0; i < plaintext.length(); i++)
	{
		if (KeywordIndex == keyword.length())
		{
			KeywordIndex = 0; //will make sure that the keyword is used in a loop
		}
		a = plaintext[i];
		letter = VigenereShiftChar(a, keyword[KeywordIndex]);
		line += letter;
		if (isalpha(a)) //Only changes the use of the keyword when it's a letter character in the plaintext, no spaces nor special characters.
		{
			KeywordIndex = KeywordIndex + 1;
		}
	}
	return line;
}

string decryptCaesar(string ciphertext,int rshift)
{
	string line = "";
	string letter;
	rshift = rshift * -1; //needed to reverse the order, so that it goes backwards in the alphabet.
	char a;
	for (int i = 0; i < ciphertext.length(); i++)
	{
		a = ciphertext[i];
		letter = CaesarShiftChar(a, rshift);
		line += letter;
	}
	return line;
}

string decryptVigenere(string ciphertext, string keyword)
{
	string line = "";
	string letter;
	char a;
	int KeyInd;
	int KeywordIndex = 0;
	for (int i = 0; i < ciphertext.length(); i++)
	{
		if (KeywordIndex == keyword.length())
		{
			KeywordIndex = 0;
		}
		a = ciphertext[i];
		KeyInd = keyword[KeywordIndex] * -1;//Needed to reverse the order, so that it goes backwards in the alphabet
		letter = VigenereShiftChar(a, KeyInd);
		line += letter;
		if (isalpha(a))
		{
			KeywordIndex = KeywordIndex + 1;
		}
	}
	return line;
}



int main()
{
	int rshift;
	string cipher, decrypt;
	string plaintext, keyword;
	cout << "\n\nEnter plaintext: ";
	getline(cin, plaintext);
	cout << "\n\n= Caesar =\n";
	cout << "Enter shift    : ";
	cin >> rshift;
	cipher = encryptCaesar(plaintext, rshift);
	cout << "Ciphertext     : " << cipher << endl;
	decrypt = decryptCaesar(cipher, rshift);
	cout << "Decrypted      : " << decrypt << endl;
	cout << "\n\n= Vigenere =\n";
	cout << "Enter keyword  : ";
	cin >> keyword;
	cipher = encryptVigenere(plaintext, keyword);
	cout << "Ciphertext     : " << cipher << endl;
	decrypt = decryptVigenere(cipher, keyword);
	cout << "Decrypted      : " << decrypt << endl;
	return 0;
}