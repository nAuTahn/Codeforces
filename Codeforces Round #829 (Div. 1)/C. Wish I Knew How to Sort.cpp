//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

const ll MAXN = 2e5 + 7;
ll n;
ll a[MAXN];
ll S = 0;

ll Pow(ll a, ll b) {
    a %= MOD; b %= MOD;
    ll ans = 1;
    for(; b; b >>= 1, a = a * a % MOD)
        if (b & 1) ans = ans * a % MOD;
    return ans;
}

ll inv(ll x) {
    return Pow(x, MOD - 2);
}

ll C2(ll p) {
    return 1LL * p * (p - 1) / 2;
}

int ToThichCau() {
    cin >> n;
    S = 0;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i]; S += a[i];
    }

    ll T = 0;
    for (ll i = 1; i <= n - S; ++i) T += a[i];

    ll ans = 0;
    for (ll i = 1; i <= T; ++i)
        ans = (ans + (C2(n) % MOD) * inv(i * i)) % MOD;

    return cout << ans << "\n", 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test; cin >> test;
    while(test--) ToThichCau();

    return 0;
}
