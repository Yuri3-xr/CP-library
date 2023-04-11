#pragma once

#include "../Template/Power.hpp"
#include "../Template/Template.hpp"
template <class Z>
struct NTT {
    std::vector<int> rev;
    std::vector<Z> roots{0, 1};

    static constexpr uint32_t getRoot() {
        auto _mod = Z::get_mod();
        using u64 = uint64_t;
        u64 ds[32] = {};
        int idx = 0;
        u64 m = _mod - 1;
        for (u64 i = 2; i * i <= m; ++i) {
            if (m % i == 0) {
                ds[idx++] = i;
                while (m % i == 0) m /= i;
            }
        }
        if (m != 1) ds[idx++] = m;

        uint32_t _pr = 2;
        for (;;) {
            int flg = 1;
            for (int i = 0; i < idx; ++i) {
                u64 a = _pr, b = (_mod - 1) / ds[i], r = 1;
                for (; b; a = a * a % _mod, b /= 2) {
                    if (b % 2 == 1) r = r * a % _mod;
                }
                if (r == 1) {
                    flg = 0;
                    break;
                }
            }
            if (flg == 1) break;
            ++_pr;
        }
        return _pr;
    };

    static constexpr uint32_t mod = Z::get_mod();
    static constexpr uint32_t rt = getRoot();

    void dft(std::vector<Z> &a) {
        int n = a.size();

        if (int(rev.size()) != n) {
            int k = __builtin_ctz(n) - 1;
            rev.resize(n);
            for (int i = 0; i < n; i++) {
                rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
            }
        }

        for (int i = 0; i < n; i++) {
            if (rev[i] < i) {
                std::swap(a[i], a[rev[i]]);
            }
        }
        if (int(roots.size()) < n) {
            int k = __builtin_ctz(roots.size());
            roots.resize(n);
            while ((1 << k) < n) {
                Z e = power(Z(rt), (mod - 1) >> (k + 1));
                for (int i = 1 << (k - 1); i < (1 << k); i++) {
                    roots[2 * i] = roots[i];
                    roots[2 * i + 1] = roots[i] * e;
                }
                k++;
            }
        }
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    Z u = a[i + j];
                    Z v = a[i + j + k] * roots[k + j];
                    a[i + j] = u + v;
                    a[i + j + k] = u - v;
                }
            }
        }
    }
    void idft(std::vector<Z> &a) {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        Z inv = (1 - mod) / n;
        for (int i = 0; i < n; i++) {
            a[i] *= inv;
        }
    }
    std::vector<Z> multiply(std::vector<Z> a, std::vector<Z> b) {
        int sz = 1, tot = a.size() + b.size() - 1;

        if (tot <= 20) {
            std::vector<Z> ret(tot);
            for (size_t i = 0; i < a.size(); i++)
                for (size_t j = 0; j < b.size(); j++) ret[i + j] += a[i] * b[j];
            return ret;
        }

        while (sz < tot) {
            sz *= 2;
        }

        a.resize(sz), b.resize(sz);
        dft(a), dft(b);

        for (int i = 0; i < sz; ++i) {
            a[i] = a[i] * b[i];
        }

        idft(a);
        a.resize(tot);
        return a;
    }
};
