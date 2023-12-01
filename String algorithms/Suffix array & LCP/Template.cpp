vi suffix_array(const string &s) {
    int n=siz(s);
    vi t(n), a(n), b(n);
    rep(i,0,n-1) t[i]=i, b[i]=s[i];
    for (int k=1; k<n; k*=2, b=a) {
        auto cmp=[&](int x, int y){ return ii(b[x],x+k<n ? b[x+k]:-1) < ii(b[y],y+k<n ? b[y+k]:-1); };
        sort(begin(t),end(t),cmp);
        a[t[0]]=0;
        rep(i,1,n-1) a[t[i]]=a[t[i-1]]+cmp(t[i-1],t[i]);
    }
    return t;
}

vi longest_common_prefix(const string &s, const vi &sa) {
    int n=siz(s), v=0;
    vi r(n), lcp(n-1);
    rep(i,0,n-1) r[sa[i]]=i;
    rep(i,0,n-1) if (r[i]>0) {
        int x=sa[r[i]], y=sa[r[i]-1];
        while (x+v<n && s[x+v]==s[y+v]) v++;
        lcp[r[i]-1]=v;
        v?v--:0;
    }
    return lcp;
}
