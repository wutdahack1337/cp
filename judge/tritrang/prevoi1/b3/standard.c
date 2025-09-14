#include <stdio.h>
#include <math.h>

#define ii pair<int, int>

#define MAXN 1000005

const int MOD = 1e9;

int n, h, a[MAXN], mxPrime[2*MAXN], primeCounterHigh[2*MAXN], primeCounterLow[2*MAXN];

// f[MAXN];

// int Find(int sl){
//     if (!sl) return 1;

//     if (f[sl] != -1) return f[sl];

//     int res = 0;
//     for (int nxtSl = 1; nxtSl <= sl; nxtSl++){
//         res = (res + 1ll*Find(nxtSl-1)*Find(sl - nxtSl)%MOD)%MOD;
//     }

//     return f[sl] = res;
// }

void Prepare(){
    for (int i = 2; i*i <= 2000002; i++){
        if (mxPrime[i] == 0){
            mxPrime[i] = i;
            for (int j = i; j <= 2000002; j += i){
                mxPrime[j] = i;
            }
        }
    }

    for (int i = sqrt(2000002); i <= 2000002; i++){
        if (mxPrime[i] == 0){
            mxPrime[i] = i;
        }
    }
}

int Pow(int x, int m){
    if (!m) return 1;

    int t = Pow(x, m/2);
    t = 1ll*t*t%MOD;

    return m%2 ? 1ll*t*x%MOD : t;
}

int main(){
    scanf("%d %d", &n, &h);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    int ans1 = n+1;
    for (int i = n-1; i >= 1; i--){
        if (a[i] > a[i+1]){
            ans1 = (n-i) + 1;
            break;
        }
    }
    printf("%d\n", ans1);

    n += 1;

    // The thing I want
        // for (int i = 1; i <= n; i++){
        //     f[i] = -1;
        // }
        // int ans2 = 0;
        // for (int sl = 1; sl <= n; sl++){
        //     ans2 = (ans2 + 1ll*Find(sl-1)*Find(n-sl)%MOD)%MOD;
        // }
        // printf("%d\n", ans2);    

    Prepare();

    for (int i = n+2; i <= 2*n; i++){
        int tmp = i;
        while (mxPrime[tmp] != tmp){

            primeCounterHigh[mxPrime[tmp]]++;
            tmp /= mxPrime[tmp];
        }
        primeCounterHigh[mxPrime[tmp]]++;
    }

    for (int i = 2; i <= n; i++){
        int tmp = i;
        while (mxPrime[tmp] != tmp){
            primeCounterLow[mxPrime[tmp]]++;
            tmp /= mxPrime[tmp];
        }
        primeCounterLow[mxPrime[tmp]]++;
    }

    int ans2 = 1;
    for (int i = 2; i <= 2*n; i++){
        primeCounterHigh[i] -= primeCounterLow[i];
        ans2 = 1ll*ans2*Pow(i, primeCounterHigh[i])%MOD;
    }

    printf("%d\n", ans2);

    return 0;
}