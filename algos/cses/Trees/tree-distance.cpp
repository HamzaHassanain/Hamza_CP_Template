#include<bits/stdc++.h>
 
using namespace std;
 
map<int,vector<int>> adj;
int farthest = 0,diametar = 0;
vector<int>dp;
void dfs(int u,int p,int path ) {
	
	
	for(auto v : adj[u]) {
		if(v == p) continue;
		dfs(v,u,path+1);
	}
	
	if(path > diametar) diametar = path, farthest = u;
	
	dp[u] = max(path, dp[u]);
	
}
int main() {
	
	
	int n;
	cin >> n;
	dp = vector<int>(n+1);
	
	for(int i = 1;i<n;i++) {
		int u,v;
		cin >> u >> v;
 
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	
	
	dfs(1,-1,0);
	dfs(farthest,-1,0);
	dfs(farthest,-1,0);
	
	for(int i = 1;i<= n;i++) {
		cout << dp[i] << " ";	
	} cout << "\n";
	return 0;
}
