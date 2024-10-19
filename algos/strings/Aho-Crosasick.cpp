// sum of patterns length
const int N = 1e5 + 5;

// ALL PATTERNS MUST BE UNIQUE
vector<string> patterns;

struct aho_corasick
{

    // term[i] = the list of patterns that end at node i
    // pi[i] = the longest proper suffix of the string ending at i which is also a prefix of the string

    const int k = 26;
    vector<int> pi;
    vector<vector<int>> term, trie;

    explicit aho_corasick(const vector<string> &a)
    {
        pi = vector<int>(N, -1);
        trie.assign(1, vector<int>(k, -1));
        term.assign(N, vector<int>());
        init(a);
    }

    inline void add(const string &s, int &idx)
    {
        int cur = 0;
        for (auto &i : s)
        {
            int c = i - 'a';
            if (trie[cur][c] == -1)
            {
                trie[cur][c] = trie.size(); // add a new node
                pi[trie.size()] = -1;       // initialize the pi value
                trie.emplace_back(k, -1);   // add the new node to the trie
            }
            cur = trie[cur][c];
        }
        term[cur].emplace_back(idx); // add the pattern index to the node
    }

    inline void build_links()
    {
        queue<int> q;

        for (int i = 0; i < k; i++)
        {
            if (trie[0][i] != -1)
            {                       // add the first level nodes to the queue
                pi[trie[0][i]] = 0; // the pi value of the first level nodes is 0
                q.push(trie[0][i]);
            }
            else
            {
                trie[0][i] = 0; // if the node has no children, it should point to the root
            }
        }

        while (q.size())
        {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < k; i++)
            {
                if (trie[cur][i] == -1)
                    continue;

                int j = next_state(pi[cur], i + 'a');
                pi[trie[cur][i]] = j;

                // add all the patterns of the current node to the next node
                for (auto &idx : term[j])
                    term[trie[cur][i]].push_back(idx);
                q.push(trie[cur][i]);
            }
        }
    }

    inline void init(const vector<string> &a)
    {
        for (int i = 0; i < sz(a); i++)
            add(a[i], i);
        build_links();
    }

    // find the next state of the current state
    inline int next_state(int cur, char c)
    {
        int ch = c - 'a';
        while (trie[cur][ch] == -1)
            cur = pi[cur];
        return trie[cur][ch];
    }

    // search for the patterns in the string
    inline vector<vector<int>> search(string &s, int n)
    {
        int cur = 0;
        vector<vector<int>> occs(n);
        for (int i = 0; i < s.size(); i++)
        {
            cur = next_state(cur, s[i]); // find the next state
            for (auto &idx : term[cur])
            {
                // add the index of the pattern to the occs vector
                occs[idx].emplace_back(i - patterns[idx].size() + 1);
            }
        }
        return occs;
    }
};
