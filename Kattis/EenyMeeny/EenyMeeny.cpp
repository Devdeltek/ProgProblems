#include <iostream>
#include <vector>
#include <queue>
#include <string>


using namespace std;

int main(){
    string rhyme, temp;
    int num;
    getline(cin, rhyme);
    cin >> num;
    vector<string> people;
    deque<string> team1;
    deque<string> team2;
    
    int count = 1;
    cin >> ws;
    for(int i = 0; i < num; i++){
        getline(cin, temp);
        people.push_back(temp);
    }
    
    for(int i = 0; i < rhyme.size(); i++){
        if(rhyme[i] == ' '){
            count++;
        }
    }
    
    string person;
    bool currTeam = true;
    while(!people.empty()){
        person = people.at((count%people.size()));
        people.erase(people.begin()+(count%people.size()));
        if(currTeam){
            team1.push_back(person);
            currTeam = false;
        }
        else{
            team2.push_back(person);
            currTeam = true;
        }
    }
    
    cout << team1.size() << endl;
    while(!team1.empty()){
        cout << team1.back() << endl;
        team1.pop_back();
    }
    
    cout << team2.size() << endl;
    while(!team2.empty()){
        cout << team2.back() << endl;
        team2.pop_back();
    }
    
    
    return 0;
}