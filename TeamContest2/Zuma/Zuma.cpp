#include <iostream>
#include <vector>
using namespace std;

int main(){
    string path;
    string fire;
    int chain = 0;

    cin >> path >> fire;

    for(int i = 0; i < fire.length(); i++){
        path += fire[i];
        chain = 0;
        int j = path.length()-1;
        while(path[j] == path[path.length()-1]){
            chain++;
            j--;
        }
        if(chain >= 3){
            path.resize(path.size()-chain);
        }
        
    }
    if(path.length() == 0){
            cout << "8)";
        }
        else{
            cout << path;
        }
}

