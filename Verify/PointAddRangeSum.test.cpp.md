---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: DataStructure/SegmentTree.hpp
  - icon: ':question:'
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
    #line 3 \"DataStructure/SegmentTree.hpp\"\n\ntemplate <typename Info>\nstruct\
    \ SegmentTree {\n    int N;\n    int size;\n    vector<Info> seg;\n\n    SegmentTree(int\
    \ _N) { init(_N); }\n\n    //[0,v.size)\n    SegmentTree(const vector<Info> &v)\
    \ {\n        init(v.size());\n        for (int i = 0; i < (int)v.size(); i++)\
    \ {\n            seg[i + size] = v[i];\n        }\n        build();\n    }\n \
    \   void init(int _N) {\n        N = _N;\n        size = 1;\n        while (size\
    \ < N) size <<= 1;\n        seg.assign(2 * size, Info());\n    }\n    void set(int\
    \ k, const Info &x) { seg[k + size] = x; }\n    void build() {\n        for (int\
    \ k = size - 1; k > 0; k--) {\n            seg[k] = seg[2 * k] + seg[2 * k + 1];\n\
    \        }\n    }\n    void update(int k, const Info &x) {\n        k += size;\n\
    \        seg[k] = x;\n        while (k >>= 1) {\n            seg[k] = seg[2 *\
    \ k] + seg[2 * k + 1];\n        }\n    }\n    void add(int k, const Info &x) {\n\
    \        k += size;\n        seg[k] += x;\n        while (k >>= 1) {\n       \
    \     seg[k] = seg[2 * k] + seg[2 * k + 1];\n        }\n    }\n    // query to\
    \ [a, b)\n    Info query(int a, int b) {\n        Info L = Info(), R = Info();\n\
    \        for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n            if\
    \ (a & 1) L = L + seg[a++];\n            if (b & 1) R = seg[--b] + R;\n      \
    \  }\n        return L + R;\n    }\n    Info &operator[](const int &k) { return\
    \ seg[k + size]; }\n};\n#line 5 \"Verify/PointAddRangeSum.test.cpp\"\n\nstruct\
    \ Info {\n    i64 x = 0;\n};\nInfo operator+(const Info& a, const Info& b) { return\
    \ {a.x + b.x}; }\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n, q;\n    cin >> n >> q;\n    vector<Info> a(n);\n    for (auto&& it\
    \ : a) cin >> it.x;\n    SegmentTree<Info> st(a);\n\n    while (q--) {\n     \
    \   int op;\n        cin >> op;\n        if (op == 0) {\n            int p, x;\n\
    \            cin >> p >> x;\n            st.update(p, {st[p].x + x});\n      \
    \  } else {\n            int l, r;\n            cin >> l >> r;\n            cout\
    \ << st.query(l, r).x << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../DataStructure/SegmentTree.hpp\"\n#include \"../Template/Template.hpp\"\
    \n\nstruct Info {\n    i64 x = 0;\n};\nInfo operator+(const Info& a, const Info&\
    \ b) { return {a.x + b.x}; }\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, q;\n    cin >> n >> q;\n    vector<Info>\
    \ a(n);\n    for (auto&& it : a) cin >> it.x;\n    SegmentTree<Info> st(a);\n\n\
    \    while (q--) {\n        int op;\n        cin >> op;\n        if (op == 0)\
    \ {\n            int p, x;\n            cin >> p >> x;\n            st.update(p,\
    \ {st[p].x + x});\n        } else {\n            int l, r;\n            cin >>\
    \ l >> r;\n            cout << st.query(l, r).x << '\\n';\n        }\n    }\n\n\
    \    return 0;\n}"
  dependsOn:
  - DataStructure/SegmentTree.hpp
  - Template/Template.hpp
  isVerificationFile: true
  path: Verify/PointAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2022-10-18 12:15:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/PointAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/Verify/PointAddRangeSum.test.cpp
- /verify/Verify/PointAddRangeSum.test.cpp.html
title: Verify/PointAddRangeSum.test.cpp
---
