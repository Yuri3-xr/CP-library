---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/ACAutomaton.hpp
    title: String/ACAutomaton.hpp
  - icon: ':heavy_check_mark:'
    path: String/Trie.hpp
    title: String/Trie.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Verify/ACAutomaton.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 2 \"String/ACAutomaton.hpp\"\n\n#line 2 \"Template/Template.hpp\"\n\n\
    #include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 3 \"String/Trie.hpp\"\
    \n\n// struct TrieNode {\n//     TrieNode() { id = 0, dep = 0, nxt = std::array<int,\
    \ 26>(); };\n//     TrieNode(int _id, int _dep) : id(_id), dep(_dep) {}\n//  \
    \   int id;\n//     int dep;\n//     std::array<int, 26> nxt = {};\n//     int\
    \ &operator[](const int x) { return this->nxt[x]; }\n// };\ntemplate <class Node>\n\
    struct trie {\n    std::vector<Node> tr;\n    trie() { tr.push_back(Node()); };\n\
    \n    int add(const std::string &s) {\n        int n = s.size();\n        int\
    \ p = 0;\n        for (int i = 0; i < n; i++) {\n            int c = s[i] - 'A';\n\
    \            if (!tr[p][c]) {\n                tr[p][c] = tr.size();\n       \
    \         tr.emplace_back(tr[p][c], tr[p].dep + 1);\n            }\n         \
    \   p = tr[p][c];\n        }\n        return p;\n    }\n\n    int size() const\
    \ { return tr.size(); }\n};\n#line 4 \"String/ACAutomaton.hpp\"\n\ntemplate <class\
    \ Node>\nstruct ACAutomaton : public trie<Node> {\n    std::vector<int> fail;\n\
    \    ACAutomaton(){};\n\n    void BuildAC() {\n        fail.resize(this->tr.size());\n\
    \        std::queue<int> Q;\n        for (int i = 0; i < 26; i++)\n          \
    \  if (this->tr[0][i]) Q.push(this->tr[0][i]);\n        while (!Q.empty()) {\n\
    \            int u = Q.front();\n            Q.pop();\n            for (int i\
    \ = 0; i < 26; i++) {\n                if (this->tr[u][i])\n                 \
    \   fail[this->tr[u][i]] = this->tr[fail[u]][i],\n                    Q.push(this->tr[u][i]);\n\
    \                else\n                    this->tr[u][i] = this->tr[fail[u]][i];\n\
    \            }\n        }\n        return;\n    }\n};\n#line 4 \"Verify/ACAutomaton.test.cpp\"\
    \n\n#line 6 \"Verify/ACAutomaton.test.cpp\"\n\nstruct TrieNode {\n    TrieNode()\
    \ { id = 0, dep = 0, nxt = std::array<int, 26>(); };\n    TrieNode(int _id, int\
    \ _dep) : id(_id), dep(_dep) {}\n    int id;\n    int dep;\n    std::array<int,\
    \ 26> nxt = {};\n    int &operator[](const int x) { return this->nxt[x]; }\n};\n\
    int main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << std::endl;\n\
    \    // string s;\n    // int m;\n    // cin >> s >> m;\n\n    // ACAutomaton<TrieNode>\
    \ ac;\n    // vector<int> pos(m + 1);\n    // for (int i = 1; i <= m; i++) {\n\
    \    //     string res;\n    //     cin >> res;\n    //     pos[i] = ac.add(res);\n\
    \    // }\n    // ac.BuildAC();\n\n    // vector<int> val(ac.size());\n    //\
    \ vector<vector<int>> adj(ac.size());\n    // for (int i = 0; i < ac.size(); i++)\
    \ {\n    //     if (i != ac.fail[i]) adj[ac.fail[i]].push_back(i);\n    // }\n\
    \n    // int p = 0;\n    // for (auto it : s) {\n    //     p = ac.tr[p][it -\
    \ 'A'];\n    //     val[p]++;\n    // }\n\n    // function<void(int)> dfs = [&](int\
    \ u) {\n    //     for (auto v : adj[u]) {\n    //         dfs(v);\n    //   \
    \      val[u] += val[v];\n    //     }\n    // };\n    // dfs(0);\n\n    // int\
    \ ans = 0;\n\n    // for (int i = 1; i <= m; i++) ans += val[pos[i]];\n    //\
    \ cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../String/ACAutomaton.hpp\"\n\n#include \"../Template/Template.hpp\"\n\nstruct\
    \ TrieNode {\n    TrieNode() { id = 0, dep = 0, nxt = std::array<int, 26>(); };\n\
    \    TrieNode(int _id, int _dep) : id(_id), dep(_dep) {}\n    int id;\n    int\
    \ dep;\n    std::array<int, 26> nxt = {};\n    int &operator[](const int x) {\
    \ return this->nxt[x]; }\n};\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int a, b;\n    std::cin >> a >> b;\n    std::cout\
    \ << a + b << std::endl;\n    // string s;\n    // int m;\n    // cin >> s >>\
    \ m;\n\n    // ACAutomaton<TrieNode> ac;\n    // vector<int> pos(m + 1);\n   \
    \ // for (int i = 1; i <= m; i++) {\n    //     string res;\n    //     cin >>\
    \ res;\n    //     pos[i] = ac.add(res);\n    // }\n    // ac.BuildAC();\n\n \
    \   // vector<int> val(ac.size());\n    // vector<vector<int>> adj(ac.size());\n\
    \    // for (int i = 0; i < ac.size(); i++) {\n    //     if (i != ac.fail[i])\
    \ adj[ac.fail[i]].push_back(i);\n    // }\n\n    // int p = 0;\n    // for (auto\
    \ it : s) {\n    //     p = ac.tr[p][it - 'A'];\n    //     val[p]++;\n    //\
    \ }\n\n    // function<void(int)> dfs = [&](int u) {\n    //     for (auto v :\
    \ adj[u]) {\n    //         dfs(v);\n    //         val[u] += val[v];\n    //\
    \     }\n    // };\n    // dfs(0);\n\n    // int ans = 0;\n\n    // for (int i\
    \ = 1; i <= m; i++) ans += val[pos[i]];\n    // cout << ans << endl;\n\n    return\
    \ 0;\n}"
  dependsOn:
  - String/ACAutomaton.hpp
  - String/Trie.hpp
  - Template/Template.hpp
  isVerificationFile: true
  path: Verify/ACAutomaton.test.cpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/ACAutomaton.test.cpp
layout: document
redirect_from:
- /verify/Verify/ACAutomaton.test.cpp
- /verify/Verify/ACAutomaton.test.cpp.html
title: Verify/ACAutomaton.test.cpp
---
