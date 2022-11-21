//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2507;
const ll Bound = 2501;

int n, m, q;
ll f[MAXN][MAXN];

void Update(int x, int y, ll val) {
    for (int i = x; i <= n; i += (i & (-i)))
        for (int j = y; j <= m; j += (j & (-j)))
            f[i][j] += val;
}

ll Query(int x, int y) {
    ll ans = 0;
    for (int i = x; i; i -= (i & (-i)))
        for (int j = y; j; j -= (j & (-j)))
            ans += f[i][j];
    return ans;
}

void add(int x1, int y1, int x2, int y2, ll t) {
    Update(x1, y1, t);
    Update(x2 + 1, y2 + 1, t);
    Update(x2 + 1, y1, -t);
    Update(x1, y2 + 1, -t);
}


int ToThichCau() {
    cin >> n >> m >> q;

    while(q--) {
        ll t, r1, c1, r2, c2;
        cin >> t >> r1 >> c1 >> r2 >> c2;
        ll tmp = 1LL * r1 + 1LL * c1 * Bound + 1LL * r2 * (Bound * Bound) + 1LL * c2 * (Bound * Bound * Bound);
        if (t == 1) add(r1, c1, r2, c2, tmp);
        else if (t == 2) add(r1, c1, r2, c2, -tmp);
        else {
            if (Query(r1, c1) == Query(r2, c2)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--) ToThichCau();


    return 0;
}
