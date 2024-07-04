#include<bits/stdc++.h>

using namespace std;
map<int,vector<int>> adj;

vector<long long> a, subtree , cost;
long long res = 0;
int n;
void preCalc(int u,int p) {
	
	subtree[u] = a[u];
	for(int& v : adj[u]) {
		if(v == p) continue;
	
		preCalc(v,u);

		subtree[u] += subtree[v];
		cost[u] += cost[v] + subtree[v];
		
	}

}
void dfs(int u, int p, long long Pcost ) {

	long long takeUFromPCost = (Pcost - cost[u] - subtree[u]);
	long long remaingSubTreeSum = subtree[1] - subtree[u];
	
	long long curTreeCost = takeUFromPCost+remaingSubTreeSum;
	
	res = max(res, curTreeCost);
	
	for(auto v : adj[u]) {
		if(p == v) continue;
		dfs(v,u,curTreeCost);
	}
}
int main() {
	
	ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	
	cin >> n;
	a = subtree = cost = vector<long long>(n+1);
	for(int i = 1;i<=n ;i++) cin >> a[i];
	for(int i = 1;i <n;i++) {
		int u,v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	
	preCalc(1,0);
	for(auto v : adj[1]) {
		dfs(v,1 , cost[1]);
	}
	// for(int i = 1;i<= n;i++)
	//	cout << cost[i] << " ";
	cout << res+1 << "\n";
	return 0;
}
