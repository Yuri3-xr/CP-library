---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/MultiplicativeFunctionPSumFast.hpp
    title: Number_Theory/MultiplicativeFunctionPSumFast.hpp
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Prime_Sieve.hpp
    title: Number_Theory/Prime_Sieve.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/LagrangeInterpolation.hpp
    title: Polynomial/LagrangeInterpolation.hpp
  - icon: ':heavy_check_mark:'
    path: Template/Power.hpp
    title: Template/Power.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"Verify/CountingPrimes.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\
    \n\n#line 2 \"Polynomial/LagrangeInterpolation.hpp\"\n\n#line 2 \"Template/Template.hpp\"\
    \n\nusing namespace std;\n\n#include <bits/stdc++.h>\n\nusing i64 = long long;\n\
    using VI = vector<int>;\nusing pii = pair<int, int>;\n#line 4 \"Polynomial/LagrangeInterpolation.hpp\"\
    \ntemplate <typename T>\nT LagrangeInterpolation(const vector<T> &y, long long\
    \ x) {\n    //(0,y[0]),(1,y[1]),...,(N,y[N])\n    int N = (int)y.size() - 1;\n\
    \    if (x <= N) return y[x];\n    T ret = 0;\n    vector<T> dp(N + 1, 1), pd(N\
    \ + 1, 1), finv(N + 1, 0);\n    T a = x, one = 1;\n    finv[N] = T(1);\n    for\
    \ (int i = 1; i <= N; i++) finv[N] *= T(i);\n    finv[N] = finv[N].inverse();\n\
    \    for (int i = N - 1; i >= 0; i--) finv[i] = finv[i + 1] * T(i + 1);\n    for\
    \ (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;\n    for (int i = N;\
    \ i > 0; i--) pd[i - 1] = pd[i] * a, a += one;\n    for (int i = 0; i <= N; i++)\
    \ {\n        T tmp = y[i] * dp[i] * pd[i] * finv[i] * finv[N - i];\n        ret\
    \ += ((N - i) & 1) ? -tmp : tmp;\n    }\n    return ret;\n}\n#line 1 \"Template/Power.hpp\"\
    \ntemplate <class T>\nT power(T a, int b) {\n    T res = 1;\n    for (; b; b /=\
    \ 2, a *= a) {\n        if (b % 2) {\n            res *= a;\n        }\n    }\n\
    \    return res;\n}\n#line 2 \"Number_Theory/Prime_Sieve.hpp\"\n\n#line 4 \"Number_Theory/Prime_Sieve.hpp\"\
    \n\nvector<int> prime_sieve(int N) {\n    vector<bool> sieve(N / 3 + 1, 1);\n\
    \    for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn;\n         p += d =\
    \ 6 - d, i++) {\n        if (!sieve[i]) continue;\n        for (int q = p * p\
    \ / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n                 qe = sieve.size();\n\
    \             q < qe; q += r = s - r)\n            sieve[q] = 0;\n    }\n    vector<int>\
    \ ret{2, 3};\n    for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n\
    \        if (sieve[i]) ret.push_back(p);\n    while (!ret.empty() && ret.back()\
    \ > N) ret.pop_back();\n    return ret;\n}\n#line 6 \"Number_Theory/MultiplicativeFunctionPSumFast.hpp\"\
    \n\ntemplate <typename T, T (*f)(i64, i64)>\nstruct MfPrefixSum {\n    i64 M,\
    \ sq, s;\n    vector<int> p;\n    int ps;\n    vector<T> buf;\n    T ans;\n\n\
    \    MfPrefixSum(i64 m) : M(m) {\n        assert(m < (1LL << 42));\n        sq\
    \ = sqrt(M);\n        while (sq * sq > M) sq--;\n        while ((sq + 1) * (sq\
    \ + 1) <= M) sq++;\n\n        if (M != 0) {\n            i64 hls = md(M, sq);\n\
    \            if (hls != 1 && md(M, hls - 1) == sq) hls--;\n            s = hls\
    \ + sq;\n\n            p = prime_sieve(sq);\n            ps = p.size();\n    \
    \        ans = T{};\n        }\n    }\n    T PSumPower(i64 n, int k) {\n     \
    \   vector<T> now(k + 2);\n        now[0] = T(0);\n        for (int i = 1; i <\
    \ k + 2; i++) {\n            T res = i;\n            now[i] = now[i - 1] + power(res,\
    \ k);\n        }\n        return LagrangeInterpolation<T>(now, n);\n    }\n  \
    \  vector<T> pi_table() {\n        //\\sum_{p\\in prime \\and p\\leq m} p^0\n\
    \        if (M == 0) return {};\n        i64 hls = md(M, sq);\n        if (hls\
    \ != 1 && md(M, hls - 1) == sq) hls--;\n\n        vector<i64> hl(hls);\n     \
    \   for (int i = 1; i < hls; i++) hl[i] = md(M, i) - 1;\n\n        vector<int>\
    \ hs(sq + 1);\n        iota(begin(hs), end(hs), -1);\n\n        int pi = 0;\n\
    \        for (auto &x : p) {\n            i64 x2 = i64(x) * x;\n            i64\
    \ imax = min<i64>(hls, md(M, x2) + 1);\n            for (i64 i = 1, ix = x; i\
    \ < imax; ++i, ix += x) {\n                hl[i] -= (ix < hls ? hl[ix] : hs[md(M,\
    \ ix)]) - pi;\n            }\n            for (int n = sq; n >= x2; n--) hs[n]\
    \ -= hs[md(n, x)] - pi;\n            pi++;\n        }\n\n        vector<T> res;\n\
    \        res.reserve(2 * sq + 10);\n        for (auto &x : hl) res.push_back(x);\n\
    \        for (int i = hs.size(); --i;) res.push_back(hs[i]);\n        assert((int)res.size()\
    \ == s);\n        return res;\n    }\n    vector<T> prime_sum_table(int k) {\n\
    \        //\\sum_{p\\in prime \\and p\\leq m} p^k\n        if (M == 0) return\
    \ {};\n        i64 hls = md(M, sq);\n        if (hls != 1 && md(M, hls - 1) ==\
    \ sq) hls--;\n\n        vector<T> h(s);\n        T inv2 = T{2}.inverse();\n  \
    \      for (int i = 1; i < hls; i++) {\n            T x = md(M, i);\n        \
    \    h[i] = PSumPower(x.get(), k) - 1;\n        }\n        for (int i = 1; i <=\
    \ sq; i++) {\n            T x = i;\n            h[s - i] = PSumPower(x.get(),\
    \ k) - 1;\n        }\n\n        for (auto &x : p) {\n            T xt = x;\n \
    \           xt = power(xt, k);\n            T pi = h[s - x + 1];\n           \
    \ i64 x2 = i64(x) * x;\n            i64 imax = min<i64>(hls, md(M, x2) + 1);\n\
    \            i64 ix = x;\n            for (i64 i = 1; i < imax; ++i, ix += x)\
    \ {\n                h[i] -= ((ix < hls ? h[ix] : h[s - md(M, ix)]) - pi) * xt;\n\
    \            }\n            for (int n = sq; n >= x2; n--) {\n               \
    \ h[s - n] -= (h[s - md(n, x)] - pi) * xt;\n            }\n        }\n\n     \
    \   assert((int)h.size() == s);\n        return h;\n    }\n\n    void dfs(int\
    \ i, int c, i64 prod, T cur) {\n        ans += cur * f(p[i], c + 1);\n       \
    \ i64 lim = md(M, prod);\n        if (lim >= 1LL * p[i] * p[i]) dfs(i, c + 1,\
    \ p[i] * prod, cur);\n        cur *= f(p[i], c);\n        ans += cur * (buf[idx(lim)]\
    \ - buf[idx(p[i])]);\n        int j = i + 1;\n        // M < 2**42 -> p_j < 2**21\
    \ -> (p_j)^3 < 2**63\n        for (; j < ps && 1LL * p[j] * p[j] * p[j] <= lim;\
    \ j++) {\n            dfs(j, 1, prod * p[j], cur);\n        }\n        for (;\
    \ j < ps && 1LL * p[j] * p[j] <= lim; j++) {\n            T sm = f(p[j], 2);\n\
    \            int id1 = idx(md(lim, p[j])), id2 = idx(p[j]);\n            sm +=\
    \ f(p[j], 1) * (buf[id1] - buf[id2]);\n            ans += cur * sm;\n        }\n\
    \    }\n\n    T run(vector<T> &fprime) {\n        if (M == 0) return {};\n   \
    \     set_buf(fprime);\n        assert((int)buf.size() == s);\n        ans = buf[idx(M)]\
    \ + 1;\n        for (int i = 0; i < ps; i++) dfs(i, 1, p[i], 1);\n        return\
    \ ans;\n    }\n\n   private:\n    i64 md(i64 n, i64 d) { return double(n) / d;\
    \ }\n    i64 idx(i64 n) { return n <= sq ? s - n : md(M, n); }\n    void set_buf(vector<T>\
    \ &_buf) { swap(buf, _buf); }\n};\n#line 4 \"Verify/CountingPrimes.test.cpp\"\n\
    i64 f(i64 p, i64 c) { return 1; }\nint main() {\n    i64 n;\n    cin >> n;\n \
    \   MfPrefixSum<i64, f> mf(n);\n    auto now = mf.pi_table();\n    cout << now[1]\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ \"../Number_Theory/MultiplicativeFunctionPSumFast.hpp\"\ni64 f(i64 p, i64 c)\
    \ { return 1; }\nint main() {\n    i64 n;\n    cin >> n;\n    MfPrefixSum<i64,\
    \ f> mf(n);\n    auto now = mf.pi_table();\n    cout << now[1] << endl;\n}"
  dependsOn:
  - Number_Theory/MultiplicativeFunctionPSumFast.hpp
  - Polynomial/LagrangeInterpolation.hpp
  - Template/Template.hpp
  - Template/Power.hpp
  - Number_Theory/Prime_Sieve.hpp
  isVerificationFile: true
  path: Verify/CountingPrimes.test.cpp
  requiredBy: []
  timestamp: '2022-10-17 18:12:23+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/CountingPrimes.test.cpp
layout: document
redirect_from:
- /verify/Verify/CountingPrimes.test.cpp
- /verify/Verify/CountingPrimes.test.cpp.html
title: Verify/CountingPrimes.test.cpp
---