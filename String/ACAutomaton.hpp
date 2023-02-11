#pragma once

#include "Trie.hpp"

template <class Node>
struct ACAutomaton : public trie<Node> {
    std::vector<int> fail;
    ACAutomaton(){};

    void BuildAC() {
        fail.resize(this->tr.size());
        std::queue<int> Q;
        for (int i = 0; i < 26; i++)
            if (this->tr[0][i]) Q.push(this->tr[0][i]);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++) {
                if (this->tr[u][i])
                    fail[this->tr[u][i]] = this->tr[fail[u]][i],
                    Q.push(this->tr[u][i]);
                else
                    this->tr[u][i] = this->tr[fail[u]][i];
            }
        }
        return;
    }
};