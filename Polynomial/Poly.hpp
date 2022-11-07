#pragma once

#include "Ntt.hpp"

template <class Z, int rt>
struct Poly {
    vector<Z> a;
    Poly() {}
    Poly(int sz, Z val) { a.assign(sz, val); }
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
        static NTT<Z, rt> ntt;
        return ntt.multiply(a.a, b.a);
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
    void shrink() {
        while (this->size() && this->a.back() == Z(0)) this->a.pop_back();
    }
    Poly &operator+=(Poly b) { return (*this) = (*this) + b; }
    Poly &operator-=(Poly b) { return (*this) = (*this) - b; }
    Poly &operator*=(Poly b) { return (*this) = (*this) * b; }
    Poly operator/(const Poly &r) const { return Poly(this->a) /= r; }
    Poly operator%(const Poly &r) const { return Poly(*this) %= r; }
    Poly &operator%=(const Poly &r) {
        *this -= *this / r * r;
        shrink();
        return *this;
    }
    Poly rev(int deg = -1) const {
        Poly ret(this->a);
        if (deg != -1) ret.a.resize(deg, Z(0));
        reverse(begin(ret.a), end(ret.a));
        return ret;
    }
    Poly &operator/=(const Poly &r) {
        if (this->size() < r.size()) {
            this->a.clear();
            return *this;
        }
        int n = this->size() - r.size() + 1;
        return *this = (rev().modxk(n) * r.rev().inv(n)).modxk(n).rev(n);
    }
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
            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((Z::get_mod() + 1) / 2);
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
    vector<Poly> subproduct_tree(const Poly &xs) const {
        int n = (int)xs.size();
        int k = 1;
        while (k < n) k *= 2;
        vector<Poly> g(2 * k, {1});
        for (int i = 0; i < n; i++) g[k + i] = {-xs[i], Z(1)};
        for (int i = k; i-- > 1;) g[i] = g[i * 2] * g[i * 2 + 1];
        return g;
    }
    Poly eval(const Poly &xs) const {
        if (size() == 0) {
            return Poly(xs.size(), Z(0));
        }
        vector<Poly> g = subproduct_tree(xs);
        int m = (int)xs.size(), k = (int)g.size() / 2;
        g[1] = *this % g[1];
        for (int i = 2; i < k + m; i++) g[i] = g[i / 2] % g[i];
        Poly ys(m, Z(0));
        for (int i = 0; i < m; i++)
            ys[i] = (g[k + i].a.empty() ? Z(0) : g[k + i][0]);
        return ys;
    }
    Poly inter(const Poly &ys) const {
        assert(size() == ys.size());
        auto mul = subproduct_tree(*this);
        int n = (int)(size()), k = (int)mul.size() / 2;
        vector<Poly> g(2 * k);
        g[1] = mul[1].deriv() % mul[1];
        for (int i = 2; i < k + n; i++) g[i] = g[i / 2] % mul[i];
        for (int i = 0; i < n; i++) g[k + i] = {ys[i] / g[k + i][0]};
        for (int i = k; i-- > 1;)
            g[i] = g[i * 2] * mul[i * 2 + 1] + g[i * 2 + 1] * mul[i * 2];
        return g[1];
    }
    Poly shift(Z t, int m = -1) {
        /*
            input: y(0) , y(1) , ... , y(n-1)
            output: y(t) , t(t+1) , ... ,y (t+m-1)
            ## m = -1 => m = n
        */
        if (m == -1) m = this->size();
        i64 T = t.get();
        int k = (int)(this->size()) - 1;
        T %= Z::get_mod();

        if (T <= k) {
            Poly ret(m, 0);
            int ptr = 0;
            for (i64 i = T; i <= k && ptr < m; i++) ret[ptr++] = a[i];
            if (k + 1 < T + m) {
                auto suf = shift(k + 1, m - ptr);
                for (int i = k + 1; i < T + m; i++)
                    ret[ptr++] = suf[i - (k + 1)];
            }
            return ret;
        }
        if (T + m > Z::get_mod()) {
            auto pref = shift(T, Z::get_mod() - T);
            auto suf = shift(0, m - pref.size());
            copy(begin(suf.a), end(suf.a), back_inserter(pref.a));
            return pref;
        }

        Poly finv(k + 1, 1), d(k + 1, 0);
        for (int i = 2; i <= k; i++) finv[k] *= i;
        finv[k] = Z(1) / finv[k];
        for (int i = k; i >= 1; i--) finv[i - 1] = finv[i] * i;
        for (int i = 0; i <= k; i++) {
            d[i] = finv[i] * finv[k - i] * a[i];
            if ((k - i) & 1) d[i] = -d[i];
        }

        Poly h(m + k, 0);
        for (int i = 0; i < m + k; i++) {
            h[i] = Z(1) / (T - k + i);
        }

        auto dh = d * h;
        Poly ret(m, 0);
        Z cur = T;
        for (int i = 1; i <= k; i++) cur *= T - i;
        for (int i = 0; i < m; i++) {
            ret[i] = cur * dh[k + i];
            cur *= T + i + 1;
            cur *= h[i];
        }
        return ret;
    }
};