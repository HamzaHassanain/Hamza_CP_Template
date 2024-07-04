#include <bits/stdc++.h>
using namespace std;
int rect_cutting(int a, int b)
{
	/*
		what will happen when we cut ?
		what are the possbile cuts ?
		we can cut horizontal or vertical
		dp[h][w] when h = w is 0
		dp[h][w] = min (
				min(dp[h][w-1]+dp[h][1] , ................ dp[h][w-(w-1)]+dp[h][w-1])
				min(dp[h-1][w]+dp[h-1][w] , ................ dp[h-(h-1)][w]+dp[(h-1)][w])
			);
	*/
	vector<vector<int>> dp(a + 10, vector<int>(b + 10, 0));
	for (int h = 1; h <= a; h++)
	{
		for (int w = 1; w <= b; w++)
		{
			if (w == h)
				dp[h][w] = 0;
			else
			{
				dp[h][w] = 1e9;
				for (int sub = 1; sub < h; sub++)
					dp[h][w] = min(dp[h][w], 1 + dp[h - sub][w] + dp[sub][w]);
				for (int sub = 1; sub < w; sub++)
					dp[h][w] = min(dp[h][w], 1 + dp[h][w - sub] + dp[h][sub]);
			}
		}
	}

	return dp[a][b];
}
int main()
{
	int a, b;
	cin >> a >> b;

	cout << rect_cutting(a, b);
}
