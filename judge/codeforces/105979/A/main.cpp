#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int l, r, k;
    cin >> l >> r >> k;
    cout << r/k - (l-1)/k << '\n';
    
    return 0;
}