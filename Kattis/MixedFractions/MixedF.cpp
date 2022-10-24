#include <iostream>

using namespace std;

int main(){
	while(true){
		int num, dom;
		int whole, frac;
		cin >> num >> dom;

		if(num == 0 && dom == 0){
			break;
		}

		whole = num/dom;
		frac = num%dom;

		cout << whole << " " << frac << " / " << dom << endl;
	}


	return 0;
}