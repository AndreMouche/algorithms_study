package chapter06_heapsort.exercise;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


/**
 * 6.2-5 Heap Sort
 * Page:76
 * Description:
 * MAX-HEAPIFY的代码效率较高，但第10行中的递归调用可能例外，它可能使某些编译程序产生出
 * 低效的代码。请用迭代的控制结构（循环）取代递归结构，从而写一个更为高效的MAX-HEAPIFY
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
public class HeapSort {
	/**array to sort*/
	protected List<Integer> numbers = new ArrayList<Integer>();
    
	/**当前堆的大小。。不是很准确，先这样吧*/
	protected int heapsize = 0;
	
	public int getHeapsize() {
		return heapsize;
	}

	public void setHeapsize(int heapsize) {
		this.heapsize = heapsize;
	}

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
	 * 对排序:
	 * 先构建numbers的最大堆,然后每次取出当前堆的最大数,即祖先,然后构建剩下子树的最大堆...
	 * 如此,便可依次取得从大到小的每个数字..
	 * 
	 * 复杂度 O(nlogn)
	 * Page:135
	 * 
	 * 貌似在构建完最大堆后,有更快的方式获取序列,用类似链表的数据结构解决?明天再测,累死我了..
	 */
	public void heapsort() {
		this.build_max_heap();
		for(int i = this.numbers.size()-1 ; i > 0 ; i -- ) {
			int curmax = this.numbers.get(0); //取出当前堆的祖先
			this.numbers.set(0, this.numbers.get(i));
			this.numbers.set(i, curmax);
			this.heapsize -- ;
			this.max_heapify(0);
		}
	}
	
	/**
	 * 利用叶子下标的特性,从第一层父亲节点开始,
	 * 构建数组numbers的最大堆
	 * Page:76
	 */
	public void build_max_heap() {
		this.setHeapsize(this.numbers.size());
		for(int i = this.numbers.size()/2 ; i >=0 ; i --) {
			this.max_heapify(i);
		}
	}
	
	/**
	 * 已知已id为父亲的左右子树均是最大堆,调整该子树,
	 * 使得id所在子树成为最大堆
	 * 
	 * 非递归版本
	 * 复杂度 log(n)
	 * Page:75 由此代码改编
	 * @param id
	 */
    public void max_heapify(int id) {
    	int left,right,maxid;
    	maxid = id;
    	do{
    		id = maxid;
	    	left = 2*id+1;
	    	right = 2*id + 2;
	    	if(left < this.heapsize && this.numbers.get(maxid) < this.numbers.get(left)) {
	    		maxid = left;
	    	}
	    	
	    	if(right < this.heapsize && this.numbers.get(maxid) < this.numbers.get(right)) {
	    		maxid = right;
	    	}
	    	
	    	if(maxid != id) { //降低id所在点的数字的层数
	    		int tmp = this.numbers.get(id);
	    		this.numbers.set(id, this.numbers.get(maxid));
	    		this.numbers.set(maxid, tmp);
	    	}
    	 }while(maxid != id);
    	
    }
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext()) { 
			n = cin.nextInt(); //需排序的数字个数
			HeapSort sorttest = new HeapSort();
			for (int i = 0; i < n; i++) {
				int num = cin.nextInt();
				sorttest.set_data(num);
			}
			sorttest.heapsort();
			sorttest.output_numbers();
		}
	}
}
