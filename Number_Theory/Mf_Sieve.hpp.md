---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Prime_Sieve.hpp
    title: Number_Theory/Prime_Sieve.hpp
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/Sum_of_Totient_Function.test.cpp
    title: Verify/Sum_of_Totient_Function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number_Theory/Mf_Sieve.hpp\"\n\n#line 2 \"Number_Theory/Prime_Sieve.hpp\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\nusing i64\
    \ = std::int64_t;\n#line 4 \"Number_Theory/Prime_Sieve.hpp\"\n\nstd::vector<int>\
    \ prime_sieve(int N) {\n    std::vector<bool> sieve(N / 3 + 1, 1);\n    for (int\
    \ p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn;\n         p += d = 6 - d, i++)\
    \ {\n        if (!sieve[i]) continue;\n        for (int q = p * p / 3, r = d *\
    \ p / 3 + (d * p % 3 == 2), s = 2 * p,\n                 qe = sieve.size();\n\
    \             q < qe; q += r = s - r)\n            sieve[q] = 0;\n    }\n    std::vector<int>\
    \ ret{2, 3};\n    for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n\
    \        if (sieve[i]) ret.push_back(p);\n    while (!ret.empty() && ret.back()\
    \ > N) ret.pop_back();\n    return ret;\n}\n#line 4 \"Number_Theory/Mf_Sieve.hpp\"\
    \n\ntemplate <class T>\nstd::vector<T> mf_sieve(int n, std::function<T(i64, i64,\
    \ i64)> f) {\n    /*\n        ##pragma f is a multiplicative-function\n      \
    \  f(n,p,c) <-> n=p^c\n    */\n    std::vector<T> ans(n + 1, T());\n    std::vector<int>\
    \ ps = prime_sieve(n);\n    int p(ps.size());\n\n    std::function<void(int, i64,\
    \ T)> dfs = [&](int i, i64 x, T y) {\n        ans[x] = y;\n        if (y == T())\
    \ return;\n        for (int j = i + 1; j < p; j++) {\n            i64 nx = x *\
    \ ps[j];\n            i64 dx = ps[j];\n            if (nx > n) break;\n      \
    \      for (int c = 1; nx <= n; nx *= ps[j], dx *= ps[j], ++c)\n             \
    \   dfs(j, nx, y * f(dx, ps[j], c));\n        }\n    };\n    ans[1] = 1;\n   \
    \ dfs(-1, 1, 1);\n    return ans;\n};\n"
  code: "#pragma once\n\n#include \"Prime_Sieve.hpp\"\n\ntemplate <class T>\nstd::vector<T>\
    \ mf_sieve(int n, std::function<T(i64, i64, i64)> f) {\n    /*\n        ##pragma\
    \ f is a multiplicative-function\n        f(n,p,c) <-> n=p^c\n    */\n    std::vector<T>\
    \ ans(n + 1, T());\n    std::vector<int> ps = prime_sieve(n);\n    int p(ps.size());\n\
    \n    std::function<void(int, i64, T)> dfs = [&](int i, i64 x, T y) {\n      \
    \  ans[x] = y;\n        if (y == T()) return;\n        for (int j = i + 1; j <\
    \ p; j++) {\n            i64 nx = x * ps[j];\n            i64 dx = ps[j];\n  \
    \          if (nx > n) break;\n            for (int c = 1; nx <= n; nx *= ps[j],\
    \ dx *= ps[j], ++c)\n                dfs(j, nx, y * f(dx, ps[j], c));\n      \
    \  }\n    };\n    ans[1] = 1;\n    dfs(-1, 1, 1);\n    return ans;\n};"
  dependsOn:
  - Number_Theory/Prime_Sieve.hpp
  - Template/Template.hpp
  isVerificationFile: false
  path: Number_Theory/Mf_Sieve.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/Sum_of_Totient_Function.test.cpp
documentation_of: Number_Theory/Mf_Sieve.hpp
layout: document
redirect_from:
- /library/Number_Theory/Mf_Sieve.hpp
- /library/Number_Theory/Mf_Sieve.hpp.html
title: Number_Theory/Mf_Sieve.hpp
---
