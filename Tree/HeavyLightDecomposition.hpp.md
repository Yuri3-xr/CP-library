---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/VertexAddPathSum.test.cpp
    title: Verify/VertexAddPathSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tree/HeavyLightDecomposition.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Tree/HeavyLightDecomposition.hpp\"\
    \nstruct HLD {\n    int n;\n    int cnt;  // dfs order [0,n)\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<int> par, dfn, hson, siz, top, dep;\n    HLD() = delete;\n\
    \    HLD(int _n)\n        : n(_n),\n          cnt(0),\n          adj(_n),\n  \
    \        par(_n),\n          dfn(_n),\n          hson(_n),\n          siz(_n),\n\
    \          top(_n),\n          dep(_n){};\n    HLD(std::vector<std::vector<int>>\
    \ tr) {\n        cnt = 0;\n        n = tr.size();\n        adj = tr;\n       \
    \ par.resize(n), dfn.resize(n), hson.resize(n), siz.resize(n),\n            top.resize(n),\
    \ dep.resize(n);\n    }\n\n    void addEdge(int x, int y) {\n        adj[x].push_back(y);\n\
    \        adj[y].push_back(x);\n        return;\n    }\n\n    void build(int root\
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
    \    }\n};\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\nstruct HLD {\n   \
    \ int n;\n    int cnt;  // dfs order [0,n)\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<int> par, dfn, hson, siz, top, dep;\n    HLD() = delete;\n\
    \    HLD(int _n)\n        : n(_n),\n          cnt(0),\n          adj(_n),\n  \
    \        par(_n),\n          dfn(_n),\n          hson(_n),\n          siz(_n),\n\
    \          top(_n),\n          dep(_n){};\n    HLD(std::vector<std::vector<int>>\
    \ tr) {\n        cnt = 0;\n        n = tr.size();\n        adj = tr;\n       \
    \ par.resize(n), dfn.resize(n), hson.resize(n), siz.resize(n),\n            top.resize(n),\
    \ dep.resize(n);\n    }\n\n    void addEdge(int x, int y) {\n        adj[x].push_back(y);\n\
    \        adj[y].push_back(x);\n        return;\n    }\n\n    void build(int root\
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
    \    }\n};\n"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/VertexAddPathSum.test.cpp
documentation_of: Tree/HeavyLightDecomposition.hpp
layout: document
title: Heavy Light Decomposition
---

# 轻重链剖分

初始化给定树的大小$n$,保证树的点序号在$[0,n)$内。

`adj`: 邻接表存图

`par`: 父亲节点标号

`hson`: 重儿子节点标号

`siz`: 子树大小

`top`: 重链顶端节点标号

`dep`: 节点深度（根结点深度$n$）

`dfn`: 节点dfs序标号

`build(int root = 0)`: 以root为根初始化构建HLD，时间复杂度$\mathcal{O}(n)$

`lca(int u,int v)`: 求$u,v$的LCA，时间复杂度$\mathcal{O}(\log{n})$

`pathP2P(int u, int v)`: 将$u,v$两点间的路径分解为若干个dfs序连续的区间$[l_i,r_i]$，区间个数级别为$\mathcal{O}(\log{n})$

`processP2P(int u, int v, F f)`: 将函数操作$f$作用在将$u,v$两点间的路径上；`f(int L,int R)->void`为dfs序在$[L,R]$上的操作函数；时间复杂度$\mathcal{O}(T(f)\log{n})$