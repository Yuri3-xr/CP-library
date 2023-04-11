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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"Verify/Factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n\n#line 2 \"Number_Theory/Factorization.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 2 \"Number_Theory/Binary-Gcd.hpp\"\
    \n\n#line 4 \"Number_Theory/Binary-Gcd.hpp\"\n\ninline i64 binary_gcd(i64 a, i64\
    \ b) {\n    if (a == 0 || b == 0) return a + b;\n    char n = __builtin_ctzll(a);\n\
    \    char m = __builtin_ctzll(b);\n    a >>= n;\n    b >>= m;\n    n = std::min(n,\
    \ m);\n    while (a != b) {\n        i64 d = a - b;\n        char s = __builtin_ctzll(d);\n\
    \        bool f = a > b;\n        b = f ? b : a;\n        a = (f ? d : -d) >>\
    \ s;\n    }\n    return a << n;\n}\n#line 5 \"Number_Theory/Factorization.hpp\"\
    \n\nnamespace Factor {\nusing u64 = std::uint64_t;\n\nu64 modmul(u64 a, u64 b,\
    \ u64 M) {\n    i64 ret = a * b - M * u64(1.L / M * a * b);\n    return ret +\
    \ M * (ret < 0) - M * (ret >= (i64)M);\n}\n\nu64 modpow(u64 b, u64 e, u64 mod)\
    \ {\n    u64 ans = 1;\n    for (; e; b = modmul(b, b, mod), e /= 2)\n        if\
    \ (e & 1) ans = modmul(ans, b, mod);\n    return ans;\n}\n\nbool isPrime(u64 n)\
    \ {\n    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n    std::vector<u64>\
    \ A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n    u64 s = __builtin_ctzll(n\
    \ - 1), d = n >> s;\n    for (u64 a : A) {  // ^ count trailing zeroes\n     \
    \   u64 p = modpow(a % n, d, n), i = s;\n        while (p != 1 && p != n - 1 &&\
    \ a % n && i--) p = modmul(p, p, n);\n        if (p != n - 1 && i != s) return\
    \ 0;\n    }\n    return 1;\n}\nu64 pollard(u64 n) {\n    auto f = [n](u64 x, u64\
    \ k) { return modmul(x, x, n) + k; };\n    u64 x = 0, y = 0, t = 30, prd = 2,\
    \ i = 1, q;\n    while (t++ % 40 || binary_gcd(prd, n) == 1) {\n        if (x\
    \ == y) x = ++i, y = f(x, i);\n        if ((q = modmul(prd, std::max(x, y) - std::min(x,\
    \ y), n))) prd = q;\n        x = f(x, i), y = f(f(y, i), i);\n    }\n    return\
    \ std::gcd(prd, n);\n}\nstd::vector<u64> factor(u64 n) {\n    if (n == 1) return\
    \ {};\n    if (isPrime(n)) return {n};\n    u64 x = pollard(n);\n    auto l =\
    \ factor(x), r = factor(n / x);\n    l.insert(l.end(), r.begin(), r.end());\n\
    \    return l;\n}\n\ntemplate <class T = u64>\nstd::vector<std::pair<T, int>>\
    \ factorSortedList(u64 n) {\n    // \\prid x_i^p_i\n    auto fac = factor(n);\n\
    \    std::sort(fac.begin(), fac.end());\n\n    std::vector<std::pair<T, int>>\
    \ lt;\n    for (int i = 0, j; i < int(fac.size()); i = j) {\n        j = i;\n\
    \        while (j < static_cast<int>(fac.size()) && fac[i] == fac[j]) j++;\n \
    \       lt.emplace_back(fac[i], j - i);\n    }\n\n    return lt;\n}\n}  // namespace\
    \ Factor\n#line 5 \"Verify/Factorize.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int _;\n    std::cin >> _;\n    while (_--)\
    \ {\n        i64 x;\n        std::cin >> x;\n        auto ans = Factor::factor(x);\n\
    \        std::sort(begin(ans), end(ans));\n\n        std::cout << ans.size() <<\
    \ '\\n';\n        for (int i = 0; i < (int)ans.size(); i++) {\n            std::cout\
    \ << ans[i] << \" \\n\"[i == (int)ans.size() - 1];\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ \"../Number_Theory/Factorization.hpp\"\n#include \"../Template/Template.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int _;\n    std::cin >> _;\n    while (_--) {\n        i64 x;\n        std::cin\
    \ >> x;\n        auto ans = Factor::factor(x);\n        std::sort(begin(ans),\
    \ end(ans));\n\n        std::cout << ans.size() << '\\n';\n        for (int i\
    \ = 0; i < (int)ans.size(); i++) {\n            std::cout << ans[i] << \" \\n\"\
    [i == (int)ans.size() - 1];\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - Number_Theory/Factorization.hpp
  - Template/Template.hpp
  - Number_Theory/Binary-Gcd.hpp
  isVerificationFile: true
  path: Verify/Factorize.test.cpp
  requiredBy: []
  timestamp: '2023-04-03 20:03:50+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/Factorize.test.cpp
layout: document
redirect_from:
- /verify/Verify/Factorize.test.cpp
- /verify/Verify/Factorize.test.cpp.html
title: Verify/Factorize.test.cpp
---
