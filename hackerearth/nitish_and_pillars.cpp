// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/nitish-and-pillars-0b5cfac4/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<pair<int, ll>> mystack;
    unordered_map<int, int> mymap;
    for (int i = n - 1; i >= 0; i--) {
        while (!mystack.empty() && mystack.top().second <= arr[i]) {
            mystack.pop();
        }

        if (mystack.empty()) {
            mymap[i] = -1;
        } else {
            mymap[i] = mystack.top().first;
        }

        mystack.push(make_pair(i, arr[i]));
    }

    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll count = 1;
        for (int i = l; i <= r;) {
            if (mymap[i] == -1) {
                break;
            } else {
                i = mymap[i];
                if (i <= r)
                    count++;
            }
        }

        cout << count << "\n";
    }
}
