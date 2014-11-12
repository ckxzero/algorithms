#include <iostream>
using namespace std;
typedef unsigned long long LL;

LL N;
LL dp[1000009];

int main() {
  cin >> N;

  dp[0] = 0; // sometimes 1 depending on definition
  dp[1] = 1;
  for (i = 2; i <= N; ++i) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  cout << dp[N] << endl;
}//end main
