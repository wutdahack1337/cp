#include <stdio.h>

#define MAXN 200005

int n, a[MAXN];

long long Max(long long a, long long b){
    return a > b ? a : b;
}

int main(){
    scanf("%d", &n);

    // sort a[]
    // Kotivalo: a[1], a[2],..., a[n-1], a[n]
    // Justiina: a[2], a[3],..., a[n],   a[1]

    int mx = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);

        mx = Max(mx, a[i]);
        sum += a[i];
    }

    printf("%lld\n", Max(sum, 2*mx));
    return 0;
}