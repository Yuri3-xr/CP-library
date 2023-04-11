#include "Ntt.hpp"

template <class Z>
std::vector<Z> multiplyLarge(const std::vector<Z>& v1,
                             const std::vector<Z>& v2) {
    using FPS = std::vector<Z>;
    static NTT<Z> ntt;
    const int L = 1 << 23;
    if (v1.size() == 0 or v2.size() == 0 or v1.size() + v2.size() - 1 <= L)
        return ntt.multiply(v1, v2);

    std::vector<FPS> v1s, v2s;
    for (int i = 0; i < v1.size(); i += L / 2) {
        FPS nxt(
            {v1.begin() + i, v1.begin() + std::min(i + L / 2, int(v1.size()))});
        nxt.resize(L);
        ntt.dft(nxt);
        v1s.push_back(nxt);
    }
    for (int i = 0; i < v2.size(); i += L / 2) {
        FPS nxt(
            {v2.begin() + i, v2.begin() + std::min(i + L / 2, int(v2.size()))});
        nxt.resize(L);
        ntt.dft(nxt);
        v2s.push_back(nxt);
    }

    std::vector<FPS> cs(v1s.size() + v2s.size() - 1, FPS(L));
    for (int x = 0; x < v1s.size(); ++x)
        for (int y = 0; y < v2s.size(); ++y)
            for (int i = 0; i < L; ++i) cs[x + y][i] += v1s[x][i] * v2s[y][i];

    for (int i = 0; i < v1s.size() + v2s.size() - 1; ++i) {
        ntt.idft(cs[i]);
    }

    FPS ret(v1.size() + v2.size() - 1);

    for (int i = 0; i < cs.size(); ++i) {
        for (int j = 0; j < L; ++j) {
            int pos = i * L / 2 + j;
            if (pos >= ret.size()) break;
            ret[pos] += cs[i][j];
        }
    }
    return ret;
}