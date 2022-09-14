#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../ModInt/Modint32_change.hpp"
#include "../Polynomial/Poly.hpp"
#include "../Template/Template.hpp"

int main() {
    int n, m;

    int mod = 998244353;
    using Z = mintc;
    Z::set_mod(mod);
    using poly = Poly<Z, 3>;

    cin >> n;

    poly f(n, 0);
    for (int i = 0; i < n; i++) cin >> f[i];

    auto ans = f.inv(n);
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];

    return 0;
}