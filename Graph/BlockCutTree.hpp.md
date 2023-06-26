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
  bundledCode: "#line 2 \"Graph/BlockCutTree.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"Graph/BlockCutTree.hpp\"\
    \ntemplate <class G>\nstruct BlockCutTree {\n    G tree;\n    std::vector<int>\
    \ dfn, low;\n    std::vector<int> ar;  // cut vertex 1/0\n    std::vector<int>\
    \ idar, idcc;\n\n    std::vector<std::vector<int>> bcc;\n    std::vector<std::vector<int>>\
    \ aux;  // block cut tree\n    BlockCutTree(const G& tree) : tree(tree) {\n  \
    \      int sz = tree.size();\n        dfn.assign(sz, -1);\n        low.assign(sz,\
    \ -1);\n        ar.assign(sz, 0);\n        idar.assign(sz, -1);\n        idcc.assign(sz,\
    \ -1);\n\n        build();\n    }\n    void build() {\n        int cnt = 0;\n\
    \        std::stack<int> st;\n        auto dfs = [&](auto&& self, int u, int fa)\
    \ -> void {\n            dfn[u] = low[u] = cnt++;\n            int childCnt =\
    \ 0;\n            st.push(u);\n            for (const auto& v : tree[u]) {\n \
    \               if (v == fa) continue;\n                if (dfn[v] == -1) {\n\
    \                    childCnt++;\n                    self(self, v, u);\n    \
    \                low[u] = std::min(low[u], low[v]);\n                    if (low[v]\
    \ >= dfn[u]) {\n                        ar[u] = 1;\n                        std::vector<int>\
    \ curBcc;\n                        while (true) {\n                          \
    \  int cur = st.top();\n                            curBcc.push_back(cur);\n \
    \                           st.pop();\n                            if (cur ==\
    \ v) break;\n                        }\n                        curBcc.push_back(u);\n\
    \                        bcc.push_back(curBcc);\n                    }\n     \
    \           } else\n                    low[u] = std::min(low[u], dfn[v]);\n \
    \           }\n            if (fa < 0 && childCnt < 2) ar[u] = 0;\n        };\n\
    \        for (int i = 0; i < (int)tree.size(); i++) {\n            if (dfn[i]\
    \ == -1) dfs(dfs, i, -1);\n        }\n\n        std::vector<int> arSet;\n    \
    \    for (int i = 0; i < (int)ar.size(); i++)\n            if (ar[i]) arSet.push_back(i);\n\
    \n        for (int i = 0; i < (int)arSet.size(); i++) idar[arSet[i]] = i;\n\n\
    \        aux.resize(arSet.size() + bcc.size());\n        std::vector<int> last(tree.size(),\
    \ -1);\n\n        for (int i = 0; i < (int)bcc.size(); i++) {\n            auto\
    \ add = [&](int i, int j) {\n                if (i == -1 or j == -1) return;\n\
    \                aux[i].push_back(j);\n                aux[j].push_back(i);\n\
    \                return;\n            };\n            for (const auto& u : bcc[i])\
    \ {\n                if (idar[u] == -1)\n                    idcc[u] = i + (int)arSet.size();\n\
    \                else if (last[u] != i) {\n                    add(i + (int)arSet.size(),\
    \ idar[u]);\n                    last[u] = i;\n                }\n           \
    \ }\n        }\n    }\n    std::vector<int>& operator[](int i) { return aux[i];\
    \ }\n    int size() const { return aux.size(); }\n    int id(int i) { return idar[i]\
    \ == -1 ? idcc[i] : idar[i]; }\n    bool is_arti(int i) { return idar[i] != -1;\
    \ }\n};\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\ntemplate <class G>\n\
    struct BlockCutTree {\n    G tree;\n    std::vector<int> dfn, low;\n    std::vector<int>\
    \ ar;  // cut vertex 1/0\n    std::vector<int> idar, idcc;\n\n    std::vector<std::vector<int>>\
    \ bcc;\n    std::vector<std::vector<int>> aux;  // block cut tree\n    BlockCutTree(const\
    \ G& tree) : tree(tree) {\n        int sz = tree.size();\n        dfn.assign(sz,\
    \ -1);\n        low.assign(sz, -1);\n        ar.assign(sz, 0);\n        idar.assign(sz,\
    \ -1);\n        idcc.assign(sz, -1);\n\n        build();\n    }\n    void build()\
    \ {\n        int cnt = 0;\n        std::stack<int> st;\n        auto dfs = [&](auto&&\
    \ self, int u, int fa) -> void {\n            dfn[u] = low[u] = cnt++;\n     \
    \       int childCnt = 0;\n            st.push(u);\n            for (const auto&\
    \ v : tree[u]) {\n                if (v == fa) continue;\n                if (dfn[v]\
    \ == -1) {\n                    childCnt++;\n                    self(self, v,\
    \ u);\n                    low[u] = std::min(low[u], low[v]);\n              \
    \      if (low[v] >= dfn[u]) {\n                        ar[u] = 1;\n         \
    \               std::vector<int> curBcc;\n                        while (true)\
    \ {\n                            int cur = st.top();\n                       \
    \     curBcc.push_back(cur);\n                            st.pop();\n        \
    \                    if (cur == v) break;\n                        }\n       \
    \                 curBcc.push_back(u);\n                        bcc.push_back(curBcc);\n\
    \                    }\n                } else\n                    low[u] = std::min(low[u],\
    \ dfn[v]);\n            }\n            if (fa < 0 && childCnt < 2) ar[u] = 0;\n\
    \        };\n        for (int i = 0; i < (int)tree.size(); i++) {\n          \
    \  if (dfn[i] == -1) dfs(dfs, i, -1);\n        }\n\n        std::vector<int> arSet;\n\
    \        for (int i = 0; i < (int)ar.size(); i++)\n            if (ar[i]) arSet.push_back(i);\n\
    \n        for (int i = 0; i < (int)arSet.size(); i++) idar[arSet[i]] = i;\n\n\
    \        aux.resize(arSet.size() + bcc.size());\n        std::vector<int> last(tree.size(),\
    \ -1);\n\n        for (int i = 0; i < (int)bcc.size(); i++) {\n            auto\
    \ add = [&](int i, int j) {\n                if (i == -1 or j == -1) return;\n\
    \                aux[i].push_back(j);\n                aux[j].push_back(i);\n\
    \                return;\n            };\n            for (const auto& u : bcc[i])\
    \ {\n                if (idar[u] == -1)\n                    idcc[u] = i + (int)arSet.size();\n\
    \                else if (last[u] != i) {\n                    add(i + (int)arSet.size(),\
    \ idar[u]);\n                    last[u] = i;\n                }\n           \
    \ }\n        }\n    }\n    std::vector<int>& operator[](int i) { return aux[i];\
    \ }\n    int size() const { return aux.size(); }\n    int id(int i) { return idar[i]\
    \ == -1 ? idcc[i] : idar[i]; }\n    bool is_arti(int i) { return idar[i] != -1;\
    \ }\n};"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: Graph/BlockCutTree.hpp
  requiredBy: []
  timestamp: '2023-06-27 04:36:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/BlockCutTree.hpp
layout: document
redirect_from:
- /library/Graph/BlockCutTree.hpp
- /library/Graph/BlockCutTree.hpp.html
title: Graph/BlockCutTree.hpp
---
