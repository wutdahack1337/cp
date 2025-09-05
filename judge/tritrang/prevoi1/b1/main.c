#include <stdio.h>

#define MAXN 1003

int n, k, a[MAXN][MAXN], f[MAXN][MAXN];

int Max(int a, int b){
    return a > b ? a : b;
}

int main(){
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++){
        int x = i + k - 1;
        if (x > n){
            break;
        }
        for (int j = 1; j <= n; j++){
            int y = j + k - 1;
            if (y > n){
                break;
            }
            
            mx = Max(mx, f[x][y] - f[x][j-1] - f[i-1][y] + f[i-1][j-1]);
        }
    }

    printf("%d\n", mx);

    return 0;
}