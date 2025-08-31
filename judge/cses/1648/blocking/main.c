#include <stdio.h>
#include <math.h>

#define MAXN 200005
#define MAXBLOCK 450

int n, q, nBlock, x[MAXN];
long long block[MAXBLOCK];

void Init(){
    nBlock = ceil(sqrt(n));
    for (int i = 0; i < nBlock; i++){
        for (int j = i*nBlock+1; j <= i*nBlock + nBlock; j++){
            block[i] += x[j];
        }
    }
}

void Update(int k, int u){
    int blockIndex = (k-1)/nBlock;
    int diff = u - x[k];

    x[k] += diff;
    block[blockIndex] += diff;
}

int Min(int a, int b){
    return a < b ? a : b;
}

long long GetSum(int l, int r){
    long long res = 0;

    int blockIndex;
    for (int i = l; i <= r;){
        if (i%nBlock==1 && i+nBlock-1 <= r){
            blockIndex = (i-1)/nBlock;
            res += block[blockIndex];
            i += nBlock;
        } else {
            res += x[i];
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

    Init();

    int type, a, b;
    while (q--){
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1){
            Update(a, b);
        } else
        if (type == 2){
            printf("%lld\n", GetSum(a, b));
        }
    }

    return 0;
}