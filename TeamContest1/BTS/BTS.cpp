#include <iostream>
using namespace std;
int main(){
	int num;
	int point1, point2;
	bool check = false;

	cin >> num;

	for(int i = 0; i < num; i++){

		check = false;
		cin >> point1 >> point2;

		if(point1 < point2){
			cout << "impossible" << endl;
		}
		else{
			for(int i = 0; i <= point1; i++){
				if((i - (point1-i))==point2){
					cout << i << " " << point1-i << endl;
					check = true;
					break;
				}
			}
			if(!check){
				cout << "impossible" << endl;
			}
		}
	}
	return 0;
}