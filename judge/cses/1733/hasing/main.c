#include <stdio.h>

#define MAXN 1000003

const int BASE = 29;
const int MOD1 = 1000000007, MOD2 = 1000000009;

char str[MAXN], tmpStr[MAXN];
int n, preHash[MAXN], basePow[MAXN];

int Pow(int x, int n){
    if (!n) return 1;

    int t = Pow(x, n/2);
    t = 1ll*t*t%MOD1;

    return n%2 ? 1ll*t*x%MOD1 : t;
}

int GetHash(int l, int r){
    return (preHash[r+1] - (1ll*preHash[l]*basePow[r-l+1]%MOD1) + MOD1)%MOD1;
}

int main(){
    scanf("%s", &str);

    basePow[0] = 1;
    preHash[0] = 0;
    n = 0;
    for (; str[n] != '\0'; n++){
        preHash[n+1] = (1ll*preHash[n]*BASE%MOD1 + str[n])%MOD1;
        basePow[n+1] = 1ll*basePow[n]*BASE%MOD1;
    }

    int cloneHash, l, r, lrHash;
    for (int len = 1; len <= n; len++){
        l = 0, r = len-1;
        lrHash = GetHash(l, r);

        cloneHash = 0;
        for (int i = n/len; i >= 1; i--){
            cloneHash = (1ll*cloneHash*basePow[r-l+1]%MOD1 + lrHash)%MOD1;
        }

        r = n%len - 1;
        cloneHash = (1ll*cloneHash*basePow[r-l+1]%MOD1 + GetHash(l, r))%MOD1;
        
        if (cloneHash == preHash[n]){
            printf("%d ", len);
        }
    }

    return 0;
}