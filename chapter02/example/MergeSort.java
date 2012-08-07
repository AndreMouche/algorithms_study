package chapter02.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Merge Sort
 * 2.3.1 Divide and Conquer on Page 17
 * Time complexity:O(nlog(n))
 * 
 * Description:
 *  sort numbers with merge sort
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
 * @author AndreMouche
 * 
 */
public class MergeSort {

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
	 * 已知numbers[p..q]及numbers[q+1..r]已按从小到大排序, 
	 * 合并numbers[p..r],使得其从小到大排序
	 * @param p
	 * @param q
	 * @param r
	 */
	public void merge(int p, int q, int r) {
		int n1 = q - p + 1;
		int n2 = r - q;
		List<Integer> Left = new ArrayList<Integer>();
		List<Integer> Right = new ArrayList<Integer>();
		for (int i = 0; i < n1; i++) {
			Left.add(this.numbers.get(p + i));
		}

		for (int i = 0; i < n2; i++) {
			Right.add(this.numbers.get(q + i + 1));
		}
		Right.add(Integer.MAX_VALUE);
		Left.add(Integer.MAX_VALUE);
		int lid = 0;
		int rid = 0;
		for (int k = p; k <= r; k++) {
			if (Left.get(lid) < Right.get(rid)) {
				this.numbers.set(k, Left.get(lid));
				lid++;
			} else {
				this.numbers.set(k, Right.get(rid));
				rid++;
			}
		}

	}

	/**
	 * 对数组numbers下标区间为[left,right]的子集进行排序
	 * @param left
	 * @param right
	 */
	public void merge_sort(int left, int right) {
		if (left >= right)
			return;
		int mid = (left + right) >> 1;
		this.merge_sort(left, mid); // 对左边序列进行排序
		this.merge_sort(mid + 1, right); // 对右边序列进行排序
		this.merge(left, mid, right); // 合并排好序的左右子集

	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext()) { 
			n = cin.nextInt(); //需排序的数字个数
			MergeSort mergesort = new MergeSort();
			for (int i = 0; i < n; i++) {
				int num = cin.nextInt();
				mergesort.set_data(num);
			}
			mergesort.merge_sort(0, n - 1);
			mergesort.output_numbers();
		}
	}
}