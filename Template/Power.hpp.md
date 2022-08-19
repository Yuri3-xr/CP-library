---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Polynomial/Ntt.hpp
    title: Polynomial/Ntt.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/Poly.hpp
    title: Polynomial/Poly.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Template/Power.hpp\"\ntemplate <class T>\nT power(T a, int\
    \ b) {\n    T res = 1;\n    for (; b; b /= 2, a *= a) {\n        if (b % 2) {\n\
    \            res *= a;\n        }\n    }\n    return res;\n}\n"
  code: "template <class T>\nT power(T a, int b) {\n    T res = 1;\n    for (; b;\
    \ b /= 2, a *= a) {\n        if (b % 2) {\n            res *= a;\n        }\n\
    \    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Template/Power.hpp
  requiredBy:
  - Polynomial/Poly.hpp
  - Polynomial/Ntt.hpp
  timestamp: '2022-08-20 01:45:54+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/convolution.test.cpp
documentation_of: Template/Power.hpp
layout: document
redirect_from:
- /library/Template/Power.hpp
- /library/Template/Power.hpp.html
title: Template/Power.hpp
---
