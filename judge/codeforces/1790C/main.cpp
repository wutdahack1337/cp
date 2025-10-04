#include <bits/stdc++.h>
using namespace std;

int arr[105][105];

void Solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n-1; j++){
            cin >> arr[i][j];
        }
    }


    for (int i = 1; i <= n; i++){
        int cntDiff = 0;
        for (int j = 1; j <= n; j++){
            if (j == i){
                continue;
            }
            cntDiff += (arr[i][1] != arr[j][1]);
        }

        if (cntDiff == 1){
            continue;
        }

        if (i == 1){
            cout << arr[i+1][1] << " ";
            for (int j = 1; j <= n-1; j++){
                cout << arr[i][j] << " ";
            }
            break;
        }

        cout << arr[i-1][1] << " ";
        for (int j = 1; j <= n-1; j++){
            cout << arr[i][j] << " ";
        }   
        break;
    }

    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int  t; cin >> t;
    while (t--){
        Solve();
    }
    
    return 0;
}