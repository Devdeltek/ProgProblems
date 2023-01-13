#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int people;
    
    cin >>  people;

    deque<long> preA;
    deque<long> preB;
    vector<long> tempV;

    long temp, total = LONG_MIN;
    long tempT = 0;

    for(int i = 1; i < people; i++){
        cin >> temp;
        if(temp == 0){
           i--; 
        }
        else{
        	tempV.push_back(temp);
        }
    }

    /*for(int i = 0; i < tempV.size(); i++){
    	cout << tempV[i] << endl;
    }*/

    for(int i = 0; i < tempV.size(); i++){
    	tempT += tempV[i]*(i+1);
    	preA.push_front(tempT);
    }
    preA.push_back(0);

    tempT = 0;

    for(int i = tempV.size()-1; i >= 0; i--){
    	tempT += tempV[i]*(i+2);
    	preB.push_back(tempT);
    }
    preB.push_front(0);

    /*for(int i = 0; i <= tempV.size(); i++){
    	cout << preA.back() << " " << preB.back() << endl;
    	preA.pop_back();
    	preB.pop_back();
    }*/

    for(int i = 0; i < people; i++){
    	temp = preA.back() + preB.back();
    	if(temp > total){
    		total = temp;
    	}
    	preA.pop_back();
    	preB.pop_back();
    }

    cout << total;
    return 0;
}