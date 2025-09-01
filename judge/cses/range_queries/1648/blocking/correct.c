#include <stdio.h>

#define MAXN 200005
#define MAXF 800005

int n, q;
int arr[MAXN];
long long f[MAXF];

void Update(int id, int l, int r, int k, int u) {
    if (r < k || k < l) return;

    if (l == r) {
        f[id] = u;
        return;
    }

    int m = (l + r) / 2;
    Update(2*id+1, l, m, k, u);
    Update(2*id+2, m+1, r, k, u);

    f[id] = f[2*id+1] + f[2*id+2];
}

long long GetSum(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;

    if (u <= l && r <= v) return f[id];

    int m = (l + r) / 2;
    return GetSum(2*id+1, l, m, u, v) + GetSum(2*id+2, m+1, r, u, v);
}

int main() {
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        Update(0, 0, n-1, i, arr[i]);
    }

    while (q--) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        x -= 1;

        if (type == 1) {
            Update(0, 0, n-1, x, y);
        } else if (type == 2) {
            y -= 1;
            printf("%lld\n", GetSum(0, 0, n-1, x, y));
        }
    }

    return 0;
}
