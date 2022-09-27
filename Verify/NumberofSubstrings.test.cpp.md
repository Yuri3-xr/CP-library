---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/RMQ.hpp
    title: DataStructure/RMQ.hpp
  - icon: ':question:'
    path: String/SuffixArray.hpp
    title: String/SuffixArray.hpp
  - icon: ':question:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"Verify/NumberofSubstrings.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\nusing i64 = long long;\n\
    using VI = vector<int>;\nusing pii = pair<int, int>;\n#line 3 \"DataStructure/RMQ.hpp\"\
    \n\ntemplate <class T, class Cmp = less<T>>\nstruct RMQ {\n    const int n;\n\
    \    const Cmp cmp;\n    vector<vector<T>> a;\n    RMQ(const vector<T> &init)\
    \ : n(init.size()), cmp(Cmp()) {\n        int lg = __lg(n);\n        a.assign(lg\
    \ + 1, vector<T>(n));\n        for (int j = 0; j <= lg; j++) {\n            for\
    \ (int i = 0; i + (1 << j) <= n; i++) {\n                a[j][i] = (j == 0 ? init[i]\n\
    \                                  : min(a[j - 1][i],\n                      \
    \                  a[j - 1][i + (1 << (j - 1))], cmp));\n            }\n     \
    \   }\n    }\n    T rangeMin(int l, int r) {\n        int k = __lg(r - l);\n \
    \       return min(a[k][l], a[k][r - (1 << k)], cmp);\n    }\n};\n#line 4 \"String/SuffixArray.hpp\"\
    \n\nstruct SuffixArray {\n    int n;\n    vector<int> sa, rk, lc;\n    RMQ<int>\
    \ *rmq;\n    SuffixArray(const string &s) : rmq(nullptr) {\n        n = s.length();\n\
    \        sa.resize(n);\n        lc.resize(n - 1);\n        rk.resize(n);\n   \
    \     iota(sa.begin(), sa.end(), 0);\n        sort(sa.begin(), sa.end(), [&](int\
    \ a, int b) { return s[a] < s[b]; });\n        rk[sa[0]] = 0;\n        for (int\
    \ i = 1; i < n; ++i)\n            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i\
    \ - 1]]);\n        int k = 1;\n        vector<int> tmp, cnt(n);\n        tmp.reserve(n);\n\
    \        while (rk[sa[n - 1]] < n - 1) {\n            tmp.clear();\n         \
    \   for (int i = 0; i < k; ++i) tmp.push_back(n - k + i);\n            for (auto\
    \ i : sa)\n                if (i >= k) tmp.push_back(i - k);\n            fill(cnt.begin(),\
    \ cnt.end(), 0);\n            for (int i = 0; i < n; ++i) ++cnt[rk[i]];\n    \
    \        for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];\n            for (int\
    \ i = n - 1; i >= 0; --i) sa[--cnt[rk[tmp[i]]]] = tmp[i];\n            swap(rk,\
    \ tmp);\n            rk[sa[0]] = 0;\n            for (int i = 1; i < n; ++i)\n\
    \                rk[sa[i]] =\n                    rk[sa[i - 1]] + (tmp[sa[i -\
    \ 1]] < tmp[sa[i]] ||\n                                     sa[i - 1] + k == n\
    \ ||\n                                     tmp[sa[i - 1] + k] < tmp[sa[i] + k]);\n\
    \            k *= 2;\n        }\n        for (int i = 0, j = 0; i < n; ++i) {\n\
    \            if (rk[i] == 0) {\n                j = 0;\n            } else {\n\
    \                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n &&\n    \
    \                             s[i + j] == s[sa[rk[i] - 1] + j];)\n           \
    \         ++j;\n                lc[rk[i] - 1] = j;\n            }\n        }\n\
    \        if (n > 1) {\n            rmq = new RMQ(lc);\n        }\n    }\n    ~SuffixArray()\
    \ {\n        if (rmq) {\n            delete rmq;\n        }\n    }\n    int lcp(int\
    \ x, int y) {\n        if (x == n || y == n) {\n            return 0;\n      \
    \  }\n        if (x == y) {\n            return n - x;\n        }\n        x =\
    \ rk[x];\n        y = rk[y];\n        if (x > y) {\n            swap(x, y);\n\
    \        }\n        return rmq->rangeMin(x, y);\n    }\n};\n#line 5 \"Verify/NumberofSubstrings.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    string s;\n    cin >> s;\n    SuffixArray SA(s);\n\n    i64 ans = (SA.n +\
    \ 1) * (SA.n) / 2;\n    for (int i = 0; i < SA.n - 1; i++) {\n        ans -= SA.lc[i];\n\
    \    }\n\n    cout << ans << '\\n';\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include \"../String/SuffixArray.hpp\"\n#include \"../Template/Template.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    string s;\n    cin >> s;\n    SuffixArray SA(s);\n\n    i64 ans = (SA.n +\
    \ 1) * (SA.n) / 2;\n    for (int i = 0; i < SA.n - 1; i++) {\n        ans -= SA.lc[i];\n\
    \    }\n\n    cout << ans << '\\n';\n\n    return 0;\n}"
  dependsOn:
  - String/SuffixArray.hpp
  - DataStructure/RMQ.hpp
  - Template/Template.hpp
  isVerificationFile: true
  path: Verify/NumberofSubstrings.test.cpp
  requiredBy: []
  timestamp: '2022-09-27 10:55:07+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/NumberofSubstrings.test.cpp
layout: document
redirect_from:
- /verify/Verify/NumberofSubstrings.test.cpp
- /verify/Verify/NumberofSubstrings.test.cpp.html
title: Verify/NumberofSubstrings.test.cpp
---