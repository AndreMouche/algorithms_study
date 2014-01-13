/**
 * 10.2-6 动态集合操作Union以两个不相交的集合s1和s2作为输入，输出集合S=S1US2包含了S1和S2的所有元素。该操作常常会破坏S1和S2。
 * 说明应如何选用一种合适的表数据结构，以便支持在O(1)时间内的UNION操作。
 * 方法:链表中设置尾指针，然后将其中一个链表的尾指针连接到另一个链表的表头
 * User: fun
 * Date: 14-1-13
 * Time: 下午8:16
 * To change this template use File | Settings | File Templates.
 */
package exercise06

import "fmt"

type SingleListItem struct {
	next *SingleListItem
	value int
}


type SingleList struct {
	head *SingleListItem
	tail *SingleListItem
}

func NewSingleList() (*SingleList) {
	sentinel := &SingleListItem{
		next:nil,
		value:0,
	}
	return &SingleList{sentinel, sentinel}
}

/**
从链表首部开始查找，直到找到该值或遇到哨兵元素为止
复杂度O(n)
 */
func (self *SingleList) Search(k int) *SingleListItem {
	item := self.head
	for {
		if item.next == self.tail { //当前元素为哨兵
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

func (self *SingleList) Union(set2 *SingleList) {
	self.tail.next = set2.head.next
	self.tail.value = set2.head.value
	self.tail = set2.tail
	return
}


func (self *SingleList) Print() {
	fmt.Println()
	for item := self.head; item != self.tail; item = item.next {
		fmt.Print(item.value, ",")
	}

	fmt.Println()
}
