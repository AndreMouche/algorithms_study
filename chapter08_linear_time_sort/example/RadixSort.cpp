/**
 * 8.3 Radix Sort
 * Page:101
 * Description:
 * 对数组A进行基数排序，其中A中所有数为非负整数
 * 分析：
 * 复杂度为O(d(n+10)),其中d为最高位编号
 * input:
 * n   ...indicate the number of integers to sort
 * n integers     ..the numbers need to sort
 * output:
 * n integers for each case,in nondecreasing order
 *
 * examples:
 * input:
	5
	5 4 3 2 1
	6
	9 6 3 6 3 1
	5
	12 143 34 43 55
	6
	9888 2332 2334 5454 3221 1234
	output:
    1 2 3 4 5
    1 3 3 6 6 9
	12 34 43 55 143
    1234 2332 2334 3221 5454 9888
 *
 *
 *PS:本节的练习太恶心了,没什么好写的就不做了...
 */

#include<stdio.h>
#include<string.h>
const int N = 1000;
int a[N];
int tmpa[10];
int tmpb[N];
int tmpc[10];

/**
 * 对数组A中每个元素根据第t位的大小进行基数排序
 */
void stable_sort_a_at_digit_t(int t,int n) {
    memset(tmpc,0,sizeof(tmpc));
	int i = 0;
	int div = 1;
	while(t--)
		div*=10;
	for(i=0;i<n;i++) {
	  tmpa[i] = (a[i]/div)%10;  //tempa[i]为a[i]的第t位上的数字
      tmpc[tmpa[i]]++;
	}
	for(i=1;i<10;i++)
		tmpc[i]+=tmpc[i-1];

	for(i=n-1;i>=0;i--) {
	    tmpb[tmpc[tmpa[i]]-1] = a[i];
		tmpc[tmpa[i]] --;
	}

	for(i=0;i<n;i++)
		a[i]=tmpb[i];
}

/**
 * 对数组A进行基数排序，其中n为A中的元素个数
 * d为A中最大数的最高位编号
 */
void redix_sort(int n,int d) {
   int i;
   for(i = 0;i < d;i++) //从低位往高位依次进行计数排序
   {
      stable_sort_a_at_digit_t(i,n);
   }

   for(i=0;i<n;i++)
	   printf("%d ",a[i]);
   printf("\n");
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int i;
		int maxid = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			maxid = a[maxid] > a[i] ? maxid : i;
		}
		int d = 0;
		int temp = a[maxid];
		while(temp) {
		   temp/=10;
		   d++;
		}
		redix_sort(n,d);
	}
	return 0;
}
