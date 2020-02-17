#include <bits/stdc++.h>
#define ll long long
#define N 1000000
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll length;
	    cin>>length;
	    string s;
	    cin>>s;
	    char ch;
	    cin>>ch;
	    ll count=0,last=0,sum=0,rem;
	    for(int i=0; i<length; i++)
	    {
	        if(s[i] == ch)
	        {
	            count++;
	            last += count;
	            rem = length - last;
	            sum += count * (rem + 1);
	            count = 0;
	        }
	        else
	            count++;
	    }
	    cout<<sum<<"\n";
	    
	}
	return 0;
}
