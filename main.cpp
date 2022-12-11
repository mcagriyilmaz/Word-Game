#include<iostream>
#include<fstream>
#include<ctime>
#include<set>
#include<vector>
#include "Dictionary.h"
#include "Words.h"
using namespace std;
using std::string;

int main() {
	Dictionary dictionary;
	Words game;
	string word;
	cout << "Bilbakalim oyununa hosgeldiniz:";
	cout << "\n5 harften olusan bir kelime tuttum.";

	dictionary.openDictionary();
	dictionary.arrayDictionary();
	word = dictionary.BringValidWord();
	game.playgame(game, word, dictionary);

	system("pause");
	return 0;
}