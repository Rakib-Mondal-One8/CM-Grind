#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define sz(x) ((int)(x).size())
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
void init_code() {
#ifdef Rakib_18
    //freopen("in.txt", "r", stdin);
#endif
}
using namespace chrono;

/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/
const int mod = 998244353;
int expo(int a, int b, int mod) { int res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
int mminvprime(int a, int b) { return expo(a, b - 2, b); }
// int inv(int i) { if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod; }
bool isPrime(int n) { if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0)return false; } return true; }
int lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
int mod_add(int a, int b, int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int mod_mul(int a, int b, int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int mod_sub(int a, int b, int m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int mod_div(int a, int b, int m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
int nXOR(int n) { if (n % 4 == 0)return n; if (n % 4 == 1)return 1; if (n % 4 == 2)return n + 1; return 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

struct Mint {
    int val;

    Mint(long long v = 0) {
        if (v < 0) v = v %  + mod;
        if (v >= mod) v %= mod;
        val = v;
    }

    static int mod_inv(int a, int m = mod) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
        return x < 0 ? x + m : x;
    }
    explicit operator int() const { return val; }
    Mint& operator+=(const Mint &other) { val += other.val; if (val >= mod) val -= mod; return *this; }
    Mint& operator-=(const Mint &other) { val -= other.val; if (val < 0) val += mod; return *this; }
    static unsigned fast_mod(uint64_t x, unsigned m = mod) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
    Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val); return *this; }
    Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() { val = val == mod - 1 ? 0 : val + 1; return *this; }
    Mint& operator--() { val = val == 0 ? mod - 1 : val - 1; return *this; }
    // friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const { return val == 0 ? 0 : mod - val; }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const { return mod_inv(val); }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1) result *= a;
            a *= a, p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
    friend istream& operator >> (istream &stream, Mint &m) { return stream >> m.val;   }
};
namespace comb {
int n(0);
vector<Mint> _fac{1}, _invfac{1}, _inv{0};
void init(int m) {
    m = min (m, mod - 1);
    if (m <= n) return;
    _fac.resize(m + 1); _invfac.resize(m + 1); _inv.resize(m + 1);
    for (int i = n + 1; i <= m; i++) _fac[i] = _fac[i - 1] * i;
    _invfac[m] = _fac[m].inv();
    for (int i = m; i > n; i--) _invfac[i - 1] = _invfac[i] * i, _inv[i] = _invfac[i] * _fac[i - 1];
    n = m;
}
Mint fac(int m) { if (m > n) init(2 * m); return _fac[m]; }
Mint invfac(int m) { if (m > n) init(2 * m); return _invfac[m]; }
Mint inv(int m) { if (m > n) init(2 * m); return _inv[m]; }
Mint ncr(int n, int r) { if (n < r || r < 0) return 0; return fac(n) * invfac(r) * invfac(n - r); }
}
using comb::fac, comb::invfac, comb::inv, comb::ncr;
void RakibOne8() {
    int n, m, k;
    cin >> n >> m >> k;

    int answer = ncr(n - 1, k).val;
    answer = mod_mul(mod_mul(answer, m, mod), expo(m - 1, k, mod), mod);

    cout << answer << nl;
}
int32_t main() {
    init_code();
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // cin >> t;
    auto start1 = high_resolution_clock::now();
    while (t--) {
        RakibOne8();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Rakib_18
    cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
    return 0;
}