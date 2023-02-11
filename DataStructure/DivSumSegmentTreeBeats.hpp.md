---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_h
  bundledCode: "#line 2 \"DataStructure/DivSumSegmentTreeBeats.hpp\"\n\ntemplate <class\
    \ T>\nstruct DivSumSegmentTreeBeats {\n    /*\n        applyDiv(l,r,v) i \\in\
    \ [l,r) a_i = a_i/v (floor)\n        applyGive(l,r,v) i \\in [l,r) a_i = v (floor)\n\
    \        rangeQuery(l,r) [l,r) sum\n        Time Complexity: O(NKlogN) K = __LG(max(x))\n\
    \        Verify: https://atcoder.jp/contests/abc256/tasks/abc256_h\n    */\n \
    \   const int n;\n    std::vector<T> tmax, tmin, tag, tsum;\n    DivSumSegmentTreeBeats(int\
    \ n)\n        : n(n),\n          tmax(4 << std::__lg(n)),\n          tmin(4 <<\
    \ std::__lg(n)),\n          tag(4 << std::__lg(n), -1),\n          tsum(4 << std::__lg(n)){};\n\
    \    DivSumSegmentTreeBeats(const std::vector<T>& init)\n        : DivSumSegmentTreeBeats(init.size())\
    \ {\n        std::function<void(int, int, int)> build = [&](int p, int l, int\
    \ r) {\n            if (r - l == 1) {\n                tmax[p] = tmin[p] = tsum[p]\
    \ = init[l];\n                return;\n            }\n            int m = (l +\
    \ r) / 2;\n            build(2 * p, l, m);\n            build(2 * p + 1, m, r);\n\
    \            pull(p);\n        };\n        build(1, 0, n);\n    }\n    void pull(int\
    \ p) {\n        tmax[p] = max(tmax[p * 2], tmax[p * 2 + 1]);\n        tmin[p]\
    \ = min(tmin[p * 2], tmin[p * 2 + 1]);\n        tsum[p] = tsum[p * 2] + tsum[p\
    \ * 2 + 1];\n        return;\n    }\n    void apply(int l, int r, int p, T v)\
    \ {\n        if (v != -1) {\n            tmax[p] = tmin[p] = tag[p] = v;\n   \
    \         tsum[p] = T(r - l) * v;\n        }\n        return;\n    }\n    void\
    \ push(int l, int r, int p) {\n        if (tag[p] != -1) {\n            int mid\
    \ = (l + r) / 2;\n            apply(l, mid, p * 2, tag[p]);\n            apply(mid,\
    \ r, p * 2 + 1, tag[p]);\n            tag[p] = -1;\n        }\n        return;\n\
    \    }\n    void applyDiv(int p, int l, int r, int x, int y, const T v) {\n  \
    \      if (l >= y || r <= x) return;\n        if (l >= x && r <= y) {\n      \
    \      if (tmax[p] == tmin[p]) {\n                apply(l, r, p, tmax[p] / v);\n\
    \                return;\n            }\n        }\n        push(l, r, p);\n \
    \       int mid = (l + r) / 2;\n        applyDiv(p * 2, l, mid, x, y, v);\n  \
    \      applyDiv(p * 2 + 1, mid, r, x, y, v);\n        pull(p);\n    }\n    void\
    \ applyGive(int p, int l, int r, int x, int y, const T v) {\n        if (l >=\
    \ y || r <= x) return;\n        if (l >= x && r <= y) {\n            apply(l,\
    \ r, p, v);\n            return;\n        }\n        push(l, r, p);\n        int\
    \ mid = (l + r) / 2;\n        applyGive(p * 2, l, mid, x, y, v);\n        applyGive(p\
    \ * 2 + 1, mid, r, x, y, v);\n        pull(p);\n    }\n    void applyDiv(int l,\
    \ int r, const T v) { applyDiv(1, 0, n, l, r, v); }\n    void applyGive(int l,\
    \ int r, const T v) { applyGive(1, 0, n, l, r, v); }\n    T rangeQuery(int p,\
    \ int l, int r, int x, int y) {\n        if (l >= y || r <= x) {\n           \
    \ return T();\n        }\n        if (r - l > 1) push(l, r, p);\n        if (l\
    \ >= x && r <= y) {\n            return tsum[p];\n        }\n        int m = (l\
    \ + r) / 2;\n        T ans = 0;\n        ans = rangeQuery(2 * p, l, m, x, y) +\
    \ rangeQuery(2 * p + 1, m, r, x, y);\n        return ans;\n    }\n    T rangeQuery(int\
    \ l, int r) { return rangeQuery(1, 0, n, l, r); }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct DivSumSegmentTreeBeats {\n   \
    \ /*\n        applyDiv(l,r,v) i \\in [l,r) a_i = a_i/v (floor)\n        applyGive(l,r,v)\
    \ i \\in [l,r) a_i = v (floor)\n        rangeQuery(l,r) [l,r) sum\n        Time\
    \ Complexity: O(NKlogN) K = __LG(max(x))\n        Verify: https://atcoder.jp/contests/abc256/tasks/abc256_h\n\
    \    */\n    const int n;\n    std::vector<T> tmax, tmin, tag, tsum;\n    DivSumSegmentTreeBeats(int\
    \ n)\n        : n(n),\n          tmax(4 << std::__lg(n)),\n          tmin(4 <<\
    \ std::__lg(n)),\n          tag(4 << std::__lg(n), -1),\n          tsum(4 << std::__lg(n)){};\n\
    \    DivSumSegmentTreeBeats(const std::vector<T>& init)\n        : DivSumSegmentTreeBeats(init.size())\
    \ {\n        std::function<void(int, int, int)> build = [&](int p, int l, int\
    \ r) {\n            if (r - l == 1) {\n                tmax[p] = tmin[p] = tsum[p]\
    \ = init[l];\n                return;\n            }\n            int m = (l +\
    \ r) / 2;\n            build(2 * p, l, m);\n            build(2 * p + 1, m, r);\n\
    \            pull(p);\n        };\n        build(1, 0, n);\n    }\n    void pull(int\
    \ p) {\n        tmax[p] = max(tmax[p * 2], tmax[p * 2 + 1]);\n        tmin[p]\
    \ = min(tmin[p * 2], tmin[p * 2 + 1]);\n        tsum[p] = tsum[p * 2] + tsum[p\
    \ * 2 + 1];\n        return;\n    }\n    void apply(int l, int r, int p, T v)\
    \ {\n        if (v != -1) {\n            tmax[p] = tmin[p] = tag[p] = v;\n   \
    \         tsum[p] = T(r - l) * v;\n        }\n        return;\n    }\n    void\
    \ push(int l, int r, int p) {\n        if (tag[p] != -1) {\n            int mid\
    \ = (l + r) / 2;\n            apply(l, mid, p * 2, tag[p]);\n            apply(mid,\
    \ r, p * 2 + 1, tag[p]);\n            tag[p] = -1;\n        }\n        return;\n\
    \    }\n    void applyDiv(int p, int l, int r, int x, int y, const T v) {\n  \
    \      if (l >= y || r <= x) return;\n        if (l >= x && r <= y) {\n      \
    \      if (tmax[p] == tmin[p]) {\n                apply(l, r, p, tmax[p] / v);\n\
    \                return;\n            }\n        }\n        push(l, r, p);\n \
    \       int mid = (l + r) / 2;\n        applyDiv(p * 2, l, mid, x, y, v);\n  \
    \      applyDiv(p * 2 + 1, mid, r, x, y, v);\n        pull(p);\n    }\n    void\
    \ applyGive(int p, int l, int r, int x, int y, const T v) {\n        if (l >=\
    \ y || r <= x) return;\n        if (l >= x && r <= y) {\n            apply(l,\
    \ r, p, v);\n            return;\n        }\n        push(l, r, p);\n        int\
    \ mid = (l + r) / 2;\n        applyGive(p * 2, l, mid, x, y, v);\n        applyGive(p\
    \ * 2 + 1, mid, r, x, y, v);\n        pull(p);\n    }\n    void applyDiv(int l,\
    \ int r, const T v) { applyDiv(1, 0, n, l, r, v); }\n    void applyGive(int l,\
    \ int r, const T v) { applyGive(1, 0, n, l, r, v); }\n    T rangeQuery(int p,\
    \ int l, int r, int x, int y) {\n        if (l >= y || r <= x) {\n           \
    \ return T();\n        }\n        if (r - l > 1) push(l, r, p);\n        if (l\
    \ >= x && r <= y) {\n            return tsum[p];\n        }\n        int m = (l\
    \ + r) / 2;\n        T ans = 0;\n        ans = rangeQuery(2 * p, l, m, x, y) +\
    \ rangeQuery(2 * p + 1, m, r, x, y);\n        return ans;\n    }\n    T rangeQuery(int\
    \ l, int r) { return rangeQuery(1, 0, n, l, r); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DivSumSegmentTreeBeats.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:25:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DivSumSegmentTreeBeats.hpp
layout: document
redirect_from:
- /library/DataStructure/DivSumSegmentTreeBeats.hpp
- /library/DataStructure/DivSumSegmentTreeBeats.hpp.html
title: DataStructure/DivSumSegmentTreeBeats.hpp
---
