#pragma once

#include "../Template/Template.hpp"

template <class T>
struct Binomial {
    std::vector<T> f, g, h;
    Binomial(int MAX = 0) {
        f.resize(1, T{1});
        g.resize(1, T{1});
        h.resize(1, T{1});

        while (MAX >= (int)f.size()) extend();
    }

    void extend() {
        int n = f.size();
        int m = n * 2;
        f.resize(m);
        g.resize(m);
        h.resize(m);
        for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);
        g[m - 1] = f[m - 1].inverse();
        h[m - 1] = g[m - 1] * f[m - 2];
        for (int i = m - 2; i >= n; i--) {
            g[i] = g[i + 1] * T(i + 1);
            h[i] = g[i] * f[i - 1];
        }
    }

    T fac(int i) {
        if (i < 0) return T(0);
        while (i >= (int)f.size()) extend();
        return f[i];
    }

    T finv(int i) {
        if (i < 0) return T(0);
        while (i >= (int)g.size()) extend();
        return g[i];
    }

    T inv(int i) {
        if (i < 0) return -inv(-i);
        while (i >= (int)h.size()) extend();
        return h[i];
    }

    T C(int n, int r) {
        if (n < 0 || n < r || r < 0) return T(0);
        return fac(n) * finv(n - r) * finv(r);
    }

    inline T operator()(int n, int r) { return C(n, r); }

    template <typename I>
    T multinomial(const std::vector<I>& r) {
        static_assert(is_integral<I>::value == true);
        int n = 0;
        for (auto& x : r) {
            if (x < 0) return T(0);
            n += x;
        }
        T res = fac(n);
        for (auto& x : r) res *= finv(x);
        return res;
    }

    template <typename I>
    T operator()(const std::vector<I>& r) {
        return multinomial(r);
    }

    T C_naive(int n, int r) {
        if (n < 0 || n < r || r < 0) return T(0);
        T ret = T(1);
        r = std::min(r, n - r);
        for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);
        return ret;
    }

    T P(int n, int r) {
        if (n < 0 || n < r || r < 0) return T(0);
        return fac(n) * finv(n - r);
    }

    T H(int n, int r) {
        if (n < 0 || r < 0) return T(0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};