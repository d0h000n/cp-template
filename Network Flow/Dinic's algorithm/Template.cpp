template <const int V, typename T, const T INF>
struct max_flow {
    vector<int> adj[V], ldj[V];
    int src, snk;
    T cap[V][V], flw[V][V];
    max_flow(int s, int t): src(s), snk(t) {}
    void add(int u, int v, T f) {
        if (!f or (cap[u][v]+=f) > f or cap[v][u]) return;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    T dfs(int s, T a=INF) {
        if (s == snk) return a;
        for (;not empty(ldj[s]); ldj[s].pop_back()) {
            int u = ldj[s].back();
            if (cap[s][u] <= flw[s][u]) continue;
            T r = dfs(u, min(a,cap[s][u]-flw[s][u]));
            if (r > 0) {
                flw[s][u] += r;
                flw[u][s] -= r;
                return r;
            }
        }
        return 0;
    }
    bool bfs() {
        queue<int> q; int dist[V];
        fill(dist,dist+V,int(1e9)), dist[src]=0;
        rep(i,0,V-1) ldj[i].clear();
        q.push(src);
        while (not empty(q)) {
            int s = q.front(); q.pop();
            for (auto u : adj[s]) {
                if (cap[s][u] <= flw[s][u]) continue;
                if (dist[u] == int(1e9)) dist[u] = dist[s]+1, q.push(u);
                if (dist[u] == dist[s]+1) ldj[s].push_back(u);
            }
        }
        return dist[snk] != int(1e9);
    }
    T get() {
        T res = 0;
        while (bfs()) {
            for (T d; (d=dfs(src));) {
                res += d;
            }
        }
        return res;
    }
};
