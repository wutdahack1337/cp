#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int next_a, next_b, next_c;
    int cnt = 0;
    while (a%2 == 0 && b%2 == 0 && c%2 == 0){
        cnt++;
        next_a = (b+c)/2;
        next_b = (a+c)/2;
        next_c = (a+b)/2;

        a = next_a;
        b = next_b;
        c = next_c;

        if (a == b && b == c){
            printf("-1");
            return 0;
        }
    }

    printf("%d\n", cnt);
    return 0;
}