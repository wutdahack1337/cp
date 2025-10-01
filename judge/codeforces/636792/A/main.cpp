#include <bits/stdc++.h>
using namespace std;

int n, nStr, q, posistion;
char c;
string str;

int Count(int start){
    int end = min(nStr-1, start+4);

    int res = 0;
    for (int i = start; i <= end; i++){
        if (str[i] == 'A' && str[i+1] == 'B' && str[i+2] == 'C'){
            res++;
            i += 2;
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q >> str;
    nStr = str.size();

    int ans = 0;
    for (int i = 0; i <= n-3; i++){
        if (str[i] == 'A' && str[i+1] == 'B' && str[i+2] == 'C'){
            ans++;
            i += 2;
        }
    }

    while (q--){
        cin >> posistion >> c;
        posistion--;
        
        int start = max(0, posistion-2);
        int cnt = Count(start);
        str[posistion] = c;

        int diff = Count(start) - cnt;
        ans += diff;

        cout << ans << '\n';
    }

    return 0;
}