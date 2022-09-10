---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Power.hpp
    title: Template/Power.hpp
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
  bundledCode: "#line 2 \"Number_Theory/Gauss-Integer.hpp\"\n\n#line 1 \"Template/Power.hpp\"\
    \ntemplate <class T>\nT power(T a, int b) {\n    T res = 1;\n    for (; b; b /=\
    \ 2, a *= a) {\n        if (b % 2) {\n            res *= a;\n        }\n    }\n\
    \    return res;\n}\n#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\
    \n#include <bits/stdc++.h>\n\nusing i64 = long long;\nusing VI = vector<int>;\n\
    using pii = pair<int, int>;\n#line 5 \"Number_Theory/Gauss-Integer.hpp\"\n// ##Tode\
    \ : Make Template\nnamespace Factorization {\nusing i128 = __int128;\nstatic mt19937_64\
    \ rng(114514);\ninline i128 mul(i128 a, i128 b, i128 c) {\n    i128 s = a * b\
    \ - c * i128((long double)a / c * b + 0.5);\n    return s < 0 ? s + c : s;\n}\n\
    \ni128 mPow(i128 a, i128 k, i128 mod) {\n    i128 res = 1;\n    for (; k; k >>=\
    \ 1, a = mul(a, a, mod))\n        if (k & 1) res = mul(res, a, mod);\n    return\
    \ res;\n}\n\nbool test(i128 n, int a) {\n    if (n == a) return 1;\n    if (n\
    \ % 2 == 0) return 0;\n\n    i128 d = (n - 1) >> __builtin_ctzll(n - 1);\n   \
    \ i128 r = mPow(a, d, n);\n\n    while (d < n - 1 && r != 1 && r != n - 1) d <<=\
    \ 1, r = mul(r, r, n);\n    return r == n - 1 || d & 1;\n}\nbool miller(i128 n)\
    \ {\n    if (n == 2) return 1;\n    for (auto p : VI{2, 3, 5, 7, 11, 13})\n  \
    \      if (test(n, p) == 0) return 0;\n    return 1;\n}\nlong long myrand(i128\
    \ a, i128 b) {\n    return uniform_int_distribution<long long>(a, b)(rng);\n}\n\
    i128 pollard(i128 n) {\n    auto f = [&](i128 x) { return ((__int128)x * x + 1)\
    \ % n; };\n    auto babs = [&](i128 x) {\n        if (x > 0)\n            return\
    \ x;\n        else\n            return -x;\n    };\n    i128 x = 0, y = 0, t =\
    \ 30, prd = 2;\n    while (t++ % 40 || __gcd(prd, n) == 1) {\n        // speedup:\
    \ don't take __gcd in each iteration.\n        if (x == y) x = myrand(2, n - 1),\
    \ y = f(x);\n        i128 tmp = mul(prd, babs(x - y), n);\n        if (tmp) prd\
    \ = tmp;\n        x = f(x), y = f(f(y));\n    }\n    return __gcd(prd, n);\n}\n\
    vector<pair<i128, i64>> work(i128 n) {\n    vector<i128> res;\n\n    function<void(i128)>\
    \ solve = [&](i128 x) {\n        if (x == 1) return;\n        if (miller(x))\n\
    \            res.push_back(x);\n        else {\n            i128 d = pollard(x);\n\
    \            solve(d);\n            solve(x / d);\n        }\n    };\n    solve(n);\n\
    \    sort(res.begin(), res.end());\n    vector<pair<i128, i64>> gao;\n    for\
    \ (int i = 0, j = 0; i < res.size(); i = j) {\n        while (res[j] == res[i]\
    \ && j < res.size()) j++;\n        gao.emplace_back(res[i], j - i);\n    }\n \
    \   return gao;\n}\n}  // namespace Factorization\nnamespace Format_Fact {\nusing\
    \ i128 = __int128;\nstruct G {\n    i128 a, b;\n    G(){};\n    G(i128 a, i128\
    \ b) : a(a), b(b){};\n    G friend operator+(const G &a, const G &b) {\n     \
    \   return {a.a + b.a, a.b + b.b};\n    }\n    G friend operator-(const G &a,\
    \ const G &b) {\n        return {a.a - b.a, a.b - b.b};\n    }\n    G friend operator*(const\
    \ G &a, const G &b) {\n        return {a.a * b.a - a.b * b.b, a.a * b.b + a.b\
    \ * b.a};\n    }\n    bool operator==(const G &x) const { return x.a == a && x.b\
    \ == b; }\n    G operator*(const i128 &t) const { return {a * t, b * t}; }\n \
    \   G operator/(const i128 &t) const { return {a / t, b / t}; }\n    G friend\
    \ operator/(const G &a, const G &b) {\n        i128 len = b.a * b.a + b.b * b.b;\n\
    \        G c = a * G(b.a, -b.b);\n        auto div = [&](i128 a, i128 n) -> i128\
    \ {\n            i128 now = (a % n + n) % n;\n            return ((a - now) /\
    \ n);\n        };\n        return {div(2 * c.a + len, 2 * len), div(2 * c.b +\
    \ len, 2 * len)};\n    }\n};\nstatic G one = G(1, 0);\nG solveprime(i128 p) {\n\
    \    if (p == 2) return {1, 1};\n    i128 t = 1;\n    auto qpow = [&](i128 a,\
    \ i128 b, i128 p) {\n        i128 res = 1;\n        while (b) {\n            if\
    \ (b & 1) res = res * a % p;\n            a = a * a % p;\n            b = b /\
    \ 2;\n        }\n        return res;\n    };\n    for (; qpow(t, (p - 1) / 2,\
    \ p) != p - 1;) t++;\n    i128 k = qpow(t, (p - 1) / 4, p);\n\n    function<G(G,\
    \ G)> Ggcd = [&](G a, G b) -> G {\n        if (b.a == 0 && b.b == 0)\n       \
    \     return a;\n        else\n            return Ggcd(b, a - (a / b) * b);\n\
    \    };\n    auto g = Ggcd({p, 0}, {k, 1});\n\n    if (g.a < 0) g.a = -g.a;\n\
    \    if (g.b < 0) g.b = -g.b;\n    if (g.a > g.b) swap(g.a, g.b);\n    return\
    \ g;\n}\nvector<G> solvecomposite(i128 n) {\n    // cerr << (i64)n << endl;\n\
    \    auto prm = Factorization::work(n);\n    vector<G> v{{1, 0}};\n    for (auto\
    \ [p, tmp] : prm) {\n        // cerr << (i64)p << \" \" << tmp << endl;\n    \
    \    if (p % 4 == 1) {\n            G A = solveprime(p);\n            G B = {A.a,\
    \ -A.b};\n            auto now = power<G>(A, 2 * tmp);\n\n            vector<G>\
    \ res;\n            for (i64 i = 0; i <= 2 * tmp; i++) {\n                for\
    \ (auto it : v) res.push_back(it * now);\n                now = now * B / A;\n\
    \            }\n            swap(v, res);\n        } else {\n            G now(p,\
    \ 0);\n            now = power<G>(now, tmp);\n            for (auto &&it : v)\
    \ it = it * now;\n        }\n    }\n    for (auto &&[a, b] : v) {\n        if\
    \ (a < 0) a = -a;\n        if (b < 0) b = -b;\n    }\n    sort(v.begin(), v.end(),\
    \ [&](const G &a, const G &b) {\n        return make_pair(a.a, a.b) < make_pair(b.a,\
    \ b.b);\n    });\n    v.resize(unique(v.begin(), v.end()) - v.begin());\n\n  \
    \  vector<G> t;\n    for (auto [a, b] : v)\n        if (a != 0 && b != 0) t.emplace_back(a,\
    \ b);\n    return t;\n}\n}  // namespace Format_Fact\n"
  code: "#pragma once\n\n#include \"../Template/Power.hpp\"\n#include \"../Template/Template.hpp\"\
    \n// ##Tode : Make Template\nnamespace Factorization {\nusing i128 = __int128;\n\
    static mt19937_64 rng(114514);\ninline i128 mul(i128 a, i128 b, i128 c) {\n  \
    \  i128 s = a * b - c * i128((long double)a / c * b + 0.5);\n    return s < 0\
    \ ? s + c : s;\n}\n\ni128 mPow(i128 a, i128 k, i128 mod) {\n    i128 res = 1;\n\
    \    for (; k; k >>= 1, a = mul(a, a, mod))\n        if (k & 1) res = mul(res,\
    \ a, mod);\n    return res;\n}\n\nbool test(i128 n, int a) {\n    if (n == a)\
    \ return 1;\n    if (n % 2 == 0) return 0;\n\n    i128 d = (n - 1) >> __builtin_ctzll(n\
    \ - 1);\n    i128 r = mPow(a, d, n);\n\n    while (d < n - 1 && r != 1 && r !=\
    \ n - 1) d <<= 1, r = mul(r, r, n);\n    return r == n - 1 || d & 1;\n}\nbool\
    \ miller(i128 n) {\n    if (n == 2) return 1;\n    for (auto p : VI{2, 3, 5, 7,\
    \ 11, 13})\n        if (test(n, p) == 0) return 0;\n    return 1;\n}\nlong long\
    \ myrand(i128 a, i128 b) {\n    return uniform_int_distribution<long long>(a,\
    \ b)(rng);\n}\ni128 pollard(i128 n) {\n    auto f = [&](i128 x) { return ((__int128)x\
    \ * x + 1) % n; };\n    auto babs = [&](i128 x) {\n        if (x > 0)\n      \
    \      return x;\n        else\n            return -x;\n    };\n    i128 x = 0,\
    \ y = 0, t = 30, prd = 2;\n    while (t++ % 40 || __gcd(prd, n) == 1) {\n    \
    \    // speedup: don't take __gcd in each iteration.\n        if (x == y) x =\
    \ myrand(2, n - 1), y = f(x);\n        i128 tmp = mul(prd, babs(x - y), n);\n\
    \        if (tmp) prd = tmp;\n        x = f(x), y = f(f(y));\n    }\n    return\
    \ __gcd(prd, n);\n}\nvector<pair<i128, i64>> work(i128 n) {\n    vector<i128>\
    \ res;\n\n    function<void(i128)> solve = [&](i128 x) {\n        if (x == 1)\
    \ return;\n        if (miller(x))\n            res.push_back(x);\n        else\
    \ {\n            i128 d = pollard(x);\n            solve(d);\n            solve(x\
    \ / d);\n        }\n    };\n    solve(n);\n    sort(res.begin(), res.end());\n\
    \    vector<pair<i128, i64>> gao;\n    for (int i = 0, j = 0; i < res.size();\
    \ i = j) {\n        while (res[j] == res[i] && j < res.size()) j++;\n        gao.emplace_back(res[i],\
    \ j - i);\n    }\n    return gao;\n}\n}  // namespace Factorization\nnamespace\
    \ Format_Fact {\nusing i128 = __int128;\nstruct G {\n    i128 a, b;\n    G(){};\n\
    \    G(i128 a, i128 b) : a(a), b(b){};\n    G friend operator+(const G &a, const\
    \ G &b) {\n        return {a.a + b.a, a.b + b.b};\n    }\n    G friend operator-(const\
    \ G &a, const G &b) {\n        return {a.a - b.a, a.b - b.b};\n    }\n    G friend\
    \ operator*(const G &a, const G &b) {\n        return {a.a * b.a - a.b * b.b,\
    \ a.a * b.b + a.b * b.a};\n    }\n    bool operator==(const G &x) const { return\
    \ x.a == a && x.b == b; }\n    G operator*(const i128 &t) const { return {a *\
    \ t, b * t}; }\n    G operator/(const i128 &t) const { return {a / t, b / t};\
    \ }\n    G friend operator/(const G &a, const G &b) {\n        i128 len = b.a\
    \ * b.a + b.b * b.b;\n        G c = a * G(b.a, -b.b);\n        auto div = [&](i128\
    \ a, i128 n) -> i128 {\n            i128 now = (a % n + n) % n;\n            return\
    \ ((a - now) / n);\n        };\n        return {div(2 * c.a + len, 2 * len), div(2\
    \ * c.b + len, 2 * len)};\n    }\n};\nstatic G one = G(1, 0);\nG solveprime(i128\
    \ p) {\n    if (p == 2) return {1, 1};\n    i128 t = 1;\n    auto qpow = [&](i128\
    \ a, i128 b, i128 p) {\n        i128 res = 1;\n        while (b) {\n         \
    \   if (b & 1) res = res * a % p;\n            a = a * a % p;\n            b =\
    \ b / 2;\n        }\n        return res;\n    };\n    for (; qpow(t, (p - 1) /\
    \ 2, p) != p - 1;) t++;\n    i128 k = qpow(t, (p - 1) / 4, p);\n\n    function<G(G,\
    \ G)> Ggcd = [&](G a, G b) -> G {\n        if (b.a == 0 && b.b == 0)\n       \
    \     return a;\n        else\n            return Ggcd(b, a - (a / b) * b);\n\
    \    };\n    auto g = Ggcd({p, 0}, {k, 1});\n\n    if (g.a < 0) g.a = -g.a;\n\
    \    if (g.b < 0) g.b = -g.b;\n    if (g.a > g.b) swap(g.a, g.b);\n    return\
    \ g;\n}\nvector<G> solvecomposite(i128 n) {\n    // cerr << (i64)n << endl;\n\
    \    auto prm = Factorization::work(n);\n    vector<G> v{{1, 0}};\n    for (auto\
    \ [p, tmp] : prm) {\n        // cerr << (i64)p << \" \" << tmp << endl;\n    \
    \    if (p % 4 == 1) {\n            G A = solveprime(p);\n            G B = {A.a,\
    \ -A.b};\n            auto now = power<G>(A, 2 * tmp);\n\n            vector<G>\
    \ res;\n            for (i64 i = 0; i <= 2 * tmp; i++) {\n                for\
    \ (auto it : v) res.push_back(it * now);\n                now = now * B / A;\n\
    \            }\n            swap(v, res);\n        } else {\n            G now(p,\
    \ 0);\n            now = power<G>(now, tmp);\n            for (auto &&it : v)\
    \ it = it * now;\n        }\n    }\n    for (auto &&[a, b] : v) {\n        if\
    \ (a < 0) a = -a;\n        if (b < 0) b = -b;\n    }\n    sort(v.begin(), v.end(),\
    \ [&](const G &a, const G &b) {\n        return make_pair(a.a, a.b) < make_pair(b.a,\
    \ b.b);\n    });\n    v.resize(unique(v.begin(), v.end()) - v.begin());\n\n  \
    \  vector<G> t;\n    for (auto [a, b] : v)\n        if (a != 0 && b != 0) t.emplace_back(a,\
    \ b);\n    return t;\n}\n}  // namespace Format_Fact\n"
  dependsOn:
  - Template/Power.hpp
  - Template/Template.hpp
  isVerificationFile: false
  path: Number_Theory/Gauss-Integer.hpp
  requiredBy: []
  timestamp: '2022-09-11 00:24:25+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number_Theory/Gauss-Integer.hpp
layout: document
redirect_from:
- /library/Number_Theory/Gauss-Integer.hpp
- /library/Number_Theory/Gauss-Integer.hpp.html
title: Number_Theory/Gauss-Integer.hpp
---
