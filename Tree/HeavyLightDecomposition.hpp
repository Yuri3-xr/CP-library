#pragma once

#include "../Template/Template.hpp"
struct HLD {
    int n;
    int cnt;  // dfs order [0,n)
    std::vector<std::vector<int>> adj;
    std::vector<int> par, dfn, hson, siz, top, dep;
    HLD() = delete;
    HLD(int _n)
        : n(_n),
          cnt(0),
          adj(_n),
          par(_n),
          dfn(_n),
          hson(_n),
          siz(_n),
          top(_n),
          dep(_n){};
    HLD(std::vector<std::vector<int>> tr) {
        cnt = 0;
        n = tr.size();
        adj = tr;
        par.resize(n), dfn.resize(n), hson.resize(n), siz.resize(n),
            top.resize(n), dep.resize(n);
    }

    void addEdge(int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
        return;
    }

    void build(int root = 0) {
        auto dfs1 = [&](auto &&self, int u, int fa) -> void {
            par[u] = fa, siz[u] = 1, hson[u] = -1;
            for (const auto &v : adj[u]) {
                if (v == fa) continue;
                dep[v] = dep[u] + 1;
                self(self, v, u);
                siz[u] += siz[v];
                if (hson[u] == -1)
                    hson[u] = v;
                else if (siz[hson[u]] < siz[v])
                    hson[u] = v;
            }
        };
        dfs1(dfs1, root, -1);
        auto dfs2 = [&](auto &&self, int u, int tp) -> void {
            dfn[u] = cnt++;
            top[u] = tp;
            if (hson[u] == -1) return;
            self(self, hson[u], tp);
            for (const auto &v : adj[u]) {
                if (v == par[u] || v == hson[u]) continue;
                self(self, v, v);
            }
        };
        dfs2(dfs2, root, root);
        return;
    }

    int lca(int u, int v) const {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]])
                u = par[top[u]];
            else
                v = par[top[v]];
        }
        return ((dep[u] > dep[v]) ? v : u);
    }

    std::vector<std::pair<int, int>> pathP2P(int u, int v) const {
        // op length O(logn)
        std::vector<std::pair<int, int>> op;
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
            op.emplace_back(dfn[top[u]], dfn[u]);
            u = par[top[u]];
        }
        if (dep[u] > dep[v]) std::swap(u, v);
        op.emplace_back(dfn[u], dfn[v]);
        return (op);
    }
    template <class F>
    void processP2P(int u, int v, F f) {
        // F: void(int L, int R) refers to the process of internal [L,R]
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
            f(dfn[top[u]], dfn[u]);
            u = par[top[u]];
        }
        if (dep[u] > dep[v]) std::swap(u, v);
        f(dfn[u], dfn[v]);
    }
};
