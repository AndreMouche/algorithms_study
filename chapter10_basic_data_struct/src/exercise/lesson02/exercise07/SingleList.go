/**
 * 10.2-7:请给出一个O（n）时间的非递归过程，它对含n个元素的单链表的链进行逆转。
 除了链表本身占用的空间外，该过程应仅使用固定量的存储空间
 * User: fun
 * Date: 14-1-14
 * Time: 下午7:41
 * To change this template use File | Settings | File Templates.
 */
package exercise07

import "fmt"

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

/**
逆转链表，复杂度O(n)
 */
func (self *SingleList) Reverse(){
   prev := self.head
   cur := self.head.next
   for ; cur.next != nil; { //最后一个为哨兵元素
	  next := cur.next
	  cur.next = prev
	  prev = cur
	  cur = next
   }
   self.head.next = cur
   self.head = prev
}

func (self *SingleList) Print() {
	fmt.Println()
	for item := self.head; item.next != nil; item = item.next {
		fmt.Print(item.value, ",")
	}

	fmt.Println()
}

