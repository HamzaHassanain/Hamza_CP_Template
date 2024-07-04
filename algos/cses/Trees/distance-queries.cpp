#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+1,LOG = 20;

int up[N][LOG];
int depth[N];

vector<int> adj[N];

void build_up(int u = 1 ,int p = 0) {

	for(int&v : adj[u]) {
	
		if(v == p) continue;
		depth[v] = depth[u]+1;
		up[v][0] = u;
		for(int j = 1;j < LOG;j++) {
			up[v][j] = up[  up[v][j-1] ][j-1]; 
		}
		build_up(v,u);
	}
}

int get_lca(int a , int b) {

	if(depth[a] < depth[b]) swap(a,b);
	
	int k = depth[a] - depth[b];
	for(int j = LOG -1; j>= 0;j--) {
		if(k&(1 << j)) a = up[a][j];
	}
	
	if(a == b) return a;

	for(int jump = LOG -1; jump>= 0;jump--) {
		if( up[a][jump] !=  up[b][jump]  ) a = up[a][jump],b = up[b][jump];
	}
	
	return up[a][0];
}

int main() {
	
	int n,q;
	cin >>n >> q;
	for(int i  =1;i<n;i++) {
		int u,v;cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	depth[1] = 0;
	for(int j =0;j < LOG;j++) up[1][j] = 1; 
	
	build_up(1);
	
	vector<pair<int,int>> qs;
	
	for (int i = 0;i < q;i++) {
		int a,b;
		cin >> a >> b;
		qs.push_back( {a,b} );
	}
	
	for(auto [a,b] : qs) {
		int lca = get_lca(a,b);
		
		cout << (depth[a]-depth[lca]) + (depth[b]-depth[lca])<< "\n";
	}
	
	
	return 0;
}
