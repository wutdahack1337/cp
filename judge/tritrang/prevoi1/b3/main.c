#include <stdio.h>

#define ii pair<int, int>

#define MAXN 1000005

const int MOD = 1e9;

int n, h, a[MAXN], fac[MAXN];

int Pow(int x, int n){
    if (!n) return 1;

    int t = Pow(x, n/2);
    t = 1ll*t*t%MOD;

    return n%2 ? 1ll*t*x%MOD : t;
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
    
    fac[0] = 1;
    for (int i = 1; i <= 2*(n+1); i++){
        fac[i] = 1ll*fac[i-1]*i%MOD;
    }



    int ans2 = fac[2*(n+1)]/(1ll*fac[(n+1)+1]*fac[n+1]);
    printf("==%lld %lld\n", fac[2*(n+1)], (1ll*fac[(n+1)+1]*fac[n+1]));
    printf("%d\n", ans2);
 
    return 0;
}