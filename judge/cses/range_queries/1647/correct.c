#include <stdio.h>
#include <math.h>

#define MAXN     200005
#define MAXBLOCK 505

int n, q, x[MAXN];

const int oo = 1e9+7;

int Min(int a, int b){
    return a < b ? a : b;
}

int GetMin(int l, int r){
    int res = oo;
    for (int i = l; i <= r; i++){
        res = Min(res, x[i]);
    }
    return res;
}

int main(){
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x[i]);
    }

    int l, r;
    while (q--){
        scanf("%d %d", &l, &r);
        printf("%d\n", GetMin(l, r));
    }

    return 0;
}