#define PROBLEM \
    "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../ModInt/Modint32.hpp"
#include "../Polynomial/LinearlyRecurrent.hpp"
#include "../Template/Template.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int mod = 998244353;
    using Z = mint<mod>;
    using poly = Poly<Z>;

    int d;
    i64 k;
    std::cin >> d >> k;
    poly a(d, 0), c(d, 0);
    for (int i = 0; i < d; i++) std::cin >> a[i];
    for (int i = 0; i < d; i++) std::cin >> c[i];

    std::cout << LinearlyRecurrent<Z>(a, c, k) << std::endl;

    return 0;
}