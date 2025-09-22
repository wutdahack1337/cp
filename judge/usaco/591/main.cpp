#include <bits/stdc++.h>
using namespace std;

int before[6], after[6];

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    for (int i = 1; i <= 4; i++){
        cin >> before[i] >> after[i];
    }

    int ans3 = after[4] - before[4];
    int ans2 = after[3] - (before[3]-ans3);
    int ans1 = after[2] - (before[2]-ans2);

    cout << ans1 << "\n" << ans2 << "\n" << ans3 << "\n";
    return 0;
}