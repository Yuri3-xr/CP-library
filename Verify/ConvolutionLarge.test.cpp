#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_large"

#include "../ModInt/Modint32.hpp"
#include "../Polynomial/NttLarge.hpp"

int main() {
    constexpr int P = 998244353;
    using Z = mint<P>;

    int n, m;
    std::cin >> n >> m;

    std::vector<Z> a(n), b(m);

    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];

    auto ans = multiplyLarge(a, b);

    for (int i = 0; i < n + m - 1; i++) {
        std::cout << ans[i] << " \n"[i == n + m - 2];
    }

    return 0;
}
