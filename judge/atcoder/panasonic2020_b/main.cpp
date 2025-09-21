#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    scanf("%d %d", &h, &w);

    if (h == 1 || w == 1){
        cout << 1 << endl;
        return 0;
    }

    long long a = 1ll*(h/2 + h%2)*(w/2 + w%2);
    long long b = 1ll*((h-1)/2 + (h-1)%2)*((w-1)/2 + (w-1)%2);

    cout << a + b << endl;
    return 0;
}