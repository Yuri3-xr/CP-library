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
  bundledCode: "#line 2 \"String/PAM.hpp\"\n\n#line 2 \"Template/Template.hpp\"\n\n\
    #include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 4 \"String/PAM.hpp\"\
    \nstruct PAM {\n    struct node {\n        std::array<int, 26> next;\n       \
    \ int len, fail;\n        node(int L) {\n            next.fill(0);\n         \
    \   len = L;\n            fail = 0;\n        }\n    };\n\n    int last;\n    std::string\
    \ s;\n    std::vector<node> pam;\n    PAM() {\n        last = 0;\n        s =\
    \ \"$\";\n        pam.emplace_back(0);\n        pam.emplace_back(-1);\n      \
    \  pam[0].fail = 1;\n    };\n\n    int getFail(int x) {\n        int tot = s.size()\
    \ - 1;\n        while (s[tot - pam[x].len - 1] != s[tot]) {\n            x = pam[x].fail;\n\
    \        }\n        return x;\n    }\n\n    int insert(char c) {\n        s.push_back(c);\n\
    \        int now = getFail(last);\n        if (pam[now].next[c - 'a'] == 0) {\n\
    \            pam.emplace_back(pam[now].len + 2);\n            pam.back().fail\
    \ = pam[getFail(pam[now].fail)].next[c - 'a'];\n            pam[now].next[c -\
    \ 'a'] = pam.size() - 1;\n        }\n        last = pam[now].next[c - 'a'];\n\n\
    \        return last;\n    }\n\n    std::vector<std::vector<int>> getFailTree()\
    \ {\n        // root at 1 !!!\n        std::vector<std::vector<int>> adj(pam.size());\n\
    \        for (int i = 1; i < pam.size(); i++) {\n            if (pam[i].fail !=\
    \ -1) {\n                adj[i].push_back(pam[i].fail), adj[pam[i].fail].push_back(i);\n\
    \            }\n        }\n        return adj;\n    }\n\n    node& operator[](const\
    \ int x) { return this->pam[x]; }\n    int size() const { return pam.size(); }\n\
    };\n"
  code: "#pragma once\n\n#include \"../Template/Template.hpp\"\nstruct PAM {\n   \
    \ struct node {\n        std::array<int, 26> next;\n        int len, fail;\n \
    \       node(int L) {\n            next.fill(0);\n            len = L;\n     \
    \       fail = 0;\n        }\n    };\n\n    int last;\n    std::string s;\n  \
    \  std::vector<node> pam;\n    PAM() {\n        last = 0;\n        s = \"$\";\n\
    \        pam.emplace_back(0);\n        pam.emplace_back(-1);\n        pam[0].fail\
    \ = 1;\n    };\n\n    int getFail(int x) {\n        int tot = s.size() - 1;\n\
    \        while (s[tot - pam[x].len - 1] != s[tot]) {\n            x = pam[x].fail;\n\
    \        }\n        return x;\n    }\n\n    int insert(char c) {\n        s.push_back(c);\n\
    \        int now = getFail(last);\n        if (pam[now].next[c - 'a'] == 0) {\n\
    \            pam.emplace_back(pam[now].len + 2);\n            pam.back().fail\
    \ = pam[getFail(pam[now].fail)].next[c - 'a'];\n            pam[now].next[c -\
    \ 'a'] = pam.size() - 1;\n        }\n        last = pam[now].next[c - 'a'];\n\n\
    \        return last;\n    }\n\n    std::vector<std::vector<int>> getFailTree()\
    \ {\n        // root at 1 !!!\n        std::vector<std::vector<int>> adj(pam.size());\n\
    \        for (int i = 1; i < pam.size(); i++) {\n            if (pam[i].fail !=\
    \ -1) {\n                adj[i].push_back(pam[i].fail), adj[pam[i].fail].push_back(i);\n\
    \            }\n        }\n        return adj;\n    }\n\n    node& operator[](const\
    \ int x) { return this->pam[x]; }\n    int size() const { return pam.size(); }\n\
    };"
  dependsOn:
  - Template/Template.hpp
  isVerificationFile: false
  path: String/PAM.hpp
  requiredBy: []
  timestamp: '2023-08-05 01:33:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/PAM.hpp
layout: document
redirect_from:
- /library/String/PAM.hpp
- /library/String/PAM.hpp.html
title: String/PAM.hpp
---
