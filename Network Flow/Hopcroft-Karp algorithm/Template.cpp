int bipartite_matching() {
    int L[N]{}, R[N]{}, lev[N]{};
    auto build = [&]() {
        fill(lev,lev+n+1,0); queue<int> q;
        rep(i,1,n) if (!R[i]) lev[i] = 1, q.push(i);
        while (not empty(q)) {
            int s = q.front(); q.pop();
            for (auto u : adj[s]) if (u != R[s]) {
                int v = L[u];
                if (!v or lev[v]) continue;
                lev[v] = lev[s]+1;
                q.push(v);
            }
        }
    };
    function<bool(int)> matched = [&](int s) -> bool {
        for (auto u : adj[s]) {
            int v = L[u];
            if (!v or (lev[s]+1 == lev[v] and matched(v))) {
                R[s] = u, L[u] = s;
                return true;
            }
        }
        return false;
    };
    int res = 0;
    while (true) {
        build();
        int inc = 0;
        rep(i,1,n) if (!R[i]) {
            inc += matched(i);
        }
        if (!inc) return res;
        res += inc;
    }
}
