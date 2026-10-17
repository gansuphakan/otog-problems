#include "imposter.h"
#include <iostream>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int N, M;
  if (!(std::cin >> N >> M) || N < 2 || N > 5000 || M < 1 || M > 10000) return 1;

  std::vector<int> P(2 * M), S(2 * M);
  for (int i = 0; i < 2 * M; ++i) if (!(std::cin >> P[i] >> S[i])) return 1;

  auto result = assign(N, M, P, S);

  std::cout << result.first << '\n' << result.second.size() << '\n';
  for (bool bit : result.second) std::cout << int(bit) << ' ';
  std::cout << '\n';
}
