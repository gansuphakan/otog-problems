#include <bits/stdc++.h>
using namespace std;


const int MAXN = 10000005;
int a[MAXN];
long long ans[MAXN];

// Fast input: non-negative integers and char only
struct Reader {
    static constexpr int SZ = 1 << 20;
    char buf[SZ]; int at = 0, len = 0;
    inline char get() { if (at == len) { len = fread(buf, 1, SZ, stdin); at = 0; if (!len) return 0; } return buf[at++]; }
    inline int number() { char c = get(); while (c && c <= ' ') c = get(); int x = 0; while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = get(); } return x; }
};

// Fast output: non-negative 64-bit integers and char
struct Writer {
    static constexpr int SZ = 1 << 20;
    char buf[SZ]; int at = 0;
    inline void flush() { if (at) fwrite(buf, 1, at, stdout); at = 0; }
    inline void ch(char c) { if (at == SZ) flush(); buf[at++] = c; }
    inline void num(long long x) { char s[24]; int p = 0; do { s[p++] = '0' + x % 10; x /= 10; } while (x); while (p) ch(s[--p]); }
    ~Writer() { flush(); }
};

Reader in;
Writer out;


int main() {
    int n = in.number();
    for (int i = 0; i < n; i++) a[i] = in.number();


    // TODO: Implement your algorithm.
    // Store the answer for position i in ans[i].


    for (int i = 0; i < n; i++) {
        out.num(ans[i]);
        out.ch(' ');
    }
    return 0;
}


