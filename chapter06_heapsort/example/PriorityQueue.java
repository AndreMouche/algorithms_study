package chapter06_heapsort.example;

import java.util.Scanner;

/**
 * 6.5 Priority Queue
 * Page 80-82 
 * Description:
 * 根据书上伪码实现的最大优先级队列
 * PS:没有测试数据真不爽 
 * 测试方案：
 * 输入一个数据集，要求从大到小输出各个数字
 * 测试构造：
 * 对输入的数据集构造优先队列，再依次输出 队首元素
 * 
 * input:
 * n   ...indicate the number of integers to sort
 * n integers     ..the numbers need to sort
 * output:
 * n integers for each case,in decreasing order
 * 
 * examples:
 * input:
	5
	5 4 3 2 1
	6
	9 6 3 6 3 1
	output:
    5 4 3 2 1 
    9 6 6 3 3 1 
 * 
 * Time complexity:O(nlog(n))
 * @author AndreMouche
 *
 */
public class PriorityQueue extends HeapSort{
	
	/**
	 * 返回当前优先队列中优先级最高元素
	 * 当前numbers队列中的最大元素
	 * @return
	 */
	public int heap_maximum(){
		return this.numbers.get(0);
	}
	
	/**
	 * 去掉并返回当前优先队列中优先级最高元素
	 * 即去掉并返回当前numbers队列中的最大元素
	 * 复杂度:O(logn)
	 * @return
	 * @throws Exception 
	 */
	public int heap_extract_max() throws Exception {
        if(this.numbers.size() == 0){
			throw new Exception("heap underflow!");
		}
        int max = this.numbers.get(0);
        this.numbers.set(0, this.numbers.get(this.numbers.size() - 1));
        this.numbers.remove(this.numbers.size() - 1 );
        this.heapsize = this.numbers.size() ;
        this.max_heapify(0);
		return max;
	}
	
	/**
	 * 获取id的父节点编号 
	 * @param id
	 * @return
	 * @throws Exception 
	 */
	protected int get_parent_id(int id ) throws Exception {
		if(id <= 0) {
			throw new Exception("root node has no parent!");
		}
		if(id%2 == 0) {
			return id/2-1;
		}
		return id/2;
	}
	
	/**
	 * 将id号元素值增加到key,key不能小于id原来的值
	 * 复杂度 O(logn)
	 * @param id
	 * @param key
	 * @throws Exception 
	 */
	public void heap_increase_key(int id,int key) throws Exception {
		if(key < this.numbers.get(id)) {
			throw new Exception("new key is smaller than current key!");
		}
		
		this.numbers.set(id, key);
	    while(id > 0) {  //沿着枝干依次检测各个父节点
	    	int parentid = this.get_parent_id(id);
	    	if(this.numbers.get(parentid) < this.numbers.get(id)) {
	    		int tmp = this.numbers.get(id);
	    		this.numbers.set(id, this.numbers.get(parentid));
	    		this.numbers.set(parentid,tmp);
	    	    id = parentid;
	    	    continue;
	    	}
	    	break;
	    }
		
	}
	
	/**
	 * 将元素x插入优先队列 
	 * @param key
	 * @throws Exception 
	 */
	public void max_heap_insert(int key) throws Exception {
		this.numbers.add(Integer.MIN_VALUE);
		this.heapsize = this.numbers.size();
		this.heap_increase_key(this.heapsize-1,key);
	}
	
	/**
	 * 测试优先队列,将输入的数据,从大到小输出
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext()) { 
			n = cin.nextInt(); //需排序的数字个数
			PriorityQueue priority_queue = new PriorityQueue();
			for (int i = 0; i < n; i++) {
				int num = cin.nextInt();
				priority_queue.max_heap_insert(num); //依次进入优先队列 
			}
			
			//priority_queue.output_numbers();
			while(priority_queue.getHeapsize()>0) { 
				int max = priority_queue.heap_extract_max();  //依次出队
				System.out.print(max+" ");
			}
			System.out.println();

		}
	}
}
