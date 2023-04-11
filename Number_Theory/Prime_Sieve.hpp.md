---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Mf_Sieve.hpp
    title: Number_Theory/Mf_Sieve.hpp
  - icon: ':heavy_check_mark:'
    path: Number_Theory/MultiplicativeFunctionPSumFast.hpp
    title: Number_Theory/MultiplicativeFunctionPSumFast.hpp
  - icon: ':warning:'
    path: Number_Theory/OsakDivisors.hpp
    title: Number_Theory/OsakDivisors.hpp
  - icon: ':warning:'
    path: Number_Theory/PNSieve.hpp
    title: PNSieve
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/CountingPrimes.test.cpp
    title: Verify/CountingPrimes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Sum_of_Totient_Function.test.cpp
    title: Verify/Sum_of_Totient_Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/SumofTotientFunction2.test.cpp
    title: Verify/SumofTotientFunction2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number_Theory/Prime_Sieve.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Number_Theory/Prime_Sieve.hpp\"\
    \n\nstd::vector<int> prime_sieve(int N) {\n    std::vector<bool> sieve(N / 3 +\
    \ 1, 1);\n    for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn;\n       \
    \  p += d = 6 - d, i++) {\n        if (!sieve[i]) continue;\n        for (int\
    \ q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n              \
    \   qe = sieve.size();\n             q < qe; q += r = s - r)\n            sieve[q]\
    \ = 0;\n    }\n    std::vector<int> ret{2, 3};\n    for (int p = 5, d = 4, i =\
    \ 1; p <= N; p += d = 6 - d, i++)\n        if (sieve[i]) ret.push_back(p);\n \
    \   while (!ret.empty() && ret.back() > N) ret.pop_back();\n    return ret;\n\
    }\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n\nstd::vector<int>\
    \ prime_sieve(int N) {\n    std::vector<bool> sieve(N / 3 + 1, 1);\n    for (int\
    \ p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn;\n         p += d = 6 - d, i++)\
    \ {\n        if (!sieve[i]) continue;\n        for (int q = p * p / 3, r = d *\
    \ p / 3 + (d * p % 3 == 2), s = 2 * p,\n                 qe = sieve.size();\n\
    \             q < qe; q += r = s - r)\n            sieve[q] = 0;\n    }\n    std::vector<int>\
    \ ret{2, 3};\n    for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n\
    \        if (sieve[i]) ret.push_back(p);\n    while (!ret.empty() && ret.back()\
    \ > N) ret.pop_back();\n    return ret;\n}"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Number_Theory/Prime_Sieve.hpp
  requiredBy:
  - Number_Theory/MultiplicativeFunctionPSumFast.hpp
  - Number_Theory/Mf_Sieve.hpp
  - Number_Theory/OsakDivisors.hpp
  - Number_Theory/PNSieve.hpp
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/SumofTotientFunction2.test.cpp
  - Verify/Sum_of_Totient_Function.test.cpp
  - Verify/CountingPrimes.test.cpp
documentation_of: Number_Theory/Prime_Sieve.hpp
layout: document
redirect_from:
- /library/Number_Theory/Prime_Sieve.hpp
- /library/Number_Theory/Prime_Sieve.hpp.html
title: Number_Theory/Prime_Sieve.hpp
---
