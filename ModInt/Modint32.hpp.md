---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/Multipoint_Evaluation.test.cpp
    title: Verify/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Polynomial_Interpolation.test.cpp
    title: Verify/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/RangeAffineRangeSum.test.cpp
    title: Verify/RangeAffineRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Sum_of_Totient_Function.test.cpp
    title: Verify/Sum_of_Totient_Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ModInt/Modint32.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\nusing i64 = long long;\n\
    using VI = vector<int>;\nusing pii = pair<int, int>;\n#line 4 \"ModInt/Modint32.hpp\"\
    \n\ntemplate <int mod>\nstruct mint {\n    int x;\n    mint() : x(0) {}\n    mint(int64_t\
    \ y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    mint &operator+=(const\
    \ mint &p) {\n        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n    mint &operator-=(const mint &p) {\n        if ((x += mod - p.x) >=\
    \ mod) x -= mod;\n        return *this;\n    }\n    mint &operator*=(const mint\
    \ &p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n\
    \    mint &operator/=(const mint &p) {\n        *this *= p.inverse();\n      \
    \  return *this;\n    }\n    mint operator-() const { return mint(-x); }\n   \
    \ mint operator+(const mint &p) const { return mint(*this) += p; }\n    mint operator-(const\
    \ mint &p) const { return mint(*this) -= p; }\n    mint operator*(const mint &p)\
    \ const { return mint(*this) *= p; }\n    mint operator/(const mint &p) const\
    \ { return mint(*this) /= p; }\n    bool operator==(const mint &p) const { return\
    \ x == p.x; }\n    bool operator!=(const mint &p) const { return x != p.x; }\n\
    \    mint inverse() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n  \
    \      while (b > 0) {\n            t = a / b;\n            swap(a -= t * b, b);\n\
    \            swap(u -= t * v, v);\n        }\n        return mint(u);\n    }\n\
    \    friend ostream &operator<<(ostream &os, const mint &p) { return os << p.x;\
    \ }\n    friend istream &operator>>(istream &is, mint &a) {\n        int64_t t;\n\
    \        is >> t;\n        a = mint<mod>(t);\n        return (is);\n    }\n  \
    \  int get() const { return x; }\n    static constexpr int get_mod() { return\
    \ mod; }\n};\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n\ntemplate <int mod>\n\
    struct mint {\n    int x;\n    mint() : x(0) {}\n    mint(int64_t y) : x(y >=\
    \ 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    mint &operator+=(const mint\
    \ &p) {\n        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n   \
    \ }\n    mint &operator-=(const mint &p) {\n        if ((x += mod - p.x) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n    mint &operator*=(const mint &p)\
    \ {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n \
    \   mint &operator/=(const mint &p) {\n        *this *= p.inverse();\n       \
    \ return *this;\n    }\n    mint operator-() const { return mint(-x); }\n    mint\
    \ operator+(const mint &p) const { return mint(*this) += p; }\n    mint operator-(const\
    \ mint &p) const { return mint(*this) -= p; }\n    mint operator*(const mint &p)\
    \ const { return mint(*this) *= p; }\n    mint operator/(const mint &p) const\
    \ { return mint(*this) /= p; }\n    bool operator==(const mint &p) const { return\
    \ x == p.x; }\n    bool operator!=(const mint &p) const { return x != p.x; }\n\
    \    mint inverse() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n  \
    \      while (b > 0) {\n            t = a / b;\n            swap(a -= t * b, b);\n\
    \            swap(u -= t * v, v);\n        }\n        return mint(u);\n    }\n\
    \    friend ostream &operator<<(ostream &os, const mint &p) { return os << p.x;\
    \ }\n    friend istream &operator>>(istream &is, mint &a) {\n        int64_t t;\n\
    \        is >> t;\n        a = mint<mod>(t);\n        return (is);\n    }\n  \
    \  int get() const { return x; }\n    static constexpr int get_mod() { return\
    \ mod; }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: ModInt/Modint32.hpp
  requiredBy: []
  timestamp: '2022-08-20 01:45:54+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/convolution.test.cpp
  - Verify/Polynomial_Interpolation.test.cpp
  - Verify/RangeAffineRangeSum.test.cpp
  - Verify/Multipoint_Evaluation.test.cpp
  - Verify/Sum_of_Totient_Function.test.cpp
documentation_of: ModInt/Modint32.hpp
layout: document
redirect_from:
- /library/ModInt/Modint32.hpp
- /library/ModInt/Modint32.hpp.html
title: ModInt/Modint32.hpp
---
