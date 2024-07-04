#include <bits/stdc++.h>
using namespace std;
 
void FastIO() { ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); }
 
int main()
{
 		int n;cin >> n;
 		
 		vector<string> grid(n);
 		for(string& s : grid) cin >> s;
   		vector<vector<int>> dp(n+1,vector<int>(n+1));
	
		if(grid[n-1][n-1] == '*' or grid[0][0] == '*') {
			cout << 0;
			return 0;
		}
		dp[n-1][n-1] = 1;
		for(int i = n-1;i>=0;i--) {
			for(int j = n-1;j>=0;j--) {
				if(grid[i][j] == '*') 
					continue;
				dp[i][j] = (dp[i][j] + (dp[i][j+1] + dp[i+1][j]) % long(1e9+7)) % long(1e9+7);
			}
		}
		
		cout << dp[0][0];
}
