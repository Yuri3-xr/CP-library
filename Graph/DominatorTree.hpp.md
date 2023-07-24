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
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    using i64 = std::int64_t;\n#line 3 \"Graph/DominatorTree.hpp\"\n\nstruct DominatorTree\
    \ {\n   public:\n    std::vector<std::vector<int>> domTree;\n    DominatorTree(const\
    \ std::vector<std::vector<int>>& adj, int root) {\n        build(adj, root);\n\
    \    }\n\n    void build(const std::vector<std::vector<int>>& adj, int root) {\n\
    \        g = adj;\n        rg.resize(adj.size());\n        par.assign(g.size(),\
    \ 0);\n        idom.assign(g.size(), -1);\n        semi.assign(g.size(), -1);\n\
    \        ord.reserve(g.size());\n        UnionFind uf(semi);\n\n        const\
    \ int N = (int)g.size();\n        dfs(root);\n        for (int i = 0; i < N; i++)\
    \ {\n            for (auto& to : g[i]) {\n                if (~semi[i]) rg[to].emplace_back(i);\n\
    \            }\n        }\n\n        std::vector<std::vector<int>> bucket(N);\n\
    \        std::vector<int> U(N);\n        for (int i = (int)ord.size() - 1; i >=\
    \ 0; i--) {\n            int x = ord[i];\n            for (int v : rg[x]) {\n\
    \                v = uf.eval(v);\n                if (semi[x] > semi[v]) semi[x]\
    \ = semi[v];\n            }\n            bucket[ord[semi[x]]].emplace_back(x);\n\
    \            for (int v : bucket[par[x]]) U[v] = uf.eval(v);\n            bucket[par[x]].clear();\n\
    \            uf.link(par[x], x);\n        }\n        for (int i = 1; i < (int)ord.size();\
    \ i++) {\n            int x = ord[i], u = U[x];\n            idom[x] = semi[x]\
    \ == semi[u] ? semi[x] : idom[u];\n        }\n\n        domTree.resize(N);\n \
    \       for (int i = 1; i < (int)ord.size(); i++) {\n            int x = ord[i];\n\
    \            idom[x] = ord[idom[x]];\n            domTree[x].push_back(idom[x]);\n\
    \            domTree[idom[x]].push_back(x);\n        }\n        idom[root] = root;\n\
    \    }\n\n    int operator[](const int& k) const { return idom[k]; }\n\n   private:\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<std::vector<int>> rg;\n\
    \n    struct UnionFind {\n        const std::vector<int>& semi;\n        std::vector<int>\
    \ par, m;\n\n        explicit UnionFind(const std::vector<int>& semi)\n      \
    \      : semi(semi), par(semi.size()), m(semi.size()) {\n            std::iota(begin(par),\
    \ end(par), 0);\n            std::iota(begin(m), end(m), 0);\n        }\n\n  \
    \      int find(int v) {\n            if (par[v] == v) return v;\n           \
    \ int r = find(par[v]);\n            if (semi[m[v]] > semi[m[par[v]]]) m[v] =\
    \ m[par[v]];\n            return par[v] = r;\n        }\n\n        int eval(int\
    \ v) {\n            find(v);\n            return m[v];\n        }\n\n        void\
    \ link(int p, int c) { par[c] = p; }\n    };\n\n    std::vector<int> ord, par;\n\
    \    std::vector<int> idom, semi;\n\n    void dfs(int idx) {\n        semi[idx]\
    \ = (int)ord.size();\n        ord.emplace_back(idx);\n        for (auto& to :\
    \ g[idx]) {\n            if (~semi[to]) continue;\n            dfs(to);\n    \
    \        par[to] = idx;\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../Template/Template.hpp\"\n\nstruct DominatorTree\
    \ {\n   public:\n    std::vector<std::vector<int>> domTree;\n    DominatorTree(const\
    \ std::vector<std::vector<int>>& adj, int root) {\n        build(adj, root);\n\
    \    }\n\n    void build(const std::vector<std::vector<int>>& adj, int root) {\n\
    \        g = adj;\n        rg.resize(adj.size());\n        par.assign(g.size(),\
    \ 0);\n        idom.assign(g.size(), -1);\n        semi.assign(g.size(), -1);\n\
    \        ord.reserve(g.size());\n        UnionFind uf(semi);\n\n        const\
    \ int N = (int)g.size();\n        dfs(root);\n        for (int i = 0; i < N; i++)\
    \ {\n            for (auto& to : g[i]) {\n                if (~semi[i]) rg[to].emplace_back(i);\n\
    \            }\n        }\n\n        std::vector<std::vector<int>> bucket(N);\n\
    \        std::vector<int> U(N);\n        for (int i = (int)ord.size() - 1; i >=\
    \ 0; i--) {\n            int x = ord[i];\n            for (int v : rg[x]) {\n\
    \                v = uf.eval(v);\n                if (semi[x] > semi[v]) semi[x]\
    \ = semi[v];\n            }\n            bucket[ord[semi[x]]].emplace_back(x);\n\
    \            for (int v : bucket[par[x]]) U[v] = uf.eval(v);\n            bucket[par[x]].clear();\n\
    \            uf.link(par[x], x);\n        }\n        for (int i = 1; i < (int)ord.size();\
    \ i++) {\n            int x = ord[i], u = U[x];\n            idom[x] = semi[x]\
    \ == semi[u] ? semi[x] : idom[u];\n        }\n\n        domTree.resize(N);\n \
    \       for (int i = 1; i < (int)ord.size(); i++) {\n            int x = ord[i];\n\
    \            idom[x] = ord[idom[x]];\n            domTree[x].push_back(idom[x]);\n\
    \            domTree[idom[x]].push_back(x);\n        }\n        idom[root] = root;\n\
    \    }\n\n    int operator[](const int& k) const { return idom[k]; }\n\n   private:\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<std::vector<int>> rg;\n\
    \n    struct UnionFind {\n        const std::vector<int>& semi;\n        std::vector<int>\
    \ par, m;\n\n        explicit UnionFind(const std::vector<int>& semi)\n      \
    \      : semi(semi), par(semi.size()), m(semi.size()) {\n            std::iota(begin(par),\
    \ end(par), 0);\n            std::iota(begin(m), end(m), 0);\n        }\n\n  \
    \      int find(int v) {\n            if (par[v] == v) return v;\n           \
    \ int r = find(par[v]);\n            if (semi[m[v]] > semi[m[par[v]]]) m[v] =\
    \ m[par[v]];\n            return par[v] = r;\n        }\n\n        int eval(int\
    \ v) {\n            find(v);\n            return m[v];\n        }\n\n        void\
    \ link(int p, int c) { par[c] = p; }\n    };\n\n    std::vector<int> ord, par;\n\
    \    std::vector<int> idom, semi;\n\n    void dfs(int idx) {\n        semi[idx]\
    \ = (int)ord.size();\n        ord.emplace_back(idx);\n        for (auto& to :\
    \ g[idx]) {\n            if (~semi[to]) continue;\n            dfs(to);\n    \
    \        par[to] = idx;\n        }\n    }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Graph/DominatorTree.hpp
  requiredBy: []
  timestamp: '2023-07-24 20:06:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/DominatorTree.hpp
layout: document
redirect_from:
- /library/Graph/DominatorTree.hpp
- /library/Graph/DominatorTree.hpp.html
title: Graph/DominatorTree.hpp
---
