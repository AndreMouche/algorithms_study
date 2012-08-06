/**
 * 练习 2.1-4
 * Page:19
 * 描述：有两个各自存放在数组A和数组B中的n位二进制整数，考虑它们的相加问题。
 * 变形后，本程序的实现，输入：
 * 每个case输入三行数据，其中第一行为一个在[2,10]内的一个整数base，第二三行代表base进制的数字
 * 输出：求第二、三行所代表数字的和，并将结果以base进制的形式呈现
 *
 */
#include<stdio.h>
#include<string.h>
const int N = 10000;
/**
 * 数组a,b分别代表alength,blength位的base进制数，其中数组的每个数代表一位
 * 求以上两个base进制数的和，为求方便，其中base <= 10
 * @param 字符串 a,数组a,a[i]代表该位数的数值
 * @param 字符串 b,类似数组a，代表一个base进制的数字
 * 求以上两数的和
*/
void sum(char *a,char *b,int base) {
   int ans[N];
   int i = 0;
   memset(ans,0,sizeof(ans));
   int alength = strlen(a);
   int blength = strlen(b);
   alength --;
   blength --;
   while(alength >= 0 && blength >=0) {
	   ans[i]+=a[alength]-'0' + b[blength]-'0';
	   ans[i+1] = ans[i+1] +  ans[i]/base;
	   ans[i] %= base;
	   i++;
	   alength --;
	   blength --;
   }

   while(alength >= 0) {
	   ans[i]+=a[alength]-'0';
	   ans[i+1] = ans[i+1] + ans[i]/base;
	   ans[i] %= base;
	   i++;
	   alength --;
   }

   while(blength >= 0) {
	   ans[i] += b[blength]-'0';
	   ans[i+1] = ans[i+1] + ans[i]/base;
	   ans[i] %= base;
	   i++;
	   blength --;
   }

   while(a[i]>base) {
	   ans[i+1] = ans[i+1]+a[i]/base;
	   ans[i] %= base;
	   i++;
   }

   while(i>0&&ans[i]==0)i--;
   while(i>=0){
	   printf("%d",ans[i]);
       i--;
   }
   printf("\n");
}

int main()
{
	char a[N],b[N];
	int base;
	while(scanf("%d",&base)!=EOF) {
		scanf("%s%s",a,b);
		sum(a,b,base);
	}
	return 0;
}

