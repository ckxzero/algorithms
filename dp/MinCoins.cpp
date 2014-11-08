/*
  Chris Nguyen
  11/7/2014

  Given a number N and M number of different coins, 
  find the minimum number of coins to reach N.

  1 <= N, M <= 10^6
 */

#include <iostream>
using namespace std;
typedef long long LL;

LL i, j;
LL N, M;
LL dp[1000009], coin[1000009];

int main(){
  cin >> N >> M;
  for(i = 0; i < M; ++i){
    cin >> coin[i];
  }

  dp[0] = 0; //takes no coins to reach 0
  for(i = 1; i <= N; ++i){
    dp[i] = 1000011; //greater than the max number of coins used to reach 10^6
    for(j = 0; j < M; ++j){
      if(coin[j] <= i && dp[i-coin[j]] + 1 < dp[i]){
	dp[i] = dp[i-coin[j]] + 1;
      }
    }
  }

  cout << dp[N] << endl;
}//end main
