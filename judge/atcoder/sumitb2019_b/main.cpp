#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int x = ceil(n/1.08);

    if ((int)(x*1.08) == n){
        printf("%d\n", x);
    } else {
        printf(":(");
    }

    return 0;
}