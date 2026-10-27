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
    int n, r1, c1, r2, c2;
    cin >> n;

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    vector<string>grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    map<pair<int, int>, bool>visited;
    vector<int>xi = {0, -1, 1, 0};
    vector<int>yi = {-1, 0, 0, 1};

    auto canGo = [&](int x, int y)->bool {
        return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == '0' && !visited[{x, y}];
    };

    auto goTraverse = [&](auto &&self, int x, int y, vector<pair<int, int>>&island)->void{
        visited[{x, y}] = true;
        for (int i = 0; i < 4; i++) {
            int nextX = x + xi[i];
            int nextY = y + yi[i];

            if(canGo(nextX, nextY)) {

                island.push_back({nextX, nextY});
                self(self, nextX, nextY, island);
            }
        }
    };

    vector<pair<int, int>>island1;
    island1.push_back({r1 - 1, c1 - 1});
    goTraverse(goTraverse, r1 - 1, c1 - 1, island1);


    vector<pair<int, int>>island2;
    island2.push_back({r2 - 1, c2 - 1});
    goTraverse(goTraverse, r2 - 1, c2 - 1, island2);

    int answer = 1e18;
    for(auto p1: island1) {
        for(auto p2: island2) {
            int curCost = (p1.first - p2.first) * (p1.first - p2.first) +
                          (p1.second - p2.second) *(p1.second - p2.second);

            answer  = min(answer, curCost);
        }
    }

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