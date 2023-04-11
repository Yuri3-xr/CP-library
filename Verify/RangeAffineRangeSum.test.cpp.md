---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.hpp
    title: DataStructure/LazySegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: ModInt/Modint32.hpp
    title: ModInt/Modint32.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"Verify/RangeAffineRangeSum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 3 \"DataStructure/LazySegmentTree.hpp\"\
    \ntemplate <class Info, class Tag>\nstruct LazySegmentTree {\n    /*\n       \
    \ Info: apply,operator +\n        Tag: apply\n        all operations obey [l,r)\n\
    \    */\n    const int n;\n    std::vector<Info> info;\n    std::vector<Tag> tag;\n\
    \    LazySegmentTree(int n)\n        : n(n), info(4 << std::__lg(n)), tag(4 <<\
    \ std::__lg(n)) {}\n    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size())\
    \ {\n        std::function<void(int, int, int)> build = [&](int p, int l, int\
    \ r) {\n            if (r - l == 1) {\n                info[p] = init[l];\n  \
    \              return;\n            }\n            int m = (l + r) / 2;\n    \
    \        build(2 * p, l, m);\n            build(2 * p + 1, m, r);\n          \
    \  pull(p);\n        };\n        build(1, 0, n);\n    }\n    void pull(int p)\
    \ { info[p] = info[2 * p] + info[2 * p + 1]; }\n    void apply(int p, const Tag\
    \ &v) {\n        info[p].apply(v);\n        tag[p].apply(v);\n    }\n    void\
    \ push(int p) {\n        apply(2 * p, tag[p]);\n        apply(2 * p + 1, tag[p]);\n\
    \        tag[p] = Tag();\n    }\n    void modify(int p, int l, int r, int x, const\
    \ Info &v) {\n        if (r - l == 1) {\n            info[p] = v;\n          \
    \  return;\n        }\n        int m = (l + r) / 2;\n        push(p);\n      \
    \  if (x < m) {\n            modify(2 * p, l, m, x, v);\n        } else {\n  \
    \          modify(2 * p + 1, m, r, x, v);\n        }\n        pull(p);\n    }\n\
    \    void modify(int p, const Info &v) { modify(1, 0, n, p, v); }\n    Info rangeQuery(int\
    \ p, int l, int r, int x, int y) {\n        if (l >= y || r <= x) {\n        \
    \    return Info();\n        }\n        if (l >= x && r <= y) {\n            return\
    \ info[p];\n        }\n        int m = (l + r) / 2;\n        push(p);\n      \
    \  return rangeQuery(2 * p, l, m, x, y) +\n               rangeQuery(2 * p + 1,\
    \ m, r, x, y);\n    }\n    Info rangeQuery(int l, int r) { return rangeQuery(1,\
    \ 0, n, l, r); }\n    void rangeApply(int p, int l, int r, int x, int y, const\
    \ Tag &v) {\n        if (l >= y || r <= x) {\n            return;\n        }\n\
    \        if (l >= x && r <= y) {\n            apply(p, v);\n            return;\n\
    \        }\n        int m = (l + r) / 2;\n        push(p);\n        rangeApply(2\
    \ * p, l, m, x, y, v);\n        rangeApply(2 * p + 1, m, r, x, y, v);\n      \
    \  pull(p);\n    }\n    void rangeApply(int l, int r, const Tag &v) {\n      \
    \  return rangeApply(1, 0, n, l, r, v);\n    }\n};\n#line 2 \"ModInt/Modint32.hpp\"\
    \n\n#line 4 \"ModInt/Modint32.hpp\"\n\ntemplate <int mod>\nstruct mint {\n   \
    \ int x;\n    mint() : x(0) {}\n    mint(int64_t y) : x(y >= 0 ? y % mod : (mod\
    \ - (-y) % mod) % mod) {}\n    mint &operator+=(const mint &p) {\n        if ((x\
    \ += p.x) >= mod) x -= mod;\n        return *this;\n    }\n    mint &operator-=(const\
    \ mint &p) {\n        if ((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n    mint &operator*=(const mint &p) {\n        x = (int)(1LL * x * p.x\
    \ % mod);\n        return *this;\n    }\n    mint &operator/=(const mint &p) {\n\
    \        *this *= p.inverse();\n        return *this;\n    }\n    mint operator-()\
    \ const { return mint(-x); }\n    mint operator+(const mint &p) const { return\
    \ mint(*this) += p; }\n    mint operator-(const mint &p) const { return mint(*this)\
    \ -= p; }\n    mint operator*(const mint &p) const { return mint(*this) *= p;\
    \ }\n    mint operator/(const mint &p) const { return mint(*this) /= p; }\n  \
    \  bool operator==(const mint &p) const { return x == p.x; }\n    bool operator!=(const\
    \ mint &p) const { return x != p.x; }\n    mint inverse() const {\n        int\
    \ a = x, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t = a\
    \ / b;\n            std::swap(a -= t * b, b);\n            std::swap(u -= t *\
    \ v, v);\n        }\n        return mint(u);\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const mint &p) {\n        return os << p.x;\n    }\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &a) {\n        int64_t t;\n        is >>\
    \ t;\n        a = mint<mod>(t);\n        return (is);\n    }\n    int get() const\
    \ { return x; }\n    static constexpr int get_mod() { return mod; }\n};\n#line\
    \ 6 \"Verify/RangeAffineRangeSum.test.cpp\"\n\nconstexpr int mod = 998244353;\n\
    using Z = mint<mod>;\nstruct Tag {\n    Z x = 1;\n    Z y = 0;\n    void apply(const\
    \ Tag& a) {\n        x = x * a.x;\n        y = a.x * y + a.y;\n    }\n};\nstruct\
    \ Info {\n    Z x = 0;\n    int l, r;\n    void apply(const Tag& a) {\n      \
    \  x *= a.x;\n        x += Z(r - l) * a.y;\n    }\n};\nInfo operator+(const Info&\
    \ a, const Info& b) { return {a.x + b.x, a.l, b.r}; }\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<Info>\
    \ a(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> a[i].x;\n    \
    \    a[i].l = i;\n        a[i].r = i + 1;\n    }\n\n    LazySegmentTree<Info,\
    \ Tag> t(a);\n\n    for (int i = 1; i <= q; i++) {\n        int op;\n        std::cin\
    \ >> op;\n        if (op == 0) {\n            int l, r, b, c;\n            std::cin\
    \ >> l >> r >> b >> c;\n            t.rangeApply(l, r, Tag{b, c});\n        }\n\
    \        if (op == 1) {\n            int l, r;\n            std::cin >> l >> r;\n\
    \            auto ans = t.rangeQuery(l, r);\n            std::cout << ans.x <<\
    \ '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../DataStructure/LazySegmentTree.hpp\"\n#include \"../ModInt/Modint32.hpp\"\
    \n#include \"../Template/Template.hpp\"\n\nconstexpr int mod = 998244353;\nusing\
    \ Z = mint<mod>;\nstruct Tag {\n    Z x = 1;\n    Z y = 0;\n    void apply(const\
    \ Tag& a) {\n        x = x * a.x;\n        y = a.x * y + a.y;\n    }\n};\nstruct\
    \ Info {\n    Z x = 0;\n    int l, r;\n    void apply(const Tag& a) {\n      \
    \  x *= a.x;\n        x += Z(r - l) * a.y;\n    }\n};\nInfo operator+(const Info&\
    \ a, const Info& b) { return {a.x + b.x, a.l, b.r}; }\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<Info>\
    \ a(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> a[i].x;\n    \
    \    a[i].l = i;\n        a[i].r = i + 1;\n    }\n\n    LazySegmentTree<Info,\
    \ Tag> t(a);\n\n    for (int i = 1; i <= q; i++) {\n        int op;\n        std::cin\
    \ >> op;\n        if (op == 0) {\n            int l, r, b, c;\n            std::cin\
    \ >> l >> r >> b >> c;\n            t.rangeApply(l, r, Tag{b, c});\n        }\n\
    \        if (op == 1) {\n            int l, r;\n            std::cin >> l >> r;\n\
    \            auto ans = t.rangeQuery(l, r);\n            std::cout << ans.x <<\
    \ '\\n';\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - DataStructure/LazySegmentTree.hpp
  - Template/Template.hpp
  - ModInt/Modint32.hpp
  isVerificationFile: true
  path: Verify/RangeAffineRangeSum.test.cpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/RangeAffineRangeSum.test.cpp
layout: document
redirect_from:
- /verify/Verify/RangeAffineRangeSum.test.cpp
- /verify/Verify/RangeAffineRangeSum.test.cpp.html
title: Verify/RangeAffineRangeSum.test.cpp
---
