#pragma once

#include "../Template/Template.hpp"
#include "Factorization.hpp"

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
template <class T>
T _power(T x, i128 b) {
    T res = one;
    while (b) {
        if (b & 1) res = res * x;
        x = x * x;
        b = b / 2;
    }
    return res;
}
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

    std::function<G(G, G)> Ggcd = [&](G a, G b) -> G {
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
std::vector<G> solvecomposite(i128 n) {
    auto fact = factorization<i64>(n);
    std::sort(begin(fact), end(fact));

    std::vector<pair<i128, i64>> prm;
    for (int i = 0, j = 0; i < int(fact.size()); i = j) {
        while (fact[j] == fact[i] && j < int(fact.size())) j++;
        prm.emplace_back(fact[i], j - i);
    }

    std::vector<G> v{{1, 0}};
    for (auto [p, tmp] : prm) {
        if (p % 4 == 1) {
            G A = solveprime(p);
            G B = {A.a, -A.b};
            auto now = _power<G>(A, 2 * tmp);

            std::vector<G> res;
            for (i64 i = 0; i <= 2 * tmp; i++) {
                for (auto it : v) res.push_back(it * now);
                now = now * B / A;
            }
            swap(v, res);
        } else {
            G now(p, 0);
            now = _power<G>(now, tmp);
            for (auto &&it : v) it = it * now;
        }
    }
    for (auto &&[a, b] : v) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
    }
    std::sort(v.begin(), v.end(), [&](const G &a, const G &b) {
        return make_pair(a.a, a.b) < make_pair(b.a, b.b);
    });
    v.resize(unique(v.begin(), v.end()) - v.begin());

    std::vector<G> t;
    for (auto [a, b] : v)
        if (a != 0 && b != 0) t.emplace_back(a, b);
    return t;
}
}  // namespace Format_Fact