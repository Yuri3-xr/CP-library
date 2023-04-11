#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../ModInt/Modint32.hpp"
#include "../Polynomial/Poly.hpp"
#include "../Template/Template.hpp"

int main() {
    int n, m;

    constexpr int mod = 998244353;
    using Z = mint<mod>;
    using poly = Poly<Z>;

    std::cin >> n >> m;

    std::vector<Z> a(n), b(m);

    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];

    auto ans = poly(a) * poly(b);

    for (int i = 0; i < (int)(ans.size()); i++)
        std::cout << ans[i] << " \n"[i == (int)ans.size() - 1];
}