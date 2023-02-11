#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../ModInt/Modint32.hpp"
#include "../Polynomial/Poly.hpp"
#include "../Template/Template.hpp"

int main() {
    int n, m;

    constexpr int mod = 998244353;
    using Z = mint<mod>;
    using poly = Poly<Z, 3>;

    std::cin >> n >> m;

    poly f(n, 0);
    for (int i = 0; i < n; i++) std::cin >> f[i];

    std::vector<Z> g(m);
    for (int i = 0; i < m; i++) std::cin >> g[i];

    auto ans = f.eval(g);

    for (int i = 0; i < m; i++) std::cout << ans[i] << " \n"[i == m - 1];

    return 0;
}