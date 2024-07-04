#include <bits/stdc++.h>
using namespace std;
 
void FastIO() { ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); }


int main()
{
 		
 	int n,x;cin >> n >> x;
 	
 	// vector<vector<int>> bst(1, vector<int>(x+10));
 	
 	vector<int> prices(n+1),pages_cnt(n+1);	
   	for(int i =1;i<=n;i++) cin >>  prices[i];
   	for(int i =1;i<=n;i++) cin >>  pages_cnt[i];
   	
 
   	vector<int> cur(x+10);
   	vector<int> prev(x+10);
   for(int i = 1;i <= n;i++) {
   		
   		for(int sum = 1;sum <= x;sum++) {
   		
   			if(prices[i] > sum) cur[sum] = prev[sum];
   			else cur[sum] = max(prev[sum] , pages_cnt[i] + prev[sum - prices[i]]);
   		
   		}
   		
   		prev = cur;
   		
   	}
  
   	cout << cur[x];
}
