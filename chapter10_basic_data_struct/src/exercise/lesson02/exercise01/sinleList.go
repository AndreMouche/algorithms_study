/**
 * 10.2-1:动态集合上的操作Insert能否用一个单链表在O(1)时间内实现？对Delete操作呢？
   a.每次插入数据时插入首部
   b.删除操作时将其下一个copy至当前位置，再将当前位置的下一个元素删除即可
 * User: fun
 * Date: 13-11-19
 * Time: 下午8:37
 * To change this template use File | Settings | File Templates.
 */
package exercise01

type SingleListItem struct {
	next *SingleListItem
	value int
}


type SingleList struct {
	head *SingleListItem
}

func NewSingleList() (*SingleList) {
	sentinel := &SingleListItem{
		next:nil,
		value:0,
	}
	return &SingleList{sentinel}
}

/**
从链表首部开始查找，直到找到该值或遇到哨兵元素为止
复杂度O(n)
 */
func (self *SingleList) Search(k int) *SingleListItem {
	item := self.head
	for {
		if item.next == nil { //当前元素为哨兵
			return nil
		}

		if item.value == k {
			return item
		}

		item = item.next
	}

	return nil
}

/**
插入到链表首部，复杂度O(1)
 */

func (self *SingleList) Insert(value int) {
	curItem := &SingleListItem{next:self.head, value:value}
	self.head = curItem
}

/**
删除元素item
将当前元素的next元素所有属性拷贝给当前元素并将next删除即可，即
item.value = item.next.value
item.next = item.next.next
由于哨兵元素的存在，以上代码不存在指向空指针引发的非法调用
复杂度O(1)
 */
func (self *SingleList) Delete(item *SingleListItem) {
	item.value = item.next.value
	item.next = item.next.next
}

