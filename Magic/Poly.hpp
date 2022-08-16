#pragma once

#include "../Template/Template.hpp"

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    int get() const { return x; }
};
constexpr int mod = 998244353;
using Z = ModInt<mod>;
template <class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
vector<int> rev;
vector<Z> roots{0, 1};
void dft(vector<Z> &a) {
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
            swap(a[i], a[rev[i]]);
        }
    }
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            Z e = power(Z(3), (mod - 1) >> (k + 1));
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
void idft(vector<Z> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end());
    dft(a);
    Z inv = (1 - mod) / n;
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}

struct Poly {
    vector<Z> a;
    Poly() {}
    Poly(const vector<Z> &a) : a(a) {}
    Poly(const initializer_list<Z> &a) : a(a) {}
    int size() const { return a.size(); }
    void resize(int n) { a.resize(n); }
    Z operator[](int idx) const {
        if (idx < size()) {
            return a[idx];
        } else {
            return 0;
        }
    }
    Z &operator[](int idx) { return a[idx]; }
    Poly mulxk(int k) const {
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly modxk(int k) const {
        k = min(k, size());
        return Poly(vector<Z>(a.begin(), a.begin() + k));
    }
    Poly divxk(int k) const {
        if (size() <= k) {
            return Poly();
        }
        return Poly(vector<Z>(a.begin() + k, a.end()));
    }
    friend Poly operator+(const Poly &a, const Poly &b) {
        vector<Z> res(max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] + b[i];
        }
        return Poly(res);
    }
    friend Poly operator-(const Poly &a, const Poly &b) {
        vector<Z> res(max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] - b[i];
        }
        return Poly(res);
    }
    friend Poly operator*(Poly a, Poly b) {
        if (a.size() == 0 || b.size() == 0) {
            return Poly();
        }
        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot) {
            sz *= 2;
        }
        a.a.resize(sz);
        b.a.resize(sz);
        dft(a.a);
        dft(b.a);
        for (int i = 0; i < sz; ++i) {
            a.a[i] = a[i] * b[i];
        }
        idft(a.a);
        a.resize(tot);
        return a;
    }
    friend Poly operator*(Z a, Poly b) {
        for (int i = 0; i < int(b.size()); i++) {
            b[i] *= a;
        }
        return b;
    }
    friend Poly operator*(Poly a, Z b) {
        for (int i = 0; i < int(a.size()); i++) {
            a[i] *= b;
        }
        return a;
    }
    Poly &operator+=(Poly b) { return (*this) = (*this) + b; }
    Poly &operator-=(Poly b) { return (*this) = (*this) - b; }
    Poly &operator*=(Poly b) { return (*this) = (*this) * b; }
    Poly deriv() const {
        if (a.empty()) {
            return Poly();
        }
        vector<Z> res(size() - 1);
        for (int i = 0; i < size() - 1; ++i) {
            res[i] = Z(i + 1) * a[i + 1];
        }
        return Poly(res);
    }
    Poly integr() const {
        vector<Z> res(size() + 1);
        for (int i = 0; i < size(); ++i) {
            res[i + 1] = a[i] / (i + 1);
        }
        return Poly(res);
    }
    Poly inv(int m) const {
        Poly x{a[0].inverse()};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{2} - modxk(k) * x)).modxk(k);
        }
        return x.modxk(m);
    }
    Poly log(int m) const { return (deriv() * inv(m)).integr().modxk(m); }
    Poly exp(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{1} - x.log(k) + modxk(k))).modxk(k);
        }
        return x.modxk(m);
    }
    Poly pow(int k, int m) const {
        int i = 0;
        while (i < size() && a[i].get() == 0) {
            i++;
        }
        if (i == size() || 1LL * i * k >= m) {
            return Poly(vector<Z>(m));
        }
        Z v = a[i];
        auto f = divxk(i) * v.inverse();
        return (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);
    }
    Poly sqrt(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((mod + 1) / 2);
        }
        return x.modxk(m);
    }
    Poly mulT(Poly b) const {
        if (b.size() == 0) {
            return Poly();
        }
        int n = b.size();
        reverse(b.a.begin(), b.a.end());
        return ((*this) * b).divxk(n - 1);
    }
    vector<Z> eval(vector<Z> x) const {
        if (size() == 0) {
            return vector<Z>(x.size(), 0);
        }
        const int n = max(int(x.size()), size());
        vector<Poly> q(4 * n);
        vector<Z> ans(x.size());
        x.resize(n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                q[p] = Poly{1, -x[l]};
            } else {
                int m = (l + r) / 2;
                build(2 * p, l, m);
                build(2 * p + 1, m, r);
                q[p] = q[2 * p] * q[2 * p + 1];
            }
        };
        build(1, 0, n);
        function<void(int, int, int, const Poly &)> work =
            [&](int p, int l, int r, const Poly &num) {
                if (r - l == 1) {
                    if (l < int(ans.size())) {
                        ans[l] = num[0];
                    }
                } else {
                    int m = (l + r) / 2;
                    work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
                    work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
                }
            };
        work(1, 0, n, mulT(q[1].inv(n)));
        return ans;
    }
    Poly inter(const Poly &x, const Poly &y) {
        vector<Poly> Q(x.size() << 2), P(x.size() << 2);
        function<void(int, int, int)> dfs1 = [&](int p, int l, int r) {
            int m = (l + r) >> 1;
            if (l == r) {
                Q[p].a.push_back(-x[m]);
                Q[p].a.push_back(Z(1));
                return;
            }
            dfs1(p * 2, l, m);
            dfs1(p * 2 + 1, m + 1, r);
            Q[p] = Q[p * 2] * Q[p * 2 + 1];
        };
        dfs1(1, 0, x.size() - 1);
        Poly f;
        f.a.resize((int)(Q[1].size()) - 1);
        for (int i = 0; i + 1 < Q[1].size(); i += 1)
            f[i] = (Q[1][i + 1] * (i + 1));
        Poly g = f.eval(x.a);
        function<void(int, int, int)> dfs2 = [&](int p, int l, int r) {
            int m = (l + r) >> 1;
            if (l == r) {
                P[p].a.push_back(y[m] * power(g[m], mod - 2));
                return;
            }
            dfs2(p * 2, l, m);
            dfs2(p * 2 + 1, m + 1, r);
            P[p].a.resize(r - l + 1);
            Poly A = P[p * 2] * Q[p * 2 + 1];
            Poly B = P[p * 2 + 1] * Q[p * 2];
            for (int i = 0; i <= r - l; i++) P[p][i] = (A[i] + B[i]);
        };
        dfs2(1, 0, x.size() - 1);
        return P[1];
    }
};
