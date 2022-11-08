#include <iostream>
#include <set>
using namespace std;

int main(){
	int num;
	string word;
	char lastLetter;
	set<string> words;

	cin >> num;
	cin >> word;
	lastLetter = word[word.length()-1];
	words.insert(word);
	for(int i = 1; i < num; i++){
		cin >> word;

		if(word[0] != lastLetter || words.find(word) != words.end()){
			cout << "Player " << (i%2)+1 << " lost";

			return 0;
		}
		words.insert(word);
		lastLetter = word[word.length()-1];
	}
	cout << "Fair Game";
	return 0;
}