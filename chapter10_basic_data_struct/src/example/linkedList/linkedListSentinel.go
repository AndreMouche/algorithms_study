/**
 * 使用哨兵元素实现linkedList
 * User: fun
 * Date: 13-11-18
 * Time: 下午8:52
 * To change this template use File | Settings | File Templates.
 */
package linkedList

type LinkedListSentinel struct {
	sentinelItem *LinkedItem
}

/*
新建链表中只有一个哨兵元素
 */
func NewLinkedListSentinel() LinkedList {
	sentinel := &LinkedItem{
		value : 0,
	}
	sentinel.next = sentinel
	sentinel.pre = sentinel
	return &LinkedListSentinel{
		sentinel,
	}
}

/**
 借助哨兵可类似形成一个循环链表的效果，
 1.当第一次插入元素x curItem时：
  curItem的前后元素均为哨兵
  curItem.next = self.sentinelItem.next = self.sentinelItem
  curItem.pre = self.sentinelItem
  哨兵的前后元素均为curItem
  self.sentinelItem.next.pre = self.sentinelItem.pre = curItem,
  self.sentinelItem.next = curItem

 2.若当前list非空，curItem分析如下：
   curItem的前元素为哨兵
   curItem.pre = self.sentinelItem

   当前元素的后元素为原哨兵后的第一个元素：
   curItem.next = self.sentinelItem.next

   原链表中第一个元素的前一个元素为curItem
   self.sentinelItem.next.pre = curItem
   哨兵的后一个元素为当前元素curItem
   self.sentinelItem.next = curItem

 */
func (self *LinkedListSentinel) Insert(x int) {
	curItem := &LinkedItem{
		pre:self.sentinelItem,
		next:self.sentinelItem.next,
		value:x,
	}

	self.sentinelItem.next.pre = curItem
	self.sentinelItem.next = curItem
}

func (self *LinkedListSentinel) Delete(x int) bool {
	item := self.Search(x)
	if item == nil {
		return false
	}

	item.pre.next = item.next
	item.next.pre = item.pre
	return true
}

func (self *LinkedListSentinel) Search(x int) *LinkedItem {
	item := self.sentinelItem.next
	for {
		if item == self.sentinelItem {
			return nil
		}

		if item.value == x {
			return item
		}

		item = item.next
	}

	return nil
}

