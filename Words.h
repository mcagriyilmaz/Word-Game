#include<string>
#include<iostream>
using namespace std;

class Words {
public:
	void playgame(Words &, string, Dictionary &);
private:
	int countOfMatchLetters(string, string);
	int countOfTruePlaceLetters(string, string);
	int numguess;
	bool cheated;
	string secretword;
};
