#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
using namespace std;

bool checkPrime(int num);
int primeFactors(int value);

int main(){
	int n, temp, min = INT_MAX;
	vector<int> distances;
	vector<int> cost;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> temp;
		distances.push_back(temp);
	}

	for(int i = 0; i < n; i++){
		cin >> temp;
		cost.push_back(temp);
	}

	int max = *max_element(distances.begin(), distances.end());

	for(int i = 1; i <= max; i++){
		temp = 0;
		for(int j = 0; j < n; j++){
			temp += (abs(distances[j]-i)*cost[j]);
		}
		if(temp < min){
			min = temp;
		}
		cout << temp << endl;
	}
	cout << min;
}