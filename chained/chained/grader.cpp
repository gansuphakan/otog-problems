/*
Input
N
state[0] state[1] ... state[N-1]
p[0] p[1] ... p[N-1]
k[0] k[1] ... k[2N-1]

Output
final_state[0] final_state[1] ... final_state[N-1]

state[i] is the hidden state of room i.
state 1 represents chained, 0 represents unchained.
p[i] is p_i.
k[j] is the j-th "k choice".
final_state[i] is the final state of room i.
Every final_state should be 0 when solve() returns.

This sample grader only rejects query-limit exceeds and invalid positions vector when querying.
This sample grader takes O(N^2 + NK) extra time where K is the sum of all ks
and takes O(N) extra space
*/



#include "blind_shuffle.h"
#include <vector>
#include <cassert>
#include <iostream>

static int N, at, flips, queries;
static std::vector<int> p, state;
static std::vector<long long> k;

static void shuffle() {
  std::vector<int> next(N);
  for (long long r = k[at++]; r > 0; r--) {
    for (int i = 0; i < N; i++)
      next[p[i]] = state[i];
    state.swap(next);
  }
}

void flip(const std::vector<int> &v) {
  assert(++flips <= N && !v.empty());
  shuffle();
  std::vector<bool> seen(N);
  for (auto e : v) {
    assert(0 <= e && e < N && !seen[e]);
    seen[e] = true;
    state[e] ^= 1;
  }
}

int parity(const std::vector<int> &v) {
  assert(++queries <= N && !v.empty());
  shuffle();
  std::vector<bool> seen(N);
  int result = 0;
  for (auto e : v) {
    assert(0 <= e && e < N && !seen[e]);
    seen[e] = true;
    result ^= state[e];
  }
  return result;
}

int main() {
  std::cin >> N;
  state.resize(N);
  p.resize(N);
  k.resize(2 * N);
  for (auto &e : state)
    std::cin >> e;
  for (auto &e : p)
    std::cin >> e;
  for (auto &e : k)
    std::cin >> e;
  solve(N, p);
  for (int i = 0; i < N; i++)
    std::cout << state[i] << ' ';
  std::cout << '\n';
}
