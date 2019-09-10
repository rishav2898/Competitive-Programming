// https://www.hackerearth.com/challenges/college/codiyapa-pre/algorithm/c0004a088db249848c45cfcfe3e0341f/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    bool sq[2001] = {false};
    int num = sqrt(2001);
    for (int i = 1; i <= num; i++) {
        if (i * i < 2001)
            sq[i * i] = true;
        if (i * i * i < 2001)
            sq[i * i * i] = true;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        arr.reserve(n);
        unordered_map<int, int> unique;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            unique[temp]++;
        }
        for (auto v : unique) {
            arr.push_back(v.first);
        }
        n = arr.size();
        long long int count = 0;
        for (int i = 0; i < n; i++) {
            int c = unique[arr[i]];
            if (c > 1 && sq[2 * arr[i]]) {
                count += c * (c - 1) / 2;
            }
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];
                if (sq[sum]) {
                    count += c * unique[arr[j]];
                }
            }
        }
        cout << count << "\n";
    }
}
