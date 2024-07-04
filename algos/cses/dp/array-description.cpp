#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9  + 7;
int main()
{
	int n,m;
   	cin >> n >> m;
   	vector<long long> a(n);
	vector<vector<long long>>dp(n+10,vector<long long>(m+10)); 
   	for(auto& a : a) cin >> a;
   	
   	if(!a[0]) for(int x = 1;x<=m;x++) dp[0][x] = 1;
   	else dp[0][a[0]] = 1;
   	
   	for(int i = 1;i<n;i++) {
   		for(int x = 1;x<=m;x++) {
   			if(a[i] and a[i] != x) continue;
   			dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x+1]) % MOD + dp[i-1][x]) % MOD;
			
   		}
   	}
   	
   	long long sum = 0;
   	for(int x=1;x<=m;x++) {
		sum += dp[n-1][x];
		sum %= MOD;   		
   	}
   	cout << sum << "\n";
}
