---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/ConvolutionLarge.test.cpp
    title: Verify/ConvolutionLarge.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/InvofFormalPowerSeries.test.cpp
    title: Verify/InvofFormalPowerSeries.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/KthtermofLinearlyRecurrentSequence.test.cpp
    title: Verify/KthtermofLinearlyRecurrentSequence.test.cpp
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
    path: Verify/SumofTotientFunction2.test.cpp
    title: Verify/SumofTotientFunction2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ModInt/Modint32.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"ModInt/Modint32.hpp\"\
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
    \      while (b > 0) {\n            t = a / b;\n            std::swap(a -= t *\
    \ b, b);\n            std::swap(u -= t * v, v);\n        }\n        return mint(u);\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, const mint &p) {\n\
    \        return os << p.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        int64_t t;\n        is >> t;\n        a = mint<mod>(t);\n\
    \        return (is);\n    }\n    int get() const { return x; }\n    static constexpr\
    \ int get_mod() { return mod; }\n};\n"
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
    \      while (b > 0) {\n            t = a / b;\n            std::swap(a -= t *\
    \ b, b);\n            std::swap(u -= t * v, v);\n        }\n        return mint(u);\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, const mint &p) {\n\
    \        return os << p.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &a) {\n        int64_t t;\n        is >> t;\n        a = mint<mod>(t);\n\
    \        return (is);\n    }\n    int get() const { return x; }\n    static constexpr\
    \ int get_mod() { return mod; }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: ModInt/Modint32.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/convolution.test.cpp
  - Verify/InvofFormalPowerSeries.test.cpp
  - Verify/ConvolutionLarge.test.cpp
  - Verify/Polynomial_Interpolation.test.cpp
  - Verify/Multipoint_Evaluation.test.cpp
  - Verify/Sum_of_Totient_Function.test.cpp
  - Verify/KthtermofLinearlyRecurrentSequence.test.cpp
  - Verify/RangeAffineRangeSum.test.cpp
  - Verify/SumofTotientFunction2.test.cpp
documentation_of: ModInt/Modint32.hpp
layout: document
redirect_from:
- /library/ModInt/Modint32.hpp
- /library/ModInt/Modint32.hpp.html
title: ModInt/Modint32.hpp
---
