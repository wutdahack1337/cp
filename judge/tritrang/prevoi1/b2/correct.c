#include <stdio.h>
#include <math.h>

#define MAXN 100003

int n, x[MAXN], y[MAXN], c[MAXN];

int Max(int a, int b){
    return a > b ? a : b;
}

int main(){
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        scanf("%d %d %d", &x[i], &y[i], &c[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int u = 1; u <= n; u++){
            if (u == i) continue;
            for (int j = 1; j <= n; j++){
                if (j == i || j == u) continue;
                for (int v = 1; v <= n; v++){
                    if (v == i || v == u || v == j) continue;

                    if (x[i] == x[j] && y[i] == y[v] && x[u] == x[v] && y[u] == y[j] && Max(Max(c[i], c[j]), Max(c[u], c[v])) == 4 && c[i]*c[j]*c[u]*c[v] == 24){
                        ++cnt;
                    }
                }
            }
        }
    }

    printf("%d\n", cnt/4);
    return 0;
}