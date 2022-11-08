#include <iostream>
#include <vector>
using namespace std;

int main(){
	int numOut, numIn, m;
	int temp, sum = 0, max = 0;
	bool containsM = false;
	int lastM = 0;
	vector<int> nums;

	cin >> numOut;
	//m needs to be the smallest value in it
	for(int i = 0; i < numOut; i++){
		cin >> numIn >> m;
		for(int j = 0; j < numIn; j++){
			cin >> temp;
			nums.push_back(temp);
		}
		for(int j = 0; j < numIn; j++){
			if(containsM && nums[j] == m){
				if(sum > max){
					max = sum;
				}
				j = lastM;
				containsM = false;
				sum = 0;
			}
			else if(!containsM && nums[j] == m){
				containsM = true;
				lastM = j;
				sum += nums[j];

			}
			else if(nums[j] < m){
				containsM = false;
				lastM = j;
				if(sum > max && containsM){
					max = sum;
				}
				sum = 0;
			}
			else {
				sum += nums[j];
			}

		}
		if(sum > max && containsM){
			max = sum;
		}


		lastM = 0;
		containsM = false;
		sum = 0;
		cout << max << endl;
		max = 0;

		nums.clear();
	}

	return 0;
}