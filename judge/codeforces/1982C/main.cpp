#include <bits/stdc++.h>
using namespace std;

int a[100005];

void Solve(){
    int n, low, high;
    cin >> n >> low >> high;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int ans = 0;
    int i = 1, sum = 0;
    for (int j = 1; j <= n; j++){
        sum += a[j];

        while (sum > high){
            sum -= a[i];
            i++;
        }

        if (low <= sum && sum <= high){
            ans++;
            sum = 0;
            i = j+1;
            continue;
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--){
        Solve();
    }
    
    return 0;
}