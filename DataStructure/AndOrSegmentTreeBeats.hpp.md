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
    links:
    - https://csacademy.com/contest/archive/task/and-or-max
  bundledCode: "#line 2 \"DataStructure/AndOrSegmentTreeBeats.hpp\"\n\n#line 2 \"\
    Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n\
    #line 4 \"DataStructure/AndOrSegmentTreeBeats.hpp\"\n\ntemplate <class T>\nstruct\
    \ AndOrSegmentTreeBeats {\n    /*\n        applyAnd(l,r,v) \\forall x \\in [l,r)\
    \ x = x&v\n        applyOr(l,r,v) \\forall x \\in [l,r) x = x|v\n        rangeQuery(l,r)\
    \  max element  [l,r)\n        Time Complexity: O(NKlogN) K = __LG(max(x))\n \
    \       Verify: https://csacademy.com/contest/archive/task/and-or-max\n    */\n\
    \    const int n;\n    std::vector<T> tor, tand, tag, mx;\n    AndOrSegmentTreeBeats(int\
    \ n)\n        : n(n),\n          tor(4 << std::__lg(n)),\n          tand(4 <<\
    \ std::__lg(n)),\n          tag(4 << std::__lg(n)),\n          mx(4 << std::__lg(n)){};\n\
    \    AndOrSegmentTreeBeats(const std::vector<T>& init)\n        : AndOrSegmentTreeBeats(init.size())\
    \ {\n        std::function<void(int, int, int)> build = [&](int p, int l, int\
    \ r) {\n            if (r - l == 1) {\n                tor[p] = tand[p] = mx[p]\
    \ = init[l];\n                return;\n            }\n            int m = (l +\
    \ r) / 2;\n            build(2 * p, l, m);\n            build(2 * p + 1, m, r);\n\
    \            pull(p);\n        };\n        build(1, 0, n);\n    }\n    void pull(int\
    \ p) {\n        tand[p] = tand[p * 2] & tand[p * 2 + 1];\n        tor[p] = tor[p\
    \ * 2] | tor[p * 2 + 1];\n        mx[p] = max(mx[p * 2], mx[p * 2 + 1]);\n   \
    \     return;\n    }\n    void apply(int p, T v) {\n        tag[p] += v;\n   \
    \     tand[p] += v;\n        tor[p] += v;\n        mx[p] += v;\n        return;\n\
    \    }\n    void push(int p) {\n        apply(p * 2, tag[p]);\n        apply(p\
    \ * 2 + 1, tag[p]);\n        tag[p] = 0;\n        return;\n    }\n\n    void applyAnd(int\
    \ p, int l, int r, int x, int y, const T v) {\n        if (l >= y || r <= x) {\n\
    \            return;\n        }\n        if (r - l > 1) push(p);\n        if ((tor[p]\
    \ & v) == tor[p]) return;\n        if (l >= x && r <= y) {\n            if (((tand[p]\
    \ & v) - tand[p]) == ((tor[p] & v) - tor[p])) {\n                apply(p, ((tand[p]\
    \ & v) - tand[p]));\n                return;\n            }\n        }\n     \
    \   int mid = (l + r) / 2;\n        applyAnd(p * 2, l, mid, x, y, v);\n      \
    \  applyAnd(p * 2 + 1, mid, r, x, y, v);\n        pull(p);\n    }\n    void applyOr(int\
    \ p, int l, int r, int x, int y, const T v) {\n        if (l >= y || r <= x) {\n\
    \            return;\n        }\n        if (r - l > 1) push(p);\n        if ((tand[p]\
    \ | v) == tand[p]) return;\n        if (l >= x && r <= y) {\n            if (((tand[p]\
    \ | v) - tand[p]) == ((tor[p] | v) - tor[p])) {\n                apply(p, ((tand[p]\
    \ | v) - tand[p]));\n                return;\n            }\n        }\n     \
    \   int mid = (l + r) / 2;\n        applyOr(p * 2, l, mid, x, y, v);\n       \
    \ applyOr(p * 2 + 1, mid, r, x, y, v);\n        pull(p);\n    }\n    void applyOr(int\
    \ l, int r, const T v) { applyOr(1, 0, n, l, r, v); }\n    void applyAnd(int l,\
    \ int r, const T v) { applyAnd(1, 0, n, l, r, v); }\n    T rangeQuery(int p, int\
    \ l, int r, int x, int y) {\n        if (l >= y || r <= x) {\n            return\
    \ T();\n        }\n        if (r - l > 1) push(p);\n        if (l >= x && r <=\
    \ y) {\n            return mx[p];\n        }\n        int m = (l + r) / 2;\n \
    \       return max(rangeQuery(2 * p, l, m, x, y),\n                   rangeQuery(2\
    \ * p + 1, m, r, x, y));\n    }\n    T rangeQuery(int l, int r) { return rangeQuery(1,\
    \ 0, n, l, r); }\n};\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\n\ntemplate <class\
    \ T>\nstruct AndOrSegmentTreeBeats {\n    /*\n        applyAnd(l,r,v) \\forall\
    \ x \\in [l,r) x = x&v\n        applyOr(l,r,v) \\forall x \\in [l,r) x = x|v\n\
    \        rangeQuery(l,r)  max element  [l,r)\n        Time Complexity: O(NKlogN)\
    \ K = __LG(max(x))\n        Verify: https://csacademy.com/contest/archive/task/and-or-max\n\
    \    */\n    const int n;\n    std::vector<T> tor, tand, tag, mx;\n    AndOrSegmentTreeBeats(int\
    \ n)\n        : n(n),\n          tor(4 << std::__lg(n)),\n          tand(4 <<\
    \ std::__lg(n)),\n          tag(4 << std::__lg(n)),\n          mx(4 << std::__lg(n)){};\n\
    \    AndOrSegmentTreeBeats(const std::vector<T>& init)\n        : AndOrSegmentTreeBeats(init.size())\
    \ {\n        std::function<void(int, int, int)> build = [&](int p, int l, int\
    \ r) {\n            if (r - l == 1) {\n                tor[p] = tand[p] = mx[p]\
    \ = init[l];\n                return;\n            }\n            int m = (l +\
    \ r) / 2;\n            build(2 * p, l, m);\n            build(2 * p + 1, m, r);\n\
    \            pull(p);\n        };\n        build(1, 0, n);\n    }\n    void pull(int\
    \ p) {\n        tand[p] = tand[p * 2] & tand[p * 2 + 1];\n        tor[p] = tor[p\
    \ * 2] | tor[p * 2 + 1];\n        mx[p] = max(mx[p * 2], mx[p * 2 + 1]);\n   \
    \     return;\n    }\n    void apply(int p, T v) {\n        tag[p] += v;\n   \
    \     tand[p] += v;\n        tor[p] += v;\n        mx[p] += v;\n        return;\n\
    \    }\n    void push(int p) {\n        apply(p * 2, tag[p]);\n        apply(p\
    \ * 2 + 1, tag[p]);\n        tag[p] = 0;\n        return;\n    }\n\n    void applyAnd(int\
    \ p, int l, int r, int x, int y, const T v) {\n        if (l >= y || r <= x) {\n\
    \            return;\n        }\n        if (r - l > 1) push(p);\n        if ((tor[p]\
    \ & v) == tor[p]) return;\n        if (l >= x && r <= y) {\n            if (((tand[p]\
    \ & v) - tand[p]) == ((tor[p] & v) - tor[p])) {\n                apply(p, ((tand[p]\
    \ & v) - tand[p]));\n                return;\n            }\n        }\n     \
    \   int mid = (l + r) / 2;\n        applyAnd(p * 2, l, mid, x, y, v);\n      \
    \  applyAnd(p * 2 + 1, mid, r, x, y, v);\n        pull(p);\n    }\n    void applyOr(int\
    \ p, int l, int r, int x, int y, const T v) {\n        if (l >= y || r <= x) {\n\
    \            return;\n        }\n        if (r - l > 1) push(p);\n        if ((tand[p]\
    \ | v) == tand[p]) return;\n        if (l >= x && r <= y) {\n            if (((tand[p]\
    \ | v) - tand[p]) == ((tor[p] | v) - tor[p])) {\n                apply(p, ((tand[p]\
    \ | v) - tand[p]));\n                return;\n            }\n        }\n     \
    \   int mid = (l + r) / 2;\n        applyOr(p * 2, l, mid, x, y, v);\n       \
    \ applyOr(p * 2 + 1, mid, r, x, y, v);\n        pull(p);\n    }\n    void applyOr(int\
    \ l, int r, const T v) { applyOr(1, 0, n, l, r, v); }\n    void applyAnd(int l,\
    \ int r, const T v) { applyAnd(1, 0, n, l, r, v); }\n    T rangeQuery(int p, int\
    \ l, int r, int x, int y) {\n        if (l >= y || r <= x) {\n            return\
    \ T();\n        }\n        if (r - l > 1) push(p);\n        if (l >= x && r <=\
    \ y) {\n            return mx[p];\n        }\n        int m = (l + r) / 2;\n \
    \       return max(rangeQuery(2 * p, l, m, x, y),\n                   rangeQuery(2\
    \ * p + 1, m, r, x, y));\n    }\n    T rangeQuery(int l, int r) { return rangeQuery(1,\
    \ 0, n, l, r); }\n};\n"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: DataStructure/AndOrSegmentTreeBeats.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/AndOrSegmentTreeBeats.hpp
layout: document
redirect_from:
- /library/DataStructure/AndOrSegmentTreeBeats.hpp
- /library/DataStructure/AndOrSegmentTreeBeats.hpp.html
title: DataStructure/AndOrSegmentTreeBeats.hpp
---
