// Codemania 2019 Prelims Question no - 2
// https://www.hackerearth.com/challenges/college/coma19p/
// Problem link - https://www.hackerearth.com/challenges/college/coma19p/algorithm/518dada476bd4089bae6eb1157518be6/
// Binary search through the sample space to come at the solution
#include <iostream>
#include <limits>
using namespace std;

int main() {
  using ll = long long int;
  ll n, y;
  cin >> n >> y;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  // The required value of x can be anything which a
  // long long int can contain
  ll low = 0;
  // Hack to make sure calculations down the line don't cause
  // integer overflow. We hope the answer won't be so big.
  ll max = numeric_limits<ll>::max() / 10;
  ll index = (low + max) / 2;
  ll old_index = 0;
  ll sum;
  // If two subseqent guesses are same then we are close to the solution
  while (index != old_index) {
    sum = 0;
    for (int j = 0; j < n; j++) {
      sum += index / arr[j];
      if (sum > y)
        break;
    }
    if (sum >= y) {
      max = index;
    } else
      low = index;

    old_index = index;
    index = (low + max) / 2;
  }

  // Incrementally check for the solution
  if (sum >= y) {
    while (sum >= y) {
      --index;
      sum = 0;
      for (int j = 0; j < n; j++) {
        sum += index / arr[j];
        if (sum > y)
          break;
      }
    }
    cout << index + 1 << endl;
  } else {
    while (sum < y) {
      ++index;
      sum = 0;
      for (int j = 0; j < n; j++) {
        sum += index / arr[j];
        if (sum > y)
          break;
      }
    }
    cout << index << endl;
  }
}
