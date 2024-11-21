const int mx = 100001;

int grandy[mx];

vector<int> divisors[mx];

void make_divs()
{
    for (int i = 2; i < mx; i++)
    {
        for (int j = i; j < mx; j = j + i)
        {
            divisors[j].push_back(i);
        }
    }
}

int get_grandy(int X)
{
    if (X == 1)
    {
        return 0;
    }
    if (grandy[X] != -1)
    {
        return grandy[X];
    }
    set<int> s;
    for (int i = 0; i < divisors[X].size(); i++)
    {
        int Y = divisors[X][i];
        int Z = X / Y;
        if (Y % 2 == 0)
            s.insert(0);
        else
            s.insert(get_grandy(Z));
    }
    int mex = 0;
    while (s.find(mex) != s.end())
        mex++;
    grandy[X] = mex;
    return grandy[X];
}
