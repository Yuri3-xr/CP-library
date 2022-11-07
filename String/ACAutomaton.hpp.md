---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Trie.hpp
    title: String/Trie.hpp
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/ACAutomaton.test.cpp
    title: Verify/ACAutomaton.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/ACAutomaton.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\nusing i64 = long long;\n\
    using VI = vector<int>;\nusing pii = pair<int, int>;\n#line 3 \"String/Trie.hpp\"\
    \n\n// struct TrieNode {\n//     TrieNode() { id = 0, dep = 0, nxt = array<int,\
    \ 26>(); };\n//     TrieNode(int _id, int _dep) : id(_id), dep(_dep) {}\n//  \
    \   int id;\n//     int dep;\n//     array<int, 26> nxt = {};\n//     int &operator[](const\
    \ int x) { return this->nxt[x]; }\n// };\ntemplate <class Node>\nstruct trie {\n\
    \    vector<Node> tr;\n    trie() { tr.push_back(Node()); };\n\n    int add(const\
    \ string &s) {\n        int n = s.size();\n        int p = 0;\n        for (int\
    \ i = 0; i < n; i++) {\n            int c = s[i] - 'A';\n            if (!tr[p][c])\
    \ {\n                tr[p][c] = tr.size();\n                tr.emplace_back(tr[p][c],\
    \ tr[p].dep + 1);\n            }\n            p = tr[p][c];\n        }\n     \
    \   return p;\n    }\n\n    int size() const { return tr.size(); }\n};\n#line\
    \ 4 \"String/ACAutomaton.hpp\"\ntemplate <class Node>\nstruct ACAutomaton : public\
    \ trie<Node> {\n    vector<int> fail;\n    ACAutomaton(){};\n\n    void BuildAC()\
    \ {\n        fail.resize(this->tr.size());\n        queue<int> Q;\n        for\
    \ (int i = 0; i < 26; i++)\n            if (this->tr[0][i]) Q.push(this->tr[0][i]);\n\
    \        while (!Q.empty()) {\n            int u = Q.front();\n            Q.pop();\n\
    \            for (int i = 0; i < 26; i++) {\n                if (this->tr[u][i])\n\
    \                    fail[this->tr[u][i]] = this->tr[fail[u]][i],\n          \
    \          Q.push(this->tr[u][i]);\n                else\n                   \
    \ this->tr[u][i] = this->tr[fail[u]][i];\n            }\n        }\n        return;\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include \"Trie.hpp\"\ntemplate <class Node>\nstruct ACAutomaton\
    \ : public trie<Node> {\n    vector<int> fail;\n    ACAutomaton(){};\n\n    void\
    \ BuildAC() {\n        fail.resize(this->tr.size());\n        queue<int> Q;\n\
    \        for (int i = 0; i < 26; i++)\n            if (this->tr[0][i]) Q.push(this->tr[0][i]);\n\
    \        while (!Q.empty()) {\n            int u = Q.front();\n            Q.pop();\n\
    \            for (int i = 0; i < 26; i++) {\n                if (this->tr[u][i])\n\
    \                    fail[this->tr[u][i]] = this->tr[fail[u]][i],\n          \
    \          Q.push(this->tr[u][i]);\n                else\n                   \
    \ this->tr[u][i] = this->tr[fail[u]][i];\n            }\n        }\n        return;\n\
    \    }\n};"
  dependsOn:
  - String/Trie.hpp
  - Template/Template.hpp
  isVerificationFile: false
  path: String/ACAutomaton.hpp
  requiredBy: []
  timestamp: '2022-10-28 17:39:21+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/ACAutomaton.test.cpp
documentation_of: String/ACAutomaton.hpp
layout: document
redirect_from:
- /library/String/ACAutomaton.hpp
- /library/String/ACAutomaton.hpp.html
title: String/ACAutomaton.hpp
---
