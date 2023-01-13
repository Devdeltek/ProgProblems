#include <iostream>
#include <vector>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;


int main(){
	int v, e, c, k, m;
	cin >> v >> e >> c >> k >> m;
	vector<vector<int>> adj;
	vector<int> Cs;

	vector<int> setup(v);
    
    for(int i = 0; i < v; i++){
        adj.push_back(setup);
    }

    int tempU, tempV, tempW;
	for(int i = 0; i < e; i++){
		cin >> tempU >> tempV >> tempW;

		adj[tempU-1][tempV-1] = tempW;
	}
	for(int i = 0; i < c; i++){
		cin >> tempW;
		Cs.push_back(tempW-1);
	}

	vector<int> dist(v);
	vector<bool> visited(v);

	for(int i = 0; i < v; i++){
		dist[i] = INT_MAX;
		visited[i] = false;
	}

	dist[0] = 0;

	for(int i = 0; i < v-1; i++){
		int min = INT_MAX, minI;
		for(int j = 0; j < v; j++){
			if(visited[j] == false && dist[j] <= min){
				min = dist[j];
				minI = j;
			}
		}

		visited[minI] = true;

		for(int j = 0; j < v; j++){
			if(!visited[j] && adj[minI][j] && dist[minI] != INT_MAX && dist[minI] + adj[minI][j] < dist[j]){
				dist[j] = dist[minI] + adj[minI][j];
			}
		}
	}

	

	vector<int> totalDist;

	for(int i = 0; i < Cs.size(); i++){
		totalDist.push_back(dist[Cs[i]] * 2);	
	}

	sort(totalDist.begin(), totalDist.end());


	if(totalDist.size() < k && totalDist.size() <= m){
		cout << -1;
	}
	else if(k < m){
		cout << totalDist[k-1];
	}
	else{
		cout << totalDist[m];
	}

	return 0;
}