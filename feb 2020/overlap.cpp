#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000001

ll dayofweek(ll d, ll m, ll y) {  
    static ll t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;  
}  

ll totalDays(ll month, ll year) {
	if( month == 2) {
		if((year%400==0) || (year%4==0 && year%100!=0))	return 29;
		else return 28;
	}
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			||month == 10 || month==12)	
		return 31;
	else return 30;
} 
vector <ll> overlap(N, 0);
int main()
{
	int t; cin >> t;
	for(int i=1; i<=400; i++) {
		ll x = dayofweek(1, 2, i);
		ll first_firday = 1;
		while(x != 5) {
			x++, x=x%7;
			first_firday++;
		}
		ll days_in_month = totalDays(2, i);
		x = dayofweek(days_in_month, 2, i);
		days_in_month -= x;
		ll second_last_sunday = days_in_month - 7;
		if(first_firday + 9 >= second_last_sunday ) overlap[i]++;
	}
	for(int i=1; i<N; i++) overlap[i]+=overlap[i-1];
	while(t--) 
	{
		ll m1, y1;  cin >> m1 >> y1;
		ll m2, y2;  cin >> m2 >> y2;
		if(m1 > 2) y1++;
		if(m2 < 2) y2--;
		ll temp1 = (y2 / 400) * overlap[400] + overlap[y2 % 400];
		ll temp2 = ((y1-1) / 400) * overlap[400] + overlap[(y1-1) % 400];
		ll ans = temp1 - temp2;
		cout << ans << endl;
	}
	return 0;
}