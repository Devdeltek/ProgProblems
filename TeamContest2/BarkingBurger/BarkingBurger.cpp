#include <iostream>
using namespace std;

int main(){
    int t, s, x;
    cin >> t >> s >> x;
    int x1 = x;

    x -= t;
    if(((x%s == 0) || (((x-1)%s) == 0) && x-1 != 0) && (x1 >= t)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}

