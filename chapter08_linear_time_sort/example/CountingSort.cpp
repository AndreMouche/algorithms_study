/**
 * 8.2 Counting Sort
 * Page:99
 * Description:
 * 对数组A进行计数排序，其中数组A中的最大值接近于数组A的长度
 * 分析：
 * 复杂度为O(n)
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
	output:
    1 2 3 4 5
    1 3 3 6 6 9
 *
 *
 *PS:本节的练习太恶心了,没什么好写的就不做了...
 */

#include<stdio.h>
#include<string.h>
const int N = 100;
int a[N], b[N], c[N];

/**
 * 对 数组a进行计数排序
 * 数组B存放结果
 * c[i]为a中出现的小于等于i的元素的个数
 */
void counting_sort(int n, int k) {
	int i;
	memset(c, 0, (k + 1) * sizeof(int));
	for (i = 0; i < n; i++)
		c[a[i]]++;
	for (i = 1; i <= k; i++)  //c[i]包含小于等于i的元素个数
		c[i] += c[i - 1];
	for (i = n - 1; i >= 0; i--) {  //那么i在排序后的位置该为c[i]-1,注意下标从0开始记录
		b[c[a[i]] - 1] = a[i];  //之所以倒着搜索是为了保证稳定性，即相同的元素会按照id排序
		c[a[i]]--;
	}

	for (i = 0; i < n; i++)
		printf("%d ", b[i]);
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
		counting_sort(n, a[maxid]);
	}
	return 0;
}
