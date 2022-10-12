---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/PointAddRangeSum.test.cpp
    title: Verify/PointAddRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include\
    \ <bits/stdc++.h>\n\nusing i64 = long long;\nusing VI = vector<int>;\nusing pii\
    \ = pair<int, int>;\n#line 3 \"DataStructure/SegmentTree.hpp\"\n\ntemplate <class\
    \ Info>\nstruct SegmentTree {\n    /*\n    Info: operator +\n    all operations\
    \ obey [l,r)\n    */\n    const int n;\n    vector<Info> info;\n    SegmentTree(int\
    \ n) : n(n), info(4 << __lg(n)) {}\n    SegmentTree(vector<Info> init) : SegmentTree(init.size())\
    \ {\n        function<void(int, int, int)> build = [&](int p, int l, int r) {\n\
    \            if (r - l == 1) {\n                info[p] = init[l];\n         \
    \       return;\n            }\n            int m = (l + r) / 2;\n           \
    \ build(2 * p, l, m);\n            build(2 * p + 1, m, r);\n            pull(p);\n\
    \        };\n        build(1, 0, n);\n    }\n    void pull(int p) { info[p] =\
    \ info[2 * p] + info[2 * p + 1]; }\n    void modify(int p, int l, int r, int x,\
    \ const Info &v) {\n        if (r - l == 1) {\n            info[p] = v;\n    \
    \        return;\n        }\n        int m = (l + r) / 2;\n        if (x < m)\
    \ {\n            modify(2 * p, l, m, x, v);\n        } else {\n            modify(2\
    \ * p + 1, m, r, x, v);\n        }\n        pull(p);\n    }\n    void modify(int\
    \ p, const Info &v) { modify(1, 0, n, p, v); }\n    Info rangeQuery(int p, int\
    \ l, int r, int x, int y) {\n        if (l >= y || r <= x) {\n            return\
    \ Info();\n        }\n        if (l >= x && r <= y) {\n            return info[p];\n\
    \        }\n        int m = (l + r) / 2;\n        return rangeQuery(2 * p, l,\
    \ m, x, y) +\n               rangeQuery(2 * p + 1, m, r, x, y);\n    }\n    Info\
    \ rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }\n};\n"
  code: "#pragma once\n#include \"../Template/Template.hpp\"\n\ntemplate <class Info>\n\
    struct SegmentTree {\n    /*\n    Info: operator +\n    all operations obey [l,r)\n\
    \    */\n    const int n;\n    vector<Info> info;\n    SegmentTree(int n) : n(n),\
    \ info(4 << __lg(n)) {}\n    SegmentTree(vector<Info> init) : SegmentTree(init.size())\
    \ {\n        function<void(int, int, int)> build = [&](int p, int l, int r) {\n\
    \            if (r - l == 1) {\n                info[p] = init[l];\n         \
    \       return;\n            }\n            int m = (l + r) / 2;\n           \
    \ build(2 * p, l, m);\n            build(2 * p + 1, m, r);\n            pull(p);\n\
    \        };\n        build(1, 0, n);\n    }\n    void pull(int p) { info[p] =\
    \ info[2 * p] + info[2 * p + 1]; }\n    void modify(int p, int l, int r, int x,\
    \ const Info &v) {\n        if (r - l == 1) {\n            info[p] = v;\n    \
    \        return;\n        }\n        int m = (l + r) / 2;\n        if (x < m)\
    \ {\n            modify(2 * p, l, m, x, v);\n        } else {\n            modify(2\
    \ * p + 1, m, r, x, v);\n        }\n        pull(p);\n    }\n    void modify(int\
    \ p, const Info &v) { modify(1, 0, n, p, v); }\n    Info rangeQuery(int p, int\
    \ l, int r, int x, int y) {\n        if (l >= y || r <= x) {\n            return\
    \ Info();\n        }\n        if (l >= x && r <= y) {\n            return info[p];\n\
    \        }\n        int m = (l + r) / 2;\n        return rangeQuery(2 * p, l,\
    \ m, x, y) +\n               rangeQuery(2 * p + 1, m, r, x, y);\n    }\n    Info\
    \ rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }\n};\n"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: DataStructure/SegmentTree.hpp
  requiredBy: []
  timestamp: '2022-09-27 01:20:16+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/PointAddRangeSum.test.cpp
documentation_of: DataStructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.hpp
- /library/DataStructure/SegmentTree.hpp.html
title: DataStructure/SegmentTree.hpp
---
