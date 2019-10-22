
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    ll arr[n];
    ll hash[1000001] = {0};
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      hash[arr[i]]++;
    }

    //cout << max;
    int max = *max_element(arr, arr + n);
    int ans = 0;
    vector<ll> visit;
    for (int i = 0; i <= 1000002; i++)
    {
      visit.push_back(0);
    }
    for (int i = n - 1; i >= 0; i--)
    {
      int count = 0;
      if (arr[i] == 1)
      {
        count += i;
      }
      if (count == 0 && visit[arr[i]] == 0)
      {
        count += hash[arr[i]] - 1;
        for (int j = 2 * arr[i]; j <= max; j += arr[i])
        {
          if (hash[j] > 0)
          {
            count += hash[j];
          }
        }
      }

      hash[arr[i]]--;
      visit[arr[i]] = 2;
      //cout << count << endl;
      if (count > ans)
        ans = count;
    }
    cout << ans << endl;
  }
  return 0;
}