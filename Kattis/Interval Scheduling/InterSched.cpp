#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int num;
	int temp1, temp2;
	int over = 1;

	cin >> num;

	vector<pair<int, int>> times;

	for(int i = 0; i < num; i++){
		cin >> temp1 >> temp2;

		times.push_back(make_pair(temp2, temp1));
	}

	sort(times.begin(), times.end());

	temp1 = times[0].first;

	for(int i = 0; i < num; i++){
		if(times[i].second >= temp1){
			over++;
			temp1 = times[i].first;
		}
	}

	cout << over;


	return 0;
}