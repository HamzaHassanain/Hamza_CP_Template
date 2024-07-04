#include<bits/stdc++.h>

using namespace std;
map<int,vector<int>> adj;


vector<long long> subtree,dp;
int n;
void preCalc(int u,int p) {
	

	subtree[u] = 1;
	for(int& v : adj[u]) {
		if(v == p) continue;
		
		preCalc(v,u);
		subtree[u] += subtree[v];
		dp[u] += dp[v] + subtree[v];
	}

}
void dfs(int u,int p) {
	
	for(int& v : adj[u]) {
		if(v == p) continue;
		
		long long newUCost = dp[u] -  (dp[v] + subtree[v]);
		dp[v] +=  newUCost + (n - subtree[v]);
		
		subtree[v] = subtree[u];
		dfs(v,u);
	}

}
int main() {
	
	
	cin >> n;
	subtree = dp = vector<long long>(n+1);
	for(int i = 1;i<n;i++) {
		int u,v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	
	preCalc(1,0);
	
	dfs(1,0);
	for(int i =1;i<=n;i++) 
		cout <<  dp[i] <<" ";
	cout << "\n";
	
	return 0;
}
