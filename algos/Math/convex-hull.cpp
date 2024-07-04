typedef complex<double> point;
#define EPS 1e-9
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(), (a).real()))
#define vec(a, b) ((b) - (a))
#define same(p1, p2) (dp(vec(p1, p2), vec(p1, p2)) < EPS)
#define dp(a, b) ((conj(a) * (b)).real()) // a * b cos(T), if zero -> prep
#define cp(a, b) ((conj(a) * (b)).imag()) // a * b sin(T), if zero -> parllel
#define length(a) (hypot((a).imag(), (a).real()))
#define normalize(a) (a) / length(a)
#define polar(r, ang) ((r) * exp(point(0, ang)))
#define rotateO(p, ang) ((p) * exp(point(0, ang)))
#define rotateA(p, ang, about) (rotateO(vec(about, p), ang) + about)
int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a < b ? -1
                                                                     : 1; }
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
struct Converx_Hull
{

    struct angleCMP
    {

        point center;

        angleCMP(point C) : center(C) {}

        bool operator()(const point &lhs, const point rhs) const
        {
            if (dcmp(cp(lhs - center, rhs - center), 0) == 0)
            {
                if (fabs(lhs.Y - rhs.Y) < EPS)
                    return lhs.X < rhs.X;
                return lhs.Y < rhs.Y;
            }
            return cp((lhs - center), (rhs - center)) < 0;
        }
    };

    vector<point> Convex_Points;

    Converx_Hull(vector<point> &points)
    {
        if (sz(points) <= 1)
            Convex_Points = points;
        else
        {
            for (int i = 0; i < sz(points); i++)
            {
                if (make_pair(points[i].Y, points[i].X) < make_pair(points[0].Y, points[0].X))
                    swap(points[i], points[0]);
            }
            sort(points.begin() + 1, points.end(), angleCMP(points[0]));

            // To remove co-linear points, un-comment this part

            // vector<point> tmp;
            // for (int i = 0; i < sz(points); i++)
            // {
            //     if (sz(tmp) > 1 && !cp(tmp.back() - tmp[0], points[i] - tmp[0]))
            //     {
            //         if (length(points[0] - tmp.back()) < length(points[0] - points[i]))
            //             tmp.back() = points[i];
            //     }
            //     else
            //     {
            //         tmp.push_back(points[i]);
            //     }
            // }
            // points = tmp;

            for (int i = 0; i < sz(points); i++)
            {
                int sz = sz(Convex_Points);
                while (sz > 1 && cp(Convex_Points[sz - 2] - Convex_Points[sz - 1], points[i] - Convex_Points[sz - 1]) < 0)
                    Convex_Points.pop_back(), sz--;
                Convex_Points.push_back(points[i]);
            }
            if (sz(Convex_Points) >= 3) // not a line
                Convex_Points.push_back(Convex_Points[0]);
        }
    }
};
