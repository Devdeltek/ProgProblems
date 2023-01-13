#include <iostream>
#include <vector>
using namespace std;

int main(){
    int r, c, n;
    int tlx, tly, brx, bry;
    vector<string> stars;
    string temp;

    cin >> r >> c;

    for(int i = 0; i < r; i++){
        cin >> temp;

        stars.push_back(temp);
    }

    cin >> n;
    int count = 0;

    for(int i = 0; i < n; i++){
        cin >> tlx >> tly >> brx >> bry;
        count = 0;

        for(int row = tlx; row <= brx; row++){
            for(int col = tly; col <= bry; col++){
                if(stars[row][col] == '*'){
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}

