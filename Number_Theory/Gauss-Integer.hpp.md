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
  bundledCode: "#line 2 \"Number_Theory/Gauss-Integer.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 2 \"Number_Theory/Factorization.hpp\"\
    \n\n#line 2 \"Number_Theory/Binary-Gcd.hpp\"\n\n#line 4 \"Number_Theory/Binary-Gcd.hpp\"\
    \nusing i64 = long long;\ninline i64 binary_gcd(i64 a, i64 b) {\n    if (a ==\
    \ 0 || b == 0) return a + b;\n    char n = __builtin_ctzll(a);\n    char m = __builtin_ctzll(b);\n\
    \    a >>= n;\n    b >>= m;\n    n = std::min(n, m);\n    while (a != b) {\n \
    \       i64 d = a - b;\n        char s = __builtin_ctzll(d);\n        bool f =\
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
    \       }\n    };\n\n    solve(n);\n\n    return res;\n}\n#line 5 \"Number_Theory/Gauss-Integer.hpp\"\
    \n\nnamespace Format_Fact {\nusing i128 = __int128;\nstruct G {\n    i128 a, b;\n\
    \    G(){};\n    G(i128 a, i128 b) : a(a), b(b){};\n    G friend operator+(const\
    \ G &a, const G &b) {\n        return {a.a + b.a, a.b + b.b};\n    }\n    G friend\
    \ operator-(const G &a, const G &b) {\n        return {a.a - b.a, a.b - b.b};\n\
    \    }\n    G friend operator*(const G &a, const G &b) {\n        return {a.a\
    \ * b.a - a.b * b.b, a.a * b.b + a.b * b.a};\n    }\n    bool operator==(const\
    \ G &x) const { return x.a == a && x.b == b; }\n    G operator*(const i128 &t)\
    \ const { return {a * t, b * t}; }\n    G operator/(const i128 &t) const { return\
    \ {a / t, b / t}; }\n    G friend operator/(const G &a, const G &b) {\n      \
    \  i128 len = b.a * b.a + b.b * b.b;\n        G c = a * G(b.a, -b.b);\n      \
    \  auto div = [&](i128 a, i128 n) -> i128 {\n            i128 now = (a % n + n)\
    \ % n;\n            return ((a - now) / n);\n        };\n        return {div(2\
    \ * c.a + len, 2 * len), div(2 * c.b + len, 2 * len)};\n    }\n};\n\nstatic G\
    \ one = G(1, 0);\ntemplate <class T>\nT _power(T x, i128 b) {\n    T res = one;\n\
    \    while (b) {\n        if (b & 1) res = res * x;\n        x = x * x;\n    \
    \    b = b / 2;\n    }\n    return res;\n}\nG solveprime(i128 p) {\n    if (p\
    \ == 2) return {1, 1};\n    i128 t = 1;\n    auto qpow = [&](i128 a, i128 b, i128\
    \ p) {\n        i128 res = 1;\n        while (b) {\n            if (b & 1) res\
    \ = res * a % p;\n            a = a * a % p;\n            b = b / 2;\n       \
    \ }\n        return res;\n    };\n    for (; qpow(t, (p - 1) / 2, p) != p - 1;)\
    \ t++;\n    i128 k = qpow(t, (p - 1) / 4, p);\n\n    std::function<G(G, G)> Ggcd\
    \ = [&](G a, G b) -> G {\n        if (b.a == 0 && b.b == 0)\n            return\
    \ a;\n        else\n            return Ggcd(b, a - (a / b) * b);\n    };\n   \
    \ auto g = Ggcd({p, 0}, {k, 1});\n\n    if (g.a < 0) g.a = -g.a;\n    if (g.b\
    \ < 0) g.b = -g.b;\n    if (g.a > g.b) swap(g.a, g.b);\n    return g;\n}\nstd::vector<G>\
    \ solvecomposite(i128 n) {\n    auto fact = factorization<i64>(n);\n    std::sort(begin(fact),\
    \ end(fact));\n\n    std::vector<pair<i128, i64>> prm;\n    for (int i = 0, j\
    \ = 0; i < int(fact.size()); i = j) {\n        while (fact[j] == fact[i] && j\
    \ < int(fact.size())) j++;\n        prm.emplace_back(fact[i], j - i);\n    }\n\
    \n    std::vector<G> v{{1, 0}};\n    for (auto [p, tmp] : prm) {\n        if (p\
    \ % 4 == 1) {\n            G A = solveprime(p);\n            G B = {A.a, -A.b};\n\
    \            auto now = _power<G>(A, 2 * tmp);\n\n            std::vector<G> res;\n\
    \            for (i64 i = 0; i <= 2 * tmp; i++) {\n                for (auto it\
    \ : v) res.push_back(it * now);\n                now = now * B / A;\n        \
    \    }\n            swap(v, res);\n        } else {\n            G now(p, 0);\n\
    \            now = _power<G>(now, tmp);\n            for (auto &&it : v) it =\
    \ it * now;\n        }\n    }\n    for (auto &&[a, b] : v) {\n        if (a <\
    \ 0) a = -a;\n        if (b < 0) b = -b;\n    }\n    std::sort(v.begin(), v.end(),\
    \ [&](const G &a, const G &b) {\n        return make_pair(a.a, a.b) < make_pair(b.a,\
    \ b.b);\n    });\n    v.resize(unique(v.begin(), v.end()) - v.begin());\n\n  \
    \  std::vector<G> t;\n    for (auto [a, b] : v)\n        if (a != 0 && b != 0)\
    \ t.emplace_back(a, b);\n    return t;\n}\n}  // namespace Format_Fact\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n#include \"Factorization.hpp\"\
    \n\nnamespace Format_Fact {\nusing i128 = __int128;\nstruct G {\n    i128 a, b;\n\
    \    G(){};\n    G(i128 a, i128 b) : a(a), b(b){};\n    G friend operator+(const\
    \ G &a, const G &b) {\n        return {a.a + b.a, a.b + b.b};\n    }\n    G friend\
    \ operator-(const G &a, const G &b) {\n        return {a.a - b.a, a.b - b.b};\n\
    \    }\n    G friend operator*(const G &a, const G &b) {\n        return {a.a\
    \ * b.a - a.b * b.b, a.a * b.b + a.b * b.a};\n    }\n    bool operator==(const\
    \ G &x) const { return x.a == a && x.b == b; }\n    G operator*(const i128 &t)\
    \ const { return {a * t, b * t}; }\n    G operator/(const i128 &t) const { return\
    \ {a / t, b / t}; }\n    G friend operator/(const G &a, const G &b) {\n      \
    \  i128 len = b.a * b.a + b.b * b.b;\n        G c = a * G(b.a, -b.b);\n      \
    \  auto div = [&](i128 a, i128 n) -> i128 {\n            i128 now = (a % n + n)\
    \ % n;\n            return ((a - now) / n);\n        };\n        return {div(2\
    \ * c.a + len, 2 * len), div(2 * c.b + len, 2 * len)};\n    }\n};\n\nstatic G\
    \ one = G(1, 0);\ntemplate <class T>\nT _power(T x, i128 b) {\n    T res = one;\n\
    \    while (b) {\n        if (b & 1) res = res * x;\n        x = x * x;\n    \
    \    b = b / 2;\n    }\n    return res;\n}\nG solveprime(i128 p) {\n    if (p\
    \ == 2) return {1, 1};\n    i128 t = 1;\n    auto qpow = [&](i128 a, i128 b, i128\
    \ p) {\n        i128 res = 1;\n        while (b) {\n            if (b & 1) res\
    \ = res * a % p;\n            a = a * a % p;\n            b = b / 2;\n       \
    \ }\n        return res;\n    };\n    for (; qpow(t, (p - 1) / 2, p) != p - 1;)\
    \ t++;\n    i128 k = qpow(t, (p - 1) / 4, p);\n\n    std::function<G(G, G)> Ggcd\
    \ = [&](G a, G b) -> G {\n        if (b.a == 0 && b.b == 0)\n            return\
    \ a;\n        else\n            return Ggcd(b, a - (a / b) * b);\n    };\n   \
    \ auto g = Ggcd({p, 0}, {k, 1});\n\n    if (g.a < 0) g.a = -g.a;\n    if (g.b\
    \ < 0) g.b = -g.b;\n    if (g.a > g.b) swap(g.a, g.b);\n    return g;\n}\nstd::vector<G>\
    \ solvecomposite(i128 n) {\n    auto fact = factorization<i64>(n);\n    std::sort(begin(fact),\
    \ end(fact));\n\n    std::vector<pair<i128, i64>> prm;\n    for (int i = 0, j\
    \ = 0; i < int(fact.size()); i = j) {\n        while (fact[j] == fact[i] && j\
    \ < int(fact.size())) j++;\n        prm.emplace_back(fact[i], j - i);\n    }\n\
    \n    std::vector<G> v{{1, 0}};\n    for (auto [p, tmp] : prm) {\n        if (p\
    \ % 4 == 1) {\n            G A = solveprime(p);\n            G B = {A.a, -A.b};\n\
    \            auto now = _power<G>(A, 2 * tmp);\n\n            std::vector<G> res;\n\
    \            for (i64 i = 0; i <= 2 * tmp; i++) {\n                for (auto it\
    \ : v) res.push_back(it * now);\n                now = now * B / A;\n        \
    \    }\n            swap(v, res);\n        } else {\n            G now(p, 0);\n\
    \            now = _power<G>(now, tmp);\n            for (auto &&it : v) it =\
    \ it * now;\n        }\n    }\n    for (auto &&[a, b] : v) {\n        if (a <\
    \ 0) a = -a;\n        if (b < 0) b = -b;\n    }\n    std::sort(v.begin(), v.end(),\
    \ [&](const G &a, const G &b) {\n        return make_pair(a.a, a.b) < make_pair(b.a,\
    \ b.b);\n    });\n    v.resize(unique(v.begin(), v.end()) - v.begin());\n\n  \
    \  std::vector<G> t;\n    for (auto [a, b] : v)\n        if (a != 0 && b != 0)\
    \ t.emplace_back(a, b);\n    return t;\n}\n}  // namespace Format_Fact"
  dependsOn:
  - Template/Template.hpp
  - Number_Theory/Factorization.hpp
  - Number_Theory/Binary-Gcd.hpp
  isVerificationFile: false
  path: Number_Theory/Gauss-Integer.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number_Theory/Gauss-Integer.hpp
layout: document
redirect_from:
- /library/Number_Theory/Gauss-Integer.hpp
- /library/Number_Theory/Gauss-Integer.hpp.html
title: Number_Theory/Gauss-Integer.hpp
---
