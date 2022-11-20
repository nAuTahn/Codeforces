//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back

const int MAXN = 2e5 + 7;

int n;
int a[MAXN], s[MAXN];
vector <int> f[MAXN];

void Update(int p, int val) {
    for (; p <= n; p += (p & (-p))) s[p] += val;
}

ll Query(int p) {
    int sum = 0;
    for (; p; p -= (p & (-p))) sum += s[p];
    return sum;
}

int ToThichCau() {
    cin >> n;

    int t;
    for (int i = 1; i <= n; ++i) {
        cin >> t; f[t].pb(i);
    }

    ll ans = 0;
    int l = 1, r = n;
    for (int i = n; i > 0; --i) {
        if ((int)f[i].size()) {
            int L = f[i][0], R = f[i].back();
            for (int j = 0; j < (int)f[i].size(); ++j)
                Update(f[i][j], 1);
            int tmp = l;
            l = min(L, r + 1);
            r = max(R, tmp - 1);
            ans += (Query(r) - Query(l - 1));
        }
    }

    return cout << ans, 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--) ToThichCau();

    return 0;
}
