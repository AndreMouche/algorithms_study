package chapter02.exercise;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Exercise 2.3-6:
 * Insertion sort with binary search
 * Page:22
 * Description:
 * 观察一下2.1节中给出的Insertion-sort过程,在5-7行的while循环中,采用了一种线性查找策略,
 * 在已排好序的子数组A[1..j-1]中(反向)扫描.是否可以改用二分查找策略(见习题2.3-5),
 * 来将插入排序算法的总体最坏情况运行时间变为O(nlogn)?
 * 
 * Thinking:不能吧.即使用了二分查找,将查找位置的复杂度降至logn,但在将key放置正确位置的复杂度
 * 依旧是O(n)吧,难道有类似链表的数据结构,即可以通过下标定为数据,又可以随时随地插入数据?
 * 
 * 
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
 * Time complexity:O(n^2)

 * @author AndreMouche
 *
 */
public class InsertionSortWithBinarySearch {
	/**array to sort*/
	private List<Integer> numbers = new ArrayList<Integer>();

	/**
	 * set array data:append num to numbers 
	 * @param num  
	 */
	public void set_data(int num) {
		this.numbers.add(num);
	}

	public void output_numbers() {
		for (int i = 0; i < this.numbers.size(); i++) {
			System.out.printf(this.numbers.get(i) + " ");

		}
		System.out.println();
	}
	
	/**
	 * 返回已按从小到大排好序数组numbers[left..right]中第一个比key大的数字的位置
	 * @param left
	 * @param right
	 * @param key
	 * @return
	 * Time complexity:O(logn)
	 */
    public int binary_search(int left,int right,int key) {
    	while(left<right) {
    		int mid = (left+right) >> 1;
    	    if(this.numbers.get(mid) <= key) {
    	    	left = mid + 1;
    	    } else {
    	    	right = mid;
    	    }
    	}
    	return left;
    }
    
	/**
	 * 插入递归排序,对a[1..n]之间的数进行排序
	 * @param n
	 */
	public void insertion_sort_with_recursion(int n) {
		if(n == 0) {  
			return ;
		}
		this.insertion_sort_with_recursion(n-1); //先对前n-1个数排序
		
		int key = this.numbers.get(n);  //再将numbers[n]插入到正确的位置
		int kid = this.binary_search(0, n-1, key); //通过二分查找,找到key的正确位置
		int i = n-1;  
		while( i>= kid ) {
			this.numbers.set(i+1, this.numbers.get(i));
			i -- ;
		}
		
		this.numbers.set(i+1, key);
	}
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext()) { 
			n = cin.nextInt(); //需排序的数字个数
			InsertionSortWithBinarySearch sort = new InsertionSortWithBinarySearch();
			for (int i = 0; i < n; i++) {
				int num = cin.nextInt();
				sort.set_data(num);
			}
			sort.insertion_sort_with_recursion(n - 1);
			sort.output_numbers();
		}
	}
}
