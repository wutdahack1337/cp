#include <bits/stdc++.h>
#define bit(x, i) (((x) >> (i)) & 1)

using namespace std;
using ll = long long int;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const ll inf = 1e18;
using pll = pair<ll, ll>;

int n, ans;

bool Check(int num){
    bool have3 = 0, have5 = 0, have7 = 0;
    while (num > 0){
        if (num%10 == 3){
            have3 = 1;
        } else
        if (num%10 == 5){
            have5 = 1;
        } else 
        if (num%10 == 7){
            have7 = 1;
        }

        num /= 10;
    }

    return have3 && have5 && have7;
}

void Solve(long long num){
    if (num > n){
        return;
    }

    if (Check(num)){
        ans++;
    }

    Solve(num*10 + 3);
    Solve(num*10 + 5);
    Solve(num*10 + 7);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("TASK.inp", "r", stdin);
        freopen("TASK.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    Solve(0);
    cout << ans << "\n";
}