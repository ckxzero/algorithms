/*
  Chris Nguyen
  11/8/2014

  Given a list of N integers, find the longest increasing subsequence.
  
  N <= 10^6
 */

#include <iostream>
using namespace std;

long long i, j;
long long N;
long long dp[100009], a[100009];

int main() {
    cin >> N;
    for (i = 0; i < N; ++i) {
      cin >> a[i];
    }
    
    dp[0] = 1;
    for (i = 1; i < N; ++i) {
      for (j = 0; j < i; ++j) {
	if(a[i] > a[j]) {
	  dp[i] = max(dp[i], dp[j]+1);
	}
      }
    }
  
    int max = dp[0];
    for(i = 0; i < N; ++i) {
      if(dp[i] > max) {
	max = dp[i];
      }
    }
    cout << max << endl;
}//end main
