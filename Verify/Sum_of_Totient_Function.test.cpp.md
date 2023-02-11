---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ModInt/Modint32.hpp
    title: ModInt/Modint32.hpp
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Mf_Sieve.hpp
    title: Number_Theory/Mf_Sieve.hpp
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Prime_Sieve.hpp
    title: Number_Theory/Prime_Sieve.hpp
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"Verify/Sum_of_Totient_Function.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\n#line 2 \"ModInt/Modint32.hpp\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\nusing i64\
    \ = std::int64_t;\n#line 4 \"ModInt/Modint32.hpp\"\n\ntemplate <int mod>\nstruct\
    \ mint {\n    int x;\n    mint() : x(0) {}\n    mint(int64_t y) : x(y >= 0 ? y\
    \ % mod : (mod - (-y) % mod) % mod) {}\n    mint &operator+=(const mint &p) {\n\
    \        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n    }\n    mint\
    \ &operator-=(const mint &p) {\n        if ((x += mod - p.x) >= mod) x -= mod;\n\
    \        return *this;\n    }\n    mint &operator*=(const mint &p) {\n       \
    \ x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n    mint &operator/=(const\
    \ mint &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n  \
    \  mint operator-() const { return mint(-x); }\n    mint operator+(const mint\
    \ &p) const { return mint(*this) += p; }\n    mint operator-(const mint &p) const\
    \ { return mint(*this) -= p; }\n    mint operator*(const mint &p) const { return\
    \ mint(*this) *= p; }\n    mint operator/(const mint &p) const { return mint(*this)\
    \ /= p; }\n    bool operator==(const mint &p) const { return x == p.x; }\n   \
    \ bool operator!=(const mint &p) const { return x != p.x; }\n    mint inverse()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            std::swap(a -= t * b, b);\n         \
    \   std::swap(u -= t * v, v);\n        }\n        return mint(u);\n    }\n   \
    \ friend std::ostream &operator<<(std::ostream &os, const mint &p) {\n       \
    \ return os << p.x;\n    }\n    friend std::istream &operator>>(std::istream &is,\
    \ mint &a) {\n        int64_t t;\n        is >> t;\n        a = mint<mod>(t);\n\
    \        return (is);\n    }\n    int get() const { return x; }\n    static constexpr\
    \ int get_mod() { return mod; }\n};\n#line 2 \"Number_Theory/Mf_Sieve.hpp\"\n\n\
    #line 2 \"Number_Theory/Prime_Sieve.hpp\"\n\n#line 4 \"Number_Theory/Prime_Sieve.hpp\"\
    \n\nstd::vector<int> prime_sieve(int N) {\n    std::vector<bool> sieve(N / 3 +\
    \ 1, 1);\n    for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn;\n       \
    \  p += d = 6 - d, i++) {\n        if (!sieve[i]) continue;\n        for (int\
    \ q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n              \
    \   qe = sieve.size();\n             q < qe; q += r = s - r)\n            sieve[q]\
    \ = 0;\n    }\n    std::vector<int> ret{2, 3};\n    for (int p = 5, d = 4, i =\
    \ 1; p <= N; p += d = 6 - d, i++)\n        if (sieve[i]) ret.push_back(p);\n \
    \   while (!ret.empty() && ret.back() > N) ret.pop_back();\n    return ret;\n\
    }\n#line 4 \"Number_Theory/Mf_Sieve.hpp\"\n\ntemplate <class T>\nstd::vector<T>\
    \ mf_sieve(int n, std::function<T(i64, i64, i64)> f) {\n    /*\n        ##pragma\
    \ f is a multiplicative-function\n        f(n,p,c) <-> n=p^c\n    */\n    std::vector<T>\
    \ ans(n + 1, T());\n    std::vector<int> ps = prime_sieve(n);\n    int p(ps.size());\n\
    \n    std::function<void(int, i64, T)> dfs = [&](int i, i64 x, T y) {\n      \
    \  ans[x] = y;\n        if (y == T()) return;\n        for (int j = i + 1; j <\
    \ p; j++) {\n            i64 nx = x * ps[j];\n            i64 dx = ps[j];\n  \
    \          if (nx > n) break;\n            for (int c = 1; nx <= n; nx *= ps[j],\
    \ dx *= ps[j], ++c)\n                dfs(j, nx, y * f(dx, ps[j], c));\n      \
    \  }\n    };\n    ans[1] = 1;\n    dfs(-1, 1, 1);\n    return ans;\n};\n#line\
    \ 6 \"Verify/Sum_of_Totient_Function.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    constexpr int mod = 998244353;\n    using Z\
    \ = mint<mod>;\n\n    i64 n;\n    std::cin >> n;\n\n    int TH = (int)pow(n, 2.0\
    \ / 3.0);\n\n    auto f = [&](i64 n, i64 p, i64 c) -> Z { return Z(n - n / p);\
    \ };\n    auto phi = mf_sieve<Z>(TH, f);\n    std::vector<Z> dphi(phi.size());\n\
    \    for (int i = 1; i <= TH; i++) dphi[i] = dphi[i - 1] + phi[i];\n\n    const\
    \ Z inv2 = Z(2).inverse();\n    std::unordered_map<i64, Z> mp;\n    std::function<Z(i64)>\
    \ dfs = [&](i64 x) -> Z {\n        if (mp.count(x)) return mp[x];\n        if\
    \ (x <= TH) return dphi[x];\n        Z ans = Z(x) * Z(x + 1) * inv2;\n       \
    \ for (i64 l = 2, r; l <= x; l = r + 1) {\n            r = x / (x / l);\n    \
    \        ans -= dfs(x / l) * Z(r - l + 1);\n        }\n        return mp[x] =\
    \ ans;\n    };\n\n    std::cout << dfs(n) << '\\n';\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n\n#include \"../ModInt/Modint32.hpp\"\n#include \"../Number_Theory/Mf_Sieve.hpp\"\
    \n#include \"../Template/Template.hpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    constexpr int mod = 998244353;\n    using Z\
    \ = mint<mod>;\n\n    i64 n;\n    std::cin >> n;\n\n    int TH = (int)pow(n, 2.0\
    \ / 3.0);\n\n    auto f = [&](i64 n, i64 p, i64 c) -> Z { return Z(n - n / p);\
    \ };\n    auto phi = mf_sieve<Z>(TH, f);\n    std::vector<Z> dphi(phi.size());\n\
    \    for (int i = 1; i <= TH; i++) dphi[i] = dphi[i - 1] + phi[i];\n\n    const\
    \ Z inv2 = Z(2).inverse();\n    std::unordered_map<i64, Z> mp;\n    std::function<Z(i64)>\
    \ dfs = [&](i64 x) -> Z {\n        if (mp.count(x)) return mp[x];\n        if\
    \ (x <= TH) return dphi[x];\n        Z ans = Z(x) * Z(x + 1) * inv2;\n       \
    \ for (i64 l = 2, r; l <= x; l = r + 1) {\n            r = x / (x / l);\n    \
    \        ans -= dfs(x / l) * Z(r - l + 1);\n        }\n        return mp[x] =\
    \ ans;\n    };\n\n    std::cout << dfs(n) << '\\n';\n\n    return 0;\n}"
  dependsOn:
  - ModInt/Modint32.hpp
  - Template/Template.hpp
  - Number_Theory/Mf_Sieve.hpp
  - Number_Theory/Prime_Sieve.hpp
  isVerificationFile: true
  path: Verify/Sum_of_Totient_Function.test.cpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/Sum_of_Totient_Function.test.cpp
layout: document
redirect_from:
- /verify/Verify/Sum_of_Totient_Function.test.cpp
- /verify/Verify/Sum_of_Totient_Function.test.cpp.html
title: Verify/Sum_of_Totient_Function.test.cpp
---
