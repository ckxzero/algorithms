#include <iostream>
using namespace std;

long long dp[100009], a[100009];
long long N, i;

int main() {
    cin >> N;
    for (i = 0; i < N; ++i) {
      cin >> a[i];
    }
    
    dp[0] = 1;
    for (i = 1; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
	if(a[i] > a[j]) {
	  dp[i] = max(dp[i], dp[j]+1);
	}
      }
    }
  
    int max = dp[0];
    for(i=0; i<N; ++i) {
      if(dp[i]>max) {
	max=dp[i];
      }
    }
    cout<<max<<endl;
}
