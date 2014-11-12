/*
  Chris Nguyen
  11/8/2014

  Given a list of N integers, find the longest increasing subsequence.
  
  N <= 10^6
 */

#include <iostream>
using namespace std;
typedef unsigned long long LL;

LL N;
LL a[100009];
int dp[1000009]; //holds longest subsequence for any dp[i]
int memo[1000009]; //remembers the values of longest dp[i]

int main(){
    cin >> N;
    for (int i = 0; i < N; ++i){
      cin >> a[i];
      dp[i] = 1; //each item is at least its longest subsequence
    }
    
    memo[0] = 0; 
    for (int i = 1; i < N; ++i){
      for (int j = 0; j < i; ++j){
	if(a[i] > a[j] && dp[i] < dp[j] + 1){
	  dp[i] = dp[j] + 1;
	  memo[i] = j;
	}
      }
    }
  
    int max = dp[0];
    int j = 0;
    for(int i = 0; i < N; ++i) {
      if(dp[i] > max) {
	max = dp[i];
	j = i;
      }
    }

    cout << max << endl;
    while(memo[j] != j){ //prints in reverse order
      cout << a[j] << " ";
      j = memo[j];
    }
    cout << a[j] << endl;
}//end main
