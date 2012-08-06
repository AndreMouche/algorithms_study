/**
 * ��ϰ 2.1-4
 * Page:19
 * ���������������Դ��������A������B�е�nλ�������������������ǵ�������⡣
 * ���κ󣬱������ʵ�֣����룺
 * ÿ��case�����������ݣ����е�һ��Ϊһ����[2,10]�ڵ�һ������base���ڶ����д���base���Ƶ�����
 * �������ڶ����������������ֵĺͣ����������base���Ƶ���ʽ����
 *
 */
#include<stdio.h>
#include<string.h>
const int N = 10000;
/**
 * ����a,b�ֱ����alength,blengthλ��base�����������������ÿ��������һλ
 * ����������base�������ĺͣ�Ϊ�󷽱㣬����base <= 10
 * @param �ַ��� a,����a,a[i]�����λ������ֵ
 * @param �ַ��� b,��������a������һ��base���Ƶ�����
 * �����������ĺ�
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
