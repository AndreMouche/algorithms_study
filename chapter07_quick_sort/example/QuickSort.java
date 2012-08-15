package chapter07_quick_sort.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 7.1 快速排序的实现
 * testdata:
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
 * 复杂度O(nlogn)
 * Page:145
 * @author AndreMouche
 *
 */
public class QuickSort {
    protected List<Integer> numbers = new ArrayList<Integer>();
    
    public void add_data(int num) {
    	this.numbers.add(num);
    }
    
    public void output_data() {
    	for(int i=0;i<this.numbers.size();i++) {
    		System.out.printf("%d ",this.numbers.get(i));
    	}
    	System.out.println();
    }
    
    /**
     * 调换numbers[i]与numbers[j]的值
     * @param i
     * @param j
     */
    public void swap(int i,int j) {
    	int tmp = this.numbers.get(i);
    	this.numbers.set(i, this.numbers.get(j));
    	this.numbers.set(j, tmp);
    }
    
    /**
     * 分解,将numbers[left,right]分解为两个子集numbers[left,t],numbers[t+1,right],
     * 使得numbers[left,t-1]中的所有数都小于等于numbers[t],
     * 且numbers[t+1,right]中的所有数都大于numbers[t]
     * 复杂度O(n)
     * @param left
     * @param right
     * @return t
     */
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
    	return i;
    }
    
    /**
     * 快速排序
     * 复杂度O(nlogn)
     * @param left
     * @param right
     */
    public void quicksort(int left,int right) {
    	if(left < right) {
    		int q = this.partition(left, right);
    		this.quicksort(left, q-1);
    		this.quicksort(q+1, right);
    	}
    }
    
    public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext()) { 
			n = cin.nextInt(); //需排序的数字个数
			QuickSort sorttest = new QuickSort();
			for (int i = 0; i < n; i++) {
				int num = cin.nextInt();
				sorttest.add_data(num);
			}
			sorttest.quicksort(0,n-1);
			sorttest.output_data();
		}
	}
    
    
    
}
