#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../ModInt/Modint32.hpp"
#include "../Polynomial/Poly.hpp"
#include "../Template/Template.hpp"

int main() {
    int n, m;

    constexpr int mod = 998244353;
    using Z = mint<mod>;
    using poly = Poly<Z>;

    std::cin >> n;

    poly f(n, 0);
    for (int i = 0; i < n; i++) std::cin >> f[i];

    auto ans = f.inv(n);
    for (int i = 0; i < n; i++) std::cout << ans[i] << " \n"[i == n - 1];

    return 0;
}