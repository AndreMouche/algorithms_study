/**
 * 用环形单链表连实现字典操作INSERT，DELETE和SEARCH，并给出它们的运行时间。
 * User: fun
 * Date: 13-11-25
 * Time: 下午8:31
 * To change this template use File | Settings | File Templates.
 */
package exercise05

import "fmt"

type DicItem struct {
	key   int
	value int
	next *DicItem
}

type LinkDir struct {
	head *DicItem
}

func NewDic() (*LinkDir) {
	sentinel := &DicItem{
		key:-1,
		value:0,
	}

	sentinel.next = sentinel
	return &LinkDir{
		head:sentinel,
	}
}

/**
查找复杂度O(n)
 */
func (self *LinkDir) Search(key int) (*DicItem) {
	for curItem := self.head.next; curItem != self.head; curItem = curItem.next {
		fmt.Println(curItem.key)
		if curItem.key == key {
			return curItem
		}

		if curItem.key == -1 {
			fmt.Println("errpr-1")
			break
		}
	}

	return nil
}

/**
复杂度为O(n)
 */
func (self *LinkDir) Insert(key, value int) (ok bool) {
	item := self.Search(key)
	if item != nil {
		return false
	}

	item = &DicItem{key:key, value:value, next:self.head.next}
	self.head.next = item
	return true
}

func (self *LinkDir) Delete(key int) (bool) {
	item := self.Search(key)
	if item == nil {
		return false
	}
	//将链表item后一个元素的所有值拷贝至当前元素，并删除item.next
	item.key = item.next.key
	item.value = item.next.value
	item.next = item.next.next
	return true
}
