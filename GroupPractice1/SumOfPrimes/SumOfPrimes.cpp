#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool checkPrime(int num);
int primeFactors(int value);

int main(){
	int n;
	cin >> n;
	int lastN = 0;

	while(!checkPrime(n) && lastN != n){
		lastN = n;
		n = primeFactors(n);
	}

	cout << n;

	return 0;
}

int primeFactors(int value){
	vector<int> primes;
	int sum = 0;
	while(value%2 == 0){
		primes.push_back(2);
		value = value/2;
	}
	for(int i = 3; i <= sqrt(value); i = i + 2){
		while(value%i == 0){
			primes.push_back(i);
			value = value/i;
		}
	}

	if(value > 2){
		primes.push_back(value);
	}

	for(int i = 0; i < primes.size(); i++){
		sum += primes[i];
		cout << primes[i] << " ";
	}
	cout << endl;
	return sum;
}

bool checkPrime(int num){
	for(int i = 2; i <= num/2; i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}