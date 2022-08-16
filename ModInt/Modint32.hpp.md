---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ModInt/Modint32.hpp\"\n\ntemplate <int mod>\nstruct ModInt\
    \ {\n    int x;\n\n    ModInt() : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0\
    \ ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    ModInt &operator+=(const ModInt\
    \ &p) {\n        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n   \
    \ }\n\n    ModInt &operator-=(const ModInt &p) {\n        if ((x += mod - p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inverse();\n\
    \        return *this;\n    }\n\n    ModInt operator-() const { return ModInt(-x);\
    \ }\n\n    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p;\
    \ }\n\n    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p;\
    \ }\n\n    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p;\
    \ }\n\n    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p;\
    \ }\n\n    bool operator==(const ModInt &p) const { return x == p.x; }\n\n   \
    \ bool operator!=(const ModInt &p) const { return x != p.x; }\n\n    ModInt inverse()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return ModInt(u);\n    }\n    friend ostream\
    \ &operator<<(ostream &os, const ModInt &p) {\n        return os << p.x;\n   \
    \ }\n\n    friend istream &operator>>(istream &is, ModInt &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = ModInt<mod>(t);\n        return (is);\n  \
    \  }\n\n    int get() const { return x; }\n};\n"
  code: "#pragma once\n\ntemplate <int mod>\nstruct ModInt {\n    int x;\n\n    ModInt()\
    \ : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)\
    \ % mod) {}\n\n    ModInt &operator+=(const ModInt &p) {\n        if ((x += p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const\
    \ ModInt &p) {\n        if ((x += mod - p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int)(1LL\
    \ * x * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    ModInt operator-() const { return ModInt(-x); }\n\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n\n    ModInt inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return ModInt(u);\n    }\n    friend ostream &operator<<(ostream &os,\
    \ const ModInt &p) {\n        return os << p.x;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n        a = ModInt<mod>(t);\n\
    \        return (is);\n    }\n\n    int get() const { return x; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ModInt/Modint32.hpp
  requiredBy: []
  timestamp: '2022-08-16 22:05:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ModInt/Modint32.hpp
layout: document
redirect_from:
- /library/ModInt/Modint32.hpp
- /library/ModInt/Modint32.hpp.html
title: ModInt/Modint32.hpp
---
