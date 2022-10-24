#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

bool pal(vector<long>& pile);
bool dups(vector<long>& pile);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int pairs;
    cin >> pairs;
    auto start = chrono::high_resolution_clock::now();
    vector<long> pile;
    long temp1, temp2;
    cin >> temp1;
    for(int i = 1; i < 2*pairs; i++){
        cin >> temp2;
        if(temp1 == temp2){
            temp1 = -1;
            temp2 = -1;
            continue;
        }
        pile.push_back(temp1);
        dups(pile);
        temp1 = temp2;
    }

    int i = 0;
    bool check = pal(pile);
    
    while(check){
        if(pal(pile)){
            break;
        }
        if(!dups(pile)){
            check = false;
        }
    }
    
    if(check){
        cout <<  2*pairs << endl;
    }
    else{
        cout << "impossible" << endl;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}

bool pal(vector<long>& pile){
    int i = 0;
    int j = pile.size()-1;
    while(i!=pile.size()/2){
        if(pile[i] != pile[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool dups(vector<long>& pile){
    bool check = false;
    int i = 0;
    while(i < pile.size()-1 && !pile.empty()){
        if(pile[i] == pile[i+1]){
            check = true;
            pile.erase(pile.begin() + i, pile.begin() + i+2);
        }
        else{
            i++;
        }
    }
    return check;
}

/*
5 2 2 3 3 1 4 1 1 4 1
*/