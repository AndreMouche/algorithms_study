package chapter06_heapsort.exercise;

/**
 * Page82
 * 6.5-7 HeapDelete:
 * Description:
 * 对含n个元素的最大堆，请给出时间为O(logn)的HeapDelete的实现
 * PS:test data...
 * 
 * 6.5-8:
 * 根据提示很容易就可以获得O(nlogk)负责度的算法,具体实现就不给了,主要是测试数据弄起来比较麻烦^ * 
 * @author AndreMouche
 *
 */
public class HeapDelete extends HeapSort {
    /**
     * 删除最大堆中id所在的元素并保持最大堆特性
     * 方案1:
     * step1:
     * 用id所在子树的某个叶子节点替换id的值
     * step2:
     * 删除step1中使用的叶子节点
     * step3:
     *   max_heapify(id)
     * 复杂度可能卡在删除叶子节点上,O(logn)?
     * @param id
     * @throws Exception 
     */
	public void heapdelete(int id) throws Exception {
    	if(id < 0 || id >= this.numbers.size()) {
    		throw new Exception("Id is illegal!");
    	}
    	
    	int leaf_id = this.get_heap_leaf_id(id);
    	this.numbers.set(id, this.numbers.get(leaf_id));//将id所在位置的值替换为id子树某个叶子节点的值
    	this.numbers.remove(leaf_id);//移除叶子节点  负责度为O(n) ...高了?
    	this.heapsize = this.numbers.size();
    	this.max_heapify(id);//使得id所在子树恢复最大堆特性
    }
	
	/**
	 *删除最大堆中id所在的元素并保持最大堆特性
     * 方案2:
     * step1:
     * 从当前节点id开始,沿着子树依次将左右子树中较大的那个数上移一层,直到遇到叶子节点
     * step2:
     * 删除叶子节点
     * 复杂度可能卡在删除叶子节点上,O(logn)?
	 * @param id
	 * @throws Exception
	 */
	public void heapdelete2(int id) throws Exception {
		if(id < 0 || id >= this.numbers.size()) {
    		throw new Exception("Id is illegal!");
    	}
    	this.heapsize = this.numbers.size();
    	int cur = id;
    	while((cur*2+1)<this.heapsize) {
    		int left = cur*2 + 1;
    		int right = left + 1 ;
    		if(left >= this.heapsize)//若当前节点不存在左子树(即已经是叶子)则退出循环
    			break;
    		//获取左右子树中值较大的那个点id,并将值赋给当前节点
    		int maxid = left;
    		if(right<this.heapsize&&this.numbers.get(maxid) < this.numbers.get(right)) {
    			maxid = right;
    		}
    		this.numbers.set(cur, this.numbers.get(maxid));
    		
    		cur = maxid;
    	}
    	
    	this.numbers.remove(cur);//cur肯定是某个叶子节点
    	
	}
	/**
	 * 获取编号为root所在子树编号最小的那个叶子节点
	 * @param root
	 * @return
	 * @throws Exception 
	 */
	public int get_heap_leaf_id(int root) throws Exception{
		if(root>this.numbers.size()) {
			throw new Exception("root is illegal!");
		}
		this.heapsize = this.numbers.size();
		int cur = root;
		while(cur < this.heapsize) {
			root = cur;
			cur = 2*root+1;
		}
		return root;
	}
}
