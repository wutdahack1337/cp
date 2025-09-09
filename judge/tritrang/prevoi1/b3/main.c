#include <stdio.h>

#define ii pair<int, int>

#define MAXN 1000005

const int MOD = 1e9;

int n, h, a[MAXN];
int nB, nC, b[MAXN], c[MAXN];

int GCD(int a, int b){
    if (!b) return a;
    return GCD(b, a%b);
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
    for (int i = n+2; i <= 2*n; i++){
        b[++nB] = i;
    }
    for (int i = 2; i <= n; i++){
        c[++nC] = i;
    }

    for (int i = 1; i <= nB; i++){
        for (int j = 1; j <= nC; j++){
            int gcd = GCD(b[i], c[j]);
            b[i] /= gcd;
            c[j] /= gcd;
        }
    }

    unsigned long long ans2 = 1;
    for (int i = 1; i <= nB; i++){
        ans2 = 1ll*ans2*b[i]%MOD;
    }
    printf("%lld\n", ans2);

    return 0;
}