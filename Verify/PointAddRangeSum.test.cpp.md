---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: DataStructure/SegmentTree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"Verify/PointAddRangeSum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\
    \nusing i64 = long long;\nusing VI = vector<int>;\nusing pii = pair<int, int>;\n\
    #line 3 \"DataStructure/SegmentTree.hpp\"\n\ntemplate <class Info>\nstruct SegmentTree\
    \ {\n    /*\n    Info: operator +\n    all operations obey [l,r)\n    */\n   \
    \ const int n;\n    vector<Info> info;\n    SegmentTree(int n) : n(n), info(4\
    \ << __lg(n)) {}\n    SegmentTree(vector<Info> init) : SegmentTree(init.size())\
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
    \ rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }\n};\n#line 5\
    \ \"Verify/PointAddRangeSum.test.cpp\"\n\nstruct Info {\n    i64 x = 0;\n};\n\
    Info operator+(const Info& a, const Info& b) { return {a.x + b.x}; }\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n, q;\n\
    \    cin >> n >> q;\n    vector<Info> a(n);\n    for (auto&& it : a) cin >> it.x;\n\
    \    SegmentTree<Info> St(a);\n\n    while (q--) {\n        int op;\n        cin\
    \ >> op;\n        if (op == 0) {\n            int p, x;\n            cin >> p\
    \ >> x;\n            St.modify(p, {St.rangeQuery(p, p + 1).x + x});\n        }\
    \ else {\n            int l, r;\n            cin >> l >> r;\n            cout\
    \ << St.rangeQuery(l, r).x << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../DataStructure/SegmentTree.hpp\"\n#include \"../Template/Template.hpp\"\
    \n\nstruct Info {\n    i64 x = 0;\n};\nInfo operator+(const Info& a, const Info&\
    \ b) { return {a.x + b.x}; }\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, q;\n    cin >> n >> q;\n    vector<Info>\
    \ a(n);\n    for (auto&& it : a) cin >> it.x;\n    SegmentTree<Info> St(a);\n\n\
    \    while (q--) {\n        int op;\n        cin >> op;\n        if (op == 0)\
    \ {\n            int p, x;\n            cin >> p >> x;\n            St.modify(p,\
    \ {St.rangeQuery(p, p + 1).x + x});\n        } else {\n            int l, r;\n\
    \            cin >> l >> r;\n            cout << St.rangeQuery(l, r).x << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - DataStructure/SegmentTree.hpp
  - Template/Template.hpp
  isVerificationFile: true
  path: Verify/PointAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 01:20:16+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/PointAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/Verify/PointAddRangeSum.test.cpp
- /verify/Verify/PointAddRangeSum.test.cpp.html
title: Verify/PointAddRangeSum.test.cpp
---
