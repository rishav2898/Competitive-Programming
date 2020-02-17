#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    cout<<"hello";
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n, greater<int>());
    int x,y;
    for(int i=1; i<n; i++)
    {
        if(a[0]!=a[i])
        {
            x=a[i];
            y=a[0];
            break;
        }
    }
    //cout<<"\n"<<x<<y;
    cout<<x % y;
}
