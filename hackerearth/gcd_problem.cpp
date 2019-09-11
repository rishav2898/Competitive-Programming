// https://www.hackerearth.com/challenges/competitive/june-circuits-19/algorithm/calculate-gcd-june-circuit-e5e41856/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define N 100001
#define power_4(x) ((((((x * x) % M) * x) % M) * x) % M)

#define M 1000000007
ll fact[N] = {1}; // Factorial Table

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return res;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    ll asign = a >= 0 ? 1 : -1;
    ll bsign = b >= 0 ? 1 : -1;
    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;

    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll _x, _y;
        ll ret = extended_euclid(b, a % b, _x, _y);
        x = asign * _y;
        y = bsign * (_x - (a / b) * _y);
        return ret;
    }
}

ll inv(ll a) {
    ll x, y;
    extended_euclid(a, M, x, y);
    if (x < 0) {
        x = M - ((-x) % M);
    }

    return x;
}

ll fact_inv(ll n) {
    static ll table[100001] = {0};
    if (!table[n]) {
        table[n] = inv(fact[n]);
    }

    return table[n];
}

int main() {
    // ll M = 1000000007;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // From
    // https://math.stackexchange.com/questions/3272313/how-to-calculate-the-gcd/3272446
    ll F[N] = {0, 0, 0, 0, 1};
    int fp = 4; // Initially we know value of F upto 4

    // Setup factorial table
    for (int i = 1; i <= N; i++) {
        fact[i] = (i * fact[i - 1]) % M;
    }
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll sum = 0;
        if (n > fp) {
            for (int i = fp + 1; i <= n; i++) {
                ll term =
                    ((((fact[i] * fact_inv(4)) % M) * fact_inv(i - 4)) % M);
                for (int j = 2; (i / j) > 3; j++) {
                    term = (term - F[i / j]) % M;
                }
                F[i] = term;
            }
        }

        fp = n;

        for (int i = 1; i <= (n / 4); i++) {
            sum += (power(i, 4) * F[n / i]) % M;
            sum %= M;
        }
        cout << sum << "\n";
    }
}