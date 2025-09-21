#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int n, x, a[MAXN];

int main(){
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (x >= a[i]){
            cnt++;
            x -= a[i];
        } else {
            x = 0;
            break;
        }
    }

    if (cnt > 0 && x > 0){
        cnt--;
    }

    printf("%d\n", cnt);

    return 0;
}