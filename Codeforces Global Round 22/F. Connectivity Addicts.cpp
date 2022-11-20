//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1005;

int n;

class DSU{
public:
    vector <int> P, S;

    DSU(int m) {
        P.resize(m + 1); S.resize(m + 1, 1);
        for (int i = 1; i <= m; ++i) P[i] = i;
    }

    int Find(int t) {
        if (t == P[t]) return t;
        return P[t] = Find(P[t]);
    }

    bool Merge(int a, int b) {
        a = Find(a); b = Find(b);
        if (a == b) return 0;

        if (S[a] < S[b]) swap(a, b);

        S[a] += S[b];
        P[b] = a;

        return 1;
    }

    int Cmp(int a, int b) {return Find(a) == Find(b);}
};

int ask(int u) {
    cout << "? " << u << endl;
    int x; cin >> x;
    return x;
}

void ans(vector <int> u, int m) {
    cout << "!";
    for (int i = 1; i <= m; ++i) cout << ' ' << u[i];
    cout << endl;
}

void ToThichCau() {
    cin >> n;

    vector <int> deg(n + 1);
    for (int  i = 1; i <= n; ++i) cin >> deg[i];

    DSU d(n + 1);
    vector <int> used(n + 1);

    while(1) {
        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            if (used[i]) continue;
            if (mx == 0) mx = i;
            if (deg[i] > deg[mx]) mx = i;
        }

        if (mx == 0) break;
        int confl = 0;
        for (int i = 0; i < deg[mx]; ++i) {
            int nxt = ask(mx);
            if (used[nxt]) {confl = nxt; break;}
            else d.Merge(mx, nxt);
        }
        int tmp = d.Find(mx);
        for (int i = 1; i <= n; ++i)
            if (d.Find(i) == tmp)
                used[i] = 1;
        if (confl != 0) d.Merge(mx, confl);
    }

    vector <int> kq(n + 1);
    for (int i = 1; i <= n; ++i) kq[i] = d.Find(i);

    ans(kq, n);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test; cin >> test;
    while(test--) ToThichCau();

    return 0;
}
