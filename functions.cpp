#include<iostream>
#include<fstream>
#include<ctime>
#include<set>
#include<vector>

using namespace std;
using std::string;
using std::set;
#include "Dictionary.h"
#include"Words.h"

void Dictionary::openDictionary()
{
	fstream dataFile;
	string valid;
	int m = 0;
	dataFile.open("words.txt", std::fstream::in);
	if (!dataFile)
	{
		cout << "File open error!" << endl;
		exit(0);
	}
	else
	{
		dataFile >> valid;
		while (!dataFile.eof())
		{
			words.insert(valid);
			dataFile >> valid;
		}

	}

}
void Dictionary::arrayDictionary() {
	ifstream dataFile;
	string word;
	dataFile.open("words.txt");

	for (int i = 0; i < 2415; i++)
	{
		dataFile >> word;
		wordarray[i] = word;
	}
}
string Dictionary::BringValidWord() {
	string random, word1;
	int i;
	srand(time(NULL));
	i = rand() % 2415;
	random = wordarray[i];
	for (auto letter1 : random) {
		int match = 0;
		for (auto letter2 : random) {
			if (letter1 == letter2)
				match++;
			if (match > 1) {
				i = rand() % 2415;
				random = wordarray[i];
			}
		}
	}
	return random;
}
bool Dictionary::IsWordValid(string guess) {
	for (int i = 0; i < 2415; i++)
	{
		if (wordarray[i] == guess)
		{
			return true;
		}
	}
	return false;
}

void Words::playgame(Words &game, string correctWord, Dictionary &dictionary) {
	string guess;
	int match;
	int place;
	cheated = false;
	cout << "\nTahmininiz Nedir? ";
	cin >> guess;
	if (guess.length()!=5)
	{
		cout << "\nKelime uzunlugu 5 olmali!";
	}
	else
	{
		if (guess == "xxxxx") {
			cout << "\nIpucu: Gizli Kelime: " << correctWord;
			cout << "\nTahmininiz Nedir? ";
			cin >> guess;
			cheated = true;
			numguess = 1;
		}
		else if(!dictionary.IsWordValid(guess))
		{
			cout << "\nKelime sozlukte yok!!";
			numguess = 0;
		}
		else
		{
			    numguess = 1;
				place = countOfTruePlaceLetters(guess, correctWord);
				match = countOfMatchLetters(guess, correctWord);
				cout << "\nEslesen harf sayisi: " << match;
				cout << "\nEslesen harflerin dogru konumu:" << place;
			
		}
	}
	
	
	
	while (guess != correctWord)
	{
		cout << "\nTahmininiz Nedir? ";
		cin >> guess;
		if (guess.length() != 5)
		{
			cout << "\nKelime uzunlugu 5 olmali!";
		}
		else
		{
			if (guess == "xxxxx") {
				cout << "\nIpucu: Gizli Kelime: " << correctWord;
				cout << "\nTahmininiz Nedir? ";
				cin >> guess;
				cheated = true;
				numguess++;
			}
			else if (!dictionary.IsWordValid(guess))
			{
				cout << "\nKelime sozlukte yok!!";
			}
			else
			{
				    
					place = countOfTruePlaceLetters(guess, correctWord);
					match = countOfMatchLetters(guess, correctWord);
					cout << "\nEslesen harf sayisi: " << match;
					cout << "\nEslesen harflerin dogru konumu:" << place;
					numguess++;
				
			}
		}

	}
	
	if (!cheated)
	{
		cout << "\nBildiniz!! " << numguess << " tahminde dogru sonuca ulastiniz!" << endl;
	}
	else
		cout << "\nBildiniz!! " << numguess << " tahminde ipucu kullanarak dogru sonuca ulastiniz!" << endl;
	
}
int Words::countOfMatchLetters(string guess, string correctWord) {
	int match = 0;

	for (auto letter1 : correctWord) {
		
		for (auto letter2 : guess) {
			if (letter1 == letter2)
				match++;
		}
	}
	
	return match;

}
int Words::countOfTruePlaceLetters(string guess, string correctWord)
{
	int place = 0;

	for (int i = 0; i < 5; i++)
	{
		if (guess[i] == correctWord[i])
			place++;
	}

	return place;
}








