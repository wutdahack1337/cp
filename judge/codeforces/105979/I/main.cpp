#include <bits/stdc++.h>
using namespace std;

long long fibo[50];

int main(){
    // freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    fibo[1] = 1;
    fibo[2] = 2;
    for (int i = 3; i <= 44; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    cout << fibo[44] << endl;

    int t; cin >> t;
    while (t--){
        int x, k;
        cin >> x >> k;

        for (int i = 1; i <= 44; i++){
            if (fibo[i]*x >= k){
                cout << i << "\n";
                break;
            }
        }
    }
    
    return 0;
}