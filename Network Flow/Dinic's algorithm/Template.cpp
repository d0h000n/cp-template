namespace max_flow {
    const int V = 503, INF = 1e9;
    vector<int> adj[V];
    int src, snk;
    int cap[V][V], flw[V][V], idx[V], dist[V];
    void add(int u, int v, int f) {
        if ((cap[u][v]+=f) > f) return;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    int dfs(int a=INF, int s=src) {
        if (s == snk) return a;
        for (int u; idx[s] < siz(adj[s]); ++idx[s]) {
            u = adj[s][idx[s]];
            if (cap[s][u] <= flw[s][u]) continue;
            if (dist[s]+1 != dist[u]) continue;
            int r = dfs(min(a,cap[s][u]-flw[s][u]), u);
            if (r > 0) {
                flw[s][u] += r;
                flw[u][s] -= r;
                return r;
            }
        }
        return 0;
    }
    bool bfs() {
        queue<int> q;
        fill(dist,dist+snk+1,INF), dist[src]=0;
        bool vis[V]{};
        vis[src] = true, q.push(src);
        while (not empty(q)) {
            int s = q.front(); q.pop();
            for (auto u : adj[s]) {
                if (cap[s][u] <= flw[s][u]) continue;
                if (vis[u]) continue;
                vis[u] = true;
                dist[u] = dist[s]+1;
                q.push(u);
            }
        }
        return vis[snk];
    }
    int get() {
        ll res = 0;
        while (bfs()) {
            int d;
            fill(idx,idx+snk+1,0);
            while ((d=dfs())) {
                res += d;
            }
        }
        return res;
    }
}
