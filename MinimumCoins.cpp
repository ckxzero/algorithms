#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long target, N;
  long long i, j, prev;
  long long dp[100009]; 

  dp[0] = 0;  
  prev = 0;  
  cin >> target;

  do {
    cin >> N;
    int value[N];
    for (int i = 0; i < N; ++i) {
      cin >> value[N];
    }

    for (i = prev + 1; i <= target; ++i) {
      dp[i] = numeric_limits<long long>::max();
      for (j = 0; j < 3; ++j) {
	if (value[j] <= i && (1 + dp[i - value[j] ] ) < dp[i] ) 
	  dp[i] = 1 + dp[i - value[j] ];
      }
    }

    if (target > prev) prev = target;
    cout << dp[target] << endl;
    cin >> target;
  } while (target != 0);
}

