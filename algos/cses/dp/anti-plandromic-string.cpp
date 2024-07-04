#include <bits/stdc++.h>
using namespace std;
vector<map<string, long long>> memo;
bool is_palandrom(string s)
{
	string co = s;
	reverse(co.begin(), co.end());

	return s == co;
}
long long dp(string &s, string pref, int i)
{
	if (pref.size() == 5 and is_palandrom(pref))
		return 0;
	if (i >= s.size())
		return !is_palandrom(pref);

	long long res = 0;
	if (memo[i].count(pref))
		return memo[i][pref];
	if (pref.size() >= 5)
	{
		string new_pref = pref.substr(1, 4);

		if (s[i] == '?')
		{
			if (!is_palandrom(new_pref + '1') and !is_palandrom(pref + '1'))
				res += dp(s, new_pref + "1", i + 1);
			if (!is_palandrom(new_pref + '0') and !is_palandrom(pref + '0'))
				res += dp(s, new_pref + "0", i + 1);
		}
		else
		{
			if (!is_palandrom(new_pref + s[i]) and !is_palandrom(pref + s[i]))
				res += dp(s, new_pref + s[i], i + 1);
		}
	}
	else
	{
		if (s[i] == '?')
			res = dp(s, pref + "1", i + 1) + dp(s, pref + "0", i + 1);
		else
			res = dp(s, pref + s[i], i + 1);
	}
	return memo[i][pref] = res;
}
void test_case(int case_num)
{
	string yes = "POSSIBLE";
	string no = "IMPOSSIBLE";

	int n;
	cin >> n;
	string s;
	cin >> s;
	memo = vector<map<string, long long>>(n);
	if (dp(s, "", 0))
		cout << "CASE #" << case_num << ": " << yes << "\n";
	else
		cout << "CASE #" << case_num << ": " << no << "\n";
}
int main()
{

	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		test_case(i);
}
/*
15
0111???????????
*/