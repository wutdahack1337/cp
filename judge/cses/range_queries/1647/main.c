#include <stdio.h>
#include <math.h>

#define MAXN     200005
#define MAXBLOCK 505

int n, q, x[MAXN];
int blockSize, block[MAXBLOCK];

const int oo = 1e9+7;

int Min(int a, int b){
    return a < b ? a : b;
}

void InitBlocking(){
    blockSize = ceil(sqrt(n));

    for (int i = 0; i <= (n-1)/blockSize; i++){
        block[i] = oo;
        for (int j = Min(n, (i+1)*blockSize); j >= i*blockSize+1; j--){
            block[i] = Min(block[i], x[j]);
        }
    }
}

int GetMin(int l, int r){
    int res = oo;
    for (int i = l; i <= r; ){
        if (i%blockSize == 1 && i+blockSize-1 <= r){
            res = Min(res, block[(i-1)/blockSize]);
            i += blockSize;
        } else {
            res = Min(res, x[i]);
            i++;
        }
    }
    return res;
}

int main(){
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x[i]);
    }

    InitBlocking();

    int l, r;
    while (q--){
        scanf("%d %d", &l, &r);
        printf("%d\n", GetMin(l, r));
    }

    return 0;
}