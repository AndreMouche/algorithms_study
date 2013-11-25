/**
 *10.2-2:用单链表实现一个栈，要求PUSH和POP的操作时间仍为O(1)
 * User: fun
 * Date: 13-11-25
 * Time: 下午7:30
 * To change this template use File | Settings | File Templates.
 */
package exercise02

import "errors"

type StackItem struct {
	value  int
	next *StackItem
}

type SingleListStack struct {
	head *StackItem
}

func NewSingleListStack() *SingleListStack {
	sentinel := &StackItem{    //仅放入哨兵元素
		value:0,
		next :nil,
	}

	return &SingleListStack{head:sentinel}
}

func (self *SingleListStack) IsEmpty() bool {
	return self.head.next == nil
}

func (self *SingleListStack) Push(x int) {
	item := &StackItem{
		value: x,
		next:self.head, }
	self.head = item
}

func (self *SingleListStack) Pop() (int, error) {
	if self.IsEmpty() {
		return 0, errors.New("stack is empty now")
	}

	item := self.head
	self.head = self.head.next
	return item.value,nil

}


