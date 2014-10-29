#include <iostream>
using namespace std;

//my node
struct node{ 
  int key;
  int posNeg; //-1=neg, 1=pos, 0=undetermined
};

//I was thinking of using index 0 as a special case
//but turns out I didn't need to
//I didn't want to change my code so I just left the arrays starting at 1
node a[1009]; //a begins at 1             
int dp[1009]; //dp begins at 1
              //dp holds the longest zigzag subsequent at any given index

int main() {
  int n; //size of list of numbers
  cin>>n;
  for(int i=1; i<=n; ++i){
    cin>>a[i].key;
  }

  dp[1]=1; //base case
  a[1].posNeg=0; //base case
  for(int i=2; i<=n; ++i){
    //look at previously determined subproblems
    //and take the max of those values
    for(int j=1; j<i; ++j){
      if(a[j].posNeg==0){
	if(a[i].key-a[j].key>0){
	  dp[i]=dp[j]+1;
	  a[i].posNeg=1;
	}else if(a[i].key-a[j].key<0){
	  dp[i]=dp[j]+1;
	  a[i].posNeg=-1;
	}else{
	  dp[i]=dp[j];
	  a[i].posNeg=0;
	}
      }else if(a[i].key>a[j].key && a[j].posNeg==-1){
	dp[i]=max(dp[i],1+dp[j]);
	a[i].posNeg=1;
      }else if(a[i].key<a[i-1].key && a[i-1].posNeg==1){
	dp[i]=max(dp[i],1+dp[j]);
	a[i].posNeg=-1;
      }
    }//j
  }//i
  
  int max=0;
  max=dp[0];
  for(int i=1; i<=n; ++i){
    if(dp[i]>max){
      max=dp[i];
    }
  }
  cout<<max<<endl;
}
