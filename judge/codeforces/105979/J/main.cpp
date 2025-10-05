#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int frac[1000005];

int Pow(int x, int n){
	if (!n) return 1;

	int t = Pow(x, n/2);
	t = 1ll*t*t%MOD;

	if (n%2){
		return 1ll*t*x%MOD;
	}

	return t;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);

	frac[0] = 1;
	for (int i = 1; i <= 1000001; i++){
		frac[i] = 1ll*frac[i-1]*i%MOD;
	}

	int t; cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;

		cout << 1ll * frac[n+1] * Pow(1ll*frac[k+1]*frac[n-k]%MOD, MOD-2) % MOD << '\n';
	} 
	
	return 0;
}