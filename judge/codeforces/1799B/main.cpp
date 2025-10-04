#include <bits/stdc++.h>
using namespace std;

#define oo 1000000007

int n, a[105];

void Solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if (n == 1){
        cout << 0 << endl;
        return;
    }

    // all same or has One
    bool allSame = true, hasOne = false;
    int min = oo, minIndex = -1;
    for (int i = 1; i <= n; i++){
        if (a[i] != a[1]){
            allSame = false;
        }
        if (a[i] == 1){
            hasOne = 1;
        }

        if (min > a[i]){
            min = a[i];
            minIndex = i;
        }
    }
    if (allSame){
        cout << 0 << endl;
        return;
    }
    if (hasOne){
        cout << -1 << endl;
        return;
    }

    // 
    vector<pair<int, int>> ans;
    bool hasChange = true;
    while (hasChange){
        hasChange = false;
        for (int i = 1; i <= n; i++){
            while (a[i] > min){
                ans.push_back({i, minIndex});
                a[i] = a[i]/min + (a[i]%min > 0);
            }

            if (a[i] < min){
                min = a[i], minIndex = i;
                hasChange = true;
                break;
            }
        }
    }
    
    cout << ans.size() << endl;
    for (pair<int, int> indies: ans){
        cout << indies.first << " " << indies.second << endl;
    }
}

int main(){
    freopen("input.in", "r", stdin);

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--){
        Solve();
    }

    return 0;
}