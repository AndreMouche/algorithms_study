package chapter02.exercise;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


/**
 * Exercise 2.3-2:
 * Merge sort without sentinel card
 * Page:22
 * Description:
 * 改写Merge过程，是之不使用哨兵元素，而是在一旦数组R或L中的所有元素都被复制回数组A后，
 * 就立即停止，再将另一个数组中的余下元素复制回数组A中
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
 * Time complexity:O(nlog(n))
 * @author AndreMouche
 *
 */
public class MergeSortWithoutSentinelCard {
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
	public void merge_without_sentinel_card(int p, int q, int r) {
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
		
		int lid = 0;
		int rid = 0;
		int k = p;
		for (; rid < Right.size() && lid< Left.size(); k++) {
			if (Left.get(lid) < Right.get(rid)) {
				this.numbers.set(k, Left.get(lid));
				lid++;
			} else {
				this.numbers.set(k, Right.get(rid));
				rid++;
			}
		}
		
		while(rid < Right.size()) {
			this.numbers.set(k, Right.get(rid));
			rid ++ ;
			k ++;
		}
		
		while(lid < Left.size()) {
			this.numbers.set(k,Left.get(lid));
			lid ++ ;
			k ++ ;
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
		this.merge_without_sentinel_card(left, mid, right); // 合并排好序的左右子集

	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext()) { 
			n = cin.nextInt(); //需排序的数字个数
			MergeSortWithoutSentinelCard mergesort = new MergeSortWithoutSentinelCard();
			for (int i = 0; i < n; i++) {
				int num = cin.nextInt();
				mergesort.set_data(num);
			}
			mergesort.merge_sort(0, n - 1);
			mergesort.output_numbers();
		}
	}
}
