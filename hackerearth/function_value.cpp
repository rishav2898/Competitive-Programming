// https://www.hackerearth.com/problem/algorithm/june-circuits-function-value-bdd25438/
#include <assert.h>
#include <iostream>
#include <tuple>

using namespace std;
using ll = long long int;

ll handle_neg(ll n, ll mod) {
    if (n >= 0) {
        return n;
    } else {
        return mod - ((-n) % mod);
    }
}

ll power2(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = ((res % mod) * (a % mod)) % mod;
        }
        a = ((a % mod) * (a % mod)) % mod;
        b /= 2;
    }
    return res;
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }
    return res;
}

ll func(ll n, ll mod) {
    if (n & 1) {
        return power2(3, (n - 1) / 2, mod);
    } else {
        return power2(n, 2, mod) - ((3 * n) % mod) + (3 % mod);
    }
}

ll sum_of_gp(ll b, ll p, ll M) {
    if (p == 0) {
        return 1;
    } else if (p == 1) {
        return (1 + b) % M;
    } else {
        if ((p & 1) == 0) {
            p /= 2;
            return ((1 + (((b * ((1 + b) % M) % M) *
                           sum_of_gp(((b * b) % M), p - 1, M)) %
                          M)) %
                    M);
        } else {
            p = p / 2;
            return ((((1 + b) % M) * sum_of_gp(((b * b) % M), p, M)) % M);
        }
    }
}

#define MUL(a, b) (((a % mod) * (b % mod)) % mod)
#define SUB(a, b) handle_neg(((a % mod) - (b % mod)) % mod, mod)
#define ADD(a, b) ((a % mod) + (b % mod)) % mod

ll summ(ll n, ll mod) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    }
    ll m = (n - 1) / 2;
    ll odd_contribution = sum_of_gp(3, m, mod);

    ll sum = 0;
    m = (n / 2) - 1;
    if (m & 1) {
        sum = 3;
        m /= 2;
        if (m > 0) {
            sum += MUL(3, SUB(sum_of_gp(9, m, mod), 1));
        }

        sum = MUL(sum, 2);
    } else {
        m /= 2;
        if (m > 0) {
            sum = MUL(2, SUB(sum_of_gp(9, m, mod), 1));
        }
    }

    sum = handle_neg(sum, mod);
    sum = ADD(sum, (n / 2));
    sum = ADD(sum, odd_contribution);
    return sum;
}

ll f(ll n, ll *table, ll mod) {
    if (table[n] != 0) {
        return table[n];
    } else if (n & 1) {
        table[n] = (3 * table[n - 2]) % mod;
    } else {
        table[n] = (2 * table[n - 1] - table[n - 2] + 2) % mod;
    }
    return table[n];
}

ll brute_force(ll l, ll r, ll mod) {
    ll table[10000] = {1, 1, 1, 0};
    for (int i = 1; i <= r; i++) {
        f(i, table, mod);
    }
    ll sum = 0;
    for (int i = l; i <= r; i++) {
        sum += f(i, table, mod);
        sum %= mod;
    }
    return handle_neg(sum, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    ll mod = 100000007;

    cin >> q >> mod;
    while (q--) {
        ll l, r;
        cin >> l >> r;

        cout << handle_neg((summ(r, mod) - summ(l - 1, mod)) % mod, mod)
             << endl;
    }
}
