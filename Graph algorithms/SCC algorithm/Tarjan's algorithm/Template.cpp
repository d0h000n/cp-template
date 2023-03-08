namespace scc {
    int num, of[N], in[N], out[N];
    vector<int> nodes[N], cdj[N];
    int t, ord[N]; stack<int> stk; bool vis[N];
    int tarjan(int s) {
        if (vis[s]) return of[s] ? 1e9 : ord[s];
        vis[s] = true, stk.push(s);
        int r = ord[s] = ++t;
        for (auto u : adj[s]) mup(r, tarjan(u));
        if (r == ord[s]) {
            ++num;
            while (not empty(stk)) {
                int u = stk.top(); stk.pop();
                nodes[of[u] = num].push_back(u);
                if (u == s) break;
            }
        }
        return r;
    }
    void build() {
        rep(u,1,n) tarjan(u);
        rep(u,1,n) for (auto v : adj[u]) {
            if (of[u] != of[v]) {
                in[of[v]]++, out[of[u]]++;
                cdj[of[u]].push_back(of[v]);
            }
        }
    }
}
