#include <bits/stdc++.h>
using namespace std;
 
void FastIO() { ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); }

int main()
{
 	
 	/*
 	
 		what is my state ? -> minium number of stemps to make a number zero -> 
	 		say   one dig -> 1 , 0 = 0
		
		 gready works just fine
		
		dp[9] = 1 -> dp[10] -> 	 	
 	*/		
 	
	
   	int n;cin >> n;
   	
   	vector<int> dp(max(n+1, 10));
   	
   	for(int i=1;i<=9;i++) dp[i] = 1;
   	
   	for(int x =10; x<= n;x++) {
   		dp[x] = 1e9;
   		for(char& ch : to_string(x)) {
   			dp[x] = min(dp[x],1 + dp[x-(ch-'0')]);
   		}
   	}

   	
   	cout << dp[n];
   	
   	return 0;
}
