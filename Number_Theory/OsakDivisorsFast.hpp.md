---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Number_Theory/Binary-Gcd.hpp
    title: Number_Theory/Binary-Gcd.hpp
  - icon: ':x:'
    path: Number_Theory/Factorization.hpp
    title: Number_Theory/Factorization.hpp
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
  bundledCode: "#line 2 \"Number_Theory/OsakDivisorsFast.hpp\"\n\n#line 2 \"Number_Theory/Factorization.hpp\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\nusing i64\
    \ = std::int64_t;\n#line 2 \"Number_Theory/Binary-Gcd.hpp\"\n\n#line 4 \"Number_Theory/Binary-Gcd.hpp\"\
    \n\ninline i64 binary_gcd(i64 a, i64 b) {\n    if (a == 0 || b == 0) return a\
    \ + b;\n    char n = __builtin_ctzll(a);\n    char m = __builtin_ctzll(b);\n \
    \   a >>= n;\n    b >>= m;\n    n = std::min(n, m);\n    while (a != b) {\n  \
    \      i64 d = a - b;\n        char s = __builtin_ctzll(d);\n        bool f =\
    \ a > b;\n        b = f ? b : a;\n        a = (f ? d : -d) >> s;\n    }\n    return\
    \ a << n;\n}\n#line 5 \"Number_Theory/Factorization.hpp\"\ntemplate <class T>\n\
    T mul(T x, T y, T c) {\n    if (std::is_same<int, T>::value) return 1ll * x *\
    \ y % c;\n    if (std::is_same<i64, T>::value) return __int128(x) * y % c;\n \
    \   return x * y % c;\n}\n\ntemplate <class T>\nbool miller(T n) {\n    if (n\
    \ == 2) return 1;\n\n    for (auto p : {2, 3, 5, 7, 11, 13})\n        if ([&](T\
    \ n, int a) -> bool {\n                if (n == a) return 1;\n               \
    \ if (n % 2 == 0) return 0;\n                auto mpow = [&](T a, T k, T mod)\
    \ {\n                    T res = 1;\n                    for (; k; k /= 2, a =\
    \ mul<T>(a, a, mod))\n                        if (k & 1) res = mul<T>(res, a,\
    \ mod);\n                    return res;\n                };\n               \
    \ T d = (n - 1) >> __builtin_ctzll(n - 1);\n                T r = mpow(a, d, n);\n\
    \n                while (d < n - 1 && r != 1 && r != n - 1)\n                \
    \    d <<= 1, r = mul<T>(r, r, n);\n                return r == n - 1 || d & 1;\n\
    \            }(n, p) == 0)\n            return 0;\n\n    return 1;\n}\ntemplate\
    \ <class T>\nstd::vector<T> factorization(T n) {\n    std::mt19937_64 rng(std::time(nullptr));\n\
    \    auto myrand = [&](i64 a, i64 b) -> i64 {\n        return std::uniform_int_distribution<i64>(a,\
    \ b)(rng);\n    };\n\n    std::vector<T> res;\n\n    std::function<void(T)> solve\
    \ = [&](T x) {\n        if (x == 1) return;\n        if (miller(x))\n        \
    \    res.push_back(x);\n        else {\n            T d = [&](T n) {\n       \
    \         auto f = [&](T x) -> T { return (mul<T>(x, x, n) + 1) % n; };\n    \
    \            T x = 0, y = 0, t = 30, prd = 2;\n                while (t++ % 40\
    \ || binary_gcd(prd, n) == 1) {\n                    if (x == y) x = myrand(2,\
    \ n - 1), y = f(x);\n                    T tmp = mul(prd, (x - y) > 0 ? (x - y)\
    \ : (y - x), n);\n                    if (tmp) prd = tmp;\n                  \
    \  x = f(x), y = f(f(y));\n                }\n                return binary_gcd(prd,\
    \ n);\n            }(x);\n            solve(d);\n            solve(x / d);\n \
    \       }\n    };\n\n    solve(n);\n\n    return res;\n}\n#line 4 \"Number_Theory/OsakDivisorsFast.hpp\"\
    \n\ntemplate <class T>\nstd::vector<T> OsakDivisorsFast(T x) {\n    auto fac =\
    \ factorization<i64>(x);\n    std::sort(fac.begin(), fac.end());\n    std::vector<std::pair<T,\
    \ int>> lt;\n    for (int i = 0, j; i < int(fac.size()); i = j) {\n        j =\
    \ i;\n        while (fac[j] == fac[i] && j < int(fac.size())) j++;\n        lt.emplace_back(fac[i],\
    \ j - i);\n    }\n    std::vector<T> div;\n    auto dfs = [&](auto rec, int i,\
    \ T c) {\n        if (i == int(lt.size())) {\n            div.push_back(c);\n\
    \            return;\n        }\n        for (int j = 0; j <= lt[i].second; j++)\
    \ {\n            rec(rec, i + 1, c);\n            c *= lt[i].first;\n        }\n\
    \    };\n    dfs(dfs, 0, 1);\n    return div;\n}\n"
  code: "#pragma once\n\n#include \"Factorization.hpp\"\n\ntemplate <class T>\nstd::vector<T>\
    \ OsakDivisorsFast(T x) {\n    auto fac = factorization<i64>(x);\n    std::sort(fac.begin(),\
    \ fac.end());\n    std::vector<std::pair<T, int>> lt;\n    for (int i = 0, j;\
    \ i < int(fac.size()); i = j) {\n        j = i;\n        while (fac[j] == fac[i]\
    \ && j < int(fac.size())) j++;\n        lt.emplace_back(fac[i], j - i);\n    }\n\
    \    std::vector<T> div;\n    auto dfs = [&](auto rec, int i, T c) {\n       \
    \ if (i == int(lt.size())) {\n            div.push_back(c);\n            return;\n\
    \        }\n        for (int j = 0; j <= lt[i].second; j++) {\n            rec(rec,\
    \ i + 1, c);\n            c *= lt[i].first;\n        }\n    };\n    dfs(dfs, 0,\
    \ 1);\n    return div;\n}"
  dependsOn:
  - Number_Theory/Factorization.hpp
  - Template/Template.hpp
  - Number_Theory/Binary-Gcd.hpp
  isVerificationFile: false
  path: Number_Theory/OsakDivisorsFast.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:54:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number_Theory/OsakDivisorsFast.hpp
layout: document
redirect_from:
- /library/Number_Theory/OsakDivisorsFast.hpp
- /library/Number_Theory/OsakDivisorsFast.hpp.html
title: Number_Theory/OsakDivisorsFast.hpp
---
