#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/gym/102694/problem/D
const int N = 3e5+1,LOG = 20;

vector<int> adj[N];

struct Ancestor {
	int u,cost;
	Ancestor() {}
	Ancestor(int u , int cost) : u {u}, cost{cost} {}
};
Ancestor up[N][LOG];
map<vector<int>, int> costs;
int depth[N];



void build_up(int u = 1 ,int p = 0) {

	for(int&v : adj[u]) {
	
		if(v == p) continue;
		
		depth[v] = depth[u]+1;
		int cost = min(costs[{min(u,v),max(u,v)}] , up[u][0].cost );
		
		up[v][0] = {u, costs[{min(u,v),max(u,v)}]};
		up[v][1] = {up[u][0].u , cost};
		
		for(int j = 2;j < LOG;j++) {
			
			up[v][j] =up[  up[v][j-1].u ][j-1]; 
		}
		
		build_up(v,u);
	}
}
int get_lca_cost(int a , int b) {

	
	if(depth[a] < depth[b]) swap(a,b);
	int k = depth[a] - depth[b];
	int cost = up[a][0].cost;
	// cout << a << " " << b << " " << depth[a] << "  " << depth[b] << " " << cost  << endl; 
	k -= 1;
	k = max(0,k);
	for(int j = LOG - 1; j>= 0;j--) {
		if(k&(1 << j)) a = up[a][j].u, cost = min(cost, up[a][j].cost);
	}
	
	if(a == b or !k) return cost;
	
	
	for(int jump = LOG - 1; jump>= 0;jump--) {
		if( up[a][jump].u !=  up[b][jump].u  ) a = up[a][jump].u,b = up[b][jump].u, cost =  min({cost , up[b][jump].cost , up[a][jump].cost} );
	}
	
	return min(cost, up[a][0].cost);
}


int main() {

	ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

	int n,m;
	cin >> n >> m;
	
	
	for(int i  = 0;i< m;i++) {
		
		int u,v,w;cin >> u >> v >> w;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		
		costs[{ min( u, v) , max(u, v )}]  = w;
	}
	
	for(int i = 0;i<LOG;i++) up[1][i] = {1, int(1e9) };
	
	build_up();
	
	vector<vector<int>> qs;
	
	int q;cin >> q;
	
	for (int i = 0;i < q;i++) {
		int a,b;
		cin >> a >> b;
		qs.push_back( {a,b} );
	
	}
	
	for(auto v : qs) {
		cout << get_lca_cost(v[0],v[1]) << "\n";
	}
	
	return 0;
}
