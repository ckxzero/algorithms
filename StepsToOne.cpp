#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long i, prev;
  long long target;
  long long dp[1009];

  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
 
  prev = 3;
  cin >> target;
  do {
    for (i = prev + 1; i <= target; ++i) {
      if (i % 2 == 0 && i % 3 == 0) dp[i] = 1 + min( min( dp[i-1], dp[i/2] ), dp[i/3] );
      else if (i % 2 == 0) dp[i] = 1 + min( dp[i-1], dp[i/2] );
      else if (i % 3 == 0) dp[i] = 1 + min( dp[i-1], dp[i/3] );
      else dp[i] = 1 + dp[i-1];
    } 
    cout << dp[target] << endl;
    if (target > prev) prev = target;
    cin >> target;
  } while (target != 0);
  
}
