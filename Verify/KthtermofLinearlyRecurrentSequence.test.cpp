#define PROBLEM \
    "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../ModInt/Modint32.hpp"
#include "../Polynomial/LinearlyRecurrent.hpp"
#include "../Template/Template.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int mod = 998244353;
    using Z = mint<mod>;
    using poly = Poly<Z, 3>;

    int d;
    i64 k;
    cin >> d >> k;
    poly a(d, 0), c(d, 0);
    for (int i = 0; i < d; i++) cin >> a[i];
    for (int i = 0; i < d; i++) cin >> c[i];

    cout << LinearlyRecurrent<Z, 3>(a, c, k) << endl;

    return 0;
}