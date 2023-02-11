#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../String/SuffixArrayFast.hpp"
#include "../Template/Template.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    SuffixArrayFast<std::string> SA(s);

    i64 ans = 1ll * (SA.n + 1) * (SA.n) / 2;
    for (int i = 0; i < SA.n - 1; i++) {
        ans -= SA.lc[i];
    }

    std::cout << ans << '\n';

    return 0;
}