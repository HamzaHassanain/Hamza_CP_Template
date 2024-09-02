
struct Suffix_Array
{

    vector<int> sa, lcp;
    Suffix_Array(string s)
    {
        s += " ";
        int n = s.size();
        sa.resize(n);
        vector<int> c(n), cnt(max(256, n), 0), p(n), pn(n);
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < 256; i++)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++)
            sa[--cnt[s[i]]] = i;
        c[sa[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[sa[i]] != s[sa[i - 1]])
                classes++;
            c[sa[i]] = classes - 1;
        }
        for (int h = 0; (1 << h) < n; h++)
        {
            for (int i = 0; i < n; i++)
            {
                p[i] = sa[i] - (1 << h);
                if (p[i] < 0)
                    p[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++)
                cnt[c[p[i]]]++;
            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--cnt[c[p[i]]]] = p[i];
            pn[sa[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++)
            {
                pair<int, int> cur = {c[sa[i]], c[(sa[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[sa[i - 1]], c[(sa[i - 1] + (1 << h)) % n]};
                if (cur != prev)
                    classes++;
                pn[sa[i]] = classes - 1;
            }
            c.swap(pn);
        }
        sa.erase(sa.begin());
        n--;

        if (sa[0] == s.size() - 1)
            sa.erase(sa.begin());

        lcp.resize(n);
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            if (k > 0)
                k--;
            if (pos[i] == n - 1)
            {
                k = 0;
                continue;
            }
            int j = sa[pos[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[pos[i]] = k;
        }
    }

    int size()
    {
        return sa.size();
    }
    int operator[](int i)
    {
        return sa[i];
    }
};

// returns -1 if s[i:] < t, 0 if s[i:] == t, 1 if s[i:] > t
auto string_compare = [&](string &s, int i, int len, string &t)
{
    for (int j = 0; j < len; j++)
    {
        if (i + j >= s.size())
            return -1;
        if (s[i + j] < t[j])
            return -1;
        if (s[i + j] > t[j])
            return 1;
    }
    return 0;
};
