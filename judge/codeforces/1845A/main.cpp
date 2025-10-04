#include <bits/stdc++.h>
using namespace std;

void Solve(){
	int n, k, x;
	cin >> n >> k >> x;
	
	if (k == 1){
		cout << "NO\n";
		return;
	}

	if (x != 1){
		cout << "YES\n" << n << "\n";
		for (int i = 1; i <= n; i++){
			cout << 1 << " ";
		}
		cout << "\n";
		return;
	}

	if (k == 2){
		// x == 1
		if (n%2){
			cout << "NO\n";
			return;
		} else {
			cout << "YES\n" << n/2 << "\n";
			for (int i = 1; i <= n/2; i++){
				cout << 2 << " ";
			}
			cout << "\n";
			return;
		}
	} else { // k >= 3
		// x == 1
		cout << "YES\n" << n/2 << "\n";
		if (n%2){
			n -= 3;
			cout << 3 << " ";
		}
		for (int i = 1; i <= n/2; i++){
			cout << 2 << " ";
		}
		return;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		Solve();
	}
	
	return 0;
}