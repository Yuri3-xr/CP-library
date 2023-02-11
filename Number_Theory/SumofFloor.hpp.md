---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/SumofFloorofLinear.test.cpp
    title: Verify/SumofFloorofLinear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number_Theory/SumofFloor.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Number_Theory/SumofFloor.hpp\"\
    \n// sum_{0 <= i < N} (ai + b) // m\ntemplate <typename T>\nT sum_of_floor(T n,\
    \ T m, T a, T b) {\n    T ret = 0;\n    if (a >= m) ret += (n - 1) * n * (a /\
    \ m) / 2, a %= m;\n    if (b >= m) ret += n * (b / m), b %= m;\n    T y = (a *\
    \ n + b) / m;\n    if (y == 0) return ret;\n    T x = y * m - b;\n    ret += (n\
    \ - (x + a - 1) / a) * y;\n    ret += sum_of_floor(y, a, m, (a - x % a) % a);\n\
    \    return ret;\n}\n\n// verify www.codechef.com/viewsolution/36222026\n// count\
    \ x : ax + b mod m < yr, 0 <= x < xr\ntemplate <typename T>\nT mod_affine_range_counting(T\
    \ a, T b, T m, T xr, T yr) {\n    assert(0 <= yr && yr <= m);\n    return sum_of_floor(xr,\
    \ m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);\n}\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n// sum_{0 <= i < N}\
    \ (ai + b) // m\ntemplate <typename T>\nT sum_of_floor(T n, T m, T a, T b) {\n\
    \    T ret = 0;\n    if (a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n \
    \   if (b >= m) ret += n * (b / m), b %= m;\n    T y = (a * n + b) / m;\n    if\
    \ (y == 0) return ret;\n    T x = y * m - b;\n    ret += (n - (x + a - 1) / a)\
    \ * y;\n    ret += sum_of_floor(y, a, m, (a - x % a) % a);\n    return ret;\n\
    }\n\n// verify www.codechef.com/viewsolution/36222026\n// count x : ax + b mod\
    \ m < yr, 0 <= x < xr\ntemplate <typename T>\nT mod_affine_range_counting(T a,\
    \ T b, T m, T xr, T yr) {\n    assert(0 <= yr && yr <= m);\n    return sum_of_floor(xr,\
    \ m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);\n}"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Number_Theory/SumofFloor.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/SumofFloorofLinear.test.cpp
documentation_of: Number_Theory/SumofFloor.hpp
layout: document
redirect_from:
- /library/Number_Theory/SumofFloor.hpp
- /library/Number_Theory/SumofFloor.hpp.html
title: Number_Theory/SumofFloor.hpp
---
