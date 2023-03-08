namespace scc {
    int num, of[N], in[N], out[N];
    vector<int> nodes[N], cdj[N];
    vector<int> rdj[N]; stack<int> stk; bool vis[N];
    void dfs1(int s) {
        if (vis[s]) return;
        vis[s] = true;
        for (auto u : adj[s]) dfs1(u);
        stk.push(s);
    }
    void dfs2(int s) {
        if (vis[s]) return;
        vis[s] = true;
        nodes[of[s] = num].push_back(s);
        for (auto u : rdj[s]) dfs2(u);
    }
    void build() {
        rep(u,1,n) for (auto v : adj[u]) rdj[v].push_back(u);
        rep(u,1,n) dfs1(u);
        fill(vis+1,vis+n+1,0);
        while (not empty(stk)) {
            int u = stk.top(); stk.pop();
            if (not vis[u]) ++num, dfs2(u);
        }
        rep(u,1,n) for (auto v : adj[u]) {
            if (of[u] != of[v]) {
                in[of[v]]++, out[of[u]]++;
                cdj[of[u]].push_back(of[v]);
            }
        }
    }
}
