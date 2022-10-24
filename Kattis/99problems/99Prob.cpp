#include <iostream>

using namespace std;

int main(){
	int price;

	cin >> price;
	int diff = price%100;

	if(diff == 99){
		cout << price;
		return 0;
	}
	if(diff >= 49){
		cout << (99-diff)+price;
	}
	else if(price-diff <= 0){
		cout << "99";
	}
	else{
		cout << price-diff-1;
	}


	return 0;
}