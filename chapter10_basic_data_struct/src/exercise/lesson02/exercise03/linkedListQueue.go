/**
 *10.2-3:用单链表实现一个队列，要求ENQUEUE和DEQUEUE的操作时间仍为O(1)
 * User: fun
 * Date: 13-11-25
 * Time: 下午7:43
 * To change this template use File | Settings | File Templates.
 */
package exercise03

import "errors"

type LinkedListQueueItem struct {
	value int
	next *LinkedListQueueItem
}

type SLinkedListQueue struct {
	head *LinkedListQueueItem
	tail *LinkedListQueueItem
}

func NewSLinkedListQueue()(*SLinkedListQueue){
	return &SLinkedListQueue{
		head:nil,
		tail:nil,
	}
}

func (self *SLinkedListQueue) EnQueue(elem int){

	item := &LinkedListQueueItem{
		value:elem,
		next:nil,
	}

	if self.head == nil{
	   self.head = item
	   self.tail = item
	} else {
		self.tail.next = item
		self.tail = item
	}
}


func (self *SLinkedListQueue) DeQueue() (int,error){
    if self.head == nil {
		return 0,errors.New("Empty Queue")
	}

	item := self.head
	self.head = self.head.next
	if self.head == nil { //已经移至队尾
		self.tail = nil
	}
	return item.value,nil
}

func (this *SLinkedListQueue) Empty() bool{
	return this.head == nil
}






