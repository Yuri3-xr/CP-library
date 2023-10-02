---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: String/SuffixArray.hpp
    title: String/SuffixArray.hpp
  - icon: ':heavy_check_mark:'
    path: String/SuffixArrayFast.hpp
    title: String/SuffixArrayFast.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/NumberofSubstrings.test.cpp
    title: Verify/NumberofSubstrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/StaticRMQ.test.cpp
    title: Verify/StaticRMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/SuffixArray.test.cpp
    title: Verify/SuffixArray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    using i64 = std::int64_t;\n#line 3 \"DataStructure/RMQ.hpp\"\n\ntemplate <class\
    \ T, class Cmp = std::less<T>>\nstruct RMQ {\n    const int n;\n    const Cmp\
    \ cmp;\n    std::vector<std::vector<T>> a;\n    RMQ(const std::vector<T> &init)\
    \ : n(init.size()), cmp(Cmp()) {\n        int lg = std::__lg(n);\n        a.assign(lg\
    \ + 1, std::vector<T>(n));\n        for (int j = 0; j <= lg; j++) {\n        \
    \    for (int i = 0; i + (1 << j) <= n; i++) {\n                a[j][i] =\n  \
    \                  (j == 0 ? init[i]\n                            : std::min(a[j\
    \ - 1][i],\n                                       a[j - 1][i + (1 << (j - 1))],\
    \ cmp));\n            }\n        }\n    }\n    T rangeMin(int l, int r) {\n  \
    \      int k = std::__lg(r - l);\n        return std::min(a[k][l], a[k][r - (1\
    \ << k)], cmp);\n    }\n};\n"
  code: "#pragma once\n#include \"../Template/Template.hpp\"\n\ntemplate <class T,\
    \ class Cmp = std::less<T>>\nstruct RMQ {\n    const int n;\n    const Cmp cmp;\n\
    \    std::vector<std::vector<T>> a;\n    RMQ(const std::vector<T> &init) : n(init.size()),\
    \ cmp(Cmp()) {\n        int lg = std::__lg(n);\n        a.assign(lg + 1, std::vector<T>(n));\n\
    \        for (int j = 0; j <= lg; j++) {\n            for (int i = 0; i + (1 <<\
    \ j) <= n; i++) {\n                a[j][i] =\n                    (j == 0 ? init[i]\n\
    \                            : std::min(a[j - 1][i],\n                       \
    \                a[j - 1][i + (1 << (j - 1))], cmp));\n            }\n       \
    \ }\n    }\n    T rangeMin(int l, int r) {\n        int k = std::__lg(r - l);\n\
    \        return std::min(a[k][l], a[k][r - (1 << k)], cmp);\n    }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: DataStructure/RMQ.hpp
  requiredBy:
  - String/SuffixArray.hpp
  - String/SuffixArrayFast.hpp
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/NumberofSubstrings.test.cpp
  - Verify/StaticRMQ.test.cpp
  - Verify/SuffixArray.test.cpp
documentation_of: DataStructure/RMQ.hpp
layout: document
redirect_from:
- /library/DataStructure/RMQ.hpp
- /library/DataStructure/RMQ.hpp.html
title: DataStructure/RMQ.hpp
---
