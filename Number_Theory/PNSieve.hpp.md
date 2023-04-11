---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Prime_Sieve.hpp
    title: Number_Theory/Prime_Sieve.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number_Theory/PNSieve.hpp\"\n\n#line 2 \"Number_Theory/Prime_Sieve.hpp\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\nusing i64\
    \ = std::int64_t;\n#line 4 \"Number_Theory/Prime_Sieve.hpp\"\n\nstd::vector<int>\
    \ prime_sieve(int N) {\n    std::vector<bool> sieve(N / 3 + 1, 1);\n    for (int\
    \ p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn;\n         p += d = 6 - d, i++)\
    \ {\n        if (!sieve[i]) continue;\n        for (int q = p * p / 3, r = d *\
    \ p / 3 + (d * p % 3 == 2), s = 2 * p,\n                 qe = sieve.size();\n\
    \             q < qe; q += r = s - r)\n            sieve[q] = 0;\n    }\n    std::vector<int>\
    \ ret{2, 3};\n    for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n\
    \        if (sieve[i]) ret.push_back(p);\n    while (!ret.empty() && ret.back()\
    \ > N) ret.pop_back();\n    return ret;\n}\n#line 4 \"Number_Theory/PNSieve.hpp\"\
    \n\ntemplate <class T>\nT PNSieve(i64 n, const std::function<T(i64)> G,\n    \
    \      const std::function<T(i64, i64, i64)> f,\n          const std::function<T(i64,\
    \ i64, i64)> g) {\n    /*\n        \\sum_{i=1}^n f(i)\n        Find g: g(x) =\
    \ f(x) when x is prime ,and g is multiplicative\n        G(x) is the prifix sum\
    \ of g.\n        Time Complexity: O (max(sqrt(n),n^t\n       (\\zeta(2*t)*\\zeta(3*t))/\\\
    zeta(6*t))) n^t for call G(x) ,\\zeta is Riemann\n       zeta function\n    */\n\
    \    const int sq = sqrt(n) + 10;\n    auto prime = prime_sieve(sq);\n    std::vector<std::vector<T>>\
    \ h(prime.size(),\n                                  std::vector<T>(std::__lg(n)\
    \ + 2));\n    for (int i = 0; i < int(prime.size()); i++) h[i][0] = T(1);\n  \
    \  T ans = 0;\n\n    auto dfs = [&](auto&& self, i64 x, T y, i64 pos) -> void\
    \ {\n        ans = ans + y * G(n / x);\n        if (pos >= int(prime.size()))\
    \ return;\n        if (x > n / prime[pos] / prime[pos]) return;\n        for (int\
    \ w = pos; w < int(prime.size()); w++) {\n            if (x > n / prime[w] / prime[w])\
    \ return;\n            i64 bet = x * prime[w];\n            for (i64 j = 1; bet\
    \ <= n; j++, bet *= prime[w]) {\n                if (h[w][j] == T()) {\n     \
    \               T nowf = f(bet / x, prime[w], j);\n                    i64 G =\
    \ prime[w];\n                    for (i64 i = 1; i <= j; i++)\n              \
    \          nowf = nowf - g(G, prime[w], i) * h[w][j - i],\n                  \
    \      G *= prime[w];\n                    h[w][j] = nowf;\n                }\n\
    \                if (h[w][j] != T()) {\n                    self(self, bet, h[w][j]\
    \ * y, w + 1);\n                }\n            }\n        }\n    };\n    dfs(dfs,\
    \ 1, 1, 0);\n    return ans;\n}\n"
  code: "#pragma once\n\n#include \"Prime_Sieve.hpp\"\n\ntemplate <class T>\nT PNSieve(i64\
    \ n, const std::function<T(i64)> G,\n          const std::function<T(i64, i64,\
    \ i64)> f,\n          const std::function<T(i64, i64, i64)> g) {\n    /*\n   \
    \     \\sum_{i=1}^n f(i)\n        Find g: g(x) = f(x) when x is prime ,and g is\
    \ multiplicative\n        G(x) is the prifix sum of g.\n        Time Complexity:\
    \ O (max(sqrt(n),n^t\n       (\\zeta(2*t)*\\zeta(3*t))/\\zeta(6*t))) n^t for call\
    \ G(x) ,\\zeta is Riemann\n       zeta function\n    */\n    const int sq = sqrt(n)\
    \ + 10;\n    auto prime = prime_sieve(sq);\n    std::vector<std::vector<T>> h(prime.size(),\n\
    \                                  std::vector<T>(std::__lg(n) + 2));\n    for\
    \ (int i = 0; i < int(prime.size()); i++) h[i][0] = T(1);\n    T ans = 0;\n\n\
    \    auto dfs = [&](auto&& self, i64 x, T y, i64 pos) -> void {\n        ans =\
    \ ans + y * G(n / x);\n        if (pos >= int(prime.size())) return;\n       \
    \ if (x > n / prime[pos] / prime[pos]) return;\n        for (int w = pos; w <\
    \ int(prime.size()); w++) {\n            if (x > n / prime[w] / prime[w]) return;\n\
    \            i64 bet = x * prime[w];\n            for (i64 j = 1; bet <= n; j++,\
    \ bet *= prime[w]) {\n                if (h[w][j] == T()) {\n                \
    \    T nowf = f(bet / x, prime[w], j);\n                    i64 G = prime[w];\n\
    \                    for (i64 i = 1; i <= j; i++)\n                        nowf\
    \ = nowf - g(G, prime[w], i) * h[w][j - i],\n                        G *= prime[w];\n\
    \                    h[w][j] = nowf;\n                }\n                if (h[w][j]\
    \ != T()) {\n                    self(self, bet, h[w][j] * y, w + 1);\n      \
    \          }\n            }\n        }\n    };\n    dfs(dfs, 1, 1, 0);\n    return\
    \ ans;\n}"
  dependsOn:
  - Number_Theory/Prime_Sieve.hpp
  - Template/Template.hpp
  isVerificationFile: false
  path: Number_Theory/PNSieve.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number_Theory/PNSieve.hpp
layout: document
title: PNSieve
---

PN筛计算积性函数$f$前缀和：$ \sum_{i=1}^n f(i)$。

找到积性函数$g$使的$g(p) = f(p)$其中$p$是质数。$G(x)$是 $g$函数的前缀和。

$f,g$以三参数传入，$f(n,p,c) \rightarrow f(p^c) = f(n)$

时间复杂度: $\mathcal{O} (\max(\sqrt{n},n^t (\frac{\zeta(2t)\zeta(3t)}{\zeta(6t)}))$ $n^t$用来计算$G(x)$ ,$\zeta$ 是Riemann zeta function。