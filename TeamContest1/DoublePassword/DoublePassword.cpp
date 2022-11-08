#include <iostream>

using namespace std;

int main(){
	string pass1, pass2;
	int count = 1;

	cin >> pass1 >> pass2;

	for(int i = 0; i < pass1.length(); i++){
		if(pass1[i] != pass2[i]){
			count *= 2;
		}
	}

	cout << count;

	return 0;
}