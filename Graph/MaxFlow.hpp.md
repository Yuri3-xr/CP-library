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
  bundledCode: "#line 2 \"Graph/MaxFlow.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Graph/MaxFlow.hpp\"\
    \ntemplate <class T>\nstruct HLPP {\n    struct arc {\n        int to, rev;\n\
    \        T cap;\n    };\n    const T inf = std::numeric_limits<T>::max();\n  \
    \  const int n;\n    std::vector<std::tuple<int, int, T, T>> arc_pool;\n    std::vector<arc>\
    \ g;\n    std::vector<int> head, ptr, d;\n    std::vector<T> ex;\n    std::vector<std::vector<int>>\
    \ active;\n    std::vector<std::set<int>> vs;\n    int highest, works;\n    HLPP(int\
    \ _n) : n(_n), head(n + 1), ptr(n), d(n), ex(n), active(n), vs(n) {}\n    void\
    \ add(int from, int to, T cap, bool directed = true) {\n        assert(cap >=\
    \ 0);\n\n        if (from == to or cap == 0) return;\n\n        arc_pool.emplace_back(from,\
    \ to, cap, directed ? 0 : cap);\n        ++head[from], ++head[to];\n    }\n  \
    \  void build() {\n        for (int v = 0; v < n; ++v) head[v + 1] += head[v];\n\
    \n        g.resize(head[n]);\n\n        for (const auto &e : arc_pool) {\n   \
    \         int i = --head[std::get<0>(e)], j = --head[std::get<1>(e)];\n      \
    \      g[i] = {std::get<1>(e), j, std::get<2>(e)},\n            g[j] = {std::get<0>(e),\
    \ i, std::get<3>(e)};\n        }\n    }\n    void push(int v, arc &a) {\n    \
    \    if (ex[a.to] == 0) active[d[a.to]].push_back(a.to);\n\n        T delta =\
    \ std::min(ex[v], a.cap);\n        ex[v] -= delta, ex[a.to] += delta;\n      \
    \  a.cap -= delta, g[a.rev].cap += delta;\n    }\n    void relabel(int v) {\n\
    \        ++works;\n        int min = 2 * n;\n\n        for (int i = head[v]; i\
    \ < head[v + 1]; ++i)\n            if (g[i].cap) min = std::min(min, d[g[i].to]);\n\
    \n        if ((int)vs[d[v]].size() == 1) {\n            for (int i = d[v]; i <\
    \ n; ++i) {\n                for (int u : vs[i]) d[u] = n;\n                active[i].clear(),\
    \ vs[i].clear();\n            }\n\n            return;\n        }\n\n        vs[d[v]].erase(v);\n\
    \n        if ((d[v] = min + 1) < n) vs[highest = d[v]].insert(v);\n    }\n   \
    \ void discharge(int v) {\n        int i = ptr[v];\n\n        while (ex[v]) {\n\
    \            if (i == head[v + 1]) {\n                relabel(v), i = head[v];\n\
    \n                if (d[v] >= n) break;\n            } else {\n              \
    \  if (g[i].cap and d[v] > d[g[i].to])\n                    push(v, g[i]);\n \
    \               else\n                    ++i;\n            }\n        }\n\n \
    \       ptr[v] = i;\n    }\n    void global_relabel(int t) {\n        std::copy(begin(head),\
    \ begin(head) + n, begin(ptr));\n        std::fill(begin(d), end(d), n);\n\n \
    \       for (int i = 0; i < n; ++i) active[i].clear(), vs[i].clear();\n\n    \
    \    highest = -1, works = 0;\n        std::queue<int> que;\n        d[t] = 0,\
    \ que.push(t);\n\n        while (not que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            vs[d[v]].insert(v);\n\n            for (int\
    \ i = head[v]; i < head[v + 1]; ++i)\n                if (g[g[i].rev].cap and\
    \ d[g[i].to] == n) {\n                    d[g[i].to] = d[v] + 1, que.push(g[i].to);\n\
    \n                    if (ex[g[i].to])\n                        active[highest\
    \ = d[g[i].to]].push_back(g[i].to);\n                }\n        }\n    }\n   \
    \ T max_flow(int s, int t) {\n        build();\n        ex[s] = inf, ex[t] = -inf;\n\
    \n        for (int i = head[s]; i < head[s + 1]; ++i) push(s, g[i]);\n\n     \
    \   global_relabel(t);\n\n        for (; highest >= 0; --highest)\n          \
    \  while (not active[highest].empty()) {\n                int v = active[highest].back();\n\
    \                active[highest].pop_back();\n                discharge(v);\n\n\
    \                if (works > 4 * n) global_relabel(t);\n            }\n\n    \
    \    return inf + ex[t];\n    }\n};\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\ntemplate <class T>\n\
    struct HLPP {\n    struct arc {\n        int to, rev;\n        T cap;\n    };\n\
    \    const T inf = std::numeric_limits<T>::max();\n    const int n;\n    std::vector<std::tuple<int,\
    \ int, T, T>> arc_pool;\n    std::vector<arc> g;\n    std::vector<int> head, ptr,\
    \ d;\n    std::vector<T> ex;\n    std::vector<std::vector<int>> active;\n    std::vector<std::set<int>>\
    \ vs;\n    int highest, works;\n    HLPP(int _n) : n(_n), head(n + 1), ptr(n),\
    \ d(n), ex(n), active(n), vs(n) {}\n    void add(int from, int to, T cap, bool\
    \ directed = true) {\n        assert(cap >= 0);\n\n        if (from == to or cap\
    \ == 0) return;\n\n        arc_pool.emplace_back(from, to, cap, directed ? 0 :\
    \ cap);\n        ++head[from], ++head[to];\n    }\n    void build() {\n      \
    \  for (int v = 0; v < n; ++v) head[v + 1] += head[v];\n\n        g.resize(head[n]);\n\
    \n        for (const auto &e : arc_pool) {\n            int i = --head[std::get<0>(e)],\
    \ j = --head[std::get<1>(e)];\n            g[i] = {std::get<1>(e), j, std::get<2>(e)},\n\
    \            g[j] = {std::get<0>(e), i, std::get<3>(e)};\n        }\n    }\n \
    \   void push(int v, arc &a) {\n        if (ex[a.to] == 0) active[d[a.to]].push_back(a.to);\n\
    \n        T delta = std::min(ex[v], a.cap);\n        ex[v] -= delta, ex[a.to]\
    \ += delta;\n        a.cap -= delta, g[a.rev].cap += delta;\n    }\n    void relabel(int\
    \ v) {\n        ++works;\n        int min = 2 * n;\n\n        for (int i = head[v];\
    \ i < head[v + 1]; ++i)\n            if (g[i].cap) min = std::min(min, d[g[i].to]);\n\
    \n        if ((int)vs[d[v]].size() == 1) {\n            for (int i = d[v]; i <\
    \ n; ++i) {\n                for (int u : vs[i]) d[u] = n;\n                active[i].clear(),\
    \ vs[i].clear();\n            }\n\n            return;\n        }\n\n        vs[d[v]].erase(v);\n\
    \n        if ((d[v] = min + 1) < n) vs[highest = d[v]].insert(v);\n    }\n   \
    \ void discharge(int v) {\n        int i = ptr[v];\n\n        while (ex[v]) {\n\
    \            if (i == head[v + 1]) {\n                relabel(v), i = head[v];\n\
    \n                if (d[v] >= n) break;\n            } else {\n              \
    \  if (g[i].cap and d[v] > d[g[i].to])\n                    push(v, g[i]);\n \
    \               else\n                    ++i;\n            }\n        }\n\n \
    \       ptr[v] = i;\n    }\n    void global_relabel(int t) {\n        std::copy(begin(head),\
    \ begin(head) + n, begin(ptr));\n        std::fill(begin(d), end(d), n);\n\n \
    \       for (int i = 0; i < n; ++i) active[i].clear(), vs[i].clear();\n\n    \
    \    highest = -1, works = 0;\n        std::queue<int> que;\n        d[t] = 0,\
    \ que.push(t);\n\n        while (not que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            vs[d[v]].insert(v);\n\n            for (int\
    \ i = head[v]; i < head[v + 1]; ++i)\n                if (g[g[i].rev].cap and\
    \ d[g[i].to] == n) {\n                    d[g[i].to] = d[v] + 1, que.push(g[i].to);\n\
    \n                    if (ex[g[i].to])\n                        active[highest\
    \ = d[g[i].to]].push_back(g[i].to);\n                }\n        }\n    }\n   \
    \ T max_flow(int s, int t) {\n        build();\n        ex[s] = inf, ex[t] = -inf;\n\
    \n        for (int i = head[s]; i < head[s + 1]; ++i) push(s, g[i]);\n\n     \
    \   global_relabel(t);\n\n        for (; highest >= 0; --highest)\n          \
    \  while (not active[highest].empty()) {\n                int v = active[highest].back();\n\
    \                active[highest].pop_back();\n                discharge(v);\n\n\
    \                if (works > 4 * n) global_relabel(t);\n            }\n\n    \
    \    return inf + ex[t];\n    }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Graph/MaxFlow.hpp
  requiredBy: []
  timestamp: '2023-04-27 02:39:36+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/MaxFlow.hpp
layout: document
redirect_from:
- /library/Graph/MaxFlow.hpp
- /library/Graph/MaxFlow.hpp.html
title: Graph/MaxFlow.hpp
---
