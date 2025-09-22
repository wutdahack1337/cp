#include <bits/stdc++.h>
using namespace std;

int main(){
    int x[10];
    for (int i = 1; i <= 7; i++){
        scanf("%d", &x[i]);
    }
    sort(x + 1, x + 1 + 7);

    int a = x[1], b = x[2], c = x[7]-a-b;

    printf("%d %d %d\n", a, b, c);
    
    return 0;
}