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
	
	ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	
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
		cout <<   (dp[i]+1 > diametar ? diametar+1 : diametar )  << "\n";	
	}
	return 0;
}
