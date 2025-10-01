#include <bits/stdc++.h>
using namespace std;

long long n;

bool Check(long long x){
    long long xClone = x;

    long long y = 0;
    while (xClone){
        y = y*10 + xClone%10;
        xClone /= 10;
    }

    return x == y;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    long long ans = 0;
    for (int i = 1; 1ll*i*i*i <= n; i++){
        if (Check(1ll*i*i*i)){
            ans = 1ll*i*i*i;
        }
    }

    cout << ans << '\n';
    return 0;
}