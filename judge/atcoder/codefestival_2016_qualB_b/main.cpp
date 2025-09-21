#include <bits/stdc++.h>
using namespace std;

int n, a, b;
string str;

int main(){
    scanf("%d %d %d", &n, &a, &b);
    cin >> str;

    int total = 0;
    int cntOverseas = 0;

    char chr;
    for (int i = 0; i < n; i++){
        chr = str[i];
        
        if (chr == 'c'){
            printf("No\n");
            continue;
        }
            
        if (chr == 'a' && total < a + b){
            printf("Yes\n");
            total++;
        } else
        if (chr == 'b' && total < a + b && cntOverseas < b){
            printf("Yes\n");
            total++;
            cntOverseas++;
        } else {
            printf("No\n");
        }
    }

    return 0;
}