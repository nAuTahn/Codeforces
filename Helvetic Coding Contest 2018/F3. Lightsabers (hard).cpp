//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

using cd = complex<double>;
const double PI = acos(-1);

int sz;

void FFT(vector<cd> &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) for (auto & x : a) x /= n;
}

vector <ll> MULTIPLY(vector <ll>  & a, vector <ll>  & b) {
    vector <cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < (int)a.size() + (int)b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);

    FFT(fa, false); FFT(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i]; // MOD if need

    FFT(fa, true);

    vector <ll> result;
    result.resize(min((int)a.size() + (int)b.size() - 1, sz + 1));
    for (int i = 0; i < (int)result.size(); ++i) {
        result[i] = round(fa[i].real());
        result[i] %= 1009;
    }

    return result;
}

int n, m, k, x;
vector <int> cnt;

int ToThichCau() {
    cin >> n >> m >> k;

    cnt.resize(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x; cnt[x]++;
    }

    sz = k;

    vector <vector <ll>> ans(m + 1);
    for (int i = 1; i <= m; ++i) ans[i] = vector <ll> (cnt[i] + 1, 1);

    function<void(int, int)>ToYeuCau = [&](int l, int r) {
        if (l == r) return;

        int mid = (l + r) / 2;
        ToYeuCau(l, mid); ToYeuCau(mid + 1, r);
        ans[r] = MULTIPLY(ans[mid], ans[r]);
    };

    ToYeuCau(1, m);
    return cout << ans[m][k], 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--) ToThichCau();

    return 0;
}
