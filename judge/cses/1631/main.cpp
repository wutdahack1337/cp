#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n, a[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> kHeap;
priority_queue<pair<int, int>> jHeap;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    if (n == 1){
        printf("%d\n", a[1]*2);
        return 0;
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        kHeap.push({a[i], i});
        jHeap.push({a[i], i});
    }

    int kBook = kHeap.top().second;
    long long kTimer = kHeap.top().first;
    kHeap.pop();
    int jBook = jHeap.top().second;
    long long jTimer = jHeap.top().first;
    jHeap.pop();

    pair<int, int> x, y;
    while (!kHeap.empty() || !jHeap.empty()){
        if (kTimer <= jTimer && !kHeap.empty()){
            x = kHeap.top();
            kHeap.pop();

            if (kTimer < jTimer && x.second == jBook){
                if (kHeap.empty()){ // Nếu hết sách -> Đợi
                    kTimer = jTimer;
                } else { // Nếu còn sách thì cứ đọc cuốn tiếp theo
                    y = kHeap.top();
                    kHeap.pop();

                    kBook = y.second, kTimer += y.first;
                }

                kHeap.push(x);
            } else {
                kBook = x.second, kTimer += x.first;
            }
        } else {
            x = jHeap.top();
            jHeap.pop();

            if (jTimer < kTimer && x.second == kBook){
                if (jHeap.empty()){ // Nếu hết sách -> Đợi
                    jTimer = kTimer;
                } else { // Nếu còn sách thì cứ đọc cuốn tiếp theo
                    y = jHeap.top();
                    jHeap.pop();

                    jBook = y.second, jTimer += y.first;
                }

                jHeap.push(x);
            } else {
                jBook = x.second, jTimer += x.first;
            }
        }
    }

    printf("%lld\n", max(kTimer, jTimer));

    return 0;
}