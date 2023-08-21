template <class T = int64_t, class U = __int128_t>
struct CHT {
    struct line {
        T a, b;
        T operator ()(T x) { return a*x+b; }
    };
    vector<line> d;
    int e=-1;
    bool ok(line x, line y, line z) {
        return U(x.b-z.b)*(y.a-x.a) <= U(x.b-y.b)*(z.a-x.a);
    }
    void insert(line l) {
        while (e >= 1 and ok(d[e-1],d[e],l)) d.pop_back(), e--;
        d.push_back(l), e++;
    }
    T get(T x) {
        assert(size(d));
        int a = 0, b = e-1, m;
        while (a <= b) {
            m = (a+b)/2;
            if (d[m](x) < d[m+1](x)) a = m+1;
            else b = m-1;
        }
        return d[a](x);
    }
};
