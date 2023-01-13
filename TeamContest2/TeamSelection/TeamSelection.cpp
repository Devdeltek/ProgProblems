#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int temp;
    cin >> n;
    vector<int> members;
    int sum = 0;

    for(int i = 0; i < 3*n; i++){
        cin >> temp;
        members.push_back(temp);
    }

    sort(members.begin(), members.end());

    for(int i = members.size()-2; n > 0; i = i - 2){
        n--;
        sum = sum + members[i];
    }

    cout << sum;
}

