#include <iostream>
using namespace std;


int main(){
    int n = 0;
    cin >> n;
    while(n != -1){
        int **points {new int*[n]};

        for(int i = 0; i < n; i++){
            points[i] = new int[n];
            for(int j = 0; j < n; j++){
                cin >> points[i][j];
            }
        }

        for(int i = 0; i < n; i++){
           
        }

        for(int i = 0; i < n; i++){
            delete points[i];
            points[i] = NULL;
        }
        delete points;
        points = NULL;
        cin >> n;
    }
    return 0;    
}

/*
5 2 2 3 3 1 4 1 1 4 1
*/