#include <iostream>
#include<queue>
using namespace std;
int main(){
	//ios::sync_with_stdio(false);
    //cin.tie(nullptr);
	int num;
	queue<string> players;
	string points, temp;
	string black[2];
	string white[2];
	int max = 1;
	char curr = 'n';
	int count = 1;
	cin >> num;

    cin >> white[0] >> black[0] >> white[1] >> black[1];

	for(int i = 4; i < num; i++){
		cin >> temp;
		players.push(temp);
	}

	cin >> points;

	int sum[points.length()-1];

	for(int i = points.length()-1; i >= 0; i--){
		if(points[i] == curr){
			count++;
		}
		else{
			count = 1;
			curr = points[i];
		}
		sum[i] = count;
		if(count > max){
			max = count;
		}
	}


	for(int i = 0; i < points.length(); i++){
		if(sum[i] ==  max && i != 0){
			if(points[i] == 'W'){
				cout << white[1] << " " << white [0] << endl;
			}
			else{
				cout << black[1] << " " << black[0] << endl;
			}
		}
		else if(sum[i] ==  max && i == 0){
			if(points[i] == 'W'){
				cout << white[0] << " " << white [1] << endl;
			}
			else{
				cout << black[0] << " " << black[1] << endl;
			}
		}
		if(points[i] == 'W'){
			temp = white[0];
			white[0] = white[1];
			white[1] = temp;

			players.push(black[1]);
			black[1] = black[0];
			black[0] = players.front();
			players.pop();
		}
		else{
			temp = black[0];
			black[0] = black[1];
			black[1] = temp;

			players.push(white[1]);
			white[1] = white[0];
			white[0] = players.front();
			players.pop();
		}
	}
	return 0;
}