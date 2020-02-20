#include <bits/stdc++.h>
#define ll long long
#define INF INT_MAX
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define T ll t; cin>>t; while(t--)
#define llin(a) ll a; cin>>a;
#define llin2(a,b) ll a,b; cin>>a>>b;
#define llin3(a,b,c) ll a,b,c; cin>>a>>b>>c;
#define rep(i, a, n) for(int i=(ll)a; i<n; i++)
#define rep1(i, a, n) for(int i=(ll)a; i<=n; i++)
#define vll vector<ll>
#define PB push_back
#define mkp make_pair
#define N 1000000
#define endl "\n"
using namespace std;
vector <string> v;
int adj[5][5] = {0};
void permute(string a, int l, int r) 
{ 
	if (l == r) 
		v.PB(a); 
	else
	{  
		for (int i = l; i <= r; i++) 
		{ 
 
			swap(a[l], a[i]); 
			permute(a, l+1, r); 
			swap(a[l], a[i]); 
		} 
	} 
} 
int solve()
{
	int profit = INT_MIN;
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.size(); j++) {
			int sum = 0;
			for(int k=1; k<=4; k++) {
				if(adj[k][v[i][k-1]-'0'] == 0) sum-=100;
				else
					sum += adj[k][v[i][k-1]-'0']*(v[j][k-1]-'0')*25;
			}
			profit = max(profit, sum);
		}
	}
	return profit;
}
int main()
{
	ll total = 0;
	permute("1234", 0, 3);
	T {
		memset(adj, 0, sizeof(adj));
		llin(n);
		while(n--) 
		{		
			char ch; ll n;	
			cin >> ch >> n;	
			adj[ch-'A'+1][n/3]++;
		}
		int profit = solve();
		cout << profit << endl;
		total += profit;
	}
	cout << total;
	return 0;
}
