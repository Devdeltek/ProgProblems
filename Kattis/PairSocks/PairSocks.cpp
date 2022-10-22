#include <iostream>
#include <vector>

using namespace std;

bool pal(vector<long>& pile);
bool dups(vector<long>& pile);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int pairs;
    cin >> pairs;
    vector<long> pile;
    long temp;
    for(int i = 0; i < 2*pairs; i++){
        cin >> temp;
        pile.push_back(temp);
    }
    
    int i = 0;
    bool check = true;
    
    while(check){
        if(pal(pile)){
            break;
        }
        if(!dups(pile)){
            check = false;
        }
    }
    
    if(check){
        cout <<  2*pairs;
    }
    else{
        cout << "impossible";
    }
    
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