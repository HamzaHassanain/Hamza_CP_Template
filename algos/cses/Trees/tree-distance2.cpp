#include<bits/stdc++.h>

using namespace std;
map<int,vector<int>> adj;


vector<long long> subTreePathsSum,result,subtreeSize;
int n;
void dfs_one(int u,int p) {
	
	int n;
	subtreeSize[u] = 1;
	for(int& v : adj[u]) {
		if(v == p) continue;
		
		dfs_one(v,u);
		subTreePathsSum[u] += subtreeSize[v] + subTreePathsSum[v];
		subtreeSize[u] += subtreeSize[v];
	}

}
void dfs_two(int u,int p) {
	

	result[u] =  result[p] + n - 2*subtreeSize[u];
	for(int& v : adj[u]) {
		if(v == p) continue;

		dfs_two(v,u);
		
	}

}
int main() {
	
	
	cin >> n;
	subtreeSize = subTreePathsSum = result = vector<long long>(n+1);
	for(int i = 1;i<n;i++) {
		int u,v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	
	dfs_one(1,0);
	result[1] = subTreePathsSum[1];
	
	for(auto v : adj[1])
		dfs_two(v,1);
	
	for(int i =1;i<=n;i++) 
		cout <<  result[i] <<" ";
	cout << "\n";
	
	return 0;
}
