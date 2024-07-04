#include <bits/stdc++.h>

using namespace std;

int memo[5005][5005];

int dp(string &a, string &b, int i = 0, int j = 0)
{

	if (i == a.size())
		return abs(int(b.size()) - (j));

	else if (j == b.size())
		return abs(int(a.size()) - (i));

	if (memo[i][j] != -1)
		return memo[i][j];
	int res = 0;
	if (a[i] == b[j])
		res = dp(a, b, i + 1, j + 1);

	else
		res = min({1 + dp(a, b, i + 1, j + 1), 1 + dp(a, b, i + 1, j), 1 + dp(a, b, i, j + 1)});

	return memo[i][j] = res;
}
long long edit_distance(string &a, string &b)
{
	/*
		we have A and B ?

		you did it fucking right but think better about your fucking base cases

	*/

	memset(memo, -1, sizeof(memo));
	return dp(a, b);
}
int main()
{
	string a, b;
	cin >> a >> b;

	cout << edit_distance(a, b) << "\n";
}
