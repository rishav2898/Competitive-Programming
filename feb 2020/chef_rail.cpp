#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define llin(a) ll a; cin>>a
#define PB push_back
#define max 100001

ll spf[max];
vector <ll> adj[100001];
void sieve() {
    spf[1] = 1;
    for (int i = 2; i < max; i++) spf[i] = i;
    for (int i = 4; i < max; i += 2) spf[i] = 2;

    for (int i = 3; i * i < max; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < max; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
void factor() {
	for(int i=1; i<100001; i++) {
		ll x = i;
        while(x > 1) {
            ll fact = x / spf[x];
            adj[i].push_back(spf[x]);
            x = fact;
        }
	}
}
ll solve(vector<ll>&x1, unordered_map<ll,ll>&x2_hash, unordered_map<ll,ll>&y_point) {
		ll ans = 0;
		//cout << "size " << x1.size() << endl;
		for(int i=0; i<x1.size(); i++) 
		{
			ll num = x1[i];
			unordered_map <ll,ll> hash;
			for(int j=0; j<adj[num].size(); j++) 
				hash[adj[num][j]]++;
			// for(auto c:adj[num]) cout << "hash "<< c << << endl;
			ll even_fact = 1;
			for(auto j:hash) {
				if((j.second) & 1) {
					even_fact = even_fact * (j.first);
				}
			}
			//cout << "eve_fact "<< even_fact << endl;
	
			if(x2_hash[num] && y_point[num]) {
				ans += (y_point[num] * x2_hash[num]); 
				//cout << "ans1 "<< ans << endl;
			}
			ll temp = 1;
			for(int j=1; temp<max; j++) {
				temp = j * j * even_fact;
				if(x2_hash[temp] && temp!=num) {
					//cout << "hi\n";
					ll val = num * temp;
					ll check = sqrt(val);
					// if(check*check == val) {
						ans = ans + y_point[check];
					// }
				}
			}

		}
		//cout << "final " << ans << endl;
		return ans;
}
int main()
{
	fast;
	sieve();
	factor();
	int t;
	cin >> t;
	while(t--)
	{
		ll n, m; cin >> n >> m;
		vector <ll> x1,x2;
		bool f=false;
		unordered_map <ll, ll> x_point;
		unordered_map <ll,ll> x2_hash;
		for(int i=0; i<n; i++) {
			llin(x), x_point[abs(x)]++;
			if(x > 0) x1.PB(x);
			else if(x < 0) x2.PB(abs(x)), x2_hash[abs(x)]++;
			else f=true; 
		}
		vector <ll> y1,y2;
		unordered_map <ll, ll> y_point;
		unordered_map<ll,ll> y2_hash;
		for(int i=0; i<m; i++) {
			llin(y), y_point[abs(y)]++;
			if(y > 0) y1.PB(y);
			else if(y < 0) y2.PB(abs(y)), y2_hash[abs(y)]++;
			else	f=true;
		}
		
		ll ans = 0;
		if(x1.size() & x2.size())
			ans += solve(x1, x2_hash, y_point);
		//cout << "first "<< ans << endl;
		if(y1.size() & y2.size())
			ans += solve(y1, y2_hash, x_point);
		//cout << "second " << ans << endl;
		if(f) {
			ll x = x1.size() + x2.size();
			
			ll y = y1.size() + y2.size();
			ans = ans + (x*y);
		}
		cout << ans << endl;

	}
	return 0;
}