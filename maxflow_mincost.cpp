bool FindWay(){
    priority_queue<lli, vector<lli>, greater<lli>> pq;
    pq.push({0, s});
    memset(trace, 0, sizeof(trace));
    trace[s] = s;
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;

    while (!pq.empty()){
        auto [l, u] = pq.top();
        pq.pop();

        if (l > d[u]) continue;

        for (auto [w, v]: adj[u]){
            if (capacity[u][v] - flow[u][v] > 0){
                if (l + (flow[u][v] >= 0 ? w : -w) < d[v]){
                    trace[v] = u;
                    d[v] = l + (flow[u][v] >= 0 ? w : -w);
                    pq.push({d[v], v});
                }
            }
        }
    }

    return (trace[t] != 0);
}

void Upd(){
    int u, v = t, mn = oo;
    while (v != s){
        u = trace[v];
        mn = min(mn, flow[u][v] >= 0 ? capacity[u][v] - flow[u][v] : -flow[u][v]);
        v = u;
    }

    v = t;
    while (v != s){
        u = trace[v];
        flow[u][v] += mn, flow[v][u] -= mn;
        v = u;
    }

    ans += mn*d[t];
}

int main() {
    // Xu ly dau vao

    while (FindWay()){
        Upd();
    }

    cout << ans << endl;

    return 0;
}
