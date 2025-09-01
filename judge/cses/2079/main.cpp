#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MAXN 200005

int n, f[MAXN];
vector<int> adj[MAXN];

void CountNodes(int u, int parent){
    f[u] = 1;

    bool descendantOk = true;

    for (int v: adj[u]){
        if (v == parent) continue;

        CountNodes(v, u);
        f[u] += f[v];

        if (f[v] > n/2){
            descendantOk = false;
        }
    }

    if (descendantOk && n-f[u] <= n/2){
        printf("%d\n", u);
        exit(0);
    }
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
}