/*
  Given a sequence of nonnegative numbers, find the longest zigzag subsequence.
  A zigzag sequence is one where a[i] < a[i+1] > a[i+2] < a[i+3] or vice versa.
 */

#include <iostream>
using namespace std;

int N;
unsigned long long a[1000009]; //holds inputs
unsigned long long memo[1000009]; //saves values for dp[i]
unsigned long long longest[1000009];
int b[1000009]; //-1 = neg, 0 = undetermined, 1 = pos
int dp[1000009]; //holds the longest zigzag subsequence for any dp[i]

int main(){
  cin >> N;
  for(int i = 0; i < N; ++i){
    cin >> a[i];
    dp[i] = 1; //each number is at least its longest subsequence
  }

  b[0] = 0; //base case
  for(int i = 1; i < N; ++i){
    //looks at previously solved subproblems and take max
    for(int j = 0; j < i; ++j){
      if(a[i] > a[j] && dp[i] < dp[j] + 1 && (b[j] == -1 || b[j] == 0)){
	dp[i] = dp[j] + 1;
	b[i] = 1;
	memo[i] = j;
      }else if(a[i] < a[j] && dp[i] < dp[j] + 1 && (b[j] == 1 || b[j] == 0)){
	dp[i] = dp[j] + 1;
	b[i] = -1;
	memo[i] = j;
      }
    }
  }

  //search for max dp[i]
  int max = dp[0];
  int j = 0;
  for(int i = 0; i < N; ++i){
    if(dp[i]>max){
      max = dp[i];
      j = i;
    }
  }
  cout << max << endl;
  
  //finding longest zigzag subsequence
  int i = max - 1;
  while (j != memo[j]){
    longest[i] = a[j];
    --i;
    j = memo[j];
  }
  longest[0] = a[j];

  for(int i = 0; i < max - 1; ++i){
    cout << longest[i] << " " ; 
  }
  cout << longest[max-1] << endl;

}//end main
