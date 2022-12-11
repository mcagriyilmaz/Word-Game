
#include<string>
#include<set>
#include<vector>
using std::string;
using namespace std;

class Dictionary {
public:
	void openDictionary();
	void arrayDictionary();
	string BringValidWord();

	bool IsWordValid(string guess);
private:
	string wordarray[2415];
	set<string> words;
	vector<string> secretwords;
};

