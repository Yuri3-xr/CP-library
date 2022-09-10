#pragma once

#include "../Template/Power.hpp"
#include "../Template/Template.hpp"
// ##Tode : Make Template
namespace Factorization {
using i128 = __int128;
static mt19937_64 rng(114514);
inline i128 mul(i128 a, i128 b, i128 c) {
    i128 s = a * b - c * i128((long double)a / c * b + 0.5);
    return s < 0 ? s + c : s;
}

i128 mPow(i128 a, i128 k, i128 mod) {
    i128 res = 1;
    for (; k; k >>= 1, a = mul(a, a, mod))
        if (k & 1) res = mul(res, a, mod);
    return res;
}

bool test(i128 n, int a) {
    if (n == a) return 1;
    if (n % 2 == 0) return 0;

    i128 d = (n - 1) >> __builtin_ctzll(n - 1);
    i128 r = mPow(a, d, n);

    while (d < n - 1 && r != 1 && r != n - 1) d <<= 1, r = mul(r, r, n);
    return r == n - 1 || d & 1;
}
bool miller(i128 n) {
    if (n == 2) return 1;
    for (auto p : VI{2, 3, 5, 7, 11, 13})
        if (test(n, p) == 0) return 0;
    return 1;
}
long long myrand(i128 a, i128 b) {
    return uniform_int_distribution<long long>(a, b)(rng);
}
i128 pollard(i128 n) {
    auto f = [&](i128 x) { return ((__int128)x * x + 1) % n; };
    auto babs = [&](i128 x) {
        if (x > 0)
            return x;
        else
            return -x;
    };
    i128 x = 0, y = 0, t = 30, prd = 2;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        // speedup: don't take __gcd in each iteration.
        if (x == y) x = myrand(2, n - 1), y = f(x);
        i128 tmp = mul(prd, babs(x - y), n);
        if (tmp) prd = tmp;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<pair<i128, i64>> work(i128 n) {
    vector<i128> res;

    function<void(i128)> solve = [&](i128 x) {
        if (x == 1) return;
        if (miller(x))
            res.push_back(x);
        else {
            i128 d = pollard(x);
            solve(d);
            solve(x / d);
        }
    };
    solve(n);
    sort(res.begin(), res.end());
    vector<pair<i128, i64>> gao;
    for (int i = 0, j = 0; i < res.size(); i = j) {
        while (res[j] == res[i] && j < res.size()) j++;
        gao.emplace_back(res[i], j - i);
    }
    return gao;
}
}  // namespace Factorization
namespace Format_Fact {
using i128 = __int128;
struct G {
    i128 a, b;
    G(){};
    G(i128 a, i128 b) : a(a), b(b){};
    G friend operator+(const G &a, const G &b) {
        return {a.a + b.a, a.b + b.b};
    }
    G friend operator-(const G &a, const G &b) {
        return {a.a - b.a, a.b - b.b};
    }
    G friend operator*(const G &a, const G &b) {
        return {a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a};
    }
    bool operator==(const G &x) const { return x.a == a && x.b == b; }
    G operator*(const i128 &t) const { return {a * t, b * t}; }
    G operator/(const i128 &t) const { return {a / t, b / t}; }
    G friend operator/(const G &a, const G &b) {
        i128 len = b.a * b.a + b.b * b.b;
        G c = a * G(b.a, -b.b);
        auto div = [&](i128 a, i128 n) -> i128 {
            i128 now = (a % n + n) % n;
            return ((a - now) / n);
        };
        return {div(2 * c.a + len, 2 * len), div(2 * c.b + len, 2 * len)};
    }
};
static G one = G(1, 0);
G solveprime(i128 p) {
    if (p == 2) return {1, 1};
    i128 t = 1;
    auto qpow = [&](i128 a, i128 b, i128 p) {
        i128 res = 1;
        while (b) {
            if (b & 1) res = res * a % p;
            a = a * a % p;
            b = b / 2;
        }
        return res;
    };
    for (; qpow(t, (p - 1) / 2, p) != p - 1;) t++;
    i128 k = qpow(t, (p - 1) / 4, p);

    function<G(G, G)> Ggcd = [&](G a, G b) -> G {
        if (b.a == 0 && b.b == 0)
            return a;
        else
            return Ggcd(b, a - (a / b) * b);
    };
    auto g = Ggcd({p, 0}, {k, 1});

    if (g.a < 0) g.a = -g.a;
    if (g.b < 0) g.b = -g.b;
    if (g.a > g.b) swap(g.a, g.b);
    return g;
}
vector<G> solvecomposite(i128 n) {
    // cerr << (i64)n << endl;
    auto prm = Factorization::work(n);
    vector<G> v{{1, 0}};
    for (auto [p, tmp] : prm) {
        // cerr << (i64)p << " " << tmp << endl;
        if (p % 4 == 1) {
            G A = solveprime(p);
            G B = {A.a, -A.b};
            auto now = power<G>(A, 2 * tmp);

            vector<G> res;
            for (i64 i = 0; i <= 2 * tmp; i++) {
                for (auto it : v) res.push_back(it * now);
                now = now * B / A;
            }
            swap(v, res);
        } else {
            G now(p, 0);
            now = power<G>(now, tmp);
            for (auto &&it : v) it = it * now;
        }
    }
    for (auto &&[a, b] : v) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
    }
    sort(v.begin(), v.end(), [&](const G &a, const G &b) {
        return make_pair(a.a, a.b) < make_pair(b.a, b.b);
    });
    v.resize(unique(v.begin(), v.end()) - v.begin());

    vector<G> t;
    for (auto [a, b] : v)
        if (a != 0 && b != 0) t.emplace_back(a, b);
    return t;
}
}  // namespace Format_Fact
