#include <bits/stdc++.h>
using namespace std;

#define MAXA 5000000

int a, b, maxPrime[MAXA+5], preSum[MAXA+5];

void Prime(){
    for (int i = 2; i*i <= MAXA; i++){
        if (maxPrime[i]) continue;

        for (int j = i; j <= MAXA; j += i){
            maxPrime[j] = i;
        }
    }

    for (int i = sqrt(MAXA); i <= MAXA; i++){
        if (maxPrime[i] == 0){
            maxPrime[i] = i;
        }
    }
}

void Solve(){
    scanf("%d %d", &a, &b);

    printf("%d\n", preSum[a] - preSum[b]);
}

int main(){
    int t;
    scanf("%d", &t);

    Prime();

    int cnt = 0, iClone;
    for (int i = 2; i <= MAXA; i++){
        cnt = 0;
        iClone = i;
        while (iClone != maxPrime[iClone]){
            cnt++;
            iClone /= maxPrime[iClone];
        }
        if (iClone > 1){
            cnt++;
        }

        preSum[i] = preSum[i-1] + cnt;
    }

    while (t--){
        Solve();
    }
    
    return 0;
}