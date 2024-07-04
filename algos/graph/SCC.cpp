#include <bits/stdc++.h>
using namespace std;
const string dl = "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MAX 100
#define vi vector<int>
#define vvi vector<vi>

#define sz(x) (int)x.size()
vector<vector<int>> adjList, comps, dagList;
vector<int> inStack, lowLink, dfn, comp, inDeg, outDeg;
stack<int> stk;
int ndfn, cntSrc, cntSnk;

vector<ll> Sizes, dp, vis, SubGraphSize;

void tarjan(int node)
{
    lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
    stk.push(node);

    for (int i = 0; i < adjList[node].size(); i++)
    {
        int ch = adjList[node][i];
        if (dfn[ch] == -1)
        {
            tarjan(ch);
            lowLink[node] = min(lowLink[node], lowLink[ch]);
        }
        else if (inStack[ch])
            lowLink[node] = min(lowLink[node], dfn[ch]);
    }

    if (lowLink[node] == dfn[node])
    {
        comps.push_back(vector<int>());
        int x = -1;
        while (x != node)
        {
            x = stk.top(), stk.pop(), inStack[x] = 0;
            comps.back().push_back(x);
            comp[x] = sz(comps) - 1;
        }
    }
}

void scc()
{
    int n = sz(adjList);

    inStack.clear();
    inStack.resize(n);
    lowLink.clear();
    lowLink.resize(n);
    dfn.clear();
    dfn.resize(n, -1);
    ndfn = 0;

    comp.clear(), comp.resize(n);
    comps.clear();

    for (int i = 0; i < n; i++)
    {
        if (dfn[i] == -1)
            tarjan(i);
    }
}

void computeCompGraph()
{
    int csz = comps.size(), cntSrc = csz, cntSnk = csz;

    outDeg.clear();
    outDeg.resize(csz);
    inDeg.clear();
    inDeg.resize(comps.size());
    dagList.clear();
    dagList.resize(csz); // will contain duplicates
    Sizes.clear();
    Sizes.resize(csz);
    dp.clear();
    dp.resize(csz);

    for (int i = 0; i < csz; i++)
    {
        Sizes[i] = comps[i].size();
        dp[i] = 0;
    }
    for (int i = 0; i < sz(adjList); i++)
        for (int j = 0; j < sz(adjList[i]); j++)
        {
            int k = adjList[i][j];
            if (comp[k] != comp[i])
            {
                dagList[comp[i]].push_back(comp[k]); // reverse
                if (!(inDeg[comp[k]]++))
                    cntSrc--;
                if (!(outDeg[comp[i]]++))
                    cntSnk--;
            }
            else
                ; // this edge is for a component comp[k]
        }

    /* Min edges to convert DAG to one cycle
    if (comps.size() == 1)
        cout << "0\n";
    else {
        cout << max(cntSrc, cntSnk) << "\n";
    }
    */
}
void calc_paths(ll u)
{
    vis[u] = 1;
    for (auto v : dagList[u])
    {
        // if (!vis[v])
        calc_paths(v);
        SubGraphSize[u] += SubGraphSize[v];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        ll n, m;
        cin >> n >> m;
        adjList.resize(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adjList[u].push_back(v);
        }

        scc();
        computeCompGraph();

        vector<int> topSort;
        // topSort the components graph
        vector<int> inDegComp(sz(comps));
        for (int i = 0; i < sz(dagList); i++)
            for (int j = 0; j < sz(dagList[i]); j++)
                inDegComp[dagList[i][j]]++;

        queue<int> q;
        for (int i = 0; i < sz(comps); i++)
            if (!inDegComp[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topSort.push_back(node);
            for (int i = 0; i < sz(dagList[node]); i++)
            {
                int ch = dagList[node][i];
                if (--inDegComp[ch] == 0)
                    q.push(ch);
            }
        }
        // reverse(all(topSort));
        vis = vector<ll>(sz(comps), 0);
        dp = vector<ll>(sz(comps), 0);
        SubGraphSize = vector<ll>(sz(comps), 0);
        for (int i = 0; i < sz(topSort); i++)
        {
            // cout << topSort[i] << " " << " " << Sizes[topSort[i]] << dl;
            // for (int j = 0; j < sz(dagList[topSort[i]]); j++)
            // {
            //     cout << dagList[topSort[i]][j] << " ";
            // }
            // cout << dl;
            dp[topSort[i]] = Sizes[topSort[i]] * Sizes[topSort[i]];
            SubGraphSize[topSort[i]] = Sizes[topSort[i]];
        }
        for (auto i : topSort)
        {
            if (vis[i])
                continue;
            calc_paths(i);
        }
        // for (auto i : SubGraphSize)
        //     cout << i << " ";
        // cout << dl;
        // for (auto i : dp)
        //     cout << i << " ";
        // cout << dl;
        for (int i = 0; i < sz(comps); i++)
        {
            for (auto j : dagList[i])
            {
                dp[i] += Sizes[i] * SubGraphSize[j];
            }
        }
        cout << accumulate(all(dp), 0LL) << dl;
    nxt:;
    }
    return 0;
}