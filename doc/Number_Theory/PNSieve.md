# PNSieve

```cpp
T PNSieve(i64 n, const function<T(i64)> G, const function<T(i64, i64, i64)> f,const function<T(i64, i64, i64)> g) 
```

 PN筛计算积性函数$f$前缀和：$ \sum_{i=1}^n f(i)$。

找到积性函数$g$使的$g(p) = f(p)$其中$p$是质数。$G(x)$是 $g$函数的前缀和。

$f,g$以三参数传入，$f(n,p,c) \rightarrow f(p^c) = f(n)$

时间复杂度: $\mathcal{O} (\max(\sqrt{n},n^t (\frac{\zeta(2t)\zeta(3t)}{\zeta(6t)}))$ $n^t$用来计算$G(x)$ ,$\zeta$ 是Riemann zeta function。