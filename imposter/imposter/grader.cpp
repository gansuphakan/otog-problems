#include "imposter.h"
#include <iostream>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    if (!(std::cin >> N >> M) || N < 3 || N > 100000 ||
        M < N - 1 || M > 200000) return 1;
    std::vector<int> P(2 * M), S(2 * M);
    for (int i = 0; i < 2 * M; ++i)
        if (!(std::cin >> P[i] >> S[i])) return 1;

    std::cout << assign(N, M, std::move(P), std::move(S)) << '\n';
}
