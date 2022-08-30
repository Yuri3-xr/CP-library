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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../ Template /\
    \ Template.hpp : line -1: no such header\n"
  code: "#pragma once\n#include \"GaussElimination.hpp\"\n#include \"LinearEquation.hpp\"\
    \n\ntemplate <class T>\nvector<vector<T>> Adjugate_Matrix(vector<vector<T>> x)\
    \ {\n    int N = x.size();\n    assert(N > 0);\n    assert(N == (int)x[0].size());\n\
    \n    vector<vector<T>> m(N, vector<T>(2 * N));\n    for (int i = 0; i < N; i++)\
    \ {\n        copy(begin(x[i]), end(x[i]), begin(m[i]));\n        m[i][N + i] =\
    \ 1;\n    }\n    int rank;\n    auto GE = GaussElimination(m, N, true);\n    rank\
    \ = GE.first;\n    if (rank <= N - 2) {\n        return vector<vector<T>>(N, vector<T>(N,\
    \ 0));\n    }\n    if (rank == N) {\n        T det = GaussElimination(x).second;\n\
    \        vector<vector<T>> b(N);\n        for (int i = 0; i < N; i++) {\n    \
    \        copy(begin(m[i]) + N, end(m[i]), back_inserter(b[i]));\n        }\n \
    \       for (int i = 0; i < N; i++) {\n            for (int j = 0; j < N; j++)\
    \ {\n                b[i][j] *= det;\n            }\n        }\n        for (int\
    \ i = 0; i < N; i++) {\n            for (int j = i + 1; j < N; j++) swap(b[i][j],\
    \ b[j][i]);\n        }\n        return b;\n    }\n    auto xt = x;\n    for (int\
    \ i = 0; i < N; i++)\n        for (int j = i + 1; j < N; j++) swap(xt[i][j], xt[j][i]);\n\
    \n    auto ps = LinearEquation<T>(xt, vector<T>(N, 0));\n    auto qs = LinearEquation<T>(x,\
    \ vector<T>(N, 0));\n    vector<T> p, q;\n    int r(0), c(0);\n    for (int i\
    \ = 0; i < ps.size(); i++) {\n        for (int j = 0; j < N; j++) {\n        \
    \    if (ps[i][j].get() != 0) {\n                p = ps[i];\n                r\
    \ = j;\n            }\n        }\n    }\n    for (int i = 0; i < qs.size(); i++)\
    \ {\n        for (int j = 0; j < N; j++) {\n            if (qs[i][j].get() !=\
    \ 0) {\n                q = qs[i];\n                c = j;\n            }\n  \
    \      }\n    }\n\n    assert(p[r].get() != 0 && q[c].get() != 0);\n\n    vector<vector<T>>\
    \ b(N, vector<T>(N));\n    vector<vector<T>> t;\n    for (int i = 0; i < N; i++)\
    \ {\n        if (i == r) continue;\n        vector<T> res;\n        for (int j\
    \ = 0; j < N; j++)\n            if (j != c) res.push_back(x[i][j]);\n        t.push_back(res);\n\
    \    }\n\n    auto tdet = GaussElimination(t).second;\n\n    b[r][c] = ((r + c)\
    \ & 1) ? -tdet : tdet;\n    for (int i = 0; i < N; i++)\n        for (int j =\
    \ 0; j < N; j++) {\n            b[i][j] = p[i] * q[j] / (p[r] * q[c]) * b[r][c];\n\
    \        }\n\n    return b;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Matrix/Adjugate_matrix.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Matrix/Adjugate_matrix.hpp
layout: document
redirect_from:
- /library/Matrix/Adjugate_matrix.hpp
- /library/Matrix/Adjugate_matrix.hpp.html
title: Matrix/Adjugate_matrix.hpp
---
