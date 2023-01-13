#include <iostream>
#include<string.h>
#include <vector>
#include <set>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int final;
    int n, m;
    int duk = 3, ass = 3, cap = 3, amb = 3, con = 3;
    string temp;
    int player = 0;
    cin >> n >> m;

    set<string> setup;

    vector<set<string>> playerCharacters;

    for(int i = 0; i < m; i++){
        playerCharacters.push_back(setup);
    }

    for(int i = 0; i < n; i++){
        player = i%m;
        cin >> temp;
        if((playerCharacters[player].find("Duke") == playerCharacters[player].end()) && temp == "Duke"){
            duk--;
        }
        else if((playerCharacters[player].find("Assassin") == playerCharacters[player].end()) && temp == "Assassin"){
            ass--;
        }
        else if((playerCharacters[player].find("Captain") == playerCharacters[player].end()) && temp == "Captain"){
            cap--;
        }
        else if((playerCharacters[player].find("Ambassador") == playerCharacters[player].end()) && temp == "Ambassador"){
            amb--;
        }
        else if((playerCharacters[player].find("Contessa") == playerCharacters[player].end()) && temp == "Contessa"){
            con--;
        }
        if(temp != "None"){
            playerCharacters[player].insert(temp);
        }
    }

    for(int i = 0; i < m; i++){
        /*set<string>::iterator iter;
        for (iter = playerCharacters[i].begin(); iter != playerCharacters[i].end(); iter++)
        {
            cout << *iter << " ";
        }*/
        if(playerCharacters[i].size() > 2){
            cout << "Yes";
            return 0;
        }
        //cout << endl;
    }
    if(duk < 0 || ass < 0 || cap < 0 || amb < 0 || con < 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}

