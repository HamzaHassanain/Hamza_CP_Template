#include<bits/stdc++.h>

using namespace std;

map<int,vector<int>> adj;

vector<int> maxLength1;
vector<int> maxLength2;
vector<int> final_ans;

void dfs(int u,int p) {
	
	for(auto v : adj[u]) {
		if(v == p) continue;
		dfs(v,u);
		if( maxLength1[v] +1 > maxLength1[u]) {
			maxLength2[u] = maxLength1[u];
			maxLength1[u] = maxLength1[v] + 1;
		}  else if( maxLength1[v] + 1 > maxLength2[u] )  {
			maxLength2[u] = maxLength1[v] + 1;
		}
	
	}
	
	

}
void dfs(int u,int p,int path ) {
	
	final_ans[u] = max(maxLength1[u],path);
	for(auto v : adj[u]) {
		if(v == p) continue;
		
		if( maxLength1[v]+1 == maxLength1[u]) dfs( v , u, max(path,maxLength2[u]) +1 );
		else dfs(v,u,final_ans[u]+1);
	}

}
int main() {
	
	
	int n;
	cin >> n;
	final_ans = maxLength1 = maxLength2 = vector<int>(n+1);
	
	for(int i = 1;i<n;i++) {
		int u,v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	
	dfs(1,-1);
	dfs(1,-1,0);
	
	for(int i = 1;i<= n;i++) {
		cout << final_ans[i] << " ";	
	} cout << "\n";
	return 0;
}
