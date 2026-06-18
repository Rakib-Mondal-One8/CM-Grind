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

const int X = 40005;
const int N = 500;
vector<vector<int>>dp(N + 1, vector<int>(X + 1));

int reverse(int val) {
	int res = 0;
	while (val > 0) {
		int lastDigit = val % 10;
		res = res * 10 + lastDigit;
		val /= 10;
	}
	return res;
}
bool isPalindrome(int val) {
	return reverse(val) == val;
}
void go() {
	vector<int>a;
	for (int i = 1; i < X; i++) {
		if (isPalindrome(i))a.push_back(i);
	}

	int n = sz(a);
	debug(n);
	for (int i = n - 1; i >= 0 ; i--) {
		for (int j = 0; j <= X; j++) {

			//Base
			if (j == 0) {
				dp[i][j] = 1;
				continue;
			}

			int optionA = 0;
			if (a[i] <= j)
				optionA = dp[i][j - a[i]];
			int optionB = dp[i + 1][j];

			dp[i][j] = (optionA + optionB) % mod;
		}
	}

}

void RakibOne8()
{
	int x;
	cin >> x;
	/*
	dp[i][j] = total no. of distinct way to get sum = j from ith to 180th all palindromic
	value
	*/
	cout << dp[0][x] << nl;
}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	auto start1 = high_resolution_clock::now();
	go();
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