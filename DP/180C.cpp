#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) ((int)(x).size())
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
void init_code() {
#ifdef Rakib_18
	freopen("Error.txt", "w", stderr);
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

void RakibOne8()
{
	string s;
	cin >> s;

	int n = sz(s);

	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(2)));
	/*
	dp[i][u][l] = minimum no of operations/transformation required
	to make the remining sequence from ith character to n-1th character
	such that u(flag) = tells uppercase letter came or not, and
	l(flag)= tells that lowercase letter came or not

	*/
	const int INF = 1e18;
	for (int i = n - 1; i >= 0; i--) {
		for (int u = 0; u < 2; u++) {
			for (int l = 0; l < 2; l++) {

				int optionA = INF; // take upper case
				int optionB = INF; // take lower case

				//upper case came & lower case doesn't
				if (u == 1 && l == 0) {
					if (s[i] >= 'A' && s[i] <= 'Z') {
						optionA = dp[i + 1][1][0];
						optionB = 1 + dp[i + 1][1][1];
					}
					else {
						optionA = 1 + dp[i + 1][1][0];
						optionB = dp[i + 1][1][1];
					}
				}
				// lowercase came & uppercase doesn't
				if (l == 1 && u == 0) {
					if (s[i] >= 'A' && s[i] <= 'Z') {
						optionB = 1 + dp[i + 1][0][1];
					}
					else {
						optionB = dp[i + 1][0][1];
					}
				}
				// both cases came
				if (u == 1 && l == 1) {
					if (s[i] >= 'A' && s[i] <= 'Z') {
						optionB = 1 + dp[i + 1][1][1];
					}
					else {
						optionB = dp[i + 1][1][1];
					}
				}

				dp[i][u][l] = min(optionA, optionB);
			}
		}
	}
	debug(dp[0][1][0], dp[0][0][1]);

	int answer = min(dp[0][1][0], dp[0][0][1]);

	cout << answer << nl;

}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	// cin >> t;
	auto start1 = high_resolution_clock::now();
	while (t--)
	{
		RakibOne8();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Rakib_18
	cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
	return 0;
}