/**
 * Page 121-122
 * User: fun
 * Date: 13-11-18
 * Time: 下午8:04
 * To change this template use File | Settings | File Templates.
 */
package linkedList

type LinkedListCommon struct {
	listhead *LinkedItem //记录链表的首部元素
}

func NewLinkedListCommon() LinkedList {
	return &LinkedListCommon{nil}
}

/**
 将value 插至链表首部，两种情况：
 1.链表为空链表
 2.链表非空
 复杂度：O(1)
 */
func (self *LinkedListCommon) Insert(value int) {
	if self.listhead == nil {
		self.listhead = &LinkedItem{pre:nil, next:nil, value:value}
		return
	} else {
		item := &LinkedItem{value:value}
		item.pre = nil
		item.next = self.listhead
		self.listhead.pre = item
		self.listhead = item
	}
}

/**
删除元素情况如下：
1.删除元素不存在链表中，返回false
2.删除元素为链表中最后一个元素，则将list置为nil,return true
3.删除元素位于链表首部
4.删除元素位于链表尾部
5.删除元素位于链表中间
复杂度为查找该元素的复杂度，即O（n）
 */
func (self *LinkedListCommon) Delete(value int) (bool) {
	item := self.Search(value)

	//删除元素不存在链表中，返回false
	if item == nil {
		return false
	}

	//当前元素为最后元素
	if item.pre == nil && item.next == nil {
		if item.next == nil {
			self.listhead = nil
			return true
		}
	}

	//位于链表首部
	if item.pre == nil {
		self.listhead = item.next
		self.listhead.pre = nil
		return true
	}

	//删除元素位于链表尾部
	if item.next == nil {
		item.pre.next = nil
		return true
	}

	//删除元素位于链表中间
	item.pre.next = item.next
	item.next.pre = item.pre

	return true

}

//复杂度O（n）
func (self *LinkedListCommon) Search(value int) (*LinkedItem) {
	item := self.listhead
	for {
		if item == nil {
			return nil
		}

		if item.value == value {
			return item
		}

		item = item.next
	}

	return nil
}

