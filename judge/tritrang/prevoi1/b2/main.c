#include <stdio.h>

#define BASE 200
#define MAXN 100003
#define MAXY 205

int n, c[MAXY+BASE][MAXY+BASE];
long long f[20];

int Max(int a, int b){
    return a > b ? a : b;
}

int main(){
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x += BASE, y += BASE;

        scanf("%d", &c[x][y]);
    }

    long long cnt = 0;
    for (int y1 = 0; y1 <= 400; y1++){
        for (int y2 = y1+1; y2 <= 400; y2++){
            for (int mask = 0; mask < (1 << 4); mask++){
                f[mask] = 0;
            }

            for (int x = 0; x <= 400; x++){
                if (c[x][y1] == c[x][y2] || !c[x][y1] || !c[x][y2]) continue;

                int mask = (1 << (c[x][y1]-1)) + (1 << (c[x][y2]-1));
                
                cnt += f[15 - mask];

                f[mask]++;
            }
        }
    }

    printf("%lld\n", cnt);
    return 0;
}