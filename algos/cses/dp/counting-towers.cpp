#include <bits/stdc++.h>
using namespace std;
 
void FastIO() { ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); }
long long MOD = 1e9  + 7;
int main()
{

 		int tc;
 		cin >> tc;
 		vector<vector<long long>> dp(3, vector<long long>(1e6+10));
	 		dp[1][1] = 1;
	 		dp[2][1] = 1;
	 		for(int h = 2;h<=1e6;h++) {
	 			dp[2][h] = (4*dp[2][h-1]) % MOD + dp[1][h-1] ;
	 			dp[2][h] %= MOD;
	 		
	 			dp[1][h] = (2*dp[1][h-1]) % MOD + dp[2][h-1];	
	 			dp[1][h] %= MOD;
	 		}
	 		
 		while(tc--) {
 		
	 		
	 		int n;
	 		cin >> n;
	 		
	 		cout <<  (dp[1][n] + dp[2][n] ) % MOD << "\n";
   		}
}
