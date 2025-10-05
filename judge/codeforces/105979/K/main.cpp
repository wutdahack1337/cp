#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005], b[100005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    sort(b + 1, b + 1 + n);

    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (k >= a[i] + b[i]){
            ans++;
            k -= a[i] + b[i];
        }
    }

    cout << ans << "\n";
}