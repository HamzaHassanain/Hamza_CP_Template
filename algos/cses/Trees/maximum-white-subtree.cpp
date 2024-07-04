#include<bits/stdc++.h>

using namespace std;

map<int, vector<int>> adj;
vector<int> dp,a;
void init(int u  =1,int p  = 0) {
	dp[u]  = a[u];
	for(int& v : adj[u]) {
		if(v == p) continue;
		init(v,u);
		
		dp[u] += max(0,dp[v]);
		 
	}	
	
} 

void dfs(int u  =1,int p  = 0) {
	
	for(int& v : adj[u]) {
		if(v == p) continue;
		
		int newU = dp[u] - max(0,dp[v]);
		int newV = dp[v] + max(0,newU);
		
		dp[v] = max(dp[v],newV);
	
		dfs(v,u);
	}	
	
} 


int main() {
	ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	int n;
	cin >> n;
	dp = a = vector<int>(n+1,0);
	
	for(int i= 1;i<= n;i++) {
		cin >> a[i];
		if(!a[i]) a[i] = -1;
	}
	
	for(int i = 1; i < n;i++) {
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	init();
	
	dfs();
	
	for(int i = 1;i<=n;i++) cout << dp[i] << " ";
	cout << "\n";
	return 0;
}
