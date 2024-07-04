#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;

 
int main() {
 
	
	int n,x;cin >> n >> x;
	vector<int> coins(n);
	vector<int> dp(x+1);
	for(int& coin : coins) cin >> coin;
	dp[0] = 1;
	for(int& coin : coins) {
		for(int y = 0;y <= x;y++) {
			if(coin <= y) dp[y] =  ( dp[y] + dp[y-coin]) % MOD;
		}
	}
 
	// sort(coins.begin(),coins.end());
	 
	
	cout << dp[x];
	
	
	return 0;
}
