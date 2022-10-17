#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "../ModInt/Modint32.hpp"
#include "../Number_Theory/MultiplicativeFunctionPSumFast.hpp"
constexpr int mod = 998244353;
using Z = mint<mod>;

Z f(i64 p, i64 c) { return power(p, c) - power(p, c - 1); }
int main() {
    i64 n;
    cin >> n;

    MfPrefixSum<Z, f> mf(n);

    auto psum = mf.prime_sum_table(1);
    auto ptable = mf.pi_table();
    for (int i = 0; i < int(psum.size()); i++) {
        psum[i] = psum[i] - ptable[i];
    }

    auto ans = mf.run(psum);

    cout << ans << endl;

    return 0;
}