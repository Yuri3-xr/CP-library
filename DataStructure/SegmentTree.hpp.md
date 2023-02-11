---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/PointAddRangeSum.test.cpp
    title: Verify/PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/VertexAddPathSum.test.cpp
    title: Verify/VertexAddPathSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    using i64 = std::int64_t;\n#line 3 \"DataStructure/SegmentTree.hpp\"\n\ntemplate\
    \ <typename Info>\nstruct SegmentTree {\n    int N;\n    int size;\n    std::vector<Info>\
    \ seg;\n\n    SegmentTree(int _N) { init(_N); }\n\n    //[0,v.size)\n    SegmentTree(const\
    \ std::vector<Info> &v) {\n        init(v.size());\n        for (int i = 0; i\
    \ < (int)v.size(); i++) {\n            seg[i + size] = v[i];\n        }\n    \
    \    build();\n    }\n    void init(int _N) {\n        N = _N;\n        size =\
    \ 1;\n        while (size < N) size <<= 1;\n        seg.assign(2 * size, Info());\n\
    \    }\n    void set(int k, const Info &x) { seg[k + size] = x; }\n    void build()\
    \ {\n        for (int k = size - 1; k > 0; k--) {\n            seg[k] = seg[2\
    \ * k] + seg[2 * k + 1];\n        }\n    }\n    void update(int k, const Info\
    \ &x) {\n        k += size;\n        seg[k] = x;\n        while (k >>= 1) {\n\
    \            seg[k] = seg[2 * k] + seg[2 * k + 1];\n        }\n    }\n    void\
    \ add(int k, const Info &x) {\n        k += size;\n        seg[k] += x;\n    \
    \    while (k >>= 1) {\n            seg[k] = seg[2 * k] + seg[2 * k + 1];\n  \
    \      }\n    }\n    // query to [a, b)\n    Info query(int a, int b) {\n    \
    \    Info L = Info(), R = Info();\n        for (a += size, b += size; a < b; a\
    \ >>= 1, b >>= 1) {\n            if (a & 1) L = L + seg[a++];\n            if\
    \ (b & 1) R = seg[--b] + R;\n        }\n        return L + R;\n    }\n    Info\
    \ &operator[](const int &k) { return seg[k + size]; }\n};\n"
  code: "#pragma once\n#include \"../Template/Template.hpp\"\n\ntemplate <typename\
    \ Info>\nstruct SegmentTree {\n    int N;\n    int size;\n    std::vector<Info>\
    \ seg;\n\n    SegmentTree(int _N) { init(_N); }\n\n    //[0,v.size)\n    SegmentTree(const\
    \ std::vector<Info> &v) {\n        init(v.size());\n        for (int i = 0; i\
    \ < (int)v.size(); i++) {\n            seg[i + size] = v[i];\n        }\n    \
    \    build();\n    }\n    void init(int _N) {\n        N = _N;\n        size =\
    \ 1;\n        while (size < N) size <<= 1;\n        seg.assign(2 * size, Info());\n\
    \    }\n    void set(int k, const Info &x) { seg[k + size] = x; }\n    void build()\
    \ {\n        for (int k = size - 1; k > 0; k--) {\n            seg[k] = seg[2\
    \ * k] + seg[2 * k + 1];\n        }\n    }\n    void update(int k, const Info\
    \ &x) {\n        k += size;\n        seg[k] = x;\n        while (k >>= 1) {\n\
    \            seg[k] = seg[2 * k] + seg[2 * k + 1];\n        }\n    }\n    void\
    \ add(int k, const Info &x) {\n        k += size;\n        seg[k] += x;\n    \
    \    while (k >>= 1) {\n            seg[k] = seg[2 * k] + seg[2 * k + 1];\n  \
    \      }\n    }\n    // query to [a, b)\n    Info query(int a, int b) {\n    \
    \    Info L = Info(), R = Info();\n        for (a += size, b += size; a < b; a\
    \ >>= 1, b >>= 1) {\n            if (a & 1) L = L + seg[a++];\n            if\
    \ (b & 1) R = seg[--b] + R;\n        }\n        return L + R;\n    }\n    Info\
    \ &operator[](const int &k) { return seg[k + size]; }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/VertexAddPathSum.test.cpp
  - Verify/PointAddRangeSum.test.cpp
documentation_of: DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.hpp
- /library/DataStructure/SegmentTree.hpp.html
title: DataStructure/SegmentTree.hpp
---
