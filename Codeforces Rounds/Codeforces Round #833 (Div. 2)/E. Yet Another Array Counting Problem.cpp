//	OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define F first
#define S second
typedef pair <int, int> pii;
typedef vector <ll> vl;
typedef vector <vl> vll;
typedef vector <pii> vpii;

const int MAXN = 2e5 + 7;
const int MOD = 1e9 + 7;

int n, m;
int a[MAXN];
vector <vl> cur;

class ST{
public:
    pii t[4 * MAXN];

    void Build(int i, int j, int pos, int a[]) {
        if (i == j) {t[pos] = {a[i], -i}; return;}

        int mid = (i + j) / 2;

        Build(i, mid, pos * 2, a);
        Build(mid + 1, j, pos * 2 + 1, a);

        t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
    }

    pii Query(int i, int j, int pos, int a, int b) {
        if (a > j || b < i) return {-INT_MAX, INT_MAX};
        if (a <= i && b >= j) return t[pos];

        int mid = (i + j) / 2;

        pii l = Query(i, mid, pos * 2, a, b);
        pii r = Query(mid + 1, j, pos * 2 + 1, a, b);

        return max(l, r);
    }
};

ST segg;

ll ToYeuCau(int x, int y, int i) {
    if (x > y) return 1;
    if (i <= 0) return 0;

    int j = -segg.Query(1, n, 1, x, y).S;
    ll &res = cur[j][i];
    if (res != -1) return res;

    return res = (ToYeuCau(x, y, i - 1) + (ToYeuCau(x, j - 1, i - 1) % MOD) * (ToYeuCau(j + 1, y, i)) % MOD) % MOD;
}

void ToThichCau() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    segg.Build(1, n, 1, a);

    cur = vll(n + 1, vl(m + 1, -1));
    cout << ToYeuCau(1, n, m) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test; cin >> test;
    while(test--) ToThichCau();

    return 0;
}
