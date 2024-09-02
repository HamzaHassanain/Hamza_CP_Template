
struct Node
{
    long long val;
    Node() { val = 0; }
    Node(long long val) : val(val) {}
};
struct Operation
{
    virtual Node work(Node, Node) { return Node(); }
};
struct SegmentTree
{
    int size;
    Node DEFAULT;
    vector<Node> data;
    Operation *operation;
    void init(int n, Node DEFAULT, Operation *operation)
    {
        size = 1;
        this->operation = operation;
        this->DEFAULT = DEFAULT;
        while (size < n)
            size *= 2;
        data.assign(2 * size, Node()); // asigin it to the cloeset poewr of two
    }
    void set(int i, Node value, int node, int beginSeg, int endSeg)
    {
        if (beginSeg == endSeg)
        {
            data[node] = value;
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        if (i <= mid)
            set(i, value, 2 * node, beginSeg, mid);
        else
            set(i, value, 2 * node + 1, mid + 1, endSeg);

        data[node] = operation->work(data[2 * node], data[2 * node + 1]);
    }

    Node query(int left, int right, int node, int beginSeg, int endSeg)
    {
        if (beginSeg > right || left > endSeg)
            return DEFAULT;

        if (beginSeg >= left && endSeg <= right)
            return data[node];

        int mid = (beginSeg + endSeg) / 2;
        Node a = this->query(left, right, 2 * node, beginSeg, mid);
        Node b = this->query(left, right, 2 * node + 1, mid + 1, endSeg);

        return operation->work(a, b);
    }
    Node query(int left, int right)
    {

        return query(left, right, 1, 1, size);
    }
    void set(int i, Node value)
    {
        set(i, value, 1, 1, size);
    }
};
