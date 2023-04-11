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
    path: Polynomial/CoeffofRationalFunction.hpp
    title: Polynomial/CoeffofRationalFunction.hpp
  - icon: ':warning:'
    path: Polynomial/Factorial.hpp
    title: Polynomial/Factorial.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/LinearlyRecurrent.hpp
    title: Polynomial/LinearlyRecurrent.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/NttLarge.hpp
    title: Polynomial/NttLarge.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/Poly.hpp
    title: Polynomial/Poly.hpp
  - icon: ':warning:'
    path: Polynomial/PrefixSumBinomial.hpp
    title: Polynomial/PrefixSumBinomial.hpp
  - icon: ':warning:'
    path: Polynomial/PrefixSumH.hpp
    title: Polynomial/PrefixSumH.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/ConvolutionLarge.test.cpp
    title: Verify/ConvolutionLarge.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/InvofFormalPowerSeries.test.cpp
    title: Verify/InvofFormalPowerSeries.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/KthtermofLinearlyRecurrentSequence.test.cpp
    title: Verify/KthtermofLinearlyRecurrentSequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Multipoint_Evaluation.test.cpp
    title: Verify/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Polynomial_Interpolation.test.cpp
    title: Verify/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Polynomial/Ntt.hpp\"\n\n#line 1 \"Template/Power.hpp\"\n\
    template <class T>\nT power(T a, int b) {\n    T res = 1;\n    for (; b; b /=\
    \ 2, a *= a) {\n        if (b % 2) {\n            res *= a;\n        }\n    }\n\
    \    return res;\n}\n#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\
    \nusing i64 = std::int64_t;\n#line 5 \"Polynomial/Ntt.hpp\"\ntemplate <class Z>\n\
    struct NTT {\n    std::vector<int> rev;\n    std::vector<Z> roots{0, 1};\n\n \
    \   static constexpr int getRoot() {\n        auto _mod = Z::get_mod();\n    \
    \    using u64 = uint64_t;\n        u64 ds[32] = {};\n        int idx = 0;\n \
    \       u64 m = _mod - 1;\n        for (u64 i = 2; i * i <= m; ++i) {\n      \
    \      if (m % i == 0) {\n                ds[idx++] = i;\n                while\
    \ (m % i == 0) m /= i;\n            }\n        }\n        if (m != 1) ds[idx++]\
    \ = m;\n\n        int _pr = 2;\n        for (;;) {\n            int flg = 1;\n\
    \            for (int i = 0; i < idx; ++i) {\n                u64 a = _pr, b =\
    \ (_mod - 1) / ds[i], r = 1;\n                for (; b; a = a * a % _mod, b /=\
    \ 2) {\n                    if (b % 2 == 1) r = r * a % _mod;\n              \
    \  }\n                if (r == 1) {\n                    flg = 0;\n          \
    \          break;\n                }\n            }\n            if (flg == 1)\
    \ break;\n            ++_pr;\n        }\n        return _pr;\n    };\n\n    static\
    \ constexpr int rt = getRoot();\n\n    void dft(std::vector<Z> &a) {\n       \
    \ int n = a.size();\n\n        if (int(rev.size()) != n) {\n            int k\
    \ = __builtin_ctz(n) - 1;\n            rev.resize(n);\n            for (int i\
    \ = 0; i < n; i++) {\n                rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\n\
    \            }\n        }\n\n        for (int i = 0; i < n; i++) {\n         \
    \   if (rev[i] < i) {\n                std::swap(a[i], a[rev[i]]);\n         \
    \   }\n        }\n        if (int(roots.size()) < n) {\n            int k = __builtin_ctz(roots.size());\n\
    \            roots.resize(n);\n            while ((1 << k) < n) {\n          \
    \      Z e = power(Z(rt), (Z::get_mod() - 1) >> (k + 1));\n                for\
    \ (int i = 1 << (k - 1); i < (1 << k); i++) {\n                    roots[2 * i]\
    \ = roots[i];\n                    roots[2 * i + 1] = roots[i] * e;\n        \
    \        }\n                k++;\n            }\n        }\n        for (int k\
    \ = 1; k < n; k *= 2) {\n            for (int i = 0; i < n; i += 2 * k) {\n  \
    \              for (int j = 0; j < k; j++) {\n                    Z u = a[i +\
    \ j];\n                    Z v = a[i + j + k] * roots[k + j];\n              \
    \      a[i + j] = u + v;\n                    a[i + j + k] = u - v;\n        \
    \        }\n            }\n        }\n    }\n    void idft(std::vector<Z> &a)\
    \ {\n        int n = a.size();\n        reverse(a.begin() + 1, a.end());\n   \
    \     dft(a);\n        Z inv = (1 - Z::get_mod()) / n;\n        for (int i = 0;\
    \ i < n; i++) {\n            a[i] *= inv;\n        }\n    }\n    std::vector<Z>\
    \ multiply(std::vector<Z> a, std::vector<Z> b) {\n        int sz = 1, tot = a.size()\
    \ + b.size() - 1;\n\n        if (tot <= 20) {\n            std::vector<Z> ret(tot);\n\
    \            for (size_t i = 0; i < a.size(); i++)\n                for (size_t\
    \ j = 0; j < b.size(); j++) ret[i + j] += a[i] * b[j];\n            return ret;\n\
    \        }\n\n        while (sz < tot) {\n            sz *= 2;\n        }\n\n\
    \        a.resize(sz), b.resize(sz);\n        dft(a), dft(b);\n\n        for (int\
    \ i = 0; i < sz; ++i) {\n            a[i] = a[i] * b[i];\n        }\n\n      \
    \  idft(a);\n        a.resize(tot);\n        return a;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../Template/Power.hpp\"\n#include \"../Template/Template.hpp\"\
    \ntemplate <class Z>\nstruct NTT {\n    std::vector<int> rev;\n    std::vector<Z>\
    \ roots{0, 1};\n\n    static constexpr int getRoot() {\n        auto _mod = Z::get_mod();\n\
    \        using u64 = uint64_t;\n        u64 ds[32] = {};\n        int idx = 0;\n\
    \        u64 m = _mod - 1;\n        for (u64 i = 2; i * i <= m; ++i) {\n     \
    \       if (m % i == 0) {\n                ds[idx++] = i;\n                while\
    \ (m % i == 0) m /= i;\n            }\n        }\n        if (m != 1) ds[idx++]\
    \ = m;\n\n        int _pr = 2;\n        for (;;) {\n            int flg = 1;\n\
    \            for (int i = 0; i < idx; ++i) {\n                u64 a = _pr, b =\
    \ (_mod - 1) / ds[i], r = 1;\n                for (; b; a = a * a % _mod, b /=\
    \ 2) {\n                    if (b % 2 == 1) r = r * a % _mod;\n              \
    \  }\n                if (r == 1) {\n                    flg = 0;\n          \
    \          break;\n                }\n            }\n            if (flg == 1)\
    \ break;\n            ++_pr;\n        }\n        return _pr;\n    };\n\n    static\
    \ constexpr int rt = getRoot();\n\n    void dft(std::vector<Z> &a) {\n       \
    \ int n = a.size();\n\n        if (int(rev.size()) != n) {\n            int k\
    \ = __builtin_ctz(n) - 1;\n            rev.resize(n);\n            for (int i\
    \ = 0; i < n; i++) {\n                rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\n\
    \            }\n        }\n\n        for (int i = 0; i < n; i++) {\n         \
    \   if (rev[i] < i) {\n                std::swap(a[i], a[rev[i]]);\n         \
    \   }\n        }\n        if (int(roots.size()) < n) {\n            int k = __builtin_ctz(roots.size());\n\
    \            roots.resize(n);\n            while ((1 << k) < n) {\n          \
    \      Z e = power(Z(rt), (Z::get_mod() - 1) >> (k + 1));\n                for\
    \ (int i = 1 << (k - 1); i < (1 << k); i++) {\n                    roots[2 * i]\
    \ = roots[i];\n                    roots[2 * i + 1] = roots[i] * e;\n        \
    \        }\n                k++;\n            }\n        }\n        for (int k\
    \ = 1; k < n; k *= 2) {\n            for (int i = 0; i < n; i += 2 * k) {\n  \
    \              for (int j = 0; j < k; j++) {\n                    Z u = a[i +\
    \ j];\n                    Z v = a[i + j + k] * roots[k + j];\n              \
    \      a[i + j] = u + v;\n                    a[i + j + k] = u - v;\n        \
    \        }\n            }\n        }\n    }\n    void idft(std::vector<Z> &a)\
    \ {\n        int n = a.size();\n        reverse(a.begin() + 1, a.end());\n   \
    \     dft(a);\n        Z inv = (1 - Z::get_mod()) / n;\n        for (int i = 0;\
    \ i < n; i++) {\n            a[i] *= inv;\n        }\n    }\n    std::vector<Z>\
    \ multiply(std::vector<Z> a, std::vector<Z> b) {\n        int sz = 1, tot = a.size()\
    \ + b.size() - 1;\n\n        if (tot <= 20) {\n            std::vector<Z> ret(tot);\n\
    \            for (size_t i = 0; i < a.size(); i++)\n                for (size_t\
    \ j = 0; j < b.size(); j++) ret[i + j] += a[i] * b[j];\n            return ret;\n\
    \        }\n\n        while (sz < tot) {\n            sz *= 2;\n        }\n\n\
    \        a.resize(sz), b.resize(sz);\n        dft(a), dft(b);\n\n        for (int\
    \ i = 0; i < sz; ++i) {\n            a[i] = a[i] * b[i];\n        }\n\n      \
    \  idft(a);\n        a.resize(tot);\n        return a;\n    }\n};\n"
  dependsOn:
  - Template/Power.hpp
  - Template/Template.hpp
  isVerificationFile: false
  path: Polynomial/Ntt.hpp
  requiredBy:
  - Polynomial/Poly.hpp
  - Polynomial/PrefixSumBinomial.hpp
  - Polynomial/CoeffofRationalFunction.hpp
  - Polynomial/Factorial.hpp
  - Polynomial/LinearlyRecurrent.hpp
  - Polynomial/NttLarge.hpp
  - Polynomial/PrefixSumH.hpp
  timestamp: '2023-04-12 00:49:31+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/InvofFormalPowerSeries.test.cpp
  - Verify/Multipoint_Evaluation.test.cpp
  - Verify/convolution.test.cpp
  - Verify/Polynomial_Interpolation.test.cpp
  - Verify/ConvolutionLarge.test.cpp
  - Verify/KthtermofLinearlyRecurrentSequence.test.cpp
documentation_of: Polynomial/Ntt.hpp
layout: document
redirect_from:
- /library/Polynomial/Ntt.hpp
- /library/Polynomial/Ntt.hpp.html
title: Polynomial/Ntt.hpp
---
