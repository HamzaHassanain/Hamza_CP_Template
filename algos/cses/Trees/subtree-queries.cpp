#include<bits/stdc++.h>
using namespace std;
struct segTree
{
    int size;
    vector<long long> data;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        data.assign(2 * size, 0LL); // asigin it to the cloeset poewr of two
    }
    void set(int i, long long value, int node, int beginSeg, int endSeg)
    {
        if (beginSeg == endSeg)
        {
            data[node] = value;
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        if (i <= mid)
            set(i, value, 2 * node, beginSeg, mid);
        else
            set(i, value, 2 * node + 1, mid + 1, endSeg);

        data[node] = (data[2 * node] + data[2 * node + 1]);
    }

    long long sum(int left, int right, int node, int beginSeg, int endSeg)
    {
        if (beginSeg > right || left > endSeg)
            return 0;

        if (beginSeg >= left && endSeg <= right)
            return data[node];

        int mid = (beginSeg + endSeg) / 2;
        long long sum1 = this->sum(left, right, 2 * node, beginSeg, mid);
        long long sum2 = this->sum(left, right, 2 * node + 1, mid + 1, endSeg);

        return (sum1 + sum2);
    }
    long long sum(int left, int right)
    {

        return sum(left, right, 1, 1, size);
    }
    void set(int i, long long value)
    {
        set(i, value, 1, 1, size);
    }
};
const int N = 2e5+1;
segTree sgt;
vector<int> adj[N];
long long a[N];
int timer = 0;

int flat[2*N];
int start[N];
int leave[N];

void flaten_tree(int u  =1,int p  = 0) {
	timer++;
	start[u] = timer;
	flat[timer] = u;
	
	for(int& v : adj[u]) {
		if(p == v) continue;
		flaten_tree(v,u);
	}
	timer++;
	leave[u] = timer;
	flat[timer] = u;
} 

int main() {

	int n,q;
	cin >> n >> q;
	sgt.init(2*n);
	for(int i  =1;i<=n;i++ ) cin >> a[i];
	for(int i  = 2;i<= n;i++) {
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	flaten_tree();
	for(int i  =1;i<=2*n;i++ ) sgt.set(i,a[flat[i]]);
	
	vector<vector<int>> qs;
	
	for (int i = 0;i < q;i++) {
		int a,b;
		cin >> a >> b;
		if(a == 1) {
			int c;cin >>c;
			qs.push_back( {a,b ,c} );
		}
		else qs.push_back( {a,b} );
	}
	
	for(auto arr : qs) {
		int type = arr[0];
		if(type ==2) {
			cout << sgt.sum(start[arr[1]] ,leave[arr[1]] ) / 2 << "\n";
		} else {
			sgt.set(start[arr[1]] , arr[2]),sgt.set(leave[arr[1]] , arr[2]);
		}
	}
	return 0;
}
