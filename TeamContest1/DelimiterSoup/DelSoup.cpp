#include <iostream>
#include <stack>
using namespace std;

int main(){
	int l;
	string del;

	int par = 0, sqr = 0, brack = 0;
	stack<int> order;
	cin >> l;
	getline(cin >> ws, del);

	for(int i = 0; i < l; i++){
		if(del[i] == '('){
			par++;
			order.push(del[i]);
		}
		else if(del[i] == ')'){
			par--;
			if(order.empty() || order.top() != '('){
				cout << del[i] << " " << i;
				return 0;
			}
			order.pop();

		}
		else if(del[i] == '['){
			sqr++;
			order.push(del[i]);

		}
		else if(del[i] == ']'){
			sqr--;
			if(order.empty() || order.top()!= '['){
				cout << del[i] << " " << i;
				return 0;
			}
			order.pop();
		}
		else if(del[i] == '{'){
			brack++;
			order.push(del[i]);

		}
		else if(del[i] == '}'){
			brack--;
			if(order.empty() || order.top()!= '{'){
				cout << del[i] << " " << i;
				return 0;
			}
			order.pop();
		}
		if(par < 0 || brack < 0 || sqr < 0){
			cout << del[i] << " " << i;
			return 0;
		}
	}

	cout << "ok so far";

	return 0;
}