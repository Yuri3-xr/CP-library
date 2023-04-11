---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: DataStructure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"Verify/VertexAddPathSum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\
    \n\n#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\nusing i64\
    \ = std::int64_t;\n#line 3 \"DataStructure/SegmentTree.hpp\"\n\ntemplate <typename\
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
    \ &operator[](const int &k) { return seg[k + size]; }\n};\n#line 2 \"Tree/HeavyLightDecomposition.hpp\"\
    \n\n#line 4 \"Tree/HeavyLightDecomposition.hpp\"\nstruct HLD {\n    int n;\n \
    \   int cnt;  // dfs order [0,n)\n    std::vector<std::vector<int>> adj;\n   \
    \ std::vector<int> par, dfn, hson, siz, top, dep;\n    HLD() = delete;\n    HLD(int\
    \ _n)\n        : n(_n),\n          cnt(0),\n          adj(_n),\n          par(_n),\n\
    \          dfn(_n),\n          hson(_n),\n          siz(_n),\n          top(_n),\n\
    \          dep(_n){};\n    HLD(std::vector<std::vector<int>> tr) {\n        cnt\
    \ = 0;\n        n = tr.size();\n        adj = tr;\n        par.resize(n), dfn.resize(n),\
    \ hson.resize(n), siz.resize(n),\n            top.resize(n), dep.resize(n);\n\
    \    }\n\n    void addEdge(int x, int y) {\n        adj[x].push_back(y);\n   \
    \     adj[y].push_back(x);\n        return;\n    }\n\n    void build(int root\
    \ = 0) {\n        auto dfs1 = [&](auto &&self, int u, int fa) -> void {\n    \
    \        par[u] = fa, siz[u] = 1, hson[u] = -1;\n            for (const auto &v\
    \ : adj[u]) {\n                if (v == fa) continue;\n                dep[v]\
    \ = dep[u] + 1;\n                self(self, v, u);\n                siz[u] +=\
    \ siz[v];\n                if (hson[u] == -1)\n                    hson[u] = v;\n\
    \                else if (siz[hson[u]] < siz[v])\n                    hson[u]\
    \ = v;\n            }\n        };\n        dfs1(dfs1, root, -1);\n        auto\
    \ dfs2 = [&](auto &&self, int u, int tp) -> void {\n            dfn[u] = cnt++;\n\
    \            top[u] = tp;\n            if (hson[u] == -1) return;\n          \
    \  self(self, hson[u], tp);\n            for (const auto &v : adj[u]) {\n    \
    \            if (v == par[u] || v == hson[u]) continue;\n                self(self,\
    \ v, v);\n            }\n        };\n        dfs2(dfs2, root, root);\n       \
    \ return;\n    }\n\n    int lca(int u, int v) const {\n        while (top[u] !=\
    \ top[v]) {\n            if (dep[top[u]] > dep[top[v]])\n                u = par[top[u]];\n\
    \            else\n                v = par[top[v]];\n        }\n        return\
    \ ((dep[u] > dep[v]) ? v : u);\n    }\n\n    std::vector<std::pair<int, int>>\
    \ pathP2P(int u, int v) const {\n        // op length O(logn)\n        std::vector<std::pair<int,\
    \ int>> op;\n        while (top[u] != top[v]) {\n            if (dep[top[u]] <\
    \ dep[top[v]]) std::swap(u, v);\n            op.emplace_back(dfn[top[u]], dfn[u]);\n\
    \            u = par[top[u]];\n        }\n        if (dep[u] > dep[v]) std::swap(u,\
    \ v);\n        op.emplace_back(dfn[u], dfn[v]);\n        return (op);\n    }\n\
    \    template <class F>\n    void processP2P(int u, int v, F f) {\n        //\
    \ F: void(int L, int R) refers to the process of internal [L,R]\n        while\
    \ (top[u] != top[v]) {\n            if (dep[top[u]] < dep[top[v]]) std::swap(u,\
    \ v);\n            f(dfn[top[u]], dfn[u]);\n            u = par[top[u]];\n   \
    \     }\n        if (dep[u] > dep[v]) std::swap(u, v);\n        f(dfn[u], dfn[v]);\n\
    \    }\n};\n#line 6 \"Verify/VertexAddPathSum.test.cpp\"\n\nstruct Info {\n  \
    \  i64 x = 0;\n    Info& operator+=(const Info& a) {\n        x += a.x;\n    \
    \    return *this;\n    }\n};\nInfo operator+(const Info& a, const Info& b) {\
    \ return {a.x + b.x}; }\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<i64>\
    \ val(n);\n    std::vector<Info> _init(n);\n\n    for (int i = 0; i < n; i++)\
    \ {\n        std::cin >> val[i];\n    }\n\n    HLD hld(n);\n    for (int i = 0;\
    \ i < n - 1; i++) {\n        int u, v;\n        std::cin >> u >> v;\n        hld.addEdge(u,\
    \ v);\n    }\n\n    hld.build();\n\n    for (int i = 0; i < n; i++) {\n      \
    \  _init[hld.dfn[i]].x = val[i];\n    }\n\n    SegmentTree<Info> ST(_init);\n\n\
    \    while (q--) {\n        int op;\n        std::cin >> op;\n        if (op ==\
    \ 0) {\n            int p, x;\n            std::cin >> p >> x;\n            ST.add(hld.dfn[p],\
    \ {x});\n        }\n        if (op == 1) {\n            int u, v;\n          \
    \  std::cin >> u >> v;\n\n            i64 sum = 0;\n            auto processSum\
    \ = [&](int L, int R) -> void {\n                sum += ST.query(L, R + 1).x;\n\
    \            };\n\n            hld.processP2P(u, v, processSum);\n           \
    \ std::cout << sum << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../DataStructure/SegmentTree.hpp\"\n#include \"../Template/Template.hpp\"\
    \n#include \"../Tree/HeavyLightDecomposition.hpp\"\n\nstruct Info {\n    i64 x\
    \ = 0;\n    Info& operator+=(const Info& a) {\n        x += a.x;\n        return\
    \ *this;\n    }\n};\nInfo operator+(const Info& a, const Info& b) { return {a.x\
    \ + b.x}; }\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<i64> val(n);\n   \
    \ std::vector<Info> _init(n);\n\n    for (int i = 0; i < n; i++) {\n        std::cin\
    \ >> val[i];\n    }\n\n    HLD hld(n);\n    for (int i = 0; i < n - 1; i++) {\n\
    \        int u, v;\n        std::cin >> u >> v;\n        hld.addEdge(u, v);\n\
    \    }\n\n    hld.build();\n\n    for (int i = 0; i < n; i++) {\n        _init[hld.dfn[i]].x\
    \ = val[i];\n    }\n\n    SegmentTree<Info> ST(_init);\n\n    while (q--) {\n\
    \        int op;\n        std::cin >> op;\n        if (op == 0) {\n          \
    \  int p, x;\n            std::cin >> p >> x;\n            ST.add(hld.dfn[p],\
    \ {x});\n        }\n        if (op == 1) {\n            int u, v;\n          \
    \  std::cin >> u >> v;\n\n            i64 sum = 0;\n            auto processSum\
    \ = [&](int L, int R) -> void {\n                sum += ST.query(L, R + 1).x;\n\
    \            };\n\n            hld.processP2P(u, v, processSum);\n           \
    \ std::cout << sum << '\\n';\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - DataStructure/SegmentTree.hpp
  - Template/Template.hpp
  - Tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: Verify/VertexAddPathSum.test.cpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/VertexAddPathSum.test.cpp
layout: document
redirect_from:
- /verify/Verify/VertexAddPathSum.test.cpp
- /verify/Verify/VertexAddPathSum.test.cpp.html
title: Verify/VertexAddPathSum.test.cpp
---
