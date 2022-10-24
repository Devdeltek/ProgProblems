#include <iostream>
#include <vector>

using namespace std;

int main(){
	int num;
	cin >> num;
	int temp;
	vector<int> cards;
	for(int i = 0; i < num; i++){
		cin >> temp;
		cards.push_back(temp);
	}

	bool check = false;

	do{
		check = false;
		for(int i = 1; i < cards.size(); i++){
			if((cards[i] + cards[i-1])%2 == 0){
				cards.erase(cards.begin() + i-1, cards.begin() + i+1);
				check = true;
			}

		}
		/*for(int i = 0; i < num; i++){
			cout << cards[i] << " ";
		}*/
	}while(check);

	cout << cards.size();
	return 0;
}