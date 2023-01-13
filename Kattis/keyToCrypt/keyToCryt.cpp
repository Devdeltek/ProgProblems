#include <iostream>

using namespace std;
int main(){
	//ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    string mess;
    string key;
    string ans = "";
    int temp;

    cin >> mess >> key;

    for(int i = 0; i < mess.length(); i++){
    	temp = mess[i] -  (key[i] - 'A');
    	if(temp < 'A'){
    		temp = 'Z' + (temp-'A') + 1;
    	}

    	ans += temp;
    	key+=temp;

    }
    cout << ans;

}