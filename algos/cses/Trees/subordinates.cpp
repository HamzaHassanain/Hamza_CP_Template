#include<bits/stdc++.h>

using namespace std;
vector<int> subordinates;
map<int,vector<int>> adj;

void dfs(int u) {
	
	subordinates[u] = adj[u].size(); 
	
	for(auto v : adj[u]) {
		
		dfs(v);
		
		
		subordinates[u] += subordinates[v];
		
	}	
	
	
	
	
}
int main() {

	
	int n;
	cin >> n;
	
	
	

	subordinates = vector<int>(n+1,0);
	for(int v = 2;v<= n;v++) {
		int u;cin >> u;
		adj[u].push_back(v);
	}
	
	
	dfs(1);
	
	for(int i  =1;i <= n;i++) cout << subordinates[i] << " ";
	
	
	
	
	
	cout << "\n";
	
	return 0;
}
