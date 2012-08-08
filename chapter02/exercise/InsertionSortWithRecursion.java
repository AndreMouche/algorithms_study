package chapter02.exercise;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Exercise 2.3-4:
 * Insertion sort with recursion
 * Page:22
 * Description:
 * 插入排序可以如下改写成一个递归过程:为排序A[1..n],先递归地排序A[1..n-1],
 * 然后再将A[n]插入到已排序的数组A[1..n-1]中去.对插入排序的这一递归版本,
 * 为它的运行时间写一个递归式
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
 * 运行时间写一个递归式:
 * T(1)= 1
 * T(n)=T(n-1)+n-1
 * @author AndreMouche
 *
 */
public class InsertionSortWithRecursion {
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
	 * 插入递归排序,对a[1..n]之间的数进行排序
	 * @param n
	 */
	public void insertion_sort_with_recursion(int n) {
		if(n == 0) {  
			return ;
		}
		this.insertion_sort_with_recursion(n-1); //先对前n-1个数排序
		int i = n-1;  
		int key = this.numbers.get(n);  //再将numbers[n]插入到正确的位置
		while( i>=0 && this.numbers.get(i) > key ) {
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
			InsertionSortWithRecursion sort = new InsertionSortWithRecursion();
			for (int i = 0; i < n; i++) {
				int num = cin.nextInt();
				sort.set_data(num);
			}
			sort.insertion_sort_with_recursion(n - 1);
			sort.output_numbers();
		}
	}
}
