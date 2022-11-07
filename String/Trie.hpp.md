---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: String/ACAutomaton.hpp
    title: String/ACAutomaton.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/ACAutomaton.test.cpp
    title: Verify/ACAutomaton.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Template/Template.hpp\"\n\nusing namespace std;\n\n#include\
    \ <bits/stdc++.h>\n\nusing i64 = long long;\nusing VI = vector<int>;\nusing pii\
    \ = pair<int, int>;\n#line 3 \"String/Trie.hpp\"\n\n// struct TrieNode {\n// \
    \    TrieNode() { id = 0, dep = 0, nxt = array<int, 26>(); };\n//     TrieNode(int\
    \ _id, int _dep) : id(_id), dep(_dep) {}\n//     int id;\n//     int dep;\n//\
    \     array<int, 26> nxt = {};\n//     int &operator[](const int x) { return this->nxt[x];\
    \ }\n// };\ntemplate <class Node>\nstruct trie {\n    vector<Node> tr;\n    trie()\
    \ { tr.push_back(Node()); };\n\n    int add(const string &s) {\n        int n\
    \ = s.size();\n        int p = 0;\n        for (int i = 0; i < n; i++) {\n   \
    \         int c = s[i] - 'A';\n            if (!tr[p][c]) {\n                tr[p][c]\
    \ = tr.size();\n                tr.emplace_back(tr[p][c], tr[p].dep + 1);\n  \
    \          }\n            p = tr[p][c];\n        }\n        return p;\n    }\n\
    \n    int size() const { return tr.size(); }\n};\n"
  code: "#pragma once\n#include \"../Template/Template.hpp\"\n\n// struct TrieNode\
    \ {\n//     TrieNode() { id = 0, dep = 0, nxt = array<int, 26>(); };\n//     TrieNode(int\
    \ _id, int _dep) : id(_id), dep(_dep) {}\n//     int id;\n//     int dep;\n//\
    \     array<int, 26> nxt = {};\n//     int &operator[](const int x) { return this->nxt[x];\
    \ }\n// };\ntemplate <class Node>\nstruct trie {\n    vector<Node> tr;\n    trie()\
    \ { tr.push_back(Node()); };\n\n    int add(const string &s) {\n        int n\
    \ = s.size();\n        int p = 0;\n        for (int i = 0; i < n; i++) {\n   \
    \         int c = s[i] - 'A';\n            if (!tr[p][c]) {\n                tr[p][c]\
    \ = tr.size();\n                tr.emplace_back(tr[p][c], tr[p].dep + 1);\n  \
    \          }\n            p = tr[p][c];\n        }\n        return p;\n    }\n\
    \n    int size() const { return tr.size(); }\n};\n"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: String/Trie.hpp
  requiredBy:
  - String/ACAutomaton.hpp
  timestamp: '2022-10-12 22:33:33+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/ACAutomaton.test.cpp
documentation_of: String/Trie.hpp
layout: document
redirect_from:
- /library/String/Trie.hpp
- /library/String/Trie.hpp.html
title: String/Trie.hpp
---
