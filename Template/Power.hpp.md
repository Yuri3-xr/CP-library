---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Number_Theory/MultiplicativeFunctionPSumFast.hpp
    title: Number_Theory/MultiplicativeFunctionPSumFast.hpp
  - icon: ':x:'
    path: Polynomial/CoeffofRationalFunction.hpp
    title: Polynomial/CoeffofRationalFunction.hpp
  - icon: ':warning:'
    path: Polynomial/Factorial.hpp
    title: Polynomial/Factorial.hpp
  - icon: ':x:'
    path: Polynomial/LinearlyRecurrent.hpp
    title: Polynomial/LinearlyRecurrent.hpp
  - icon: ':x:'
    path: Polynomial/Ntt.hpp
    title: Polynomial/Ntt.hpp
  - icon: ':x:'
    path: Polynomial/Poly.hpp
    title: Polynomial/Poly.hpp
  - icon: ':warning:'
    path: Polynomial/PrefixSumBinomial.hpp
    title: Polynomial/PrefixSumBinomial.hpp
  - icon: ':warning:'
    path: Polynomial/PrefixSumH.hpp
    title: Polynomial/PrefixSumH.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/CountingPrimes.test.cpp
    title: Verify/CountingPrimes.test.cpp
  - icon: ':x:'
    path: Verify/InvofFormalPowerSeries.test.cpp
    title: Verify/InvofFormalPowerSeries.test.cpp
  - icon: ':x:'
    path: Verify/KthtermofLinearlyRecurrentSequence.test.cpp
    title: Verify/KthtermofLinearlyRecurrentSequence.test.cpp
  - icon: ':x:'
    path: Verify/Multipoint_Evaluation.test.cpp
    title: Verify/Multipoint_Evaluation.test.cpp
  - icon: ':x:'
    path: Verify/Polynomial_Interpolation.test.cpp
    title: Verify/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/SumofTotientFunction2.test.cpp
    title: Verify/SumofTotientFunction2.test.cpp
  - icon: ':x:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Template/Power.hpp\"\ntemplate <class T>\nT power(T a, int\
    \ b) {\n    T res = 1;\n    for (; b; b /= 2, a *= a) {\n        if (b % 2) {\n\
    \            res *= a;\n        }\n    }\n    return res;\n}\n"
  code: "template <class T>\nT power(T a, int b) {\n    T res = 1;\n    for (; b;\
    \ b /= 2, a *= a) {\n        if (b % 2) {\n            res *= a;\n        }\n\
    \    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Template/Power.hpp
  requiredBy:
  - Number_Theory/MultiplicativeFunctionPSumFast.hpp
  - Polynomial/Poly.hpp
  - Polynomial/PrefixSumBinomial.hpp
  - Polynomial/CoeffofRationalFunction.hpp
  - Polynomial/Factorial.hpp
  - Polynomial/LinearlyRecurrent.hpp
  - Polynomial/Ntt.hpp
  - Polynomial/PrefixSumH.hpp
  timestamp: '2022-08-20 01:45:54+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/InvofFormalPowerSeries.test.cpp
  - Verify/SumofTotientFunction2.test.cpp
  - Verify/Multipoint_Evaluation.test.cpp
  - Verify/convolution.test.cpp
  - Verify/CountingPrimes.test.cpp
  - Verify/Polynomial_Interpolation.test.cpp
  - Verify/KthtermofLinearlyRecurrentSequence.test.cpp
documentation_of: Template/Power.hpp
layout: document
redirect_from:
- /library/Template/Power.hpp
- /library/Template/Power.hpp.html
title: Template/Power.hpp
---
