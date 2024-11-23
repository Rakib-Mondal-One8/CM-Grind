#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (ll i = s; i <= n; i++)
using namespace std;
ll possibility_1(vector<ll> a, ll n)
{
	ll ans1 = 0;
	ll zero = 0;
	for (ll i = n - 1; i >= 0; i--)
	{
		if (a[i] == 0)
			zero++;
		else
			ans1 += zero;
	}
	loop(i, 0, n - 1)
	{
		if (a[i] == 0)
		{
			a[i] = 1;
			break;
		}
	}
	ll ans2 = 0;
	zero = 0;
	for (ll i = n - 1; i >= 0; i--)
	{
		if (a[i] == 0)
			zero++;
		else
			ans2 += zero;
	}
	return max(ans1, ans2);
}
ll possibility_2(vector<ll> a, ll n)
{
	ll ans1 = 0;
	ll zero = 0;
	for (ll i = n - 1; i >= 0; i--)
	{
		if (a[i] == 0)
			zero++;
		else
			ans1 += zero;
	}
	for (ll i = n - 1; i >= 0; i--)
	{
		if (a[i] == 1)
		{
			a[i] = 0;
			break;
		}
	}
	ll ans2 = 0;
	zero = 0;
	for (ll i = n - 1; i >= 0; i--)
	{
		if (a[i] == 0)
			zero++;
		else
			ans2 += zero;
	}
	return max(ans1, ans2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;
		vector<ll> a(n);
		loop(i, 0, n - 1)
		{
			cin >> a[i];
		}

		ll op1 = possibility_1(a, n);
		ll op2 = possibility_2(a, n);

		cout << max(op1, op2) << nl;
	}
	return 0;
}