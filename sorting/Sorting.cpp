#include <iostream>
#include <vector>
using namespace std;

template<class T> int partition(T* a, int l, int r){
  T temp;
  T p = a[r]; //pivot
  for(int i = l, int j = l; i < r; ++i){
    if(a[i] < p){
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      ++j;
    }
  }
  temp = p;
  a[r] = a[j];
  a[j] = p;
  return j;
}//end partition

template<class T> void quick(T* a, int l, int r){
  if(l < r){
    int m = partition(a, l, r);
    quick(a, l, m-1);
    quick(a, m+1, r);
  }
}//end quick

template<class T> void insertion(T* a, int N){
  T temp;
  for(int i = 1; i < N; ++i){
    for(int j = 0; j < i; ++j){
      if(a[i] < a[j]){
	temp = a[i];
	for(int k = i; k > j; --k){
	  a[k] = a[k-1];
	}
	a[j] = temp;
	break;
      }
    }
  }
}//end insertion

template<class T> void print(T* a, int N){
  for(int i = 0; i < N-1; ++i){
    cout << a[i] << " ";
  }
  cout << a[N-1] << endl;
}//end print

int main(){
  int* a = new int[10] {1,3,353,59,52,2,6,8,9,10};
  //insertion(a, 10);
  quick(a, 0, 9);
  print(a, 10);
  delete[] a;
  print(a, 10);
}//end main
