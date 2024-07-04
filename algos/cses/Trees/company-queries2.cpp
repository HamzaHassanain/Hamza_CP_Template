#include<bits/stdc++.h>

using namespace std;



int main() {

	int n,q;
	cin >> n >> q;
	int LOG =20;
	vector<int> tree(n+1);
	vector<int> depth(n+1);
	for(int i = 2;i <= n;i++) cin >> tree[i];
		
	vector<vector<int>> up(n+1,vector<int>(LOG));
	
	tree[1] = 1;
	depth[1] = 0;
	for(int u = 1;u<=n;u++) {
		if(u != 1) {
			depth[u] = depth[tree[u]]+1;
		}
		up[u][0] = tree[u];
		for(int jump = 1;jump < LOG;jump++) {
			up[u][jump] = up[ up[u][jump-1] ][jump-1] ;
		}
	}
	vector<pair<int,int>> qs;
	
	for (int i = 0;i < q;i++) {
		int a,b;
		cin >> a >> b;
		qs.push_back( {a,b} );
	}
	for(auto [a,b] : qs) {
		
		if(depth[a] < depth[b]) swap(a,b);
		int k = depth[a] - depth[b];
		for(int jump = LOG -1; jump>= 0;jump--) {
			if(k&(1 << jump)) a = up[a][jump];
		}
		
		if(a == b) cout << a << "\n";
		else {
			
			for(int jump = LOG -1; jump>= 0;jump--) {
				if( up[a][jump] !=  up[b][jump]  ) a = up[a][jump],b = up[b][jump];
			}
			cout << up[a][0] << "\n";
		}
		
	}
	return 0;
}
