---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"ModInt/Modint32_change.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"ModInt/Modint32_change.hpp\"\
    \nstruct mintc {\n    int x;\n    using Type = int;\n    static Type mod;\n  \
    \  mintc() : x(0) {}\n    mintc(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y)\
    \ % mod) % mod) {}\n    mintc &operator+=(const mintc &p) {\n        if ((x +=\
    \ p.x) >= mod) x -= mod;\n        return *this;\n    }\n    mintc &operator-=(const\
    \ mintc &p) {\n        if ((x += mod - p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n    mintc &operator*=(const mintc &p) {\n        x = (int)(1LL\
    \ * x * p.x % mod);\n        return *this;\n    }\n    mintc &operator/=(const\
    \ mintc &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n \
    \   mintc operator-() const { return mintc(-x); }\n    mintc operator+(const mintc\
    \ &p) const { return mintc(*this) += p; }\n    mintc operator-(const mintc &p)\
    \ const { return mintc(*this) -= p; }\n    mintc operator*(const mintc &p) const\
    \ { return mintc(*this) *= p; }\n    mintc operator/(const mintc &p) const { return\
    \ mintc(*this) /= p; }\n    bool operator==(const mintc &p) const { return x ==\
    \ p.x; }\n    bool operator!=(const mintc &p) const { return x != p.x; }\n   \
    \ mintc inverse() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n    \
    \    while (b > 0) {\n            t = a / b;\n            std::swap(a -= t * b,\
    \ b);\n            std::swap(u -= t * v, v);\n        }\n        return mintc(u);\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, const mintc &p)\
    \ {\n        return os << p.x;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, mintc &a) {\n        int64_t t;\n        is >> t;\n        a = mintc(t);\n\
    \        return (is);\n    }\n    int get() const { return x; }\n    static int\
    \ get_mod() { return mod; }\n    static void set_mod(int md) {\n        assert(0\
    \ < md && md <= (1LL << 30) - 1);\n        mod = md;\n    }\n};\n\ntypename mintc::Type\
    \ mintc::mod;\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\nstruct mintc {\n \
    \   int x;\n    using Type = int;\n    static Type mod;\n    mintc() : x(0) {}\n\
    \    mintc(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n  \
    \  mintc &operator+=(const mintc &p) {\n        if ((x += p.x) >= mod) x -= mod;\n\
    \        return *this;\n    }\n    mintc &operator-=(const mintc &p) {\n     \
    \   if ((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n    }\n   \
    \ mintc &operator*=(const mintc &p) {\n        x = (int)(1LL * x * p.x % mod);\n\
    \        return *this;\n    }\n    mintc &operator/=(const mintc &p) {\n     \
    \   *this *= p.inverse();\n        return *this;\n    }\n    mintc operator-()\
    \ const { return mintc(-x); }\n    mintc operator+(const mintc &p) const { return\
    \ mintc(*this) += p; }\n    mintc operator-(const mintc &p) const { return mintc(*this)\
    \ -= p; }\n    mintc operator*(const mintc &p) const { return mintc(*this) *=\
    \ p; }\n    mintc operator/(const mintc &p) const { return mintc(*this) /= p;\
    \ }\n    bool operator==(const mintc &p) const { return x == p.x; }\n    bool\
    \ operator!=(const mintc &p) const { return x != p.x; }\n    mintc inverse() const\
    \ {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n \
    \           t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return mintc(u);\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mintc &p) {\n        return os << p.x;\n\
    \    }\n    friend std::istream &operator>>(std::istream &is, mintc &a) {\n  \
    \      int64_t t;\n        is >> t;\n        a = mintc(t);\n        return (is);\n\
    \    }\n    int get() const { return x; }\n    static int get_mod() { return mod;\
    \ }\n    static void set_mod(int md) {\n        assert(0 < md && md <= (1LL <<\
    \ 30) - 1);\n        mod = md;\n    }\n};\n\ntypename mintc::Type mintc::mod;"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: ModInt/Modint32_change.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ModInt/Modint32_change.hpp
layout: document
redirect_from:
- /library/ModInt/Modint32_change.hpp
- /library/ModInt/Modint32_change.hpp.html
title: ModInt/Modint32_change.hpp
---
