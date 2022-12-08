//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
typedef pair <int, int> pii;
typedef long long ll;
const int INF = 1e9 + 7;
const int MAXN = 5e5 + 7;
#define ls rt << 1
#define rs rt << 1 | 1

int n, m;
int a[MAXN];
int tmp[MAXN], ans[MAXN];
vector<pii> que[MAXN];
map <int, int> tick;

//    Persistent Segment Tree
int t[4 * MAXN];

void Update(int rt, int l, int r, int pos, int v) {
    if (l != r && t[rt] == INF) t[ls] = t[rs] = INF;
    t[rt] = min(t[rt], v);

    if (l == r) return;

    int mid = (l + r) / 2;
    if (pos <= mid) Update(ls, l, mid, pos, v);
    else Update(rs, mid + 1, r, pos, v);
}

int Query(int rt, int l, int r, int X) {
    if (l != r && t[rt] == INF) t[ls] = t[rs] = INF;

    if (X > r) return INF;
    if (l >= X) return t[rt];

    int mid = (l + r) / 2;
    return min(Query(ls, l, mid, X), Query(rs, mid  + 1, r, X));
}

int ToThichCau() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    t[1] = INF;

    int l, r;
    for (int i = 1; i <= m; ++i)
    {
        cin >> l >> r;
        que[r].pb({l, i});
    }

    for (int i = n; i >= 1; --i)
        tmp[tick[a[i]]] = i, tick[a[i]] = i;

    for (int i = 1; i <= n; ++i) {
        if (tmp[i]) Update(1, 1, n, tmp[i], i - tmp[i]);
        for (auto &t : que[i])
            ans[t.S] = Query(1, 1, n, t.F);
    }

    for (int i = 1; i <= m; ++i)
        cout << (ans[i] == INF? -1 : ans[i]) << "\n";
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--) ToThichCau();

    return 0;
}
