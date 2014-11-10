public class Sorting{
    public static void main(String[] args){
	Double[] a = new Double[] {2.4, 329.32, 39.9, 1.1, 1.2, 3.328};
	print(a);
	//insertion(a);
	quick(a, 0, a.length-1);
	print(a);
    }//end main

    public static int void counting(int[] a , T k){
	int[] b = new int[a.length];
	int[] c = new int[a.length];
	
    }

    public static <T extends Comparable<T>> void quick(T[] a, int l, int r){
	if(l < r){
	    int m = partition(a, l, r);
	    quick(a, l, m-1);
	    quick(a, m+1, r);
	}
    }//end quick

    public static <T extends Comparable<T>> int partition(T[] a, int l, int r){
	T p = a[r];
	T temp;
	int i = 0, j = 0;
	for(i = l, j = l; i < r; ++i){
	    if(a[i].compareTo(p) < 0){
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		++j;
	    }
	}
	temp = p;
	a[r] = a[j];
	a[j] = temp;
	return j;
    }//end partition

    public static <T extends Comparable<T>> void insertion(T[] a){
	T temp;
	for(int i = 1; i < a.length; ++i){
	    for(int j = 0; j < i; ++j){
		if(a[i].compareTo(a[j]) < 0){
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

    public static <T extends Comparable<T>> void print(T[] a){
	for(T element:a){
	    System.out.print(element + " ");
	}
	System.out.println();
    }//end print
}//end class