package chapter02.exercise;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/**
 * Exercise 2.3-7:
 * 
 * Page:23
 * Description:
 * 请给出一个运行时间为O(nlogn)的算法,使之能在给定一个由n个整数构成的集合S和另一个整数x时,
 * 判断出S中是否存在有两个其和等于x的元素 
 * Thinking:
 * 方案1：
 * step1:对集合S进行预处理,对其进行排序,使用快排,复杂度为nlogn
 * step2:对集合S中的从左到右的每个数,求出x-s[i]的值,
 * 根据大小在s[i+1..n]中使用二分寻找x-s[i]的值，复杂度为nlogn
 * 综上，此为符合题意的一种解法，其它更好的O(nlogn)解法？
 * 
 * 方案2：
 * O(n)的解法
 * step1:对集合S进行预处理，用一个HashMap存储，其中key表示数字，value为key在集合中出现的次数,
 * 复杂度为O(n)
 * step2:对集合中的每个元素,用 tmp = x-value,在HashMap中寻找tmp,若tmp == value,需保证tmp
 * 对应的value大于等于2,复杂度依旧为O(n)
 * 
 * input:
 * n   ...indicate the number of integers to sort
 * n integers     ..the Set S
 * x ..just x
 * output:
 * two integers from S,and there sum is x exactly. Or "SORRY" if do not exist
 * 
 * examples:
 * input:
	5
	-5 -4 3 2 1
	5
	6
	9 6 4 6 3 1
	8
	output:
    2 3
    SORRY

 * @author AndreMouche
 *
 */
public class CheckWhetherSumExist {
	/**Set S*/
	private List<Integer> numbers = new ArrayList<Integer>();
	private int x = 0;

	/**
	 * set array data:append num to numbers 
	 * @param num  
	 */
	public void set_data(int num) {
		this.numbers.add(num);
	}
   
	public void set_x(int x) {
		this.x = x;
	}
	
	/**
	 * 返回已按从小到大排好序数组numbers[left..right]中寻找是否存在key
	 * @param left
	 * @param right
	 * @param key
	 * @return
	 * Time complexity:O(logn)
	 */
    public boolean binary_search(int left,int right,int key) {
    	while(left<=right) {
    		int mid = (left+right) >> 1;
    	    if(this.numbers.get(mid) < key) {
    	    	left = mid + 1;
    	    } else if(this.numbers.get(mid) > key ) {
    	    	right = mid - 1 ;
    	    } else {
    	    	return true;
    	    }
    	}
    	return false;
    }
    
    /**
     * 方案1,复杂度为O(nlogn)
     */
	public void method1() {
		Collections.sort(this.numbers);
		for(int i = 0 ; i < this.numbers.size(); i++ ) {
			int y = x - this.numbers.get(i);
			if(y < this.numbers.get(i)) { //前面的数字事先已扫过,故跳过
				continue;
			} else {
				if(this.binary_search(i+1, this.numbers.size()-1,y)){
					System.out.println(this.numbers.get(i)+" " + y);
					return;
				}
			}
		}
		
	  System.out.println("SORRY");
	}
	
	/**
	 * 方案2 复杂度为O(n)
	 */
	public void method2() {
	  HashMap<Integer,Integer> S = new HashMap<Integer,Integer> ();	
	  for(int i = 0; i < this.numbers.size(); i++) {
		  int key = this.numbers.get(i);
		  if(S.containsKey(key)) {
			  S.put(key, S.get(key) + 1);
		  } else {
			  S.put(key, 1);
		  }
	  }
	  
	  for(int i = 0;i < this.numbers.size();i ++) {
		  int key = this.numbers.get(i);
		  int y = x - key;
		  if(S.containsKey(y)) {
			  if(key == y && S.get(y) == 1) {
				  continue;
			  } 
			  
			  System.out.println( key + " " + y);
			  return ;
		  }
	  }
	  
	  System.out.println("SORRY");
	}
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		while (cin.hasNext()) { 
			n = cin.nextInt(); //需排序的数字个数
			CheckWhetherSumExist test = new CheckWhetherSumExist();
			for (int i = 0; i < n; i++) {
				int num = cin.nextInt();
				test.set_data(num);
			}
			int x = cin.nextInt();
			test.set_x(x);
			//test.method1();
			test.method2();
		}
	}
}
