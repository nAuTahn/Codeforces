//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef pair <double, double> point;
#define F first
#define S second
#define epsilon 1e-6

//    Bài ko khó nhưng code dễ bug :((

typedef struct C{
    int x, y, r;
} Circle;

Circle cir[5];
vector <point> inters;
int n;
int v = 0, e = 0;

double Distance(point a, point b) {
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

bool operator == (point a, point b) {
    return (Distance(a, b) < epsilon);
}

//    Intersec 2 circle
//    1 line if they are intersec or tangent
//    else 0
vector <point> operator * (Circle a, Circle b) {
    vector <point> ret;

    point centre_a, centre_b;
    centre_a.F = a.x, centre_a.S = a.y;
    centre_b.F = b.x, centre_b.S = b.y;
    double d = Distance(centre_a, centre_b);

    if ((d > a.r + b.r) || (d < abs(a.r - b.r)))
        return ret;

    double ctan = ((a.r * a.r) - (b.r * b.r) + (d * d)) / (2.0 * d);
    double x2 = a.x + (b.x - a.x) * ctan / d;
    double y2 = a.y + (b.y - a.y) * ctan / d;
    double h = sqrt((a.r * a.r) - (ctan * ctan));
    double rx = -(b.y - a.y) * (h / d);
    double ry = (b.x - a.x) * (h / d);
    point tmp1 = {x2 + rx, y2 + ry};
    point tmp2 = {x2 - rx, y2 - ry};
    ret.pb(tmp1);
    if (tmp1 == tmp2) return ret;
    ret.pb(tmp2); return ret;
}

int ToThichCau() {
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> cir[i].x >> cir[i].y >> cir[i].r;

    if (n == 1) return cout << 2, 1;

    for (int i = 0; i < n; ++i) {
        vector <point> tmp;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            vector <point> ans = cir[i] * cir[j];
            for (auto x_inline : ans) {
                bool ok = true;
                for (auto y_inline : inters)
                    if (x_inline == y_inline) ok = false;
                if (ok) inters.pb(x_inline);
            }

            for (auto x_inline : ans) {
                bool ok = true;
                for (auto y_inline : tmp)
                    if (x_inline == y_inline) ok = false;
                if (ok) tmp.pb(x_inline);
            }
        }

        e += (int)tmp.size();
        if ((int)tmp.size() == 0) ++e;
    }

    v = (int)inters.size();
    if (v == 0) {
        if (n == 2) return cout << 3, 1;
        else return cout << 4, 1;
    }
    return cout << e + 2 - v, 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--) ToThichCau();

    return 0;
}
