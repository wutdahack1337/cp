#include <bits/stdc++.h>
using namespace std;

#define MAXN 3000005
#define MOD 998244353

int n, a[MAXN], g[MAXN], f[MAXN][2];

int main(){
    freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    f[1][0] = 1;
    g[a[1]] = 1;
    for (int i = 2; i <= n; i++){
        f[i][0] = (f[i-1][0] + f[i-1][1])%MOD;
        f[i][1] = g[a[i]];

        g[a[i]] = (g[a[i]] + f[i][0])%MOD;
    }

    cout << (f[n][0] + f[n][1])%MOD << "\n";

    return 0;
}