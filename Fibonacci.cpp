#include <iostream>
using namespace std;

int main() {
  long long target, i, prev;
  long long dp[100009];
  
  dp[0] = 0; // sometimes 1 depending on definition
  dp[1] = 1;
  prev = 1;  

  cin >> target;
  do {
    for (i = prev+1; i <= target; ++i) {
      dp[i] = dp[i-1] + dp[i-2];
    }

    if (target > prev) prev = target;
 
    cout << dp[target] << endl;

    cin >> target;

  } while (target != -1);
}
