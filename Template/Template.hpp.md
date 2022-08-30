---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/Minkowski_Sum.hpp
    title: Geometry/Minkowski_Sum.hpp
  - icon: ':warning:'
    path: Matrix/Adjugate_matrix.hpp
    title: Matrix/Adjugate_matrix.hpp
  - icon: ':warning:'
    path: Matrix/GaussElimination.hpp
    title: Matrix/GaussElimination.hpp
  - icon: ':warning:'
    path: Matrix/LinearEquation.hpp
    title: Matrix/LinearEquation.hpp
  - icon: ':heavy_check_mark:'
    path: ModInt/Modint32.hpp
    title: ModInt/Modint32.hpp
  - icon: ':warning:'
    path: Polynomial/Factorial.hpp
    title: Polynomial/Factorial.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/Ntt.hpp
    title: Polynomial/Ntt.hpp
  - icon: ':heavy_check_mark:'
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
    path: Verify/Multipoint_Evaluation.test.cpp
    title: Verify/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Polynomial_Interpolation.test.cpp
    title: Verify/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "Template/Template.hpp"


    using namespace std;


    #include <bits/stdc++.h>


    using i64 = long long;

    using VI = vector<int>;

    using pii = pair<int, int>;

    '
  code: '#pragma once


    using namespace std;


    #include <bits/stdc++.h>


    using i64 = long long;

    using VI = vector<int>;

    using pii = pair<int, int>;

    '
  dependsOn: []
  isVerificationFile: false
  path: Template/Template.hpp
  requiredBy:
  - Geometry/Minkowski_Sum.hpp
  - ModInt/Modint32.hpp
  - Matrix/GaussElimination.hpp
  - Matrix/LinearEquation.hpp
  - Matrix/Adjugate_matrix.hpp
  - Polynomial/PrefixSumBinomial.hpp
  - Polynomial/PrefixSumH.hpp
  - Polynomial/Poly.hpp
  - Polynomial/Ntt.hpp
  - Polynomial/Factorial.hpp
  timestamp: '2022-08-16 22:05:54+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/convolution.test.cpp
  - Verify/Multipoint_Evaluation.test.cpp
  - Verify/Polynomial_Interpolation.test.cpp
documentation_of: Template/Template.hpp
layout: document
redirect_from:
- /library/Template/Template.hpp
- /library/Template/Template.hpp.html
title: Template/Template.hpp
---