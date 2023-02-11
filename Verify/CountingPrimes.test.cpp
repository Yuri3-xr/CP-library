#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../Number_Theory/MultiplicativeFunctionPSumFast.hpp"
i64 f(i64 p, i64 c) { return 1; }
int main() {
    i64 n;
    std::cin >> n;

    MfPrefixSum<i64, f> mf(n);
    auto now = mf.pi_table();
    std::cout << now[1] << std::endl;

    return 0;
}