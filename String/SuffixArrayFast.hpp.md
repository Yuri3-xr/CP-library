---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ.hpp
    title: DataStructure/RMQ.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Template.hpp
    title: Template/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/NumberofSubstrings.test.cpp
    title: Verify/NumberofSubstrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/SuffixArrayFast.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nusing i64 = std::int64_t;\n#line 3 \"DataStructure/RMQ.hpp\"\
    \n\ntemplate <class T, class Cmp = std::less<T>>\nstruct RMQ {\n    const int\
    \ n;\n    const Cmp cmp;\n    std::vector<std::vector<T>> a;\n    RMQ(const std::vector<T>\
    \ &init) : n(init.size()), cmp(Cmp()) {\n        int lg = std::__lg(n);\n    \
    \    a.assign(lg + 1, std::vector<T>(n));\n        for (int j = 0; j <= lg; j++)\
    \ {\n            for (int i = 0; i + (1 << j) <= n; i++) {\n                a[j][i]\
    \ =\n                    (j == 0 ? init[i]\n                            : std::min(a[j\
    \ - 1][i],\n                                       a[j - 1][i + (1 << (j - 1))],\
    \ cmp));\n            }\n        }\n    }\n    T rangeMin(int l, int r) {\n  \
    \      int k = std::__lg(r - l);\n        return std::min(a[k][l], a[k][r - (1\
    \ << k)], cmp);\n    }\n};\n#line 5 \"String/SuffixArrayFast.hpp\"\n\ntemplate\
    \ <class T>\nstruct SuffixArrayFast {\n    int n;\n    std::vector<int> sa, rk,\
    \ lc;\n    RMQ<int> *rmq;\n\n    std::vector<int> sa_is(const std::vector<int>\
    \ &s) const {\n        const int n = (int)s.size();\n        std::vector<int>\
    \ ret(n);\n\n        std::vector<int> is_s(n), is_lms(n);\n        int m = 0;\n\
    \        for (int i = n - 2; i >= 0; i--) {\n            is_s[i] = (s[i] > s[i\
    \ + 1]) or (s[i] == s[i + 1] and is_s[i + 1]);\n            m += (is_lms[i + 1]\
    \ = is_s[i] and not is_s[i + 1]);\n        }\n\n        auto induced_sort = [&](const\
    \ std::vector<int> &lms) {\n            int upper = *(std::max_element(s.begin(),\
    \ s.end()));\n            std::vector<int> l(upper + 2), r(upper + 2);\n     \
    \       for (auto &&v : s) {\n                ++l[v + 1];\n                ++r[v];\n\
    \            }\n            std::partial_sum(l.begin(), l.end(), l.begin());\n\
    \            std::partial_sum(r.begin(), r.end(), r.begin());\n            std::fill(ret.begin(),\
    \ ret.end(), -1);\n            for (int i = (int)lms.size() - 1; i >= 0; i--)\
    \ {\n                ret[--r[s[lms[i]]]] = lms[i];\n            }\n          \
    \  for (auto &&v : ret) {\n                if (v >= 1 and is_s[v - 1]) ret[l[s[v\
    \ - 1]]++] = v - 1;\n            }\n            std::fill(r.begin(), r.end(),\
    \ 0);\n            for (auto &&v : s) ++r[v];\n            std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n            for (int k = (int)ret.size() - 1, i = ret[k];\
    \ k >= 1;\n                 i = ret[--k]) {\n                if (i >= 1 and not\
    \ is_s[i - 1]) {\n                    ret[--r[s[i - 1]]] = i - 1;\n          \
    \      }\n            }\n        };\n\n        std::vector<int> lms;\n       \
    \ lms.reserve(m);\n        for (int i = 1; i < n; i++) {\n            if (is_lms[i])\
    \ lms.push_back(i);\n        }\n\n        induced_sort(lms);\n\n        std::vector<int>\
    \ new_lms;\n        new_lms.reserve(m);\n        for (int i = 0; i < n; i++) {\n\
    \            if (not is_s[ret[i]] and ret[i] > 0 and is_s[ret[i] - 1]) {\n   \
    \             new_lms.push_back(ret[i]);\n            }\n        }\n\n       \
    \ auto is_same = [&](int a, int b) {\n            if (s[a++] != s[b++]) return\
    \ false;\n            for (;; ++a, ++b) {\n                if (s[a] != s[b]) return\
    \ false;\n                if (is_lms[a] or is_lms[b]) return is_lms[a] and is_lms[b];\n\
    \            }\n        };\n\n        int rank = 0;\n        ret[n - 1] = 0;\n\
    \        for (int i = 1; i < m; i++) {\n            if (not is_same(new_lms[i\
    \ - 1], new_lms[i])) ++rank;\n            ret[new_lms[i]] = rank;\n        }\n\
    \n        if (rank + 1 < m) {\n            std::vector<int> new_s(m);\n      \
    \      for (int i = 0; i < m; i++) {\n                new_s[i] = ret[lms[i]];\n\
    \            }\n            auto lms_sa = sa_is(new_s);\n            for (int\
    \ i = 0; i < m; i++) {\n                new_lms[i] = lms[lms_sa[i]];\n       \
    \     }\n        }\n\n        induced_sort(new_lms);\n\n        return ret;\n\
    \    }\n\n    SuffixArrayFast(const T &vs, bool compress = false) : rmq(nullptr)\
    \ {\n        std::vector<int> new_vs(vs.size() + 1);\n        if (compress) {\n\
    \            T xs = vs;\n            std::sort(xs.begin(), xs.end());\n      \
    \      xs.erase(unique(xs.begin(), xs.end()), xs.end());\n            for (int\
    \ i = 0; i < (int)vs.size(); i++) {\n                new_vs[i] = std::lower_bound(xs.begin(),\
    \ xs.end(), vs[i]) -\n                            xs.begin() + 1;\n          \
    \  }\n        } else {\n            auto d = *(std::min_element(vs.begin(), vs.end()));\n\
    \            for (int i = 0; i < (int)vs.size(); i++) {\n                new_vs[i]\
    \ = vs[i] - d + 1;\n            }\n        }\n        auto res = sa_is(new_vs);\n\
    \        sa.assign(begin(res) + 1, end(res));\n        n = sa.size();\n      \
    \  rk.resize(n);\n        lc.resize(n - 1);\n        for (int i = 0; i < n; i++)\
    \ {\n            rk[sa[i]] = i;\n        }\n        for (int i = 0, j = 0; i <\
    \ n; ++i) {\n            if (rk[i] == 0) {\n                j = 0;\n         \
    \   } else {\n                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j\
    \ < n &&\n                                 vs[i + j] == vs[sa[rk[i] - 1] + j];)\n\
    \                    ++j;\n                lc[rk[i] - 1] = j;\n            }\n\
    \        }\n        if (n > 1) {\n            rmq = new RMQ(lc);\n        }\n\
    \    }\n    ~SuffixArrayFast() {\n        if (rmq) {\n            delete rmq;\n\
    \        }\n    }\n    int lcp(int x, int y) {\n        if (x == n || y == n)\
    \ {\n            return 0;\n        }\n        if (x == y) {\n            return\
    \ n - x;\n        }\n        x = rk[x];\n        y = rk[y];\n        if (x > y)\
    \ {\n            std::swap(x, y);\n        }\n        return rmq->rangeMin(x,\
    \ y);\n    }\n};\n"
  code: "#pragma once\n\n#include \"../DataStructure/RMQ.hpp\"\n#include \"../Template/Template.hpp\"\
    \n\ntemplate <class T>\nstruct SuffixArrayFast {\n    int n;\n    std::vector<int>\
    \ sa, rk, lc;\n    RMQ<int> *rmq;\n\n    std::vector<int> sa_is(const std::vector<int>\
    \ &s) const {\n        const int n = (int)s.size();\n        std::vector<int>\
    \ ret(n);\n\n        std::vector<int> is_s(n), is_lms(n);\n        int m = 0;\n\
    \        for (int i = n - 2; i >= 0; i--) {\n            is_s[i] = (s[i] > s[i\
    \ + 1]) or (s[i] == s[i + 1] and is_s[i + 1]);\n            m += (is_lms[i + 1]\
    \ = is_s[i] and not is_s[i + 1]);\n        }\n\n        auto induced_sort = [&](const\
    \ std::vector<int> &lms) {\n            int upper = *(std::max_element(s.begin(),\
    \ s.end()));\n            std::vector<int> l(upper + 2), r(upper + 2);\n     \
    \       for (auto &&v : s) {\n                ++l[v + 1];\n                ++r[v];\n\
    \            }\n            std::partial_sum(l.begin(), l.end(), l.begin());\n\
    \            std::partial_sum(r.begin(), r.end(), r.begin());\n            std::fill(ret.begin(),\
    \ ret.end(), -1);\n            for (int i = (int)lms.size() - 1; i >= 0; i--)\
    \ {\n                ret[--r[s[lms[i]]]] = lms[i];\n            }\n          \
    \  for (auto &&v : ret) {\n                if (v >= 1 and is_s[v - 1]) ret[l[s[v\
    \ - 1]]++] = v - 1;\n            }\n            std::fill(r.begin(), r.end(),\
    \ 0);\n            for (auto &&v : s) ++r[v];\n            std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n            for (int k = (int)ret.size() - 1, i = ret[k];\
    \ k >= 1;\n                 i = ret[--k]) {\n                if (i >= 1 and not\
    \ is_s[i - 1]) {\n                    ret[--r[s[i - 1]]] = i - 1;\n          \
    \      }\n            }\n        };\n\n        std::vector<int> lms;\n       \
    \ lms.reserve(m);\n        for (int i = 1; i < n; i++) {\n            if (is_lms[i])\
    \ lms.push_back(i);\n        }\n\n        induced_sort(lms);\n\n        std::vector<int>\
    \ new_lms;\n        new_lms.reserve(m);\n        for (int i = 0; i < n; i++) {\n\
    \            if (not is_s[ret[i]] and ret[i] > 0 and is_s[ret[i] - 1]) {\n   \
    \             new_lms.push_back(ret[i]);\n            }\n        }\n\n       \
    \ auto is_same = [&](int a, int b) {\n            if (s[a++] != s[b++]) return\
    \ false;\n            for (;; ++a, ++b) {\n                if (s[a] != s[b]) return\
    \ false;\n                if (is_lms[a] or is_lms[b]) return is_lms[a] and is_lms[b];\n\
    \            }\n        };\n\n        int rank = 0;\n        ret[n - 1] = 0;\n\
    \        for (int i = 1; i < m; i++) {\n            if (not is_same(new_lms[i\
    \ - 1], new_lms[i])) ++rank;\n            ret[new_lms[i]] = rank;\n        }\n\
    \n        if (rank + 1 < m) {\n            std::vector<int> new_s(m);\n      \
    \      for (int i = 0; i < m; i++) {\n                new_s[i] = ret[lms[i]];\n\
    \            }\n            auto lms_sa = sa_is(new_s);\n            for (int\
    \ i = 0; i < m; i++) {\n                new_lms[i] = lms[lms_sa[i]];\n       \
    \     }\n        }\n\n        induced_sort(new_lms);\n\n        return ret;\n\
    \    }\n\n    SuffixArrayFast(const T &vs, bool compress = false) : rmq(nullptr)\
    \ {\n        std::vector<int> new_vs(vs.size() + 1);\n        if (compress) {\n\
    \            T xs = vs;\n            std::sort(xs.begin(), xs.end());\n      \
    \      xs.erase(unique(xs.begin(), xs.end()), xs.end());\n            for (int\
    \ i = 0; i < (int)vs.size(); i++) {\n                new_vs[i] = std::lower_bound(xs.begin(),\
    \ xs.end(), vs[i]) -\n                            xs.begin() + 1;\n          \
    \  }\n        } else {\n            auto d = *(std::min_element(vs.begin(), vs.end()));\n\
    \            for (int i = 0; i < (int)vs.size(); i++) {\n                new_vs[i]\
    \ = vs[i] - d + 1;\n            }\n        }\n        auto res = sa_is(new_vs);\n\
    \        sa.assign(begin(res) + 1, end(res));\n        n = sa.size();\n      \
    \  rk.resize(n);\n        lc.resize(n - 1);\n        for (int i = 0; i < n; i++)\
    \ {\n            rk[sa[i]] = i;\n        }\n        for (int i = 0, j = 0; i <\
    \ n; ++i) {\n            if (rk[i] == 0) {\n                j = 0;\n         \
    \   } else {\n                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j\
    \ < n &&\n                                 vs[i + j] == vs[sa[rk[i] - 1] + j];)\n\
    \                    ++j;\n                lc[rk[i] - 1] = j;\n            }\n\
    \        }\n        if (n > 1) {\n            rmq = new RMQ(lc);\n        }\n\
    \    }\n    ~SuffixArrayFast() {\n        if (rmq) {\n            delete rmq;\n\
    \        }\n    }\n    int lcp(int x, int y) {\n        if (x == n || y == n)\
    \ {\n            return 0;\n        }\n        if (x == y) {\n            return\
    \ n - x;\n        }\n        x = rk[x];\n        y = rk[y];\n        if (x > y)\
    \ {\n            std::swap(x, y);\n        }\n        return rmq->rangeMin(x,\
    \ y);\n    }\n};"
  dependsOn:
  - DataStructure/RMQ.hpp
  - Template/Template.hpp
  isVerificationFile: false
  path: String/SuffixArrayFast.hpp
  requiredBy: []
  timestamp: '2023-02-11 22:28:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/NumberofSubstrings.test.cpp
documentation_of: String/SuffixArrayFast.hpp
layout: document
redirect_from:
- /library/String/SuffixArrayFast.hpp
- /library/String/SuffixArrayFast.hpp.html
title: String/SuffixArrayFast.hpp
---
