---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentSegmentTree.hpp
    title: DataStructure/PersistentSegmentTree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"Verify/RangeKthSmallest.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\
    \n\n#line 2 \"DataStructure/PersistentSegmentTree.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"DataStructure/PersistentSegmentTree.hpp\"\
    \n\nstruct PersistentSegmentTree {\n    struct Node {\n        Node* l;\n    \
    \    Node* r;\n        int x;\n        i64 sum = 0;\n        Node() : l(nullptr),\
    \ r(nullptr), x(0), sum(0){};\n    };\n\n    std::vector<Node*> node;\n    std::vector<int>\
    \ v;\n    int sz = 0;\n\n    PersistentSegmentTree(const std::vector<int>& a)\
    \ {\n        int n = a.size();\n        v = a;\n        std::sort(begin(v), end(v));\n\
    \        v.resize(std::unique(begin(v), end(v)) - begin(v));\n        sz = v.size();\n\
    \        node.resize(n + 1);\n        node[0] = build(0, sz);\n        for (int\
    \ i = 0; i < n; i++) {\n            int p = std::lower_bound(v.begin(), v.end(),\
    \ a[i]) - v.begin();\n            node[i + 1] = add(node[i], 0, sz, p, v[p]);\n\
    \        }\n        return;\n    }\n    Node* build(int l, int r) {\n        auto\
    \ nt = new Node();\n        if (r - l == 1) {\n            return nt;\n      \
    \  }\n\n        int m = (l + r) / 2;\n        nt->l = build(l, m);\n        nt->r\
    \ = build(m, r);\n\n        return nt;\n    }\n\n    Node* add(Node* t, int l,\
    \ int r, int x, i64 real) {\n        Node* nt = new Node();\n\n        if (t)\
    \ {\n            *nt = *t;\n        }\n\n        if (r - l == 1) {\n         \
    \   nt->x += 1;\n            nt->sum += real;\n            return nt;\n      \
    \  }\n\n        int m = (l + r) / 2;\n\n        if (x < m)\n            nt->l\
    \ = add(nt->l, l, m, x, real);\n        else\n            nt->r = add(nt->r, m,\
    \ r, x, real);\n\n        nt->x = (nt->l->x) + (nt->r->x);\n        nt->sum =\
    \ (nt->l->sum) + (nt->r->sum);\n\n        return nt;\n    }\n    std::pair<int,\
    \ i64> query(Node*& p, Node*& q, int l, int r, int k) {\n        if (r - l ==\
    \ 1) {\n            int cnt = (q->x) - (p->x);\n            i64 sum = (q->sum)\
    \ - (p->sum);\n            if (cnt == 0) return {l, 0};\n            return {l,\
    \ 1LL * sum / cnt * k};\n        }\n        int cnt = (q->l->x) - (p->l->x);\n\
    \        int m = (l + r) / 2;\n\n        i64 ret = 0;\n        int pos = -1;\n\
    \        if (k <= cnt) {\n            auto [x, y] = query(p->l, q->l, l, m, k);\n\
    \            pos = x;\n            ret += y;\n        } else {\n            auto\
    \ [x, y] = query(p->r, q->r, m, r, k - cnt);\n            pos = x;\n         \
    \   ret += (q->l->sum) - (p->l->sum) + y;\n        }\n\n        return {pos, ret};\n\
    \    }\n\n    std::pair<int, i64> rangeKth(int l, int r, int k) {\n        //\
    \ [l,r)\n        auto [x, sum] = query(node[l], node[r], 0, sz, k);\n        return\
    \ {v[x], sum};\n    }\n};\n#line 4 \"Verify/RangeKthSmallest.test.cpp\"\n\nint\
    \ main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<int> a(n);\n    for\
    \ (int i = 0; i < n; i++) {\n        std::cin >> a[i];\n    }\n\n    PersistentSegmentTree\
    \ SegmentTree(a);\n    while (q--) {\n        int l, r, k;\n        std::cin >>\
    \ l >> r >> k;\n        std::cout << SegmentTree.rangeKth(l, r, k + 1).first <<\
    \ std::endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../DataStructure/PersistentSegmentTree.hpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for (int i = 0; i < n; i++) {\n        std::cin >> a[i];\n    }\n\
    \n    PersistentSegmentTree SegmentTree(a);\n    while (q--) {\n        int l,\
    \ r, k;\n        std::cin >> l >> r >> k;\n        std::cout << SegmentTree.rangeKth(l,\
    \ r, k + 1).first << std::endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - DataStructure/PersistentSegmentTree.hpp
  - Template/Template.hpp
  isVerificationFile: true
  path: Verify/RangeKthSmallest.test.cpp
  requiredBy: []
  timestamp: '2023-10-02 22:35:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/RangeKthSmallest.test.cpp
layout: document
redirect_from:
- /verify/Verify/RangeKthSmallest.test.cpp
- /verify/Verify/RangeKthSmallest.test.cpp.html
title: Verify/RangeKthSmallest.test.cpp
---