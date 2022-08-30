#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../ModInt/Modint32.hpp"
#include "../Polynomial/Poly.hpp"
#include "../Template/Template.hpp"

int main() {
    constexpr int mod = 998244353;
    using Z = mint<mod>;
    using poly = Poly<Z, 3>;

    int n;
    cin >> n;

    poly x(n, 0);
    poly y(n, 0);

    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    auto ans = x.inter(y);

    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];

    return 0;
}