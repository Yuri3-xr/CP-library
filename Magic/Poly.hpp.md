---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Magic/Poly.hpp\"\n\ntemplate <class T>\nT power(T a, int\
    \ b) {\n    T res = 1;\n    for (; b; b /= 2, a *= a) {\n        if (b % 2) {\n\
    \            res *= a;\n        }\n    }\n    return res;\n}\nvector<int> rev;\n\
    vector<Z> roots{0, 1};\nvoid dft(vector<Z> &a) {\n    int n = a.size();\n\n  \
    \  if (int(rev.size()) != n) {\n        int k = __builtin_ctz(n) - 1;\n      \
    \  rev.resize(n);\n        for (int i = 0; i < n; i++) {\n            rev[i] =\
    \ rev[i >> 1] >> 1 | (i & 1) << k;\n        }\n    }\n\n    for (int i = 0; i\
    \ < n; i++) {\n        if (rev[i] < i) {\n            swap(a[i], a[rev[i]]);\n\
    \        }\n    }\n    if (int(roots.size()) < n) {\n        int k = __builtin_ctz(roots.size());\n\
    \        roots.resize(n);\n        while ((1 << k) < n) {\n            Z e = power(Z(3),\
    \ (mod - 1) >> (k + 1));\n            for (int i = 1 << (k - 1); i < (1 << k);\
    \ i++) {\n                roots[2 * i] = roots[i];\n                roots[2 *\
    \ i + 1] = roots[i] * e;\n            }\n            k++;\n        }\n    }\n\
    \    for (int k = 1; k < n; k *= 2) {\n        for (int i = 0; i < n; i += 2 *\
    \ k) {\n            for (int j = 0; j < k; j++) {\n                Z u = a[i +\
    \ j];\n                Z v = a[i + j + k] * roots[k + j];\n                a[i\
    \ + j] = u + v;\n                a[i + j + k] = u - v;\n            }\n      \
    \  }\n    }\n}\nvoid idft(vector<Z> &a) {\n    int n = a.size();\n    reverse(a.begin()\
    \ + 1, a.end());\n    dft(a);\n    Z inv = (1 - mod) / n;\n    for (int i = 0;\
    \ i < n; i++) {\n        a[i] *= inv;\n    }\n}\nstruct Poly {\n    vector<Z>\
    \ a;\n    Poly() {}\n    Poly(const vector<Z> &a) : a(a) {}\n    Poly(const initializer_list<Z>\
    \ &a) : a(a) {}\n    int size() const { return a.size(); }\n    void resize(int\
    \ n) { a.resize(n); }\n    Z operator[](int idx) const {\n        if (idx < size())\
    \ {\n            return a[idx];\n        } else {\n            return 0;\n   \
    \     }\n    }\n    Z &operator[](int idx) { return a[idx]; }\n    Poly mulxk(int\
    \ k) const {\n        auto b = a;\n        b.insert(b.begin(), k, 0);\n      \
    \  return Poly(b);\n    }\n    Poly modxk(int k) const {\n        k = min(k, size());\n\
    \        return Poly(vector<Z>(a.begin(), a.begin() + k));\n    }\n    Poly divxk(int\
    \ k) const {\n        if (size() <= k) {\n            return Poly();\n       \
    \ }\n        return Poly(vector<Z>(a.begin() + k, a.end()));\n    }\n    friend\
    \ Poly operator+(const Poly &a, const Poly &b) {\n        vector<Z> res(max(a.size(),\
    \ b.size()));\n        for (int i = 0; i < int(res.size()); i++) {\n         \
    \   res[i] = a[i] + b[i];\n        }\n        return Poly(res);\n    }\n    friend\
    \ Poly operator-(const Poly &a, const Poly &b) {\n        vector<Z> res(max(a.size(),\
    \ b.size()));\n        for (int i = 0; i < int(res.size()); i++) {\n         \
    \   res[i] = a[i] - b[i];\n        }\n        return Poly(res);\n    }\n    friend\
    \ Poly operator*(Poly a, Poly b) {\n        if (a.size() == 0 || b.size() == 0)\
    \ {\n            return Poly();\n        }\n        int sz = 1, tot = a.size()\
    \ + b.size() - 1;\n        while (sz < tot) {\n            sz *= 2;\n        }\n\
    \        a.a.resize(sz);\n        b.a.resize(sz);\n        dft(a.a);\n       \
    \ dft(b.a);\n        for (int i = 0; i < sz; ++i) {\n            a.a[i] = a[i]\
    \ * b[i];\n        }\n        idft(a.a);\n        a.resize(tot);\n        return\
    \ a;\n    }\n    friend Poly operator*(Z a, Poly b) {\n        for (int i = 0;\
    \ i < int(b.size()); i++) {\n            b[i] *= a;\n        }\n        return\
    \ b;\n    }\n    friend Poly operator*(Poly a, Z b) {\n        for (int i = 0;\
    \ i < int(a.size()); i++) {\n            a[i] *= b;\n        }\n        return\
    \ a;\n    }\n    Poly &operator+=(Poly b) { return (*this) = (*this) + b; }\n\
    \    Poly &operator-=(Poly b) { return (*this) = (*this) - b; }\n    Poly &operator*=(Poly\
    \ b) { return (*this) = (*this) * b; }\n    Poly deriv() const {\n        if (a.empty())\
    \ {\n            return Poly();\n        }\n        vector<Z> res(size() - 1);\n\
    \        for (int i = 0; i < size() - 1; ++i) {\n            res[i] = Z(i + 1)\
    \ * a[i + 1];\n        }\n        return Poly(res);\n    }\n    Poly integr()\
    \ const {\n        vector<Z> res(size() + 1);\n        for (int i = 0; i < size();\
    \ ++i) {\n            res[i + 1] = a[i] / (i + 1);\n        }\n        return\
    \ Poly(res);\n    }\n    Poly inv(int m) const {\n        Poly x{a[0].inverse()};\n\
    \        int k = 1;\n        while (k < m) {\n            k *= 2;\n          \
    \  x = (x * (Poly{2} - modxk(k) * x)).modxk(k);\n        }\n        return x.modxk(m);\n\
    \    }\n    Poly log(int m) const { return (deriv() * inv(m)).integr().modxk(m);\
    \ }\n    Poly exp(int m) const {\n        Poly x{1};\n        int k = 1;\n   \
    \     while (k < m) {\n            k *= 2;\n            x = (x * (Poly{1} - x.log(k)\
    \ + modxk(k))).modxk(k);\n        }\n        return x.modxk(m);\n    }\n    Poly\
    \ pow(int k, int m) const {\n        int i = 0;\n        while (i < size() &&\
    \ a[i].get() == 0) {\n            i++;\n        }\n        if (i == size() ||\
    \ 1LL * i * k >= m) {\n            return Poly(vector<Z>(m));\n        }\n   \
    \     Z v = a[i];\n        auto f = divxk(i) * v.inverse();\n        return (f.log(m\
    \ - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);\n    }\n    Poly sqrt(int\
    \ m) const {\n        Poly x{1};\n        int k = 1;\n        while (k < m) {\n\
    \            k *= 2;\n            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((mod\
    \ + 1) / 2);\n        }\n        return x.modxk(m);\n    }\n    Poly mulT(Poly\
    \ b) const {\n        if (b.size() == 0) {\n            return Poly();\n     \
    \   }\n        int n = b.size();\n        reverse(b.a.begin(), b.a.end());\n \
    \       return ((*this) * b).divxk(n - 1);\n    }\n    vector<Z> eval(vector<Z>\
    \ x) const {\n        if (size() == 0) {\n            return vector<Z>(x.size(),\
    \ 0);\n        }\n        const int n = max(int(x.size()), size());\n        vector<Poly>\
    \ q(4 * n);\n        vector<Z> ans(x.size());\n        x.resize(n);\n        function<void(int,\
    \ int, int)> build = [&](int p, int l, int r) {\n            if (r - l == 1) {\n\
    \                q[p] = Poly{1, -x[l]};\n            } else {\n              \
    \  int m = (l + r) / 2;\n                build(2 * p, l, m);\n               \
    \ build(2 * p + 1, m, r);\n                q[p] = q[2 * p] * q[2 * p + 1];\n \
    \           }\n        };\n        build(1, 0, n);\n        function<void(int,\
    \ int, int, const Poly &)> work =\n            [&](int p, int l, int r, const\
    \ Poly &num) {\n                if (r - l == 1) {\n                    if (l <\
    \ int(ans.size())) {\n                        ans[l] = num[0];\n             \
    \       }\n                } else {\n                    int m = (l + r) / 2;\n\
    \                    work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));\n\
    \                    work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));\n\
    \                }\n            };\n        work(1, 0, n, mulT(q[1].inv(n)));\n\
    \        return ans;\n    }\n    Poly inter(const Poly &x, const Poly &y) {\n\
    \        vector<Poly> Q(x.size() << 2), P(x.size() << 2);\n        function<void(int,\
    \ int, int)> dfs1 = [&](int p, int l, int r) {\n            int m = (l + r) >>\
    \ 1;\n            if (l == r) {\n                Q[p].a.push_back(-x[m]);\n  \
    \              Q[p].a.push_back(Z(1));\n                return;\n            }\n\
    \            dfs1(p * 2, l, m);\n            dfs1(p * 2 + 1, m + 1, r);\n    \
    \        Q[p] = Q[p * 2] * Q[p * 2 + 1];\n        };\n        dfs1(1, 0, x.size()\
    \ - 1);\n        Poly f;\n        f.a.resize((int)(Q[1].size()) - 1);\n      \
    \  for (int i = 0; i + 1 < Q[1].size(); i += 1)\n            f[i] = (Q[1][i +\
    \ 1] * (i + 1));\n        Poly g = f.eval(x.a);\n        function<void(int, int,\
    \ int)> dfs2 = [&](int p, int l, int r) {\n            int m = (l + r) >> 1;\n\
    \            if (l == r) {\n                P[p].a.push_back(y[m] * power(g[m],\
    \ mod - 2));\n                return;\n            }\n            dfs2(p * 2,\
    \ l, m);\n            dfs2(p * 2 + 1, m + 1, r);\n            P[p].a.resize(r\
    \ - l + 1);\n            Poly A = P[p * 2] * Q[p * 2 + 1];\n            Poly B\
    \ = P[p * 2 + 1] * Q[p * 2];\n            for (int i = 0; i <= r - l; i++) P[p][i]\
    \ = (A[i] + B[i]);\n        };\n        dfs2(1, 0, x.size() - 1);\n        return\
    \ P[1];\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nT power(T a, int b) {\n    T res = 1;\n\
    \    for (; b; b /= 2, a *= a) {\n        if (b % 2) {\n            res *= a;\n\
    \        }\n    }\n    return res;\n}\nvector<int> rev;\nvector<Z> roots{0, 1};\n\
    void dft(vector<Z> &a) {\n    int n = a.size();\n\n    if (int(rev.size()) !=\
    \ n) {\n        int k = __builtin_ctz(n) - 1;\n        rev.resize(n);\n      \
    \  for (int i = 0; i < n; i++) {\n            rev[i] = rev[i >> 1] >> 1 | (i &\
    \ 1) << k;\n        }\n    }\n\n    for (int i = 0; i < n; i++) {\n        if\
    \ (rev[i] < i) {\n            swap(a[i], a[rev[i]]);\n        }\n    }\n    if\
    \ (int(roots.size()) < n) {\n        int k = __builtin_ctz(roots.size());\n  \
    \      roots.resize(n);\n        while ((1 << k) < n) {\n            Z e = power(Z(3),\
    \ (mod - 1) >> (k + 1));\n            for (int i = 1 << (k - 1); i < (1 << k);\
    \ i++) {\n                roots[2 * i] = roots[i];\n                roots[2 *\
    \ i + 1] = roots[i] * e;\n            }\n            k++;\n        }\n    }\n\
    \    for (int k = 1; k < n; k *= 2) {\n        for (int i = 0; i < n; i += 2 *\
    \ k) {\n            for (int j = 0; j < k; j++) {\n                Z u = a[i +\
    \ j];\n                Z v = a[i + j + k] * roots[k + j];\n                a[i\
    \ + j] = u + v;\n                a[i + j + k] = u - v;\n            }\n      \
    \  }\n    }\n}\nvoid idft(vector<Z> &a) {\n    int n = a.size();\n    reverse(a.begin()\
    \ + 1, a.end());\n    dft(a);\n    Z inv = (1 - mod) / n;\n    for (int i = 0;\
    \ i < n; i++) {\n        a[i] *= inv;\n    }\n}\nstruct Poly {\n    vector<Z>\
    \ a;\n    Poly() {}\n    Poly(const vector<Z> &a) : a(a) {}\n    Poly(const initializer_list<Z>\
    \ &a) : a(a) {}\n    int size() const { return a.size(); }\n    void resize(int\
    \ n) { a.resize(n); }\n    Z operator[](int idx) const {\n        if (idx < size())\
    \ {\n            return a[idx];\n        } else {\n            return 0;\n   \
    \     }\n    }\n    Z &operator[](int idx) { return a[idx]; }\n    Poly mulxk(int\
    \ k) const {\n        auto b = a;\n        b.insert(b.begin(), k, 0);\n      \
    \  return Poly(b);\n    }\n    Poly modxk(int k) const {\n        k = min(k, size());\n\
    \        return Poly(vector<Z>(a.begin(), a.begin() + k));\n    }\n    Poly divxk(int\
    \ k) const {\n        if (size() <= k) {\n            return Poly();\n       \
    \ }\n        return Poly(vector<Z>(a.begin() + k, a.end()));\n    }\n    friend\
    \ Poly operator+(const Poly &a, const Poly &b) {\n        vector<Z> res(max(a.size(),\
    \ b.size()));\n        for (int i = 0; i < int(res.size()); i++) {\n         \
    \   res[i] = a[i] + b[i];\n        }\n        return Poly(res);\n    }\n    friend\
    \ Poly operator-(const Poly &a, const Poly &b) {\n        vector<Z> res(max(a.size(),\
    \ b.size()));\n        for (int i = 0; i < int(res.size()); i++) {\n         \
    \   res[i] = a[i] - b[i];\n        }\n        return Poly(res);\n    }\n    friend\
    \ Poly operator*(Poly a, Poly b) {\n        if (a.size() == 0 || b.size() == 0)\
    \ {\n            return Poly();\n        }\n        int sz = 1, tot = a.size()\
    \ + b.size() - 1;\n        while (sz < tot) {\n            sz *= 2;\n        }\n\
    \        a.a.resize(sz);\n        b.a.resize(sz);\n        dft(a.a);\n       \
    \ dft(b.a);\n        for (int i = 0; i < sz; ++i) {\n            a.a[i] = a[i]\
    \ * b[i];\n        }\n        idft(a.a);\n        a.resize(tot);\n        return\
    \ a;\n    }\n    friend Poly operator*(Z a, Poly b) {\n        for (int i = 0;\
    \ i < int(b.size()); i++) {\n            b[i] *= a;\n        }\n        return\
    \ b;\n    }\n    friend Poly operator*(Poly a, Z b) {\n        for (int i = 0;\
    \ i < int(a.size()); i++) {\n            a[i] *= b;\n        }\n        return\
    \ a;\n    }\n    Poly &operator+=(Poly b) { return (*this) = (*this) + b; }\n\
    \    Poly &operator-=(Poly b) { return (*this) = (*this) - b; }\n    Poly &operator*=(Poly\
    \ b) { return (*this) = (*this) * b; }\n    Poly deriv() const {\n        if (a.empty())\
    \ {\n            return Poly();\n        }\n        vector<Z> res(size() - 1);\n\
    \        for (int i = 0; i < size() - 1; ++i) {\n            res[i] = Z(i + 1)\
    \ * a[i + 1];\n        }\n        return Poly(res);\n    }\n    Poly integr()\
    \ const {\n        vector<Z> res(size() + 1);\n        for (int i = 0; i < size();\
    \ ++i) {\n            res[i + 1] = a[i] / (i + 1);\n        }\n        return\
    \ Poly(res);\n    }\n    Poly inv(int m) const {\n        Poly x{a[0].inverse()};\n\
    \        int k = 1;\n        while (k < m) {\n            k *= 2;\n          \
    \  x = (x * (Poly{2} - modxk(k) * x)).modxk(k);\n        }\n        return x.modxk(m);\n\
    \    }\n    Poly log(int m) const { return (deriv() * inv(m)).integr().modxk(m);\
    \ }\n    Poly exp(int m) const {\n        Poly x{1};\n        int k = 1;\n   \
    \     while (k < m) {\n            k *= 2;\n            x = (x * (Poly{1} - x.log(k)\
    \ + modxk(k))).modxk(k);\n        }\n        return x.modxk(m);\n    }\n    Poly\
    \ pow(int k, int m) const {\n        int i = 0;\n        while (i < size() &&\
    \ a[i].get() == 0) {\n            i++;\n        }\n        if (i == size() ||\
    \ 1LL * i * k >= m) {\n            return Poly(vector<Z>(m));\n        }\n   \
    \     Z v = a[i];\n        auto f = divxk(i) * v.inverse();\n        return (f.log(m\
    \ - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);\n    }\n    Poly sqrt(int\
    \ m) const {\n        Poly x{1};\n        int k = 1;\n        while (k < m) {\n\
    \            k *= 2;\n            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((mod\
    \ + 1) / 2);\n        }\n        return x.modxk(m);\n    }\n    Poly mulT(Poly\
    \ b) const {\n        if (b.size() == 0) {\n            return Poly();\n     \
    \   }\n        int n = b.size();\n        reverse(b.a.begin(), b.a.end());\n \
    \       return ((*this) * b).divxk(n - 1);\n    }\n    vector<Z> eval(vector<Z>\
    \ x) const {\n        if (size() == 0) {\n            return vector<Z>(x.size(),\
    \ 0);\n        }\n        const int n = max(int(x.size()), size());\n        vector<Poly>\
    \ q(4 * n);\n        vector<Z> ans(x.size());\n        x.resize(n);\n        function<void(int,\
    \ int, int)> build = [&](int p, int l, int r) {\n            if (r - l == 1) {\n\
    \                q[p] = Poly{1, -x[l]};\n            } else {\n              \
    \  int m = (l + r) / 2;\n                build(2 * p, l, m);\n               \
    \ build(2 * p + 1, m, r);\n                q[p] = q[2 * p] * q[2 * p + 1];\n \
    \           }\n        };\n        build(1, 0, n);\n        function<void(int,\
    \ int, int, const Poly &)> work =\n            [&](int p, int l, int r, const\
    \ Poly &num) {\n                if (r - l == 1) {\n                    if (l <\
    \ int(ans.size())) {\n                        ans[l] = num[0];\n             \
    \       }\n                } else {\n                    int m = (l + r) / 2;\n\
    \                    work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));\n\
    \                    work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));\n\
    \                }\n            };\n        work(1, 0, n, mulT(q[1].inv(n)));\n\
    \        return ans;\n    }\n    Poly inter(const Poly &x, const Poly &y) {\n\
    \        vector<Poly> Q(x.size() << 2), P(x.size() << 2);\n        function<void(int,\
    \ int, int)> dfs1 = [&](int p, int l, int r) {\n            int m = (l + r) >>\
    \ 1;\n            if (l == r) {\n                Q[p].a.push_back(-x[m]);\n  \
    \              Q[p].a.push_back(Z(1));\n                return;\n            }\n\
    \            dfs1(p * 2, l, m);\n            dfs1(p * 2 + 1, m + 1, r);\n    \
    \        Q[p] = Q[p * 2] * Q[p * 2 + 1];\n        };\n        dfs1(1, 0, x.size()\
    \ - 1);\n        Poly f;\n        f.a.resize((int)(Q[1].size()) - 1);\n      \
    \  for (int i = 0; i + 1 < Q[1].size(); i += 1)\n            f[i] = (Q[1][i +\
    \ 1] * (i + 1));\n        Poly g = f.eval(x.a);\n        function<void(int, int,\
    \ int)> dfs2 = [&](int p, int l, int r) {\n            int m = (l + r) >> 1;\n\
    \            if (l == r) {\n                P[p].a.push_back(y[m] * power(g[m],\
    \ mod - 2));\n                return;\n            }\n            dfs2(p * 2,\
    \ l, m);\n            dfs2(p * 2 + 1, m + 1, r);\n            P[p].a.resize(r\
    \ - l + 1);\n            Poly A = P[p * 2] * Q[p * 2 + 1];\n            Poly B\
    \ = P[p * 2 + 1] * Q[p * 2];\n            for (int i = 0; i <= r - l; i++) P[p][i]\
    \ = (A[i] + B[i]);\n        };\n        dfs2(1, 0, x.size() - 1);\n        return\
    \ P[1];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Magic/Poly.hpp
  requiredBy: []
  timestamp: '2022-08-16 22:05:54+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/convolution.test.cpp
documentation_of: Magic/Poly.hpp
layout: document
redirect_from:
- /library/Magic/Poly.hpp
- /library/Magic/Poly.hpp.html
title: Magic/Poly.hpp
---
