#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n, cnt[20][15];
long long a[MAXN];

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> n;

    long long sum = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];

        long long clone = a[i];
        int position = 0;
        while (clone){
            int digit = clone%10;
            sum += digit;
            cnt[position][digit]++;
            clone /= 10;
            position++;
        }
    }

    long long ans = 2ll*n*sum;

    long long pow = 10;
    vector<long long> aClone;
    for (int pos = 0; pos <= 14; pos++){
        for (int i = 1; i <= n; i++){
            aClone.push_back(a[i]%pow);
        }
        sort(aClone.begin(), aClone.end());

        for (long long x: aClone){
            auto it = lower_bound(aClone.begin(), aClone.end(), pow-x);
            if (it != aClone.end()){
                int index = (it - aClone.begin());
                ans -= 9*(n - index);
            }
        }

        pow *= 10;
        aClone.clear();
    }

    cout << ans << endl;
    
    return 0;
}