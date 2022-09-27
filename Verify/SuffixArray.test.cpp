#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../String/SuffixArray.hpp"

#include "../Template/Template.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    SuffixArray SA(s);

    for (int i = 0; i < SA.n; i++) {
        cout << SA.sa[i] << " \n"[i == SA.n - 1];
    }

    return 0;
}