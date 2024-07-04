#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n, q;
	cin >> n >> q;

	vector<int> tree(n + 1);
	vector<int> depth(n + 1);
	for (int i = 2; i <= n; i++)
		cin >> tree[i];

	vector<vector<int>> up(n + 1, vector<int>(20));

	tree[1] = 1;
	depth[1] = 0;
	for (int u = 1; u <= n; u++)
	{
		if (u != 1)
		{
			depth[u] = depth[tree[u]] + 1;
		}
		up[u][0] = tree[u];
		for (int jump = 1; jump < 20; jump++)
		{
			up[u][jump] = up[up[u][jump - 1]][jump - 1];
		}
	}
	vector<pair<int, int>> qs;

	for (int i = 0; i < q; i++)
	{
		int node, k;
		cin >> node >> k;
		qs.push_back({node, k});
	}
	for (auto [node, k] : qs)
	{
		if (depth[node] < k)
		{
			cout << -1 << "\n";
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (k & (1 << i))
					node = up[node][i];
			}
			cout << node << "\n";
		}
	}
	return 0;
}
