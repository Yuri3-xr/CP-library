---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ModInt/Binomial.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"ModInt/Binomial.hpp\"\
    \n\ntemplate <class T>\nstruct Binomial {\n    std::vector<T> f, g, h;\n    Binomial(int\
    \ MAX = 0) {\n        f.resize(1, T{1});\n        while (MAX >= (int)f.size())\
    \ extend();\n    }\n\n    void extend() {\n        int n = f.size();\n       \
    \ int m = n * 2;\n        f.resize(m);\n        g.resize(m);\n        h.resize(m);\n\
    \        for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n        g[m - 1]\
    \ = f[m - 1].inverse();\n        h[m - 1] = g[m - 1] * f[m - 2];\n        for\
    \ (int i = m - 2; i >= n; i--) {\n            g[i] = g[i + 1] * T(i + 1);\n  \
    \          h[i] = g[i] * f[i - 1];\n        }\n    }\n\n    T fac(int i) {\n \
    \       if (i < 0) return T(0);\n        while (i >= (int)f.size()) extend();\n\
    \        return f[i];\n    }\n\n    T finv(int i) {\n        if (i < 0) return\
    \ T(0);\n        while (i >= (int)g.size()) extend();\n        return g[i];\n\
    \    }\n\n    T inv(int i) {\n        if (i < 0) return -inv(-i);\n        while\
    \ (i >= (int)h.size()) extend();\n        return h[i];\n    }\n\n    T C(int n,\
    \ int r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n        return\
    \ fac(n) * finv(n - r) * finv(r);\n    }\n\n    inline T operator()(int n, int\
    \ r) { return C(n, r); }\n\n    template <typename I>\n    T multinomial(const\
    \ std::vector<I>& r) {\n        static_assert(is_integral<I>::value == true);\n\
    \        int n = 0;\n        for (auto& x : r) {\n            if (x < 0) return\
    \ T(0);\n            n += x;\n        }\n        T res = fac(n);\n        for\
    \ (auto& x : r) res *= finv(x);\n        return res;\n    }\n\n    template <typename\
    \ I>\n    T operator()(const std::vector<I>& r) {\n        return multinomial(r);\n\
    \    }\n\n    T C_naive(int n, int r) {\n        if (n < 0 || n < r || r < 0)\
    \ return T(0);\n        T ret = T(1);\n        r = std::min(r, n - r);\n     \
    \   for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n        return ret;\n\
    \    }\n\n    T P(int n, int r) {\n        if (n < 0 || n < r || r < 0) return\
    \ T(0);\n        return fac(n) * finv(n - r);\n    }\n\n    T H(int n, int r)\
    \ {\n        if (n < 0 || r < 0) return T(0);\n        return r == 0 ? 1 : C(n\
    \ + r - 1, r);\n    }\n};\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n\ntemplate <class\
    \ T>\nstruct Binomial {\n    std::vector<T> f, g, h;\n    Binomial(int MAX = 0)\
    \ {\n        f.resize(1, T{1});\n        while (MAX >= (int)f.size()) extend();\n\
    \    }\n\n    void extend() {\n        int n = f.size();\n        int m = n *\
    \ 2;\n        f.resize(m);\n        g.resize(m);\n        h.resize(m);\n     \
    \   for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n        g[m - 1] = f[m\
    \ - 1].inverse();\n        h[m - 1] = g[m - 1] * f[m - 2];\n        for (int i\
    \ = m - 2; i >= n; i--) {\n            g[i] = g[i + 1] * T(i + 1);\n         \
    \   h[i] = g[i] * f[i - 1];\n        }\n    }\n\n    T fac(int i) {\n        if\
    \ (i < 0) return T(0);\n        while (i >= (int)f.size()) extend();\n       \
    \ return f[i];\n    }\n\n    T finv(int i) {\n        if (i < 0) return T(0);\n\
    \        while (i >= (int)g.size()) extend();\n        return g[i];\n    }\n\n\
    \    T inv(int i) {\n        if (i < 0) return -inv(-i);\n        while (i >=\
    \ (int)h.size()) extend();\n        return h[i];\n    }\n\n    T C(int n, int\
    \ r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n        return fac(n)\
    \ * finv(n - r) * finv(r);\n    }\n\n    inline T operator()(int n, int r) { return\
    \ C(n, r); }\n\n    template <typename I>\n    T multinomial(const std::vector<I>&\
    \ r) {\n        static_assert(is_integral<I>::value == true);\n        int n =\
    \ 0;\n        for (auto& x : r) {\n            if (x < 0) return T(0);\n     \
    \       n += x;\n        }\n        T res = fac(n);\n        for (auto& x : r)\
    \ res *= finv(x);\n        return res;\n    }\n\n    template <typename I>\n \
    \   T operator()(const std::vector<I>& r) {\n        return multinomial(r);\n\
    \    }\n\n    T C_naive(int n, int r) {\n        if (n < 0 || n < r || r < 0)\
    \ return T(0);\n        T ret = T(1);\n        r = std::min(r, n - r);\n     \
    \   for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n        return ret;\n\
    \    }\n\n    T P(int n, int r) {\n        if (n < 0 || n < r || r < 0) return\
    \ T(0);\n        return fac(n) * finv(n - r);\n    }\n\n    T H(int n, int r)\
    \ {\n        if (n < 0 || r < 0) return T(0);\n        return r == 0 ? 1 : C(n\
    \ + r - 1, r);\n    }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: ModInt/Binomial.hpp
  requiredBy: []
  timestamp: '2023-03-24 02:56:20+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ModInt/Binomial.hpp
layout: document
redirect_from:
- /library/ModInt/Binomial.hpp
- /library/ModInt/Binomial.hpp.html
title: ModInt/Binomial.hpp
---
