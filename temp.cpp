#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define el '\n'
using namespace std;
const int N = 1e4 + 5, INF = 1e9 + 5, mod = 1e9 + 7;

#define ld long double
#define point complex<ld>
#define pi acos(-1)
#define rad(v) arg(v)
#define deg(v) rad(v) * 180.0 / pi
#define dot(a, b) ((conj(a) * (b)).real())
#define cross(a, b) ((conj(a) * (b)).imag())
#define vec(a, b) (point)(b - a)
#define same(a, b) (dot(vec(a, b), vec(a, b)) < eps)
#define includedAngle(a, b) acos(dot(a, b) / (abs(a) * abs(b)))
#define X real()
#define Y imag()
const ld eps = 1e-8;

int dcmp(const ld &a, const ld &b)
{
    if (fabs(a - b) <= eps)
        return 0;

    return (a > b ? 1 : -1);
}

point cntr;

bool cmp(point a, point b)
{
    if (a.X != b.X)
        return a.X < b.X;
    return a.Y < b.Y;
}

bool sortCCW(point a, point b)
{
    a -= cntr;
    b -= cntr;
    if (cross(a, b) == 0)
    {
        if (a.Y != b.Y)
        {
            return a.Y < b.Y;
        }
        return a.X < b.X;
    }
    return cross(a, b) > 0;
}
void sortPolygonCCW(vector<point> &p)
{
    sort(p.begin(), p.end(), cmp);

    for (int i = 1; i < (int)p.size(); i++)
    {
        if (p[i].Y < p[0].Y)
            swap(p[i], p[0]);
        else if (p[i].Y == p[0].Y && p[i].X < p[0].X)
            swap(p[i], p[0]);
    }

    cntr = p[0];
    sort(p.begin() + 1, p.end(), sortCCW);
}

bool intersectSegments(point a, point b, point c, point d, point &intersect)
{
    ld d1 = cross(vec(b, a), vec(c, d)), d2 = cross(vec(c, a), vec(c, d)), d3 = cross(vec(b, a), vec(c, a));

    if (fabs(d1) < eps)
        return 0; /// parllel or identical

    ld t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;

    /// segment: [0, 1]
    /// ray: [0, INF]
    /// line: [-INF, INF]

    /// make sure that eps is not too accurate
    if (t1 < -eps or t1 > 1 + eps or t2 < -eps or t2 > 1 + eps)
        return 0;

    return 1;
}
ld polygonArea(vector<point> &p)
{ /// polygon has to be in ccw or cw
    int n = p.size();
    p.push_back(p[0]);
    ld ret = 0;

    for (int i = 0; i < n; i++)
        ret += cross(p[i], p[i + 1]);

    p.pop_back();

    return fabs(ret / 2.0);
}

bool areCollinear(point a, point b, point c)
{
    return fabs(cross(b - a, c - a)) < eps;
}

vector<point> convexHull(vector<point> points)
{
    sort(points.begin(), points.end(), cmp);

    vector<point> p;
    p.push_back(points[0]);

    for (int i = 1; i < (int)points.size(); i++)
    {
        if (points[i] == points[i - 1])
            continue;

        p.push_back(points[i]);
    }

    if (p.size() <= 1)
        return p;

    for (int i = 1; i < (int)p.size(); i++)
    {
        if (p[i].Y < p[0].Y)
            swap(p[i], p[0]);
        else if (p[i].Y == p[0].Y && p[i].X < p[0].X)
            swap(p[i], p[0]);
    }

    cntr = p[0];
    sort(p.begin() + 1, p.end(), sortCCW);
    vector<point> ch;
    p.push_back(p[0]);

    for (int i = 0; i < p.size(); i++)
    {
        while (ch.size() > 1)
        {
            auto cur = ch.back(), prv = ch[ch.size() - 2];

            if (cross(prv - cur, p[i] - cur) <= 0)
                break;

            ch.pop_back();
        }
        ch.push_back(p[i]);
    }
    ch.pop_back();

    /// ch is convex hull with collinear points
    /// removing collinear points

    vector<point> finalCH = {ch[0]};

    for (int i = 1; i + 1 < ch.size(); i++)
        if (!areCollinear(ch[i - 1], ch[i], ch[i + 1]))
            finalCH.push_back(ch[i]);

    finalCH.push_back(ch.back());
    return finalCH;
}

ld w, h;
int a;

void doWork()
{
    cin >> w >> h >> a;

    if (a == 0 or a == 180)
    {
        cout << w * h;
        return;
    }

    vector<point> oldRect(4), newRect(4);

    oldRect[0] = point(-w / 2, h / 2);
    oldRect[1] = point(-w / 2, -h / 2);
    oldRect[2] = point(w / 2, -h / 2);
    oldRect[3] = point(w / 2, h / 2);

    for (int i = 0; i < 4; i++)
        newRect[i] = oldRect[i] * polar((ld)1.0, ((ld)pi * a) / 180.0);

    sortPolygonCCW(oldRect);
    sortPolygonCCW(newRect);

    vector<point> intersections;

    oldRect.push_back(oldRect[0]);
    newRect.push_back(newRect[0]);

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            point inter;

            if (intersectSegments(oldRect[i - 1], oldRect[i], newRect[j - 1], newRect[j], inter))
                intersections.push_back(inter);
        }
    }

    for (auto &p : intersections)
        cout << p.X << " " << p.Y << endl;

    vector<point> hull = convexHull(intersections);

    cout << polygonArea(hull);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(12);
    int tests = 1;
    //    cin >> tests;
    while (tests--)
        doWork();
}

/*
Rectangle Puzzle
time limit per test: 2 seconds
memory limit per test: 256 megabytes

You are given two rectangles on a plane. The centers of both rectangles are located in the origin of coordinates (meaning the center of the rectangle's symmetry). The first rectangle's sides are parallel to the coordinate axes: the length of the side that is parallel to the Ox axis, equals w, the length of the side that is parallel to the Oy axis, equals h. The second rectangle can be obtained by rotating the first rectangle relative to the origin of coordinates by angle α.

<img i>
Your task is to find the area of the region which belongs to both given rectangles. This region is shaded in the picture.

Input
The first line contains three integers w, h, α (1 ≤ w, h ≤ \(10^6\); 0 ≤ α ≤ 180). Angle α is given in degrees.

Output
In a single line print a real number — the area of the region which belongs to both given rectangles.

The answer will be considered correct if its relative or absolute error doesn't exceed \(10 ^{- 6}\).

Note
The second sample has been drawn on the picture above.

Solution:
The first thing that comes to mind is just to rotate the points of the first rectangle by the angle α, then for each side of both the original rectangle and the rotated rectangle, find the point where they intersect. Considering all these intersection points, we will need to get the polygon such that its corners are the intersection some of the intersection points, such that, if we draw a line between all these points in counter-clockwise order, we will get the polygon that represents the intersection of the two rectangles. Then we can calculate the area of this polygon.
To find this polygon naively, (assuming we have all the intersection points), we can try all possible subsets of these points, then for each subset of points, we can check if they form a convex polygon, and if they do, we also need to check if all the other points (points that are not in the subset) are inside this polygon. If they are, then we can calculate the area of this polygon.
But there is a better way, and more efficient way to do this, we can get the convex hull of the intersection points, and then we can remove the collinear points from the convex hull, and then we can calculate the area of the polygon.

The convex hull basically is the smallest convex polygon that contains all the points, and it can be found in O(n log n) time complexity, where n is the number of points. The convex hull can be found using the Graham scan algorithm, which is a well-known algorithm to find the convex hull of a set of points. The convex hull can be found by sorting the points based on their x-coordinate, then we can sort the points based on their angle with the lowest x-coordinate point, then we can iterate over the points, and for each point, we can check if the last two points in the convex hull and the current point form a right turn, if they do, we can remove the last point from the convex hull, and we can keep doing this until we get a left turn, then we can add the current point to the convex hull. We can repeat this process for all the points, and we will get the convex hull of the points.

There will be lots of geometry stuff we will be discussing, but now, just read the intput.

*/