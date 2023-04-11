---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ModInt/Modint32.hpp
    title: ModInt/Modint32.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/Ntt.hpp
    title: Polynomial/Ntt.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/NttLarge.hpp
    title: Polynomial/NttLarge.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Power.hpp
    title: Template/Power.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_large
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_large
  bundledCode: "#line 1 \"Verify/ConvolutionLarge.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_large\"\
    \n\n#line 2 \"ModInt/Modint32.hpp\"\n\n#line 2 \"Template/Template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"ModInt/Modint32.hpp\"\
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
    \ int get_mod() { return mod; }\n};\n#line 2 \"Polynomial/Ntt.hpp\"\n\n#line 1\
    \ \"Template/Power.hpp\"\ntemplate <class T>\nT power(T a, int b) {\n    T res\
    \ = 1;\n    for (; b; b /= 2, a *= a) {\n        if (b % 2) {\n            res\
    \ *= a;\n        }\n    }\n    return res;\n}\n#line 5 \"Polynomial/Ntt.hpp\"\n\
    template <class Z>\nstruct NTT {\n    std::vector<int> rev;\n    std::vector<Z>\
    \ roots{0, 1};\n\n    static constexpr int getRoot() {\n        auto _mod = Z::get_mod();\n\
    \        using u64 = uint64_t;\n        u64 ds[32] = {};\n        int idx = 0;\n\
    \        u64 m = _mod - 1;\n        for (u64 i = 2; i * i <= m; ++i) {\n     \
    \       if (m % i == 0) {\n                ds[idx++] = i;\n                while\
    \ (m % i == 0) m /= i;\n            }\n        }\n        if (m != 1) ds[idx++]\
    \ = m;\n\n        int _pr = 2;\n        for (;;) {\n            int flg = 1;\n\
    \            for (int i = 0; i < idx; ++i) {\n                u64 a = _pr, b =\
    \ (_mod - 1) / ds[i], r = 1;\n                for (; b; a = a * a % _mod, b /=\
    \ 2) {\n                    if (b % 2 == 1) r = r * a % _mod;\n              \
    \  }\n                if (r == 1) {\n                    flg = 0;\n          \
    \          break;\n                }\n            }\n            if (flg == 1)\
    \ break;\n            ++_pr;\n        }\n        return _pr;\n    };\n\n    static\
    \ constexpr int rt = getRoot();\n\n    void dft(std::vector<Z> &a) {\n       \
    \ int n = a.size();\n\n        if (int(rev.size()) != n) {\n            int k\
    \ = __builtin_ctz(n) - 1;\n            rev.resize(n);\n            for (int i\
    \ = 0; i < n; i++) {\n                rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;\n\
    \            }\n        }\n\n        for (int i = 0; i < n; i++) {\n         \
    \   if (rev[i] < i) {\n                std::swap(a[i], a[rev[i]]);\n         \
    \   }\n        }\n        if (int(roots.size()) < n) {\n            int k = __builtin_ctz(roots.size());\n\
    \            roots.resize(n);\n            while ((1 << k) < n) {\n          \
    \      Z e = power(Z(rt), (Z::get_mod() - 1) >> (k + 1));\n                for\
    \ (int i = 1 << (k - 1); i < (1 << k); i++) {\n                    roots[2 * i]\
    \ = roots[i];\n                    roots[2 * i + 1] = roots[i] * e;\n        \
    \        }\n                k++;\n            }\n        }\n        for (int k\
    \ = 1; k < n; k *= 2) {\n            for (int i = 0; i < n; i += 2 * k) {\n  \
    \              for (int j = 0; j < k; j++) {\n                    Z u = a[i +\
    \ j];\n                    Z v = a[i + j + k] * roots[k + j];\n              \
    \      a[i + j] = u + v;\n                    a[i + j + k] = u - v;\n        \
    \        }\n            }\n        }\n    }\n    void idft(std::vector<Z> &a)\
    \ {\n        int n = a.size();\n        reverse(a.begin() + 1, a.end());\n   \
    \     dft(a);\n        Z inv = (1 - Z::get_mod()) / n;\n        for (int i = 0;\
    \ i < n; i++) {\n            a[i] *= inv;\n        }\n    }\n    std::vector<Z>\
    \ multiply(std::vector<Z> a, std::vector<Z> b) {\n        int sz = 1, tot = a.size()\
    \ + b.size() - 1;\n\n        if (tot <= 20) {\n            std::vector<Z> ret(tot);\n\
    \            for (size_t i = 0; i < a.size(); i++)\n                for (size_t\
    \ j = 0; j < b.size(); j++) ret[i + j] += a[i] * b[j];\n            return ret;\n\
    \        }\n\n        while (sz < tot) {\n            sz *= 2;\n        }\n\n\
    \        a.resize(sz), b.resize(sz);\n        dft(a), dft(b);\n\n        for (int\
    \ i = 0; i < sz; ++i) {\n            a[i] = a[i] * b[i];\n        }\n\n      \
    \  idft(a);\n        a.resize(tot);\n        return a;\n    }\n};\n#line 2 \"\
    Polynomial/NttLarge.hpp\"\n\ntemplate <class Z>\nstd::vector<Z> multiplyLarge(const\
    \ std::vector<Z>& v1,\n                             const std::vector<Z>& v2)\
    \ {\n    using FPS = std::vector<Z>;\n    static NTT<Z> ntt;\n    const int L\
    \ = 1 << 23;\n    if (v1.size() == 0 or v2.size() == 0 or v1.size() + v2.size()\
    \ - 1 <= L)\n        return ntt.multiply(v1, v2);\n\n    std::vector<FPS> v1s,\
    \ v2s;\n    for (int i = 0; i < v1.size(); i += L / 2) {\n        FPS nxt(\n \
    \           {v1.begin() + i, v1.begin() + std::min(i + L / 2, int(v1.size()))});\n\
    \        nxt.resize(L);\n        ntt.dft(nxt);\n        v1s.push_back(nxt);\n\
    \    }\n    for (int i = 0; i < v2.size(); i += L / 2) {\n        FPS nxt(\n \
    \           {v2.begin() + i, v2.begin() + std::min(i + L / 2, int(v2.size()))});\n\
    \        nxt.resize(L);\n        ntt.dft(nxt);\n        v2s.push_back(nxt);\n\
    \    }\n\n    std::vector<FPS> cs(v1s.size() + v2s.size() - 1, FPS(L));\n    for\
    \ (int x = 0; x < v1s.size(); ++x)\n        for (int y = 0; y < v2s.size(); ++y)\n\
    \            for (int i = 0; i < L; ++i) cs[x + y][i] += v1s[x][i] * v2s[y][i];\n\
    \n    for (int i = 0; i < v1s.size() + v2s.size() - 1; ++i) {\n        ntt.idft(cs[i]);\n\
    \    }\n\n    FPS ret(v1.size() + v2.size() - 1);\n\n    for (int i = 0; i < cs.size();\
    \ ++i) {\n        for (int j = 0; j < L; ++j) {\n            int pos = i * L /\
    \ 2 + j;\n            if (pos >= ret.size()) break;\n            ret[pos] += cs[i][j];\n\
    \        }\n    }\n    return ret;\n}\n#line 5 \"Verify/ConvolutionLarge.test.cpp\"\
    \n\nint main() {\n    constexpr int P = 998244353;\n    using Z = mint<P>;\n\n\
    \    int n, m;\n    std::cin >> n >> m;\n\n    std::vector<Z> a(n), b(m);\n\n\
    \    for (int i = 0; i < n; i++) std::cin >> a[i];\n    for (int i = 0; i < m;\
    \ i++) std::cin >> b[i];\n\n    auto ans = multiplyLarge(a, b);\n\n    for (int\
    \ i = 0; i < n + m - 1; i++) {\n        std::cout << ans[i] << \" \\n\"[i == n\
    \ + m - 2];\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_large\"\
    \n\n#include \"../ModInt/Modint32.hpp\"\n#include \"../Polynomial/NttLarge.hpp\"\
    \n\nint main() {\n    constexpr int P = 998244353;\n    using Z = mint<P>;\n\n\
    \    int n, m;\n    std::cin >> n >> m;\n\n    std::vector<Z> a(n), b(m);\n\n\
    \    for (int i = 0; i < n; i++) std::cin >> a[i];\n    for (int i = 0; i < m;\
    \ i++) std::cin >> b[i];\n\n    auto ans = multiplyLarge(a, b);\n\n    for (int\
    \ i = 0; i < n + m - 1; i++) {\n        std::cout << ans[i] << \" \\n\"[i == n\
    \ + m - 2];\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - ModInt/Modint32.hpp
  - Template/Template.hpp
  - Polynomial/NttLarge.hpp
  - Polynomial/Ntt.hpp
  - Template/Power.hpp
  isVerificationFile: true
  path: Verify/ConvolutionLarge.test.cpp
  requiredBy: []
  timestamp: '2023-04-12 01:12:26+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/ConvolutionLarge.test.cpp
layout: document
redirect_from:
- /verify/Verify/ConvolutionLarge.test.cpp
- /verify/Verify/ConvolutionLarge.test.cpp.html
title: Verify/ConvolutionLarge.test.cpp
---
