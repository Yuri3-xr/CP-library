---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Power.hpp
    title: Template/Power.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Polynomial/Poly.hpp
    title: Polynomial/Poly.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Template/Power.hpp\"\ntemplate <class T>\nT power(T a, int\
    \ b) {\n    T res = 1;\n    for (; b; b /= 2, a *= a) {\n        if (b % 2) {\n\
    \            res *= a;\n        }\n    }\n    return res;\n}\n#line 2 \"Template/Template.hpp\"\
    \n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\nusing i64 = long long;\n\
    using VI = vector<int>;\nusing pii = pair<int, int>;\n#line 4 \"Polynomial/Ntt.hpp\"\
    \ntemplate <class Z, int rt>\nstruct NTT {\n    vector<int> rev;\n    vector<Z>\
    \ roots{0, 1};\n    void dft(vector<Z> &a) {\n        int n = a.size();\n\n  \
    \      if (int(rev.size()) != n) {\n            int k = __builtin_ctz(n) - 1;\n\
    \            rev.resize(n);\n            for (int i = 0; i < n; i++) {\n     \
    \           rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\n            }\n       \
    \ }\n\n        for (int i = 0; i < n; i++) {\n            if (rev[i] < i) {\n\
    \                swap(a[i], a[rev[i]]);\n            }\n        }\n        if\
    \ (int(roots.size()) < n) {\n            int k = __builtin_ctz(roots.size());\n\
    \            roots.resize(n);\n            while ((1 << k) < n) {\n          \
    \      Z e = power(Z(rt), (Z::get_mod() - 1) >> (k + 1));\n                for\
    \ (int i = 1 << (k - 1); i < (1 << k); i++) {\n                    roots[2 * i]\
    \ = roots[i];\n                    roots[2 * i + 1] = roots[i] * e;\n        \
    \        }\n                k++;\n            }\n        }\n        for (int k\
    \ = 1; k < n; k *= 2) {\n            for (int i = 0; i < n; i += 2 * k) {\n  \
    \              for (int j = 0; j < k; j++) {\n                    Z u = a[i +\
    \ j];\n                    Z v = a[i + j + k] * roots[k + j];\n              \
    \      a[i + j] = u + v;\n                    a[i + j + k] = u - v;\n        \
    \        }\n            }\n        }\n    }\n    void idft(vector<Z> &a) {\n \
    \       int n = a.size();\n        reverse(a.begin() + 1, a.end());\n        dft(a);\n\
    \        Z inv = (1 - Z::get_mod()) / n;\n        for (int i = 0; i < n; i++)\
    \ {\n            a[i] *= inv;\n        }\n    }\n    vector<Z> multiply(vector<Z>\
    \ a, vector<Z> b) {\n        int sz = 1, tot = a.size() + b.size() - 1;\n    \
    \    while (sz < tot) {\n            sz *= 2;\n        }\n\n        a.resize(sz),\
    \ b.resize(sz);\n        dft(a), dft(b);\n\n        for (int i = 0; i < sz; ++i)\
    \ {\n            a[i] = a[i] * b[i];\n        }\n\n        idft(a);\n        a.resize(tot);\n\
    \n        return a;\n    }\n};\n"
  code: "#pragma once\n#include \"../Template/Power.hpp\"\n#include \"../Template/Template.hpp\"\
    \ntemplate <class Z, int rt>\nstruct NTT {\n    vector<int> rev;\n    vector<Z>\
    \ roots{0, 1};\n    void dft(vector<Z> &a) {\n        int n = a.size();\n\n  \
    \      if (int(rev.size()) != n) {\n            int k = __builtin_ctz(n) - 1;\n\
    \            rev.resize(n);\n            for (int i = 0; i < n; i++) {\n     \
    \           rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\n            }\n       \
    \ }\n\n        for (int i = 0; i < n; i++) {\n            if (rev[i] < i) {\n\
    \                swap(a[i], a[rev[i]]);\n            }\n        }\n        if\
    \ (int(roots.size()) < n) {\n            int k = __builtin_ctz(roots.size());\n\
    \            roots.resize(n);\n            while ((1 << k) < n) {\n          \
    \      Z e = power(Z(rt), (Z::get_mod() - 1) >> (k + 1));\n                for\
    \ (int i = 1 << (k - 1); i < (1 << k); i++) {\n                    roots[2 * i]\
    \ = roots[i];\n                    roots[2 * i + 1] = roots[i] * e;\n        \
    \        }\n                k++;\n            }\n        }\n        for (int k\
    \ = 1; k < n; k *= 2) {\n            for (int i = 0; i < n; i += 2 * k) {\n  \
    \              for (int j = 0; j < k; j++) {\n                    Z u = a[i +\
    \ j];\n                    Z v = a[i + j + k] * roots[k + j];\n              \
    \      a[i + j] = u + v;\n                    a[i + j + k] = u - v;\n        \
    \        }\n            }\n        }\n    }\n    void idft(vector<Z> &a) {\n \
    \       int n = a.size();\n        reverse(a.begin() + 1, a.end());\n        dft(a);\n\
    \        Z inv = (1 - Z::get_mod()) / n;\n        for (int i = 0; i < n; i++)\
    \ {\n            a[i] *= inv;\n        }\n    }\n    vector<Z> multiply(vector<Z>\
    \ a, vector<Z> b) {\n        int sz = 1, tot = a.size() + b.size() - 1;\n    \
    \    while (sz < tot) {\n            sz *= 2;\n        }\n\n        a.resize(sz),\
    \ b.resize(sz);\n        dft(a), dft(b);\n\n        for (int i = 0; i < sz; ++i)\
    \ {\n            a[i] = a[i] * b[i];\n        }\n\n        idft(a);\n        a.resize(tot);\n\
    \n        return a;\n    }\n};\n"
  dependsOn:
  - Template/Power.hpp
  - Template/Template.hpp
  isVerificationFile: false
  path: Polynomial/Ntt.hpp
  requiredBy:
  - Polynomial/Poly.hpp
  timestamp: '2022-08-20 01:45:54+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/convolution.test.cpp
documentation_of: Polynomial/Ntt.hpp
layout: document
redirect_from:
- /library/Polynomial/Ntt.hpp
- /library/Polynomial/Ntt.hpp.html
title: Polynomial/Ntt.hpp
---
