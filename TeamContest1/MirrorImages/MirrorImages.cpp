#include <iostream>
#include <vector>

using namespace std;

int main(){
	int num;
	int l, w;
	string temp;

	vector<string> grid;

	cin >> num;
	for(int i = 0; i < num; i++){
		cout << "Test " << i+1 << endl;

		cin >> l >> w;

		for(int j = 0; j < l; j++){
			cin >> temp;
			grid.push_back(temp);
		}

		for(int j = l-1; j >= 0; j--){
			for(int k = w-1; k >= 0; k--){
				cout << grid[j][k];
			}
			cout << endl;
		}

		grid.clear();
	}	

	return 0;
}