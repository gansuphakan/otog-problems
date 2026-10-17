# Imposter Village: local compilation

Implement the declaration in `imposter.h`, including that header in your source. Submit your implementation only, without `main`.

```cpp
long long assign(int N, int M, std::vector<int> P, std::vector<int> S);
```

Return the maximum number of ordered pairs of distinct villagers for which impersonation is possible. The problem author supplies the statement separately.

Compile and run the starter:

```sh
g++ grader.cpp imposter.cpp -O2 -std=c++17 -o imposter
./imposter < sample.in
```

The grader reads `N M`, followed by `2*M` registration lines `P[i] S[i]`. Each stamp occurs exactly twice; records need not be adjacent. The grader prints your returned integer. The correct sample answer is `21`.

Limits: 3≤N≤100,000, N−1≤M≤200,000, 1 second, 64 MiB. Use `long long`.
