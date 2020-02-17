#include <bits/stdc++.h>
#define ll long long
#define N 1000000
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m,k;
	    cin>>n>>m>>k;
	    
	   set<pair <ll,ll>> mypair;
	    while(k--)
	    {
	        ll a,b;
	        cin>>a>>b;
	        mypair.insert(pair<ll,ll>(a,b));
	    }
	    ll sum=0;
	    for(auto a:mypair)
	    {
	        auto r = a.first;
	        auto c = a.second;
	        if(mypair.count(pair <ll,ll>(r+1,c)) == 0)
	            sum++;
	            if(mypair.count(pair <ll,ll>(r-1,c)) == 0)
	                sum++;
	                 if(mypair.count(pair <ll,ll>(r,c+1)) == 0)
	                    sum++;
	                     if(mypair.count(pair <ll,ll>(r,c-1)) == 0)
	                        sum++;
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}
