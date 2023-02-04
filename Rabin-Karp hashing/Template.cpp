struct rabin_karp {
    const ll A, B; vector<ll> h, p;
    rabin_karp(const string &s, ll a, ll b):
    A(a), B(b), h(siz(s)), p(siz(s)) { // 1-based string
        assert(siz(s)), p[0] = 1;
        rep(i,1,siz(s)-1) {
            h[i] = (h[i-1]*A+s[i])%B;
            p[i] = p[i-1]*A%B;
        }
    }
    ll hash(int a, int b) { // closed form
        assert(a <= b);
        ll r = (h[b]-h[a-1]*p[b-a+1])%B;
        return r >= 0 ? r : r+B;
    }
};
