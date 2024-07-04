#include<bits/stdc++.h>

using namespace std;
map<int,vector<int>> adj;
vector<bool> taken;

void dfs(int u, int p,int& cnt) {
	
	
	for(int v : adj[u]) {
		if(v == p) continue;
		dfs(v,u,cnt);
		if(!taken[u] and !taken[v]) taken[u] = taken[v] = 1,cnt++;
	}
	

}
int main() {

	int n;
	cin >> n;
	
	
	taken = vector<bool>(n+1,0);
	
	for(int i = 1;i<n;i++) {
		int u,v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt = 0;
	dfs(1,-1,cnt);
	cout << cnt << "\n";
	
	return 0;
}

