#include <bits/stdc++.h>
using namespace std; using ii = pair<int,int>; using ll = long long; using vi = vector<int>;
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define per(i,a,b) for (auto i = (b); i >= (a); --i)
#define all(x) begin(x), end(x)
#define siz(x) int((x).size())
#define Mup(x,y) x = max(x,y)
#define mup(x,y) x = min(x,y)
#define fi first
#define se second
#define dbg(...) fprintf(stderr,__VA_ARGS__)

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    vi sa;
    for (auto e : sa=suffix_array(s)) cout << e+1 << ' ';
    cout << "\nx ";
    for (auto e : longest_common_prefix(s,sa)) cout << e << ' ';
}
