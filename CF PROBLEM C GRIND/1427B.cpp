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
const int mod = 1e9 + 7;
int expo(int a, int b, int mod) { int res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
int mminvprime(int a, int b) { return expo(a, b - 2, b); }
int inv(int i) { if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod; }
bool isPrime(int n) { if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0)return false; } return true; }
int lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
int mod_add(int a, int b, int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int mod_mul(int a, int b, int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int mod_sub(int a, int b, int m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int mod_div(int a, int b, int m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
int nXOR(int n) { if (n % 4 == 0)return n; if (n % 4 == 1)return 1; if (n % 4 == 2)return n + 1; return 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

void RakibOne8() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int answer = 0;
    bool hasWin = false;
    for (auto c : s)
        if (c == 'W') {
            answer++;
            hasWin = true;
        }

    vector<pair<int, int>>seg;
    int j = 0;
    for(int i = 0; i<n; i++) {
        if(s[i] == 'W') {
            j = i + 1;
            while(j<n && s[j] == 'L')j++;
            if(j<n)
                seg.push_back({i, j});
        }
    }

    sort(seg.begin(), seg.end(), [&](pair<int, int>a, pair<int, int>b) {
        return a.second - a.first < b.second - b.first;
    });

    for (auto p : seg) {
        int l = p.first + 1;
        int r = p.second - 1;

        if (r - l + 1 <= k) {
            answer += 2 * (r - l + 1);
            answer += 1; // for joining to segments;

            for (int i = l; i <= r; i++)s[i] = 'W';
            k -= (r - l + 1);
        }
    }
    debug(seg, s);

    int lost = 0;
    for (auto c : s)if (c == 'L')lost++;

    answer += min(lost, k) * 2;
    if (!hasWin && k > 0)answer -= 1;

    cout << answer << nl;
}
int32_t main() {
    init_code();
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    cin >> t;
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