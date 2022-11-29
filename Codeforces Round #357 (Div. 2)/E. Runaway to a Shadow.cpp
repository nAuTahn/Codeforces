//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define epsilon 1e-6
#define F first
#define S second

const ll INF = 10000000000LL;
const int MAXN = 1e5 + 7;
const double PI = acos(-1.00);

typedef pair <double, double> point;

int n;
double v, T, D;
double x_0, y_0, x, y, r;

vector <point> listP;
double sum = 0, last = 0;

double Dis(double a, double b) {
    return a * a + b * b;
}

point spire () {
    double dis = Dis(x, y);

    if (dis > (D + r) * (D + r)) return {0.00, 0.00};

    double check_cos = (r * r + dis - D * D) / (2 * r * sqrt(dis));
    check_cos = acos(check_cos);

    double check_cos2 = r / sqrt(dis);
    check_cos2 = PI / 2 - asin(check_cos2);

    if (D > sqrt(dis + r * r)) check_cos = INF;

    if (check_cos < check_cos2) {
        check_cos = (D * D + dis - r * r) / (2 * D * sqrt(dis));
        check_cos = acos(check_cos);
    }
    else {
        check_cos = r / sqrt(dis);
        check_cos = asin(check_cos);
    }

    double ang = atan2(y, x);
    double tmp1 = ang - check_cos, tmp2 = ang + check_cos;

    tmp1 += 4 * PI, tmp2 += 4 * PI;
//    Mod Pi
    while(tmp1 > PI) tmp1 -= 2 * PI;
    while(tmp2 > PI) tmp2 -= 2 * PI;

    if (tmp1 > tmp2) swap(tmp1, tmp2);
    return {tmp1, tmp2};
}


int ToThichCau() {
    cin >> x_0 >> y_0 >> v >> T >> n;

    D = v * T;

    for (int i = 1; i <= n; ++i) {
        cin >> x >> y >> r;
        x -= x_0; y -= y_0; //move

        if (r * r - x * x - y * y >= 0)
            return cout << "1.000000", 1;

        point upd = spire();

        if (upd.S - upd.F <= PI) listP.pb(upd);
        else {
            listP.pb({upd.S, PI});
            listP.pb({-PI, upd.F});
        }
    }

    sort(listP.begin(), listP.end());

    sum = 0.00; last = -PI;

    for (auto & t : listP) {
        last = max(last, t.F);
        sum += max(0.00, t.S - last);
        last = max(last, t.S);
    }

    return cout << sum / (2 * PI), 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--) ToThichCau();

    return 0;
}
