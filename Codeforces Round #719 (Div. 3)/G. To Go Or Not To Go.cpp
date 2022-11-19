//    OniGirichan
//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2003;
const ll INF = 1000000000000000000LL;
typedef pair <int, int> pii;
#define F first
#define S second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, w;
int a[MAXN][MAXN];
ll ans;

ll DP1[MAXN][MAXN];
ll DP2[MAXN][MAXN];

void BFS(ll d[MAXN][MAXN], int sx, int sy) {
    queue <pii> q;
    q.push({sx, sy});
    d[sx][sy] = 0;
    while(!q.empty()) {
        pii tmp;
        tmp = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = tmp.F + dx[i];
            int y = tmp.S + dy[i];
            if (x && (x <= n) && y && (y <= m) && a[x][y] != -1 && d[x][y] == INF) {
                d[x][y] = d[tmp.F][tmp.S] + w;
                q.push({x, y});
            }
        }
    }
}

int ToThichCau(){
    cin >> n >> m >> w;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            DP1[i][j] = INF, DP2[i][j] = INF;

    BFS(DP1, 1, 1);
    BFS(DP2, n, m);

    ans = DP1[n][m];
    ll FF = INF, SS = INF;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] > 0 && DP1[i][j] != INF)
                FF = min(FF, DP1[i][j] + a[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] > 0 && DP2[i][j] != INF)
                SS = min(SS, DP2[i][j] + a[i][j]);

    ans = min(ans, FF + SS);
    if (ans == INF)
        return cout << "-1", 0;

    return cout << ans, 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--)
        ToThichCau();

    return 0;
}
