package chapter07_quick_sort.exercise;

import chapter07_quick_sort.example.QuickSort;

/**
 * 7.1-2 当数组A[p..r]中的元素均相同时，Partition返回的q值是什么？。。(r)
 * 修改Partition,使得当数组A[p..r]中所有元素的值相同时，q=(p+r)/2。。耍个无赖，见代码
 * 7.1-4 傻逼的问题，不说了。。
 * @author AndreMouche
 *
 */
public class QuickSort_E extends QuickSort {
	  public int partition(int left,int right) {
	    	int x = this.numbers.get(right);
	    	int i = left-1;
	    	for(int j=left;j < right;j++) {
	    		if(this.numbers.get(j) <= x) {
	    			i++;
	    			this.swap(i, j);
	    		}
	    	}
	    	i++;
	    	this.swap(i,right);
	    	if(i == right) {  //所有元素都相等时，返回中间位置
	    		return (left+right)/2;
	    	}
	    	return i;
	    }
}
