---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Binary-Gcd.hpp
    title: Number_Theory/Binary-Gcd.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 2 \"Number_Theory/Gauss-Integer.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 2 \"Number_Theory/Factorization.hpp\"\
    \n\n#line 2 \"Number_Theory/Binary-Gcd.hpp\"\n\n#line 4 \"Number_Theory/Binary-Gcd.hpp\"\
    \n\ninline i64 binary_gcd(i64 a, i64 b) {\n    if (a == 0 || b == 0) return a\
    \ + b;\n    char n = __builtin_ctzll(a);\n    char m = __builtin_ctzll(b);\n \
    \   a >>= n;\n    b >>= m;\n    n = std::min(n, m);\n    while (a != b) {\n  \
    \      i64 d = a - b;\n        char s = __builtin_ctzll(d);\n        bool f =\
    \ a > b;\n        b = f ? b : a;\n        a = (f ? d : -d) >> s;\n    }\n    return\
    \ a << n;\n}\n#line 5 \"Number_Theory/Factorization.hpp\"\n\nnamespace Factor\
    \ {\nusing u64 = std::uint64_t;\n\nu64 modmul(u64 a, u64 b, u64 M) {\n    i64\
    \ ret = a * b - M * u64(1.L / M * a * b);\n    return ret + M * (ret < 0) - M\
    \ * (ret >= (i64)M);\n}\n\nu64 modpow(u64 b, u64 e, u64 mod) {\n    u64 ans =\
    \ 1;\n    for (; e; b = modmul(b, b, mod), e /= 2)\n        if (e & 1) ans = modmul(ans,\
    \ b, mod);\n    return ans;\n}\n\nbool isPrime(u64 n) {\n    if (n < 2 || n %\
    \ 6 % 4 != 1) return (n | 1) == 3;\n    std::vector<u64> A = {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022};\n    u64 s = __builtin_ctzll(n - 1), d = n >>\
    \ s;\n    for (u64 a : A) {  // ^ count trailing zeroes\n        u64 p = modpow(a\
    \ % n, d, n), i = s;\n        while (p != 1 && p != n - 1 && a % n && i--) p =\
    \ modmul(p, p, n);\n        if (p != n - 1 && i != s) return 0;\n    }\n    return\
    \ 1;\n}\nu64 pollard(u64 n) {\n    auto f = [n](u64 x, u64 k) { return modmul(x,\
    \ x, n) + k; };\n    u64 x = 0, y = 0, t = 30, prd = 2, i = 1, q;\n    while (t++\
    \ % 40 || binary_gcd(prd, n) == 1) {\n        if (x == y) x = ++i, y = f(x, i);\n\
    \        if ((q = modmul(prd, std::max(x, y) - std::min(x, y), n))) prd = q;\n\
    \        x = f(x, i), y = f(f(y, i), i);\n    }\n    return std::gcd(prd, n);\n\
    }\nstd::vector<u64> factor(u64 n) {\n    if (n == 1) return {};\n    if (isPrime(n))\
    \ return {n};\n    u64 x = pollard(n);\n    auto l = factor(x), r = factor(n /\
    \ x);\n    l.insert(l.end(), r.begin(), r.end());\n    return l;\n}\n\ntemplate\
    \ <class T = u64>\nstd::vector<std::pair<T, int>> factorSortedList(u64 n) {\n\
    \    // \\prid x_i^p_i\n    auto fac = factor(n);\n    std::sort(fac.begin(),\
    \ fac.end());\n\n    std::vector<std::pair<T, int>> lt;\n    for (int i = 0, j;\
    \ i < int(fac.size()); i = j) {\n        j = i;\n        while (j < static_cast<int>(fac.size())\
    \ && fac[i] == fac[j]) j++;\n        lt.emplace_back(fac[i], j - i);\n    }\n\n\
    \    return lt;\n}\n}  // namespace Factor\n#line 5 \"Number_Theory/Gauss-Integer.hpp\"\
    \n\nnamespace Format_Fact {\nusing i128 = __int128;\nstruct G {\n    i128 a, b;\n\
    \    G(){};\n    G(i128 a, i128 b) : a(a), b(b){};\n    G friend operator+(const\
    \ G &a, const G &b) {\n        return {a.a + b.a, a.b + b.b};\n    }\n    G friend\
    \ operator-(const G &a, const G &b) {\n        return {a.a - b.a, a.b - b.b};\n\
    \    }\n    G friend operator*(const G &a, const G &b) {\n        return {a.a\
    \ * b.a - a.b * b.b, a.a * b.b + a.b * b.a};\n    }\n    bool operator==(const\
    \ G &x) const { return x.a == a && x.b == b; }\n    inline G operator*(const i128\
    \ &t) const { return {a * t, b * t}; }\n    inline G operator/(const i128 &t)\
    \ const { return {a / t, b / t}; }\n    G friend operator/(const G &a, const G\
    \ &b) {\n        i128 len = b.a * b.a + b.b * b.b;\n        G c = a * G(b.a, -b.b);\n\
    \        auto div = [&](i128 a, i128 n) -> i128 {\n            i128 now = (a %\
    \ n + n) % n;\n            return ((a - now) / n);\n        };\n        return\
    \ {div(2 * c.a + len, 2 * len), div(2 * c.b + len, 2 * len)};\n    }\n    G power(i128\
    \ b) {\n        G res(1, 0);\n        G a = *this;\n        for (; b; b /= 2,\
    \ a = a * a) {\n            if (b % 2) {\n                res = res * a;\n   \
    \         }\n        }\n        return res;\n    }\n};\n\nG solveprime(i128 p)\
    \ {\n    if (p == 2) return {1, 1};\n    i128 t = 1;\n    auto qpow = [](i128\
    \ a, i128 b, i128 p) {\n        i128 res = 1;\n        while (b) {\n         \
    \   if (b & 1) res = res * a % p;\n            a = a * a % p;\n            b =\
    \ b / 2;\n        }\n        return res;\n    };\n    for (; qpow(t, (p - 1) /\
    \ 2, p) != p - 1;) t++;\n    i128 k = qpow(t, (p - 1) / 4, p);\n\n    auto gcd\
    \ = [&](auto &&self, G a, G b) -> G {\n        if (b.a == 0 && b.b == 0)\n   \
    \         return a;\n        else\n            return self(self, b, a - (a / b)\
    \ * b);\n    };\n    auto g = gcd(gcd, {p, 0}, {k, 1});\n\n    if (g.a < 0) g.a\
    \ = -g.a;\n    if (g.b < 0) g.b = -g.b;\n    if (g.a > g.b) std::swap(g.a, g.b);\n\
    \    return g;\n}\nstd::vector<G> solvecomposite(i128 n) {\n    auto prm = Factor::factorSortedList<i128>(n);\n\
    \n    std::vector<G> v{{1, 0}};\n    for (const auto &[p, tmp] : prm) {\n    \
    \    if (p % 4 == 1) {\n            G A = solveprime(p);\n            G B = {A.a,\
    \ -A.b};\n            auto now = A.power(2 * tmp);\n\n            std::vector<G>\
    \ res;\n            for (i64 i = 0; i <= 2 * tmp; i++) {\n                for\
    \ (auto it : v) res.push_back(it * now);\n                now = now * B / A;\n\
    \            }\n            swap(v, res);\n        } else {\n            G now(p,\
    \ 0);\n            now = now.power(tmp);\n            for (auto &&it : v) it =\
    \ it * now;\n        }\n    }\n    for (auto &&[a, b] : v) {\n        if (a <\
    \ 0) a = -a;\n        if (b < 0) b = -b;\n    }\n    std::sort(v.begin(), v.end(),\
    \ [&](const G &a, const G &b) {\n        return std::make_pair(a.a, a.b) < std::make_pair(b.a,\
    \ b.b);\n    });\n    v.resize(unique(v.begin(), v.end()) - v.begin());\n\n  \
    \  std::vector<G> t;\n    for (const auto &[a, b] : v)\n        if (a != 0 &&\
    \ b != 0) t.emplace_back(a, b);\n    return t;\n}\n}  // namespace Format_Fact\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n#include \"Factorization.hpp\"\
    \n\nnamespace Format_Fact {\nusing i128 = __int128;\nstruct G {\n    i128 a, b;\n\
    \    G(){};\n    G(i128 a, i128 b) : a(a), b(b){};\n    G friend operator+(const\
    \ G &a, const G &b) {\n        return {a.a + b.a, a.b + b.b};\n    }\n    G friend\
    \ operator-(const G &a, const G &b) {\n        return {a.a - b.a, a.b - b.b};\n\
    \    }\n    G friend operator*(const G &a, const G &b) {\n        return {a.a\
    \ * b.a - a.b * b.b, a.a * b.b + a.b * b.a};\n    }\n    bool operator==(const\
    \ G &x) const { return x.a == a && x.b == b; }\n    inline G operator*(const i128\
    \ &t) const { return {a * t, b * t}; }\n    inline G operator/(const i128 &t)\
    \ const { return {a / t, b / t}; }\n    G friend operator/(const G &a, const G\
    \ &b) {\n        i128 len = b.a * b.a + b.b * b.b;\n        G c = a * G(b.a, -b.b);\n\
    \        auto div = [&](i128 a, i128 n) -> i128 {\n            i128 now = (a %\
    \ n + n) % n;\n            return ((a - now) / n);\n        };\n        return\
    \ {div(2 * c.a + len, 2 * len), div(2 * c.b + len, 2 * len)};\n    }\n    G power(i128\
    \ b) {\n        G res(1, 0);\n        G a = *this;\n        for (; b; b /= 2,\
    \ a = a * a) {\n            if (b % 2) {\n                res = res * a;\n   \
    \         }\n        }\n        return res;\n    }\n};\n\nG solveprime(i128 p)\
    \ {\n    if (p == 2) return {1, 1};\n    i128 t = 1;\n    auto qpow = [](i128\
    \ a, i128 b, i128 p) {\n        i128 res = 1;\n        while (b) {\n         \
    \   if (b & 1) res = res * a % p;\n            a = a * a % p;\n            b =\
    \ b / 2;\n        }\n        return res;\n    };\n    for (; qpow(t, (p - 1) /\
    \ 2, p) != p - 1;) t++;\n    i128 k = qpow(t, (p - 1) / 4, p);\n\n    auto gcd\
    \ = [&](auto &&self, G a, G b) -> G {\n        if (b.a == 0 && b.b == 0)\n   \
    \         return a;\n        else\n            return self(self, b, a - (a / b)\
    \ * b);\n    };\n    auto g = gcd(gcd, {p, 0}, {k, 1});\n\n    if (g.a < 0) g.a\
    \ = -g.a;\n    if (g.b < 0) g.b = -g.b;\n    if (g.a > g.b) std::swap(g.a, g.b);\n\
    \    return g;\n}\nstd::vector<G> solvecomposite(i128 n) {\n    auto prm = Factor::factorSortedList<i128>(n);\n\
    \n    std::vector<G> v{{1, 0}};\n    for (const auto &[p, tmp] : prm) {\n    \
    \    if (p % 4 == 1) {\n            G A = solveprime(p);\n            G B = {A.a,\
    \ -A.b};\n            auto now = A.power(2 * tmp);\n\n            std::vector<G>\
    \ res;\n            for (i64 i = 0; i <= 2 * tmp; i++) {\n                for\
    \ (auto it : v) res.push_back(it * now);\n                now = now * B / A;\n\
    \            }\n            swap(v, res);\n        } else {\n            G now(p,\
    \ 0);\n            now = now.power(tmp);\n            for (auto &&it : v) it =\
    \ it * now;\n        }\n    }\n    for (auto &&[a, b] : v) {\n        if (a <\
    \ 0) a = -a;\n        if (b < 0) b = -b;\n    }\n    std::sort(v.begin(), v.end(),\
    \ [&](const G &a, const G &b) {\n        return std::make_pair(a.a, a.b) < std::make_pair(b.a,\
    \ b.b);\n    });\n    v.resize(unique(v.begin(), v.end()) - v.begin());\n\n  \
    \  std::vector<G> t;\n    for (const auto &[a, b] : v)\n        if (a != 0 &&\
    \ b != 0) t.emplace_back(a, b);\n    return t;\n}\n}  // namespace Format_Fact"
  dependsOn:
  - Template/Template.hpp
  - Number_Theory/Factorization.hpp
  - Number_Theory/Binary-Gcd.hpp
  isVerificationFile: false
  path: Number_Theory/Gauss-Integer.hpp
  requiredBy: []
  timestamp: '2023-04-03 20:21:35+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number_Theory/Gauss-Integer.hpp
layout: document
redirect_from:
- /library/Number_Theory/Gauss-Integer.hpp
- /library/Number_Theory/Gauss-Integer.hpp.html
title: Number_Theory/Gauss-Integer.hpp
---
