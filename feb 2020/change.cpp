#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n, p; cin >> n >> p;
		vector <ll> arr, temp;
		set <ll> st;
		bool check = true, final = false;
		for(int i=0; i<n; i++) {
			ll num; cin >> num;
			arr.push_back(num), temp.push_back(num);
			st.insert(num);
			if(num!=1 && p%num!=0) check = false;
		}
		sort(temp.begin(), temp.end());
		bool flag = false;
		// cout << "check " << check << endl;
		// check every coin is divisible by each other
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(temp[j] % temp[i] != 0)
					flag=true;
			}
			if(flag) break;
		}
		if(!flag) {
			if(check & (!flag))
				final = true,cout << "NO\n";
			else {
				ll small = 1e14, large = -1;
				ll idx1,idx2;
				for(int i=0; i<n; i++) {
					if(arr[i]<small && arr[i]!=1) small=arr[i], idx1=i;
					if(arr[i]>large && arr[i]!=1) large=arr[i], idx2=i;
				}
				if(small==large && (check)) final = true, cout << "NO\n"; 
			}
		}
		if(!final)
		{		
			ll cent = -1, indx=0;
			ll ans[n] = {0};
			// find the coin that is not divisible by sum
			for(int i=0; i<n; i++) {
				if(p%arr[i]!=0 && arr[i]>cent) 
					cent=arr[i], indx=i;
			}	
			if(cent!=-1) ans[indx]=p/cent+1;
			// if coin not found
			else {
				auto it = st.rbegin();
				ll large, small;
				while(true) {						
					large=(*it);
					it++;
					small=(*it);
					if(large%small != 0) break;
				}
				for(int i=0; i<n; i++) {
					// cout << large << " large\n";
					if(arr[i] == large) {
						ll x = p/large-1;
						// cout << "x " << endl;
						ans[i] = x;
						p = p-x*large;
						break;
					} 
				}
				for(int i=0; i<n; i++) {
					if(arr[i] == small) {
						ans[i] = p/small+1;
						break;
					} 
				}
			}
			cout << "YES ";
			for(auto i:ans) cout << i << " ";
			cout << endl;
		}

	}
	return 0;
}