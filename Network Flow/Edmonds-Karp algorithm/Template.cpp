namespace max_flow {
    vector<int> adj[V];
    int flw[V][V], cap[V][V], trk[V];
    int src, snk;
    void add_edge(int u, int v, int f) {
        if ((cap[u][v]+=f) > f) return;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    int augment() {
        queue<ii> q; q.push({src,1e9});
        fill(trk,trk+V,0), trk[src]=-1;
        while (not empty(q)) {
            auto [s,f] = q.front(); q.pop();
            for (auto u : adj[s]) if (cap[s][u] > flw[s][u]) {
                if (trk[u]) continue;
                trk[u] = s;
                if (u == snk) return min(f,cap[s][u]-flw[s][u]);
                q.push({u,min(f,cap[s][u]-flw[s][u])});
            }
        }
        return 0;
    }
    int get() {
        int res=0, d;
        while ((d=augment())) {
            int v=snk, u=trk[v];
            res += d;
            while (v != src) {
                flw[u][v] += d;
                v=u, u=trk[u];
            }
        }
        return res;
    }
}
