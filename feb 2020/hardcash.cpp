#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n,k; cin >>n>>k;
		ll sum=0;
		for(int i=0; i<n; i++) {
			ll x; cin >> x;
			sum += x;
		}
		cout << sum%k << endl;
	}
	return 0;
}