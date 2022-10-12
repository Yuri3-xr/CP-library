---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/RangeAffineRangeSum.test.cpp
    title: Verify/RangeAffineRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include\
    \ <bits/stdc++.h>\n\nusing i64 = long long;\nusing VI = vector<int>;\nusing pii\
    \ = pair<int, int>;\n#line 3 \"DataStructure/LazySegmentTree.hpp\"\ntemplate <class\
    \ Info, class Tag>\nstruct LazySegmentTree {\n    /*\n        Info: apply,operator\
    \ +\n        Tag: apply\n        all operations obey [l,r)\n    */\n    const\
    \ int n;\n    vector<Info> info;\n    vector<Tag> tag;\n    LazySegmentTree(int\
    \ n) : n(n), info(4 << __lg(n)), tag(4 << __lg(n)) {}\n    LazySegmentTree(vector<Info>\
    \ init) : LazySegmentTree(init.size()) {\n        function<void(int, int, int)>\
    \ build = [&](int p, int l, int r) {\n            if (r - l == 1) {\n        \
    \        info[p] = init[l];\n                return;\n            }\n        \
    \    int m = (l + r) / 2;\n            build(2 * p, l, m);\n            build(2\
    \ * p + 1, m, r);\n            pull(p);\n        };\n        build(1, 0, n);\n\
    \    }\n    void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }\n  \
    \  void apply(int p, const Tag &v) {\n        info[p].apply(v);\n        tag[p].apply(v);\n\
    \    }\n    void push(int p) {\n        apply(2 * p, tag[p]);\n        apply(2\
    \ * p + 1, tag[p]);\n        tag[p] = Tag();\n    }\n    void modify(int p, int\
    \ l, int r, int x, const Info &v) {\n        if (r - l == 1) {\n            info[p]\
    \ = v;\n            return;\n        }\n        int m = (l + r) / 2;\n       \
    \ push(p);\n        if (x < m) {\n            modify(2 * p, l, m, x, v);\n   \
    \     } else {\n            modify(2 * p + 1, m, r, x, v);\n        }\n      \
    \  pull(p);\n    }\n    void modify(int p, const Info &v) { modify(1, 0, n, p,\
    \ v); }\n    Info rangeQuery(int p, int l, int r, int x, int y) {\n        if\
    \ (l >= y || r <= x) {\n            return Info();\n        }\n        if (l >=\
    \ x && r <= y) {\n            return info[p];\n        }\n        int m = (l +\
    \ r) / 2;\n        push(p);\n        return rangeQuery(2 * p, l, m, x, y) +\n\
    \               rangeQuery(2 * p + 1, m, r, x, y);\n    }\n    Info rangeQuery(int\
    \ l, int r) { return rangeQuery(1, 0, n, l, r); }\n    void rangeApply(int p,\
    \ int l, int r, int x, int y, const Tag &v) {\n        if (l >= y || r <= x) {\n\
    \            return;\n        }\n        if (l >= x && r <= y) {\n           \
    \ apply(p, v);\n            return;\n        }\n        int m = (l + r) / 2;\n\
    \        push(p);\n        rangeApply(2 * p, l, m, x, y, v);\n        rangeApply(2\
    \ * p + 1, m, r, x, y, v);\n        pull(p);\n    }\n    void rangeApply(int l,\
    \ int r, const Tag &v) {\n        return rangeApply(1, 0, n, l, r, v);\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../Template/Template.hpp\"\ntemplate <class Info,\
    \ class Tag>\nstruct LazySegmentTree {\n    /*\n        Info: apply,operator +\n\
    \        Tag: apply\n        all operations obey [l,r)\n    */\n    const int\
    \ n;\n    vector<Info> info;\n    vector<Tag> tag;\n    LazySegmentTree(int n)\
    \ : n(n), info(4 << __lg(n)), tag(4 << __lg(n)) {}\n    LazySegmentTree(vector<Info>\
    \ init) : LazySegmentTree(init.size()) {\n        function<void(int, int, int)>\
    \ build = [&](int p, int l, int r) {\n            if (r - l == 1) {\n        \
    \        info[p] = init[l];\n                return;\n            }\n        \
    \    int m = (l + r) / 2;\n            build(2 * p, l, m);\n            build(2\
    \ * p + 1, m, r);\n            pull(p);\n        };\n        build(1, 0, n);\n\
    \    }\n    void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }\n  \
    \  void apply(int p, const Tag &v) {\n        info[p].apply(v);\n        tag[p].apply(v);\n\
    \    }\n    void push(int p) {\n        apply(2 * p, tag[p]);\n        apply(2\
    \ * p + 1, tag[p]);\n        tag[p] = Tag();\n    }\n    void modify(int p, int\
    \ l, int r, int x, const Info &v) {\n        if (r - l == 1) {\n            info[p]\
    \ = v;\n            return;\n        }\n        int m = (l + r) / 2;\n       \
    \ push(p);\n        if (x < m) {\n            modify(2 * p, l, m, x, v);\n   \
    \     } else {\n            modify(2 * p + 1, m, r, x, v);\n        }\n      \
    \  pull(p);\n    }\n    void modify(int p, const Info &v) { modify(1, 0, n, p,\
    \ v); }\n    Info rangeQuery(int p, int l, int r, int x, int y) {\n        if\
    \ (l >= y || r <= x) {\n            return Info();\n        }\n        if (l >=\
    \ x && r <= y) {\n            return info[p];\n        }\n        int m = (l +\
    \ r) / 2;\n        push(p);\n        return rangeQuery(2 * p, l, m, x, y) +\n\
    \               rangeQuery(2 * p + 1, m, r, x, y);\n    }\n    Info rangeQuery(int\
    \ l, int r) { return rangeQuery(1, 0, n, l, r); }\n    void rangeApply(int p,\
    \ int l, int r, int x, int y, const Tag &v) {\n        if (l >= y || r <= x) {\n\
    \            return;\n        }\n        if (l >= x && r <= y) {\n           \
    \ apply(p, v);\n            return;\n        }\n        int m = (l + r) / 2;\n\
    \        push(p);\n        rangeApply(2 * p, l, m, x, y, v);\n        rangeApply(2\
    \ * p + 1, m, r, x, y, v);\n        pull(p);\n    }\n    void rangeApply(int l,\
    \ int r, const Tag &v) {\n        return rangeApply(1, 0, n, l, r, v);\n    }\n\
    };\n"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: DataStructure/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2022-09-14 16:58:56+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/RangeAffineRangeSum.test.cpp
documentation_of: DataStructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/DataStructure/LazySegmentTree.hpp
- /library/DataStructure/LazySegmentTree.hpp.html
title: DataStructure/LazySegmentTree.hpp
---
