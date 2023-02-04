#include <bits/stdc++.h>
using namespace std; using ii = pair<int,int>; using ll = long long;
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define per(i,a,b) for (auto i = (b); i >= (a); --i)
#define all(x) begin(x), end(x)
#define siz(x) int((x).size())
#define Mup(x,y) x = max(x,y)
#define mup(x,y) x = min(x,y)
#define fi first
#define se second
#define dbg(...) fprintf(stderr,__VA_ARGS__)

mt19937 rng(random_device{}());
#define my_random(l,r) uniform_int_distribution<ll>(l,r)(rng)
#define my_shuffle(...) shufflle(__VA_ARGS__,rng)

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

ll A = my_random(1e6,1e9);

int main() {
    string s = "$abcd", t = "$abaabcd";
    rabin_karp sh(s,A,1e9+7), th(t,A,1e9+7);
    cout << (sh.hash(1,4) == th.hash(4,7) ? "True" : "False");
}
