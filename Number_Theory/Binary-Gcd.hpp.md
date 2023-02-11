---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Number_Theory/Factorization.hpp
    title: Number_Theory/Factorization.hpp
  - icon: ':warning:'
    path: Number_Theory/Gauss-Integer.hpp
    title: Number_Theory/Gauss-Integer.hpp
  - icon: ':warning:'
    path: Number_Theory/OsakDivisorsFast.hpp
    title: Number_Theory/OsakDivisorsFast.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/Factorize.test.cpp
    title: Verify/Factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number_Theory/Binary-Gcd.hpp\"\n\n#include <algorithm>\n\
    using i64 = long long;\ninline i64 binary_gcd(i64 a, i64 b) {\n    if (a == 0\
    \ || b == 0) return a + b;\n    char n = __builtin_ctzll(a);\n    char m = __builtin_ctzll(b);\n\
    \    a >>= n;\n    b >>= m;\n    n = std::min(n, m);\n    while (a != b) {\n \
    \       i64 d = a - b;\n        char s = __builtin_ctzll(d);\n        bool f =\
    \ a > b;\n        b = f ? b : a;\n        a = (f ? d : -d) >> s;\n    }\n    return\
    \ a << n;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\nusing i64 = long long;\ninline i64\
    \ binary_gcd(i64 a, i64 b) {\n    if (a == 0 || b == 0) return a + b;\n    char\
    \ n = __builtin_ctzll(a);\n    char m = __builtin_ctzll(b);\n    a >>= n;\n  \
    \  b >>= m;\n    n = std::min(n, m);\n    while (a != b) {\n        i64 d = a\
    \ - b;\n        char s = __builtin_ctzll(d);\n        bool f = a > b;\n      \
    \  b = f ? b : a;\n        a = (f ? d : -d) >> s;\n    }\n    return a << n;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Number_Theory/Binary-Gcd.hpp
  requiredBy:
  - Number_Theory/Factorization.hpp
  - Number_Theory/OsakDivisorsFast.hpp
  - Number_Theory/Gauss-Integer.hpp
  timestamp: '2022-09-03 03:40:06+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/Factorize.test.cpp
documentation_of: Number_Theory/Binary-Gcd.hpp
layout: document
redirect_from:
- /library/Number_Theory/Binary-Gcd.hpp
- /library/Number_Theory/Binary-Gcd.hpp.html
title: Number_Theory/Binary-Gcd.hpp
---
