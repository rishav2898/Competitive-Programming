#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long int;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int arr[100009] = {0};
        int n;
        cin >> n;
        unordered_map<ll, ll> hash;
        ll temp;
        for (int i = 1; i <= n; i++) {
            cin >> temp;
            int j = (i - temp) <= 0 ? 1 : (i - temp);
            int k = (i + temp) > n ? n + 1 : (i + temp + 1);
            arr[j] += 1;
            arr[k] -= 1;
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += arr[i];
            hash[sum] += 1;
        }
        int i;
        for (i = 0; i < n; i++) {
            cin >> temp;
            if (hash[temp] > 0) {
                hash[temp] -= 1;
            } else {
                cout << "NO" << endl;
                cin.ignore(n * 20, '\n');
                break;
            }
        }
        if (i == n) {
            cout << "YES" << endl;
        }
    }
}