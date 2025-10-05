#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n, m, ku[MAXN], par[MAXN], ans[MAXN], memberCnter[MAXN];
vector<int> adj[MAXN];
pair<int, int> e[MAXN];

int Find(int u){
    return par[u] == u ? u : par[u] = Find(par[u]);
}

void Join(int u, int v){
    int uPar = Find(u), vPar = Find(v);

    if (uPar != vPar){
        par[vPar] = uPar;
        memberCnter[uPar] += memberCnter[vPar];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int u = 1; u <= n; u++){
        cin >> e[u].first;
        e[u].second = u;

        ku[u] = e[u].first;

        par[u] = u;
        memberCnter[u] = 1;
    }
    sort(e + 1, e + 1 + n);

    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        if (e[i].first == e[i+1].first){
            int j = i;
            while (e[j].first == e[i].first){
                j++;
            }
            j--;

            for (int k = i; k <= j; k++){
                int u = e[k].second;
        
                for (int v: adj[u]){
                    if (ku[v] > ku[u]){
                        continue;
                    } 
                    Join(u, v);
                }
            }

            for (int k = i; k <= j; k++){
                int u = e[k].second;
                ans[u] = memberCnter[Find(u)];
            }

            i = j;
            continue;
        }

        int u = e[i].second;
        
        for (int v: adj[u]){
            if (ku[v] > ku[u]){
                continue;
            } 
            Join(u, v);
        }

        ans[u] = memberCnter[Find(u)];
    }

    for (int u = 1; u <= n; u++){
        cout << ans[u] << "\n";         
    }

    return 0;
}