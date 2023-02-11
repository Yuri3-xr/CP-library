#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../String/SuffixArray.hpp"

#include "../Template/Template.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    SuffixArray SA(s);

    for (int i = 0; i < SA.n; i++) {
        std::cout << SA.sa[i] << " \n"[i == SA.n - 1];
    }

    return 0;
}