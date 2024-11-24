#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
bool is_palindrome(string tmp)
{
	string rev = tmp;
	reverse(tmp.begin(), tmp.end());
	if (rev == tmp)
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s = "";
	loop(i, 1, n)
	{
		s += 'a';
	}
	int l = 0, r = 0;
	string tmp = "";
	while (r < n)
	{
		if (r - l + 1 == 3)
		{
			if (is_palindrome(tmp))
			{
				if (s[l] == 'a')
				{
					s[r] = 'b';
					tmp[2] = s[r];
				}
				else if (s[l] == 'b')
				{
					s[r] == 'a';
					tmp[2] = s[r];
				}
				tmp.erase(0, 1);
			}
			l++;
		}
		r++;
		tmp += s[r];
	}
	cout << s << nl;
	return 0;
}