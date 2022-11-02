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
  bundledCode: "#line 2 \"Number_Theory/OsakDivisors.hpp\"\n\n#line 2 \"Number_Theory/Prime_Sieve.hpp\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\
    \nusing i64 = long long;\nusing VI = vector<int>;\nusing pii = pair<int, int>;\n\
    #line 4 \"Number_Theory/Prime_Sieve.hpp\"\n\nvector<int> prime_sieve(int N) {\n\
    \    vector<bool> sieve(N / 3 + 1, 1);\n    for (int p = 5, d = 4, i = 1, sqn\
    \ = sqrt(N); p <= sqn;\n         p += d = 6 - d, i++) {\n        if (!sieve[i])\
    \ continue;\n        for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2),\
    \ s = 2 * p,\n                 qe = sieve.size();\n             q < qe; q += r\
    \ = s - r)\n            sieve[q] = 0;\n    }\n    vector<int> ret{2, 3};\n   \
    \ for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n        if (sieve[i])\
    \ ret.push_back(p);\n    while (!ret.empty() && ret.back() > N) ret.pop_back();\n\
    \    return ret;\n}\n#line 4 \"Number_Theory/OsakDivisors.hpp\"\n\ntemplate <class\
    \ T>\nvector<T> OsakDivisors(T x) {\n    auto primes = prime_sieve(sqrt(x) + 10);\n\
    \n    vector<pair<T, int>> lt;\n    for (auto p : primes) {\n        if (1LL *\
    \ p * p > x) break;\n        int cnt = 0;\n        while (x % p == 0) {\n    \
    \        x /= p;\n            cnt++;\n        }\n        if (cnt >= 1) lt.emplace_back(p,\
    \ cnt);\n    }\n    if (x > 1) lt.emplace_back(x, 1);\n    vector<T> div;\n  \
    \  auto dfs = [&](auto rec, int i, T c) {\n        if (i == int(lt.size())) {\n\
    \            div.push_back(c);\n            return;\n        }\n        for (int\
    \ j = 0; j <= lt[i].second; j++) {\n            rec(rec, i + 1, c);\n        \
    \    c *= lt[i].first;\n        }\n    };\n    dfs(dfs, 0, 1);\n    return div;\n\
    }\n"
  code: "#pragma once\n\n#include \"Prime_Sieve.hpp\"\n\ntemplate <class T>\nvector<T>\
    \ OsakDivisors(T x) {\n    auto primes = prime_sieve(sqrt(x) + 10);\n\n    vector<pair<T,\
    \ int>> lt;\n    for (auto p : primes) {\n        if (1LL * p * p > x) break;\n\
    \        int cnt = 0;\n        while (x % p == 0) {\n            x /= p;\n   \
    \         cnt++;\n        }\n        if (cnt >= 1) lt.emplace_back(p, cnt);\n\
    \    }\n    if (x > 1) lt.emplace_back(x, 1);\n    vector<T> div;\n    auto dfs\
    \ = [&](auto rec, int i, T c) {\n        if (i == int(lt.size())) {\n        \
    \    div.push_back(c);\n            return;\n        }\n        for (int j = 0;\
    \ j <= lt[i].second; j++) {\n            rec(rec, i + 1, c);\n            c *=\
    \ lt[i].first;\n        }\n    };\n    dfs(dfs, 0, 1);\n    return div;\n}"
  dependsOn:
  - Number_Theory/Prime_Sieve.hpp
  - Template/Template.hpp
  isVerificationFile: false
  path: Number_Theory/OsakDivisors.hpp
  requiredBy: []
  timestamp: '2022-11-03 01:01:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number_Theory/OsakDivisors.hpp
layout: document
redirect_from:
- /library/Number_Theory/OsakDivisors.hpp
- /library/Number_Theory/OsakDivisors.hpp.html
title: Number_Theory/OsakDivisors.hpp
---
