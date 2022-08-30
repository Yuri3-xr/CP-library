---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ Template /\
    \ Template.hpp : line -1: no such header\n"
  code: "#pragma once\n\n#include \"../ Template / Template.hpp \"\n\ntemplate <typename\
    \ T>\nstd::pair<int, T> GaussElimination(vector<vector<T>> &a, int pivot_end =\
    \ -1,\n                                   bool diagonalize = false) {\n    int\
    \ H = a.size(), W = a[0].size();\n    int rank = 0, je = pivot_end;\n    if (je\
    \ == -1) je = W;\n    T det = 1;\n    for (int j = 0; j < je; j++) {\n       \
    \ int idx = -1;\n        for (int i = rank; i < H; i++) {\n            if (a[i][j]\
    \ != T(0)) {\n                idx = i;\n                break;\n            }\n\
    \        }\n        if (idx == -1) {\n            det = 0;\n            continue;\n\
    \        }\n        if (rank != idx) {\n            det = -det;\n            swap(a[rank],\
    \ a[idx]);\n        }\n        det *= a[rank][j];\n        if (diagonalize &&\
    \ a[rank][j] != T(1)) {\n            T coeff = a[rank][j].inverse();\n       \
    \     for (int k = j; k < W; k++) a[rank][k] *= coeff;\n        }\n        int\
    \ is = diagonalize ? 0 : rank + 1;\n        for (int i = is; i < H; i++) {\n \
    \           if (i == rank) continue;\n            if (a[i][j] != T(0)) {\n   \
    \             T coeff = a[i][j] / a[rank][j];\n                for (int k = j;\
    \ k < W; k++) a[i][k] -= a[rank][k] * coeff;\n            }\n        }\n     \
    \   rank++;\n    }\n    return make_pair(rank, det);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Matrix/GaussElimination.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Matrix/GaussElimination.hpp
layout: document
redirect_from:
- /library/Matrix/GaussElimination.hpp
- /library/Matrix/GaussElimination.hpp.html
title: Matrix/GaussElimination.hpp
---
