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
ll power(ll x,ll y) {ll res=1; x=x%mod; while (y > 0){ if(y&1)res=(res*x)%mod; y=y>>1; x=(x*x)%mod;} return res;}
ll prime(ll n){if(n%2==0) return 0; for(ll i=3;i*i<=n;i=i+2)if(n%i==0)return 0; return 1;}

int arr[N], sze[N];
int root(int i) { while(arr[i] != i){i = arr[arr[i]];} return i;}
void Union(int x, int y){
    int root_x = root(x); int root_y = root(y); if(root_x == root_y) return; if(sze[root_x] < sze[root_y]){
        arr[root_x] = arr[root_y]; sze[root_y] += sze[root_x];} else{arr[root_y] = arr[root_x]; sze[root_x] += sze[root_y];}}

ll gcdExtended(ll a, ll b, ll *x, ll *y){ if (a == 0) { *x = 0, *y = 1; return b;} ll x1, y1; ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1; *y = x1; return gcd;}
ll modinverse(ll a, ll m) { ll x, y; ll g = gcdExtended(a, m, &x, &y); assert(g == 1); return (x % m + m) % m;}

int main()
{
	T {
		llin(n);
		vector <ll> v1,v2;
		rep(i,0,n) {
			llin(x);
			v1.PB(x);
		}
		rep(i,0,n) {
			llin(x);
			v2.PB(x);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		ll ans = 0;
		rep(i,0,n)	ans += min(v1[i], v2[i]);
		cout << ans << endl;
	}
	
	return 0;
}
