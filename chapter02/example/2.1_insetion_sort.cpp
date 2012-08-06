/**
 * Insertion sort
 * Time complexity:O(n^2)
 * Page:10
 *
 * Description:
 *  使用插入排序法对n个整数进行排序
 * input:
 * n   ...indicate the number of integers to sort
 * n integers     ..the numbers need to sort
 *
 * output:
 * n integers for each case,in nondecreasing order
 *
 * examples:
 * input:
	5
	5 4 3 2 1
	6
	9 6 3 6 3 1

   output:
   1 2 3 4 5
   1 3 3 6 6 9
 *
 */

#include<stdio.h>
#include<string.h>
const int N = 10000;

/**
对有n个元素的整数数组number进行插入排序
复杂度为O(n^2)
@param n: the length of the array
@number:the array need to sort
*/
void insertion_sort( int n,int *number ) {
    int i,j;
	for(i=1;i<n;i++) {
	   j = i-1;
	   int key = number[i];
	   while(j>=0&&number[j]>key) {
	      number[j+1]=number[j];
		  j--;
	   }
	  number[j+1] = key;
	}
}


int main()
{
	int n;
	int a[N];
	while(scanf("%d",&n)!=EOF) {
	   int i;
	   for(i=0;i<n;i++) {
	     scanf("%d",&a[i]);
	   }
	   insertion_sort(n,a);
	   for(i=0;i<n;i++) {
	       printf("%d ",a[i]);
	   }
	   printf("\n");
	}
	return 0;
}



