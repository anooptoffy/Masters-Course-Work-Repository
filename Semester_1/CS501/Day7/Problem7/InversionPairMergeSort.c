#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Inversion Pair   Can we do better ? O(nlogn)  Try using Merge Sort logic
 * 
 *  Let a0, a1, a2, ... , an-1  be a arbitrary sequence of numbers
 *  if i < j and ai > aj then [ai,aj] forms the inversion pair
 *
 *  Unsorted
 *  Links : http://www.geeksforgeeks.org/counting-inversions/
 *  
 *  Added the sorting logic, just to verify if the algorithm is working correctly
 *  For sorted desc = n(n-1)/2
 *  For sorted asc = 0
 */


int comparator(const void *a, const void *b){
	int f = *(int *)a;
	int s = *(int *)b;
	return s-f; //desc
}

int MIP(int a[], int f, int mid, int l){
	int c = 0;
	int a1, a2;
	a1 = mid - f + 1;
	a2 = l - mid;
	a1++;
	a2++;
	int i,j;
	int L[a1], R[a2];

	for(i = 1 ; i <= a1; i++){
		L[i] = a[f + i -  1];
		printf("%d ", L[i] );
	}
	printf("\n");
	
	//L[i + 1] = INT_MAX;

	for(j = 1 ; j <= a2; j++){
		R[j] = a[ mid + j];
		printf("%d ",R[j] );
	}
	printf("\n");

	//R[j + 1] = INT_MAX;
	
	i = 1;
	j = 1;
	while(i <= a1 && j <= a2){
		if(L[i] <= R[j]){
			i++;
		}
		else{
			j--;
			c += mid - i;			
		}
	}
	return c;
}

int IP(int a[], int i, int j){
	int invCount = 0;
	if(i < j){
		int mid = (i+j)/2;
		invCount = IP(a,i,mid);
		invCount += IP(a,mid+1,j);
		invCount += MIP(a,i,mid,j);
	}
	return invCount;
}

int main(int argc, char const *argv[])
{
	int a[] = {4, 5, 2, 6, 1};
	int size = sizeof(a)/sizeof(a[0]);
	 qsort((void *)a,size, sizeof(a[0]),comparator);
	// for (int i = 0; i < size; ++i)
	//  {
	//  	printf("%d ", a[i]);
	//  }
	
	printf("\nThe number of inversion pairs are, %d\n",IP(a,0,size - 1));

	return 0;
}