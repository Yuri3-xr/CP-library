---
title: Heavy Light Decomposition
documentation_of: Tree/HeavyLightDecomposition.hpp
---

# 轻重链剖分

初始化给定树的大小$n$,保证树的点序号在$[0,n)$内。

`adj`: 邻接表存图

`par`: 父亲节点标号

`hson`: 重儿子节点标号

`siz`: 子树大小

`top`: 重链顶端节点标号

`dep`: 节点深度（根结点深度$n$）

`dfn`: 节点dfs序标号

`build(int root = 0)`: 以root为根初始化构建HLD，时间复杂度$\mathcal{O}(n)$

`lca(int u,int v)`: 求$u,v$的LCA，时间复杂度$\mathcal{O}(\log{n})$

`pathP2P(int u, int v)`: 将$u,v$两点间的路径分解为若干个dfs序连续的区间$[l_i,r_i]$，区间个数级别为$\mathcal{O}(\log{n})$

`processP2P(int u, int v, F f)`: 将函数操作$f$作用在将$u,v$两点间的路径上；`f(int L,int R)->void`为dfs序在$[L,R]$上的操作函数；时间复杂度$\mathcal{O}(T(f)\log{n})$