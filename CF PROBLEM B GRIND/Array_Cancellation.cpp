#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<ll> a(n);
		loop(i, 0, n - 1)
		{
			cin >> a[i];
		}
		reverse(a.begin(), a.end());
		ll s = 0;
		ll ans = INT_MIN;
		loop(i, 0, n - 1)
		{
			s += a[i];
			ans = max(ans, s);
		}
		cout << ans << nl;
	}
	return 0;
}