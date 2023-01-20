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
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include\
    \ <bits/stdc++.h>\n\nusing i64 = long long;\nusing VI = vector<int>;\nusing pii\
    \ = pair<int, int>;\n#line 3 \"DataStructure/RMQ.hpp\"\n\ntemplate <class T, class\
    \ Cmp = less<T>>\nstruct RMQ {\n    const int n;\n    const Cmp cmp;\n    vector<vector<T>>\
    \ a;\n    RMQ(const vector<T> &init) : n(init.size()), cmp(Cmp()) {\n        int\
    \ lg = __lg(n);\n        a.assign(lg + 1, vector<T>(n));\n        for (int j =\
    \ 0; j <= lg; j++) {\n            for (int i = 0; i + (1 << j) <= n; i++) {\n\
    \                a[j][i] = (j == 0 ? init[i]\n                               \
    \   : min(a[j - 1][i],\n                                        a[j - 1][i + (1\
    \ << (j - 1))], cmp));\n            }\n        }\n    }\n    T rangeMin(int l,\
    \ int r) {\n        int k = __lg(r - l);\n        return min(a[k][l], a[k][r -\
    \ (1 << k)], cmp);\n    }\n};\n"
  code: "#pragma once\n#include \"../Template/Template.hpp\"\n\ntemplate <class T,\
    \ class Cmp = less<T>>\nstruct RMQ {\n    const int n;\n    const Cmp cmp;\n \
    \   vector<vector<T>> a;\n    RMQ(const vector<T> &init) : n(init.size()), cmp(Cmp())\
    \ {\n        int lg = __lg(n);\n        a.assign(lg + 1, vector<T>(n));\n    \
    \    for (int j = 0; j <= lg; j++) {\n            for (int i = 0; i + (1 << j)\
    \ <= n; i++) {\n                a[j][i] = (j == 0 ? init[i]\n                \
    \                  : min(a[j - 1][i],\n                                      \
    \  a[j - 1][i + (1 << (j - 1))], cmp));\n            }\n        }\n    }\n   \
    \ T rangeMin(int l, int r) {\n        int k = __lg(r - l);\n        return min(a[k][l],\
    \ a[k][r - (1 << k)], cmp);\n    }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: DataStructure/RMQ.hpp
  requiredBy:
  - String/SuffixArrayFast.hpp
  - String/SuffixArray.hpp
  timestamp: '2022-09-27 10:55:07+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/StaticRMQ.test.cpp
  - Verify/NumberofSubstrings.test.cpp
  - Verify/SuffixArray.test.cpp
documentation_of: DataStructure/RMQ.hpp
layout: document
redirect_from:
- /library/DataStructure/RMQ.hpp
- /library/DataStructure/RMQ.hpp.html
title: DataStructure/RMQ.hpp
---
