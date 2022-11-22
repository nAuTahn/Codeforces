//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back

const int MAXN = 1e5 + 7;

struct node {
    int l, r, num;
};

int n, m, k;
int a[MAXN];
int cnt[MAXN * 50];
ll S = 0, SQRT;
ll ans[MAXN];
vector <node> q;

//    Chia căn, lần đầu code :((

void add(int x) {
    S += cnt[x];
    cnt[x ^ k]++;
}

void del(int x) {
    cnt[x ^ k]--;
    S -= cnt[x];
}

int ToThichCau() {
    cin >> n >> m >> k;

    SQRT = (int)sqrt(m);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    int l, r;
    for (int i = 1; i <= m; ++i) {
        cin >> l >> r;
        --l;
        q.pb({l, r, i});
    }
    sort(q.begin(), q.end(), [&](node x, node y)
    {
        if (x.l / SQRT == y.l / SQRT) return x.r < y.r;
        return x.l < y.l;
    });

    l = 1, r = 0;
    for (auto i : q) {
        while(l > i.l) add(a[--l]);
        while(r < i.r) add(a[++r]);
        while(l < i.l) del(a[l++]);
        while(r > i.r) del(a[r--]);
        ans[i.num] = S;
    }

    for (int i = 1; i <= m; ++i) cout << ans[i] << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--) ToThichCau();

    return 0;
}
