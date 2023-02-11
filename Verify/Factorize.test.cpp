#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../Number_Theory/Factorization.hpp"
#include "../Template/Template.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _;
    std::cin >> _;
    while (_--) {
        i64 x;
        std::cin >> x;
        auto ans = factorization<i64>(x);
        std::sort(begin(ans), end(ans));

        std::cout << ans.size() << '\n';
        for (int i = 0; i < (int)ans.size(); i++) {
            std::cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        }
    }

    return 0;
}
