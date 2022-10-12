---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.hpp
    title: DataStructure/LazySegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ.hpp
    title: DataStructure/RMQ.hpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: DataStructure/SegmentTree.hpp
  - icon: ':warning:'
    path: Geometry/Minkowski_Sum.hpp
    title: Geometry/Minkowski_Sum.hpp
  - icon: ':warning:'
    path: Matrix/AdjugateMatrix.hpp
    title: Matrix/AdjugateMatrix.hpp
  - icon: ':warning:'
    path: Matrix/GaussElimination.hpp
    title: Matrix/GaussElimination.hpp
  - icon: ':warning:'
    path: Matrix/LinearEquation.hpp
    title: Matrix/LinearEquation.hpp
  - icon: ':heavy_check_mark:'
    path: ModInt/Modint32.hpp
    title: ModInt/Modint32.hpp
  - icon: ':heavy_check_mark:'
    path: ModInt/Modint32_change.hpp
    title: ModInt/Modint32_change.hpp
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Factorization.hpp
    title: Number_Theory/Factorization.hpp
  - icon: ':warning:'
    path: Number_Theory/Gauss-Integer.hpp
    title: Number_Theory/Gauss-Integer.hpp
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Mf_Sieve.hpp
    title: Number_Theory/Mf_Sieve.hpp
  - icon: ':heavy_check_mark:'
    path: Number_Theory/Prime_Sieve.hpp
    title: Number_Theory/Prime_Sieve.hpp
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
  - icon: ':x:'
    path: String/ACAutomaton.hpp
    title: String/ACAutomaton.hpp
  - icon: ':heavy_check_mark:'
    path: String/SuffixArray.hpp
    title: String/SuffixArray.hpp
  - icon: ':heavy_check_mark:'
    path: String/SuffixArrayFast.hpp
    title: String/SuffixArrayFast.hpp
  - icon: ':x:'
    path: String/Trie.hpp
    title: String/Trie.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/ACAutomaton.test.cpp
    title: Verify/ACAutomaton.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Factorize.test.cpp
    title: Verify/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/InvofFormalPowerSeries.test.cpp
    title: Verify/InvofFormalPowerSeries.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Multipoint_Evaluation.test.cpp
    title: Verify/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/NumberofSubstrings.test.cpp
    title: Verify/NumberofSubstrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/PointAddRangeSum.test.cpp
    title: Verify/PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Polynomial_Interpolation.test.cpp
    title: Verify/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/RangeAffineRangeSum.test.cpp
    title: Verify/RangeAffineRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/StaticRMQ.test.cpp
    title: Verify/StaticRMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/SuffixArray.test.cpp
    title: Verify/SuffixArray.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/Sum_of_Totient_Function.test.cpp
    title: Verify/Sum_of_Totient_Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/convolution.test.cpp
    title: Verify/convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - ModInt/Modint32_change.hpp
  - Polynomial/Factorial.hpp
  - Polynomial/Ntt.hpp
  - Polynomial/Poly.hpp
  - Polynomial/PrefixSumBinomial.hpp
  - Polynomial/PrefixSumH.hpp
  - String/SuffixArray.hpp
  - String/Trie.hpp
  - String/ACAutomaton.hpp
  - String/SuffixArrayFast.hpp
  - DataStructure/LazySegmentTree.hpp
  - DataStructure/RMQ.hpp
  - DataStructure/SegmentTree.hpp
  - Number_Theory/Factorization.hpp
  - Number_Theory/Mf_Sieve.hpp
  - Number_Theory/Gauss-Integer.hpp
  - Number_Theory/Prime_Sieve.hpp
  - Matrix/LinearEquation.hpp
  - Matrix/AdjugateMatrix.hpp
  - Matrix/GaussElimination.hpp
  timestamp: '2022-08-16 22:05:54+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/NumberofSubstrings.test.cpp
  - Verify/Factorize.test.cpp
  - Verify/convolution.test.cpp
  - Verify/SuffixArray.test.cpp
  - Verify/Polynomial_Interpolation.test.cpp
  - Verify/PointAddRangeSum.test.cpp
  - Verify/RangeAffineRangeSum.test.cpp
  - Verify/StaticRMQ.test.cpp
  - Verify/ACAutomaton.test.cpp
  - Verify/InvofFormalPowerSeries.test.cpp
  - Verify/Multipoint_Evaluation.test.cpp
  - Verify/Sum_of_Totient_Function.test.cpp
documentation_of: Template/Template.hpp
layout: document
redirect_from:
- /library/Template/Template.hpp
- /library/Template/Template.hpp.html
title: Template/Template.hpp
---