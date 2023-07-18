---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"Number_Theory/Crt.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Number_Theory/Crt.hpp\"\
    \n\ntemplate <typename T>\nT inv_mod(T x, T m) {\n    assert(1 <= m);\n\n    T\
    \ b = m - 2;\n    T res = 1;\n    for (; b; b /= 2, x = 1LL * x * x % m) {\n \
    \       if (b % 2) {\n            res = 1LL * res * x % m;\n        }\n    }\n\
    \    return res;\n}\n\nstd::pair<long long, long long> inv_gcd(i64 a, i64 b) {\n\
    \    a = a % b;\n    if (a == 0) return std::make_pair(b, 0LL);\n\n    i64 s =\
    \ b, t = a;\n    i64 m0 = 0, m1 = 1;\n    while (t) {\n        i64 u = s / t;\n\
    \        s -= t * u;\n        m0 -= m1 * u;\n        std::swap(s, t);\n      \
    \  std::swap(m0, m1);\n    }\n\n    if (m0 < 0) m0 += b / s;\n    return std::make_pair(s,\
    \ m0);\n}\n// (rem, mod)\nstd::pair<i64, i64> crt(const std::vector<i64>& r, const\
    \ std::vector<i64>& m) {\n    assert(r.size() == m.size());\n    const int n =\
    \ r.size();\n    i64 r0 = 0, m0 = 1;\n    for (int i = 0; i < n; ++i) {\n    \
    \    assert(1 <= m[i]);\n        i64 r1 = r[i] % m[i], m1 = m[i];\n        if\
    \ (m0 < m1) {\n            std::swap(r0, r1);\n            std::swap(m0, m1);\n\
    \        }\n        if (m0 % m1 == 0) {\n            if (r0 % m1 != r1) return\
    \ std::make_pair(0LL, 0LL);\n            continue;\n        }\n\n        i64 g,\
    \ im;\n        std::tie(g, im) = inv_gcd(m0, m1);\n        i64 u1 = m1 / g;\n\
    \        if ((r1 - r0) % g) return std::make_pair(0LL, 0LL);\n        i64 x =\
    \ (r1 - r0) / g % u1 * im % u1;\n\n        r0 += x * m0;\n        m0 *= u1;\n\
    \        if (r0 < 0) r0 += m0;\n    }\n    return std::make_pair(r0, m0);\n}\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n\ntemplate <typename\
    \ T>\nT inv_mod(T x, T m) {\n    assert(1 <= m);\n\n    T b = m - 2;\n    T res\
    \ = 1;\n    for (; b; b /= 2, x = 1LL * x * x % m) {\n        if (b % 2) {\n \
    \           res = 1LL * res * x % m;\n        }\n    }\n    return res;\n}\n\n\
    std::pair<long long, long long> inv_gcd(i64 a, i64 b) {\n    a = a % b;\n    if\
    \ (a == 0) return std::make_pair(b, 0LL);\n\n    i64 s = b, t = a;\n    i64 m0\
    \ = 0, m1 = 1;\n    while (t) {\n        i64 u = s / t;\n        s -= t * u;\n\
    \        m0 -= m1 * u;\n        std::swap(s, t);\n        std::swap(m0, m1);\n\
    \    }\n\n    if (m0 < 0) m0 += b / s;\n    return std::make_pair(s, m0);\n}\n\
    // (rem, mod)\nstd::pair<i64, i64> crt(const std::vector<i64>& r, const std::vector<i64>&\
    \ m) {\n    assert(r.size() == m.size());\n    const int n = r.size();\n    i64\
    \ r0 = 0, m0 = 1;\n    for (int i = 0; i < n; ++i) {\n        assert(1 <= m[i]);\n\
    \        i64 r1 = r[i] % m[i], m1 = m[i];\n        if (m0 < m1) {\n          \
    \  std::swap(r0, r1);\n            std::swap(m0, m1);\n        }\n        if (m0\
    \ % m1 == 0) {\n            if (r0 % m1 != r1) return std::make_pair(0LL, 0LL);\n\
    \            continue;\n        }\n\n        i64 g, im;\n        std::tie(g, im)\
    \ = inv_gcd(m0, m1);\n        i64 u1 = m1 / g;\n        if ((r1 - r0) % g) return\
    \ std::make_pair(0LL, 0LL);\n        i64 x = (r1 - r0) / g % u1 * im % u1;\n\n\
    \        r0 += x * m0;\n        m0 *= u1;\n        if (r0 < 0) r0 += m0;\n   \
    \ }\n    return std::make_pair(r0, m0);\n}\n"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Number_Theory/Crt.hpp
  requiredBy: []
  timestamp: '2023-07-19 04:07:27+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number_Theory/Crt.hpp
layout: document
redirect_from:
- /library/Number_Theory/Crt.hpp
- /library/Number_Theory/Crt.hpp.html
title: Number_Theory/Crt.hpp
---
