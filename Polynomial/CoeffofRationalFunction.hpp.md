---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Polynomial/Ntt.hpp
    title: Polynomial/Ntt.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/Poly.hpp
    title: Polynomial/Poly.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Power.hpp
    title: Template/Power.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Polynomial/LinearlyRecurrent.hpp
    title: Polynomial/LinearlyRecurrent.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/KthtermofLinearlyRecurrentSequence.test.cpp
    title: Verify/KthtermofLinearlyRecurrentSequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Polynomial/CoeffofRationalFunction.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 2 \"Polynomial/Poly.hpp\"\
    \n\n#line 2 \"Polynomial/Ntt.hpp\"\n\n#line 1 \"Template/Power.hpp\"\ntemplate\
    \ <class T>\nT power(T a, int b) {\n    T res = 1;\n    for (; b; b /= 2, a *=\
    \ a) {\n        if (b % 2) {\n            res *= a;\n        }\n    }\n    return\
    \ res;\n}\n#line 5 \"Polynomial/Ntt.hpp\"\ntemplate <class Z, int rt>\nstruct\
    \ NTT {\n    std::vector<int> rev;\n    std::vector<Z> roots{0, 1};\n    void\
    \ dft(std::vector<Z> &a) {\n        int n = a.size();\n\n        if (int(rev.size())\
    \ != n) {\n            int k = __builtin_ctz(n) - 1;\n            rev.resize(n);\n\
    \            for (int i = 0; i < n; i++) {\n                rev[i] = rev[i >>\
    \ 1] >> 1 | (i & 1) << k;\n            }\n        }\n\n        for (int i = 0;\
    \ i < n; i++) {\n            if (rev[i] < i) {\n                std::swap(a[i],\
    \ a[rev[i]]);\n            }\n        }\n        if (int(roots.size()) < n) {\n\
    \            int k = __builtin_ctz(roots.size());\n            roots.resize(n);\n\
    \            while ((1 << k) < n) {\n                Z e = power(Z(rt), (Z::get_mod()\
    \ - 1) >> (k + 1));\n                for (int i = 1 << (k - 1); i < (1 << k);\
    \ i++) {\n                    roots[2 * i] = roots[i];\n                    roots[2\
    \ * i + 1] = roots[i] * e;\n                }\n                k++;\n        \
    \    }\n        }\n        for (int k = 1; k < n; k *= 2) {\n            for (int\
    \ i = 0; i < n; i += 2 * k) {\n                for (int j = 0; j < k; j++) {\n\
    \                    Z u = a[i + j];\n                    Z v = a[i + j + k] *\
    \ roots[k + j];\n                    a[i + j] = u + v;\n                    a[i\
    \ + j + k] = u - v;\n                }\n            }\n        }\n    }\n    void\
    \ idft(std::vector<Z> &a) {\n        int n = a.size();\n        reverse(a.begin()\
    \ + 1, a.end());\n        dft(a);\n        Z inv = (1 - Z::get_mod()) / n;\n \
    \       for (int i = 0; i < n; i++) {\n            a[i] *= inv;\n        }\n \
    \   }\n    std::vector<Z> multiply(std::vector<Z> a, std::vector<Z> b) {\n   \
    \     int sz = 1, tot = a.size() + b.size() - 1;\n\n        if (tot <= 20) {\n\
    \            std::vector<Z> ret(tot);\n            for (size_t i = 0; i < a.size();\
    \ i++)\n                for (size_t j = 0; j < b.size(); j++) ret[i + j] += a[i]\
    \ * b[j];\n            return ret;\n        }\n\n        while (sz < tot) {\n\
    \            sz *= 2;\n        }\n\n        a.resize(sz), b.resize(sz);\n    \
    \    dft(a), dft(b);\n\n        for (int i = 0; i < sz; ++i) {\n            a[i]\
    \ = a[i] * b[i];\n        }\n\n        idft(a);\n        a.resize(tot);\n    \
    \    return a;\n    }\n};\n#line 4 \"Polynomial/Poly.hpp\"\n\ntemplate <class\
    \ Z, int rt>\nstruct Poly {\n    std::vector<Z> a;\n    Poly() {}\n    Poly(int\
    \ sz, Z val) { a.assign(sz, val); }\n    Poly(const std::vector<Z> &a) : a(a)\
    \ {}\n    Poly(const std::initializer_list<Z> &a) : a(a) {}\n    int size() const\
    \ { return a.size(); }\n    void resize(int n) { a.resize(n); }\n    Z operator[](int\
    \ idx) const {\n        if (idx < size()) {\n            return a[idx];\n    \
    \    } else {\n            return 0;\n        }\n    }\n    Z &operator[](int\
    \ idx) { return a[idx]; }\n    Poly mulxk(int k) const {\n        auto b = a;\n\
    \        b.insert(b.begin(), k, 0);\n        return Poly(b);\n    }\n    Poly\
    \ modxk(int k) const {\n        k = std::min(k, size());\n        return Poly(std::vector<Z>(a.begin(),\
    \ a.begin() + k));\n    }\n    Poly divxk(int k) const {\n        if (size() <=\
    \ k) {\n            return Poly();\n        }\n        return Poly(std::vector<Z>(a.begin()\
    \ + k, a.end()));\n    }\n    friend Poly operator+(const Poly &a, const Poly\
    \ &b) {\n        std::vector<Z> res(std::max(a.size(), b.size()));\n        for\
    \ (int i = 0; i < int(res.size()); i++) {\n            res[i] = a[i] + b[i];\n\
    \        }\n        return Poly(res);\n    }\n    friend Poly operator-(const\
    \ Poly &a, const Poly &b) {\n        std::vector<Z> res(std::max(a.size(), b.size()));\n\
    \        for (int i = 0; i < int(res.size()); i++) {\n            res[i] = a[i]\
    \ - b[i];\n        }\n        return Poly(res);\n    }\n\n    friend Poly operator*(Poly\
    \ a, Poly b) {\n        if (a.size() == 0 || b.size() == 0) {\n            return\
    \ Poly();\n        }\n        static NTT<Z, rt> ntt;\n        return ntt.multiply(a.a,\
    \ b.a);\n    }\n    friend Poly operator*(Z a, Poly b) {\n        for (int i =\
    \ 0; i < int(b.size()); i++) {\n            b[i] *= a;\n        }\n        return\
    \ b;\n    }\n    friend Poly operator*(Poly a, Z b) {\n        for (int i = 0;\
    \ i < int(a.size()); i++) {\n            a[i] *= b;\n        }\n        return\
    \ a;\n    }\n    Poly &operator+=(Poly b) { return (*this) = (*this) + b; }\n\
    \    Poly &operator-=(Poly b) { return (*this) = (*this) - b; }\n    Poly &operator*=(Poly\
    \ b) { return (*this) = (*this) * b; }\n    Poly operator/(const Poly &r) const\
    \ { return Poly(this->a) /= r; }\n    Poly rev(int deg = -1) const {\n       \
    \ Poly ret(this->a);\n        if (deg != -1) ret.a.resize(deg, Z(0));\n      \
    \  reverse(begin(ret.a), end(ret.a));\n        return ret;\n    }\n    Poly &operator/=(const\
    \ Poly &r) {\n        if (this->size() < r.size()) {\n            this->a.clear();\n\
    \            return *this;\n        }\n        int n = this->size() - r.size()\
    \ + 1;\n        return *this = (rev().modxk(n) * r.rev().inv(n)).modxk(n).rev(n);\n\
    \    }\n    Poly deriv() const {\n        if (a.empty()) {\n            return\
    \ Poly();\n        }\n        std::vector<Z> res(size() - 1);\n        for (int\
    \ i = 0; i < size() - 1; ++i) {\n            res[i] = Z(i + 1) * a[i + 1];\n \
    \       }\n        return Poly(res);\n    }\n    Poly integr() const {\n     \
    \   std::vector<Z> res(size() + 1);\n        for (int i = 0; i < size(); ++i)\
    \ {\n            res[i + 1] = a[i] / (i + 1);\n        }\n        return Poly(res);\n\
    \    }\n    Poly inv(int m) const {\n        Poly x{a[0].inverse()};\n       \
    \ int k = 1;\n        while (k < m) {\n            k *= 2;\n            x = (x\
    \ * (Poly{2} - modxk(k) * x)).modxk(k);\n        }\n        return x.modxk(m);\n\
    \    }\n    Poly log(int m) const { return (deriv() * inv(m)).integr().modxk(m);\
    \ }\n    Poly exp(int m) const {\n        Poly x{1};\n        int k = 1;\n   \
    \     while (k < m) {\n            k *= 2;\n            x = (x * (Poly{1} - x.log(k)\
    \ + modxk(k))).modxk(k);\n        }\n        return x.modxk(m);\n    }\n    Poly\
    \ pow(int k, int m) const {\n        int i = 0;\n        while (i < size() &&\
    \ a[i].get() == 0) {\n            i++;\n        }\n        if (i == size() ||\
    \ 1LL * i * k >= m) {\n            return Poly(std::vector<Z>(m));\n        }\n\
    \        Z v = a[i];\n        auto f = divxk(i) * v.inverse();\n        return\
    \ (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);\n    }\n \
    \   Poly sqrt(int m) const {\n        Poly x{1};\n        int k = 1;\n       \
    \ while (k < m) {\n            k *= 2;\n            x = (x + (modxk(k) * x.inv(k)).modxk(k))\
    \ * ((Z::get_mod() + 1) / 2);\n        }\n        return x.modxk(m);\n    }\n\
    \    Poly mulT(Poly b) const {\n        if (b.size() == 0) {\n            return\
    \ Poly();\n        }\n        int n = b.size();\n        reverse(b.a.begin(),\
    \ b.a.end());\n        return ((*this) * b).divxk(n - 1);\n    }\n    std::vector<Z>\
    \ eval(std::vector<Z> x) const {\n        if (size() == 0) {\n            return\
    \ std::vector<Z>(x.size(), 0);\n        }\n        const int n = std::max(int(x.size()),\
    \ size());\n        std::vector<Poly> q(4 * n);\n        std::vector<Z> ans(x.size());\n\
    \        x.resize(n);\n        std::function<void(int, int, int)> build = [&](int\
    \ p, int l, int r) {\n            if (r - l == 1) {\n                q[p] = Poly{1,\
    \ -x[l]};\n            } else {\n                int m = (l + r) / 2;\n      \
    \          build(2 * p, l, m);\n                build(2 * p + 1, m, r);\n    \
    \            q[p] = q[2 * p] * q[2 * p + 1];\n            }\n        };\n    \
    \    build(1, 0, n);\n        std::function<void(int, int, int, const Poly &)>\
    \ work =\n            [&](int p, int l, int r, const Poly &num) {\n          \
    \      if (r - l == 1) {\n                    if (l < int(ans.size())) {\n   \
    \                     ans[l] = num[0];\n                    }\n              \
    \  } else {\n                    int m = (l + r) / 2;\n                    work(2\
    \ * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));\n                    work(2\
    \ * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));\n                }\n      \
    \      };\n        work(1, 0, n, mulT(q[1].inv(n)));\n        return ans;\n  \
    \  }\n    Poly inter(const Poly &y) const {\n        std::vector<Poly> Q(a.size()\
    \ * 4), P(a.size() * 4);\n        std::function<void(int, int, int)> build = [&](int\
    \ p, int l, int r) {\n            int m = (l + r) >> 1;\n            if (l ==\
    \ r) {\n                Q[p] = Poly{-a[m], Z(1)};\n            } else {\n    \
    \            build(p * 2, l, m);\n                build(p * 2 + 1, m + 1, r);\n\
    \                Q[p] = Q[p * 2] * Q[p * 2 + 1];\n            }\n        };\n\
    \        build(1, 0, a.size() - 1);\n        Poly f;\n        f.a.resize((int)(Q[1].size())\
    \ - 1);\n        for (int i = 0; i + 1 < Q[1].size(); i += 1)\n            f[i]\
    \ = (Q[1][i + 1] * (i + 1));\n        Poly g = f.eval(a);\n        std::function<void(int,\
    \ int, int)> work = [&](int p, int l, int r) {\n            int m = (l + r) >>\
    \ 1;\n            if (l == r) {\n                P[p].a.push_back(y[m] * power(g[m],\
    \ Z::get_mod() - 2));\n                return;\n            }\n            work(p\
    \ * 2, l, m);\n            work(p * 2 + 1, m + 1, r);\n            P[p].a.resize(r\
    \ - l + 1);\n            Poly A = P[p * 2] * Q[p * 2 + 1];\n            Poly B\
    \ = P[p * 2 + 1] * Q[p * 2];\n            for (int i = 0; i <= r - l; i++) P[p][i]\
    \ = (A[i] + B[i]);\n        };\n        work(1, 0, a.size() - 1);\n        return\
    \ P[1];\n    }\n    Poly shift(Z t, int m = -1) {\n        /*\n            input:\
    \ y(0) , y(1) , ... , y(n-1)\n            output: y(t) , t(t+1) , ... ,y (t+m-1)\n\
    \            ## m = -1 => m = n\n        */\n        if (m == -1) m = this->size();\n\
    \        i64 T = t.get();\n        int k = (int)(this->size()) - 1;\n        T\
    \ %= Z::get_mod();\n\n        if (T <= k) {\n            Poly ret(m, 0);\n   \
    \         int ptr = 0;\n            for (i64 i = T; i <= k && ptr < m; i++) ret[ptr++]\
    \ = a[i];\n            if (k + 1 < T + m) {\n                auto suf = shift(k\
    \ + 1, m - ptr);\n                for (int i = k + 1; i < T + m; i++)\n      \
    \              ret[ptr++] = suf[i - (k + 1)];\n            }\n            return\
    \ ret;\n        }\n        if (T + m > Z::get_mod()) {\n            auto pref\
    \ = shift(T, Z::get_mod() - T);\n            auto suf = shift(0, m - pref.size());\n\
    \            copy(begin(suf.a), end(suf.a), back_inserter(pref.a));\n        \
    \    return pref;\n        }\n\n        Poly finv(k + 1, 1), d(k + 1, 0);\n  \
    \      for (int i = 2; i <= k; i++) finv[k] *= i;\n        finv[k] = Z(1) / finv[k];\n\
    \        for (int i = k; i >= 1; i--) finv[i - 1] = finv[i] * i;\n        for\
    \ (int i = 0; i <= k; i++) {\n            d[i] = finv[i] * finv[k - i] * a[i];\n\
    \            if ((k - i) & 1) d[i] = -d[i];\n        }\n\n        Poly h(m + k,\
    \ 0);\n        for (int i = 0; i < m + k; i++) {\n            h[i] = Z(1) / (T\
    \ - k + i);\n        }\n\n        auto dh = d * h;\n        Poly ret(m, 0);\n\
    \        Z cur = T;\n        for (int i = 1; i <= k; i++) cur *= T - i;\n    \
    \    for (int i = 0; i < m; i++) {\n            ret[i] = cur * dh[k + i];\n  \
    \          cur *= T + i + 1;\n            cur *= h[i];\n        }\n        return\
    \ ret;\n    }\n};\n#line 5 \"Polynomial/CoeffofRationalFunction.hpp\"\n\ntemplate\
    \ <class Z, int rt>\nZ CoeffofRationalFunction(Poly<Z, rt> P, Poly<Z, rt> Q, i64\
    \ k) {\n    Z ret = 0;\n    if (P.size() >= Q.size()) {\n        auto R = P /\
    \ Q;\n        P -= R * Q;\n        while (P.size() && P.a.back() == Z(0)) P.a.pop_back();\n\
    \        if (k < int(R.size())) ret += R[k];\n    }\n    if (P.a.empty()) return\
    \ ret;\n    P.a.resize(int(Q.size()) - 1);\n\n    while (k > 0) {\n        Poly<Z,\
    \ rt> Q2(Q.a);\n        for (int i = 1; i < int(Q2.size()); i += 2) Q2[i] = -Q2[i];\n\
    \        auto sub = [&](const Poly<Z, rt> &as, bool odd) {\n            Poly<Z,\
    \ rt> bs((as.size() + !odd) / 2, 0);\n            for (int i = odd; i < (int)as.size();\
    \ i += 2) bs[i >> 1] = as[i];\n            return bs;\n        };\n        P =\
    \ sub(P * Q2, k & 1);\n        Q = sub(Q * Q2, 0);\n        k /= 2;\n    }\n\n\
    \    return ret + P[0];\n}\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n#include \"Poly.hpp\"\
    \n\ntemplate <class Z, int rt>\nZ CoeffofRationalFunction(Poly<Z, rt> P, Poly<Z,\
    \ rt> Q, i64 k) {\n    Z ret = 0;\n    if (P.size() >= Q.size()) {\n        auto\
    \ R = P / Q;\n        P -= R * Q;\n        while (P.size() && P.a.back() == Z(0))\
    \ P.a.pop_back();\n        if (k < int(R.size())) ret += R[k];\n    }\n    if\
    \ (P.a.empty()) return ret;\n    P.a.resize(int(Q.size()) - 1);\n\n    while (k\
    \ > 0) {\n        Poly<Z, rt> Q2(Q.a);\n        for (int i = 1; i < int(Q2.size());\
    \ i += 2) Q2[i] = -Q2[i];\n        auto sub = [&](const Poly<Z, rt> &as, bool\
    \ odd) {\n            Poly<Z, rt> bs((as.size() + !odd) / 2, 0);\n           \
    \ for (int i = odd; i < (int)as.size(); i += 2) bs[i >> 1] = as[i];\n        \
    \    return bs;\n        };\n        P = sub(P * Q2, k & 1);\n        Q = sub(Q\
    \ * Q2, 0);\n        k /= 2;\n    }\n\n    return ret + P[0];\n}\n"
  dependsOn:
  - Template/Template.hpp
  - Polynomial/Poly.hpp
  - Polynomial/Ntt.hpp
  - Template/Power.hpp
  isVerificationFile: false
  path: Polynomial/CoeffofRationalFunction.hpp
  requiredBy:
  - Polynomial/LinearlyRecurrent.hpp
  timestamp: '2023-02-11 22:39:37+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/KthtermofLinearlyRecurrentSequence.test.cpp
documentation_of: Polynomial/CoeffofRationalFunction.hpp
layout: document
redirect_from:
- /library/Polynomial/CoeffofRationalFunction.hpp
- /library/Polynomial/CoeffofRationalFunction.hpp.html
title: Polynomial/CoeffofRationalFunction.hpp
---