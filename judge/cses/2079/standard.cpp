#include <stdio.h>
#include <vector>
using namespace std;

#define MAXN 200005

int n, f[MAXN];
vector<int> adj[MAXN];

void CountNodes(int u, int parent){
    f[u] = 1;
    for (int v: adj[u]){
        if (v == parent) continue;

        CountNodes(v, u);
        f[u] += f[v];
    }
}

int GetCentroid(int u, int parent){
    for (int v: adj[u]){
        if (v == parent) continue;

        if (f[v] > n/2){
            return GetCentroid(v, u);
        }
    }

    return u;
}

int main(){
    scanf("%d", &n);

    int u, v;
    for (int i = 1; i <= n-1; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 1;
    CountNodes(root, root);
    printf("%d\n", GetCentroid(root, root));
}